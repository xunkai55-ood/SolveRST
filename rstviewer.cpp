#include "rstviewer.h"

#include <QDebug>
#include <QGraphicsRectItem>

RSTViewer::RSTViewer(RST *rst, QObject *parent) :
    QObject(parent),
    bronze_(255, 128, 0), black_(0, 0, 0), darkBronze_(225, 108, 0),
    bkg_(30, 192, 30), BKG(30, 192, 30), edgeDarkFactor_(270),
    loopWidth_(4), pointRadius_(5), lineWidth_(4), edgeWidth_(8),
    emptyBoardSize_(300), boardMargin_(10), sc_(-1), limitSize_(100)
{
    mainView = new MainRSTView(this);
    miniView = new MiniRSTView(this);
    rst_ = rst;

    connect(miniView, SIGNAL(pickPort(qreal, qreal, qreal)), this, SLOT(setRealPort(qreal, qreal, qreal)));
    connect(mainView, SIGNAL(pickPort(qreal, qreal, qreal)), this, SLOT(setRealPort(qreal, qreal, qreal)));
    connect(this, SIGNAL(portChanged()), mainView, SLOT(rePort()));
    connect(mainView, SIGNAL(portChanged(qreal, qreal)),
            miniView, SLOT(drawPort(qreal, qreal)));
}

RSTViewer::~RSTViewer()
{
    delete mainView;
    delete miniView;
}

void RSTViewer::paint()
{
    QGraphicsScene *oldMainScene = mainView->scene();
    QGraphicsScene *oldMiniScene = miniView->scene();
    QGraphicsScene *mainScene = new QGraphicsScene();
    QGraphicsScene *miniScene = new QGraphicsScene();

    //qDebug("%d", rst_->v_op.size());
    //qDebug("start paint");
    paintBackground(mainScene, miniScene);
    if (rst_->isSolved())
        paintSegments(mainScene, miniScene);
    paintOriginalPoints(mainScene, miniScene);

    mainView->setScene(mainScene);
    miniView->setScene(miniScene);

    //qDebug("main scene size : %lf %lf", miniView->sceneRect().width(), miniView->sceneRect().height());
    //double sc = (double) miniView->getSceneSize() / std::max(mainScene->width(), mainScene->height());
    //miniView->resetTransform();
    //miniView->scale(sc, sc);
    //qDebug("mini scene size : %lf %lf", miniView->sceneRect().width(), miniView->sceneRect().height());
    //qDebug("will center %lf %lf", miniView->getSceneSize() / 2.0, miniView->getSceneSize() / 2.0);
    //qDebug("mini scene lefttop: %lf %lf", miniView->sceneRect().x(), miniView->sceneRect().y());

    miniView->centerOn(miniView->sceneRect().center());
    if (rst_->isNew())
    {
        resetPort();
        rst_->setNew(0);
    }
    else
        setRealPort(fx_, fy_, sc_);

    if (oldMainScene)
        delete oldMainScene;
    if (oldMiniScene)
        delete oldMiniScene;
}

inline void RSTViewer::paintOriginalPoints(QGraphicsScene *mainScene, QGraphicsScene *miniScene)
{
    QPen pen(bronze_);
    pen.setWidth(loopWidth_);
    QBrush brush(black_);

    for (int i = 0; i < rst_->v_op.size(); i++)
    {
        Point2D p = rst_->v_op[i];
        qreal x = p.x - pointRadius_, y = p.y - pointRadius_, d = 2 * pointRadius_;
        mainScene->addEllipse(x, y, d, d, pen, brush);

        d *= realToMini(x, y, mainScene->sceneRect());
        miniScene->addEllipse(x, y, d, d, pen, brush);
    }
}

inline void RSTViewer::paintSegments(QGraphicsScene *mainScene, QGraphicsScene *miniScene)
{
    QPen seg_pen(darkBronze_);
    seg_pen.setWidth(lineWidth_);

    for (int i = 0; i < rst_->v_seg.size(); i++)
    {
        Segment2D sg = rst_->v_seg[i];
        qreal x1 = sg.u.x, y1 = sg.u.y, x2 = sg.v.x, y2 = sg.v.y;
        mainScene->addLine(x1, y1, x2, y2, seg_pen);
        realToMini(x1, y1, mainScene->sceneRect());
        realToMini(x2, y2, mainScene->sceneRect());
        miniScene->addLine(x1, y1, x2, y2, seg_pen);
    }
}

inline void RSTViewer::paintBackground(QGraphicsScene *mainScene, QGraphicsScene *miniScene)
{
    QPen pen(edge_());
    pen.setWidth(edgeWidth_);
    QBrush brush(bkg_);

    qreal minx, miny, maxx, maxy, mino, maxo;
    minx = miny = 2000000000;
    maxx = maxy = -2000000000;
    for (int i = 0; i < rst_->v_op.size(); i++)
    {
        Point2D p = rst_->v_op[i];
        if (p.x > maxx) maxx = p.x;
        if (p.x < minx) minx = p.x;
        if (p.y > maxy) maxy = p.y;
        if (p.y < miny) miny = p.y;
    }

    QRectF bkgr;
    if (!rst_->v_op.size()) // Empty
    {
        minx = miny = 0;
        maxx = maxy = emptyBoardSize_;
        bkgr.setRect(0, 0, emptyBoardSize_, emptyBoardSize_);
    }
    else
    {
        mino = std::min(minx, miny) - boardMargin_;
        maxo = std::max(maxx, maxy) + boardMargin_;
        bkgr.setRect(mino, mino, maxo - mino, maxo - mino);
        if (maxo - mino < limitSize_)
        {
            bkgr.setRect((mino + maxo - limitSize_) / 2, (mino + maxo - limitSize_) / 2,
                         limitSize_, limitSize_);
        }
    }

    QGraphicsRectItem* bkgi = mainScene->addRect(bkgr, pen, brush);
    mainView->setBkgItem(&(*bkgi));

    mainView->setBkgRect(bkgr);
    //qDebug("set main bkg %lf %lf %lf %lf", bkgr.x(), bkgr.y(), bkgr.width(), bkgr.height());
    setBkgRect(bkgr);

    realToMini(bkgr, mainView->bkgRect());
    //qDebug("set mini bkg %lf %lf %lf %lf", bkgr.x(), bkgr.y(), bkgr.width(), bkgr.height());
    miniView->setBkg(bkgr);
    miniScene->addRect(bkgr, pen, brush);
}

inline QColor RSTViewer::edge_()
{
    return bkg_.darker(edgeDarkFactor_);
}

QColor RSTViewer::viewRect()
{
    if (bkg_.lightness() < 64)
        return QColor(255, 255, 255);
    else
        return QColor(0, 0, 0);
}

double RSTViewer::realToMini(qreal &x, qreal &y, QRectF mainSize)
{
    qreal x0, y0, w0, h0;
    mainSize.getRect(&x0, &y0, &w0, &h0);
    double scale = (double) miniView->getSceneSize() / std::max(w0, h0);

    x = (x - x0) * scale;
    y = (y - y0) * scale;
    return scale;
}

double RSTViewer::miniToReal(qreal &x, qreal &y, QRectF mainSize)
{
    qreal x0, y0, w0, h0;
    mainSize.getRect(&x0, &y0, &w0, &h0);
    double scale = std::max(w0, h0) / (double) miniView->getSceneSize();

    x = x * scale + x0;
    y = y * scale + y0;
    return scale;
}

double RSTViewer::realToMini(QRectF &target, QRectF mainSize)
{
    qreal x0, y0, w0, h0;
    mainSize.getRect(&x0, &y0, &w0, &h0);
    double scale = (double) miniView->getSceneSize() / std::max(w0, h0);

    target.setRect((target.x() - x0) * scale, (target.y() - y0) * scale,
                   target.width() * scale, target.height() * scale);
    return scale;
}

double RSTViewer::miniToReal(QRectF &target, QRectF mainSize)
{
    qreal x0, y0, w0, h0;
    mainSize.getRect(&x0, &y0, &w0, &h0);
    double scale = std::max(w0, h0) / (double) miniView->getSceneSize();

    target.setRect(target.x() * scale + x0, target.y() * scale + y0,
                   target.width() * scale, target.height() * scale);
    return scale;
}

void RSTViewer::setRealPort(qreal fx, qreal fy, qreal sc = 0)
{
    //if (fx == fx_ && fy_ == fy && sc_ == sc)
        //return;
    if (sc > 0) sc_ = sc;
    fx_ = fx, fy_ = fy;
    emit portChanged();
}

void RSTViewer::resetPort()
{
    QPointF cen = bkgRect_.center();
    setRealPort(cen.x(), cen.y(), 1);
}

QRectF RSTViewer::bkgRect()
{
    return bkgRect_;
}

void RSTViewer::setBkgRect(QRectF r)
{
    bkgRect_ = r;
}

void RSTViewer::setBkgClr(QColor clr)
{
    bkg_ = clr;
}

void RSTViewer::printToJpeg(const QString *fileName)
{
    //QImage img(mainView->sceneRect().width(), mainView->sceneRect().height(), QImage::Format_ARGB32);

    QRectF src = mainView->scene()->sceneRect();
    QRectF tar = mainView->scene()->sceneRect();
    tar.moveTo(0, 0);
    QImage img(src.width(), src.height(), QImage::Format_ARGB32);
    img.fill(Qt::white);
    QPainter painter(&img);

    //qDebug("%s", fileName->toStdString().c_str());
    mainView->scene()->render(&painter, tar, src.toRect());
    bool flag = img.save(fileName->toStdString().c_str());
    //qDebug("%d", flag);
}

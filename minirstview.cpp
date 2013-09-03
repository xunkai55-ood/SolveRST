#include "minirstview.h"
#include "rstviewer.h"

#include <QMouseEvent>
#include <QGraphicsRectItem>

MiniRSTView::MiniRSTView(RSTViewer *fa, QWidget *parent) :
    QGraphicsView(parent),
    viewerSize_(210),
    sceneSize_(200),
    portItem_(0)
{
    father_ = fa;

    setMinimumSize(viewerSize_, viewerSize_);
    setMaximumSize(viewerSize_, viewerSize_);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

int MiniRSTView::getSceneSize()
{
    return sceneSize_;
}

void MiniRSTView::drawPort(qreal w, qreal h)
{
    //QPen pen(father_->viewRect());
    //QPen pen(QColor(0, 0, 0));
    //pen.setWidth(1);
    //QBrush brush(Qt::NoBrush);
    QPen pen(Qt::NoPen);
    QBrush brush(father_->viewRect(), Qt::Dense5Pattern);

    QRectF target(father_->fx_ - w / 2.0, father_->fy_ - h / 2.0, w, h);
    father_->realToMini(target, father_->mainView->bkgRect());
    currentPort_ = target;

    if (target.x() < 0)
        target.setX(0);
    if (target.y() < 0)
        target.setY(0);
    if (target.width() + target.x() > sceneSize_)
        target.setWidth(sceneSize_ - target.x());
    if (target.height() + target.y() > sceneSize_)
        target.setHeight(sceneSize_ - target.y());

    if (portItem_ && portItem_->scene() == scene())
    {
        scene()->removeItem(portItem_);
        delete portItem_;
    }
    QGraphicsRectItem *t = scene()->addRect(target, pen, brush);
    portItem_ = &(*t);
    assert(t == portItem_);
    centerOn(currentBkg_.center());
    //qDebug("mini Center : %lf %lf", currentBkg_.center().x(), currentBkg_.center().y());
}

void MiniRSTView::setBkg(QRectF r)
{
    currentBkg_ = r;
}

QRectF MiniRSTView::getBkg()
{
    return currentBkg_;
}

void MiniRSTView::mouseMoveEvent(QMouseEvent *event)
{
    //qDebug("move %lf %lf, can %d", event->localPos().x(), event->localPos().y(), canMove_);
    if (!canMove_) return;
    trySetPort((event->localPos() - startMovePos_) + oldCenter_);
}

void MiniRSTView::mouseReleaseEvent(QMouseEvent *event)
{
    if (!canMove_) return;
    trySetPort((event->localPos() - startMovePos_) + oldCenter_);
    canMove_ = 0;
}

void MiniRSTView::mousePressEvent(QMouseEvent *event)
{
    //qDebug("press %lf %lf", event->localPos().x(), event->localPos().y());
    if (event->button() != Qt::LeftButton) return;
    if (!currentPort_.contains(event->localPos())) return;
    startMovePos_ = event->localPos();
    oldCenter_ = currentPort_.center();
    canMove_ = 1;
}

int MiniRSTView::trySetPort(QPointF p)
{
    //qDebug("try %lf %lf", p.x(), p.y());
    QRectF nextPort = currentPort_;
    nextPort.moveCenter(p);

    //qDebug("current port %lf %lf %lf %lf", currentPort_.x(), currentPort_.y(),
    //       currentPort_.width(), currentPort_.height());
    //qDebug("next port %lf %lf %lf %lf", nextPort.x(), nextPort.y(), nextPort.width(), nextPort.height());
    //qDebug("cbkg %lf %lf %lf %lf", currentBkg_.x(), currentBkg_.y(), currentBkg_.width(), currentBkg_.height());
    if (currentBkg_.contains(nextPort.center()))
    {
        currentPort_ = nextPort;
        father_->miniToReal(nextPort, father_->mainView->bkgRect());
        emit pickPort(nextPort.center().x(), nextPort.center().y(), 0);
        return 1;
    }
    else
        return 0;
}

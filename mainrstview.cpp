#include "mainrstview.h"
#include "rstviewer.h"

#include <QMouseEvent>
#include <QWheelEvent>
#include <QEvent>
#include <QGraphicsItem>

MainRSTView::MainRSTView(RSTViewer *fa, QWidget *parent) :
    QGraphicsView(parent),
    wheelFactor_(0.001)
{
    father_ = fa;
}

void MainRSTView::setPort(qreal fx, qreal fy, qreal sc)
{
    resetTransform();
    centerOn(fx, fy);
    scale(sc, sc);
}

QRectF MainRSTView::bkgRect()
{
    return currentMainSize_;
}

void MainRSTView::setBkgRect(QRectF r)
{
    currentMainSize_ = r;
}

QGraphicsItem* MainRSTView::getBkgItem()
{
    return bkgItem_;
}

void MainRSTView::setBkgItem(QGraphicsItem *i)
{
    bkgItem_ = i;
}

void MainRSTView::rePort()
{
    resetTransform();
    centerOn(father_->fx_, father_->fy_);
    scale(father_->sc_, father_->sc_);

    emit portChanged(width() / father_->sc_, height() / father_->sc_);
}

QGraphicsItem* MainRSTView::clickOnPoint(QPointF p)
{
    QPointF realPos = mapToScene(p.toPoint());
    QGraphicsItem *it;
    if ((it = itemAt(p.toPoint())) == bkgItem_)
        return 0;
    QRectF bd = it->sceneBoundingRect();
    double e = bd.width() / bd.height();
    if (std::abs(e - 1) > 0.1)
        return 0;
    return it;
}

void MainRSTView::mouseMoveEvent(QMouseEvent *event)
{
    if (isLeft_ == 1)
    {
        //qDebug("move %lf %lf, can %d", event->localPos().x(), event->localPos().y(), canMove_);
        if (!canMove_) return;
        trySetPort(-(event->localPos() - startMovePos_) + oldCenter_);
    }
    else if (isLeft_ == -1)
    {
        if (!currentMainSize_.contains(mapToScene(event->localPos().toPoint()))) return;
        QPointF newP = mapToScene(event->localPos().toPoint());
        father_->rst_->deleteAndAdd(targetPoint_.x(), targetPoint_.y(), newP.x(), newP.y());
        targetPoint_ = newP;
    }
}

void MainRSTView::mouseReleaseEvent(QMouseEvent *event)
{
    isLeft_ = 0;
    if (event->button() == Qt::LeftButton)
    {
        if (!canMove_) return;
        trySetPort(-(event->localPos() - startMovePos_) + oldCenter_);
        canMove_ = 0;
    }
    else if (event->button() == Qt::RightButton)
    {
        if (!currentMainSize_.contains(mapToScene(event->localPos().toPoint()))) return;
        canDrag_ = 0;
        if (event->localPos() == rightClickPos_) // single click event
        {
            QGraphicsItem *it = clickOnPoint(event->localPos());
            if (it)
            {
                QRectF bd = it->sceneBoundingRect();
                father_->rst_->deletePoint(bd.center().x(), bd.center().y());
            }
            else
            {
                QPointF realPos = mapToScene(rightClickPos_.toPoint());
                father_->rst_->addPoint(realPos.x(), realPos.y());
            }

        }
    }
}

void MainRSTView::mousePressEvent(QMouseEvent *event)
{
    //qDebug("press %lf %lf", event->localPos().x(), event->localPos().y());
    if (event->button() == Qt::LeftButton)
    {
        startMovePos_ = event->localPos();
        oldCenter_ = QPointF(father_->fx_, father_->fy_);
        canMove_ = 1;
        isLeft_ = 1;
    }
    else if (event->button() == Qt::RightButton)
    {
        if (!currentMainSize_.contains(mapToScene(event->localPos().toPoint()))) return;
        isLeft_ = -1;
        rightClickPos_ = event->localPos();
        QGraphicsItem *it = clickOnPoint(rightClickPos_);
        if (it)
        {
            canDrag_ = 1;
            QRectF bd = it->sceneBoundingRect();
            targetPoint_ = bd.center();
        }
    }
}

void MainRSTView::wheelEvent(QWheelEvent *event)
{
    int dDeg = event->delta();
    if (father_->sc_ + dDeg * wheelFactor_ <= 0) return;
    father_->sc_ += dDeg * wheelFactor_;

    //qDebug("%d %lf", dDeg, father_->sc_);
    emit pickPort(father_->fx_, father_->fy_, father_->sc_);
}

int MainRSTView::trySetPort(QPointF p)
{
    if (!currentMainSize_.contains(p))
        return 0;
    emit pickPort(p.x(), p.y(), 0);
    return 1;
}

bool MainRSTView::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::Resize)
    {
        emit pickPort(father_->fx_, father_->fy_, father_->sc_);
    }
    return QObject::eventFilter(obj, event);
}

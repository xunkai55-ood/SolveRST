#ifndef MAINRSTVIEW_H
#define MAINRSTVIEW_H

#include <QGraphicsView>

class RSTViewer;

class MainRSTView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MainRSTView(RSTViewer *fa, QWidget *parent = 0);
    void setPort(qreal fx, qreal fy, qreal sc);

    QRectF bkgRect();
    void setBkgRect(QRectF r);

    void setBkgItem(QGraphicsItem *i);
    QGraphicsItem *getBkgItem();
    
signals:
    void portChanged(qreal w, qreal h);
    void pickPort(qreal nx, qreal ny, qreal nsc);

public slots:
    void rePort();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    bool eventFilter(QObject *obj, QEvent *event);

private:
    QRectF currentMainSize_;
    qreal fx_, fy_, sc_;
    RSTViewer *father_;
    int trySetPort(QPointF p);

    QGraphicsItem *bkgItem_;
    QPointF startMovePos_;
    QPointF oldCenter_;
    int canMove_, canDrag_;
    int isLeft_;

    QPointF rightClickPos_;
    QPointF targetPoint_;

    double wheelFactor_;

    QGraphicsItem *clickOnPoint(QPointF p);
};

#endif // MAINRSTVIEW_H

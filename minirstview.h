#ifndef MINIRSTVIEW_H
#define MINIRSTVIEW_H

#include <QGraphicsView>

class RSTViewer;

class MiniRSTView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MiniRSTView(RSTViewer *fa, QWidget *parent = 0);
    int getSceneSize();

    QRectF getBkg();
    void setBkg(QRectF r);

signals:
    void pickPort(qreal nx, qreal ny, qreal sc0);
    
public slots:
    void drawPort(qreal w, qreal h);

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    int viewerSize_, sceneSize_;
    RSTViewer *father_;
    QRectF currentPort_, currentBkg_;
    QGraphicsItem *portItem_;

    int trySetPort(QPointF p);

    QPointF startMovePos_;
    QPointF oldCenter_;
    int canMove_;
};

#endif // MINIRSTVIEW_H

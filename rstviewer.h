#ifndef RSTVIEWER_H
#define RSTVIEWER_H

#include <QGraphicsView>
#include <QObject>
#include <QGraphicsScene>

#include "rst.h"
#include "mainrstview.h"
#include "minirstview.h"

#include <QPen>
#include <QBrush>
#include <QColor>

class RSTViewer : public QObject
{
    Q_OBJECT
public:
    explicit RSTViewer(RST *rst, QObject *parent = 0);
    ~RSTViewer();

    friend class MainRSTView;
    friend class MiniRSTView;

    MainRSTView *mainView;
    MiniRSTView *miniView;

    int useInstantSolve();
    QColor viewRect();

    const QColor BKG;
    void setBkgClr(QColor clr);

    QRectF bkgRect();
    void setBkgRect(QRectF r);

    double realToMini(qreal &x, qreal &y, QRectF mainSize);
    double miniToReal(qreal &x, qreal &y, QRectF mainSize);
    double realToMini(QRectF &target, QRectF mainSize);
    double miniToReal(QRectF &target, QRectF mainSize);

    void resetPort();

    void printToJpeg(const QString *fileName);
    
signals:
    void portChanged();
    
public slots:
    void paint();
    void setRealPort(qreal fx, qreal fy, qreal sc);

private:
    RST *rst_;
    QColor bronze_, black_, darkBronze_, bkg_;
    int edgeDarkFactor_;
    int loopWidth_, pointRadius_, lineWidth_, edgeWidth_, limitSize_;
    int emptyBoardSize_, boardMargin_;
    QColor edge_();

    int instantSolve_;

    inline void paintOriginalPoints(QGraphicsScene *mainScene, QGraphicsScene *miniScene);
    inline void paintSegments(QGraphicsScene *mainScene, QGraphicsScene *miniScene);
    inline void paintBackground(QGraphicsScene *mainScene, QGraphicsScene *miniScene);

    qreal fx_, fy_, sc_;
    QRectF bkgRect_;
};

#endif // RSTVIEWER_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QIcon>

#include "rst.h"
#include "rstviewer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int useInstantSolve();

public slots:
    void load();
    void solve();
    void instantSolve();
    void generate();
    void generate_Save();
    void save_Data();
    void chooseAlgo(int s_idx);
    void chooseColor();
    void save_Jpeg();
    void setInstantSolve(int isInstant);
    void addAPoint();
    void help();
    void resetViewport();

private:
    Ui::MainWindow *ui;
    RST* rst_;
    RSTViewer* rstViewer_;
    QButtonGroup* algos_;
    QIcon icon_;

    int instantSolve_;
};

#endif // MAINWINDOW_H

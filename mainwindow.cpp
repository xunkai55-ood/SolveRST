#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gendialog.h"
#include "apdialog.h"

#include <QDebug>
#include <QFileDialog>
#include <QColorDialog>
#include <QMessageBox>
#include <strstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    instantSolve_(1),
    icon_("://resources/ico.png")
{
    //setWindowIcon(icon_);

    //qDebug("hello");
    ui->setupUi(this);
    rst_ = new RST;
    rstViewer_ = new RSTViewer(rst_);
    rstViewer_->paint();

    setCentralWidget(rstViewer_->mainView);
    ui->formLayout_3->insertRow(0, rstViewer_->miniView);

    /* menu */
    connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT(load()));
    connect(ui->actionSolve, SIGNAL(triggered()), this, SLOT(solve()));
    connect(ui->actionGenerate, SIGNAL(triggered()), this, SLOT(generate()));
    connect(ui->actionGenerate_Save, SIGNAL(triggered()), this, SLOT(generate_Save()));
    connect(ui->actionSave_Current_Data, SIGNAL(triggered()), this, SLOT(save_Data()));
    connect(ui->actionColor, SIGNAL(triggered()), this, SLOT(chooseColor()));
    connect(ui->actionSave_a_jpeg, SIGNAL(triggered()), this, SLOT(save_Jpeg()));
    connect(ui->actionAdd_a_point, SIGNAL(triggered()), this, SLOT(addAPoint()));
    connect(ui->actionHelp, SIGNAL(triggered()), this, SLOT(help()));

    /* toolbar */
    connect(ui->actionLoadTool, SIGNAL(triggered()), this, SLOT(load()));
    ui->actionLoadTool->setIcon(QIcon("://resources/load.png"));
    connect(ui->actionGenerateTool, SIGNAL(triggered()), this, SLOT(generate()));
    ui->actionGenerateTool->setIcon(QIcon("://resources/gen.png"));
    connect(ui->actionSolveTool, SIGNAL(triggered()), this, SLOT(solve()));
    ui->actionSolveTool->setIcon(QIcon("://resources/exec.png"));
    connect(ui->pushButton, SIGNAL(released()), this, SLOT(resetViewport()));

    /* algorithm box */
    algos_ = new QButtonGroup(this);
    algos_->addButton(ui->algoRadio1, 1);
    algos_->addButton(ui->algoRadio2, 2);
    algos_->setExclusive(true);
    connect(algos_, SIGNAL(buttonClicked(int)), this, SLOT(chooseAlgo(int)));
    connect(ui->instantSolveBox, SIGNAL(stateChanged(int)), this, SLOT(setInstantSolve(int)));

    /* logic */
    connect(rst_, SIGNAL(pointsChanged(int)), this, SLOT(instantSolve()));
    connect(rst_, SIGNAL(strategyChanged(int)), this, SLOT(instantSolve()));

    connect(rst_, SIGNAL(solveFinished()), rstViewer_, SLOT(paint()));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete rst_;
    delete rstViewer_;
}

void MainWindow::load()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        "Open Points Data", "./", "Points Data (*)");
    if (fileName.isEmpty()) return;
    rst_->loadPoints(fileName.toStdString().c_str());
}

void MainWindow::solve()
{
    if (!rst_->getStrategy())
    {
        QMessageBox msgBox;
        msgBox.setText("Error: No Algorithm Selected. ");
        msgBox.exec();
        return;
    }
    if (!rst_->hasData())
    {
        QMessageBox msgBox;
        msgBox.setText("Error: No Input Data. ");
        msgBox.exec();
        return;
    }
    rst_->toSolveRST();
}

void MainWindow::instantSolve()
{
    if (useInstantSolve())
    {
        if (!rst_->getStrategy() || !rst_->hasData())
        {
            rstViewer_->paint();
            return;
        }
        else if (rst_->getStrategy() == 2 && rst_->hasData() > 200)
        {
            QMessageBox msgBox;
            msgBox.setText("Warning: Algorithm \"ZMST\" will run extremely slow with such big input and may lead to a crash. Simultaneous solving will not work.");
            msgBox.exec();
            rstViewer_->paint();
            return;
        }
        else
            rst_->toSolveRST();
    }
    else
        rstViewer_->paint();
    //qDebug("Instant Solved");
}

void MainWindow::generate()
{
    GenDialog genDialog(this);
    int ans = genDialog.exec();

    if (ans)
    {
        rst_->loadPoints(genDialog.gen_p);
    }
    //qDebug("Generated");
}

void MainWindow::generate_Save()
{
    generate();
    save_Data();
}

void MainWindow::save_Data()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        "Save Points Data", "./", "Points Data (*)");
    rst_->savePoints(fileName.toStdString().c_str());

}

void MainWindow::setInstantSolve(int isInstant)
{
    instantSolve_ = isInstant;
}

int MainWindow::useInstantSolve()
{
    return instantSolve_;
}

void MainWindow::chooseAlgo(int s_idx)
{
    rst_->changeStrategy(s_idx);
    if (useInstantSolve())
        solve();
}

void MainWindow::chooseColor()
{
    QColorDialog dlg(rstViewer_->BKG, this);
    dlg.exec();
    rstViewer_->setBkgClr(dlg.selectedColor());
    rstViewer_->paint();
}

void MainWindow::save_Jpeg()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        "Save an image", "./", "Image files (*.jpg *.jpeg *.bmp *.png)");
    rstViewer_->printToJpeg(&fileName);
}

void MainWindow::addAPoint()
{
    APDialog dlg(this);
    int ans = dlg.exec();

    if (ans)
    {
        rst_->addPoint(dlg.myX, dlg.myY);
    }

}

void MainWindow::help()
{
    QMessageBox msg;
    std::strstream s;
    s << " ============= help =============== " << "\n";
    s << " @ Use left mouse button to locate your view port" << "\n";
    s << " @ Use right mouse button to move, drag or delete a point" << "\n";
    s << " ================================== " << "\n";
    s << "\n";
    s << " ============ my info ============= " << "\n";
    s << " # By Zhang Xunkai (ID:badpoet)" << "\n";
    s << " # contact me at : badpoet55@gmail.com" << "\n";
    s << " ================================== ";
    QString txt(s.str());
    msg.setText(txt);
    msg.exec();
}

void MainWindow::resetViewport()
{
    rstViewer_->resetPort();
}

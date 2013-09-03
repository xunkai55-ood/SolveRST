#include "apdialog.h"
#include "ui_apdialog.h"

APDialog::APDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::APDialog)
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(addPoint()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(cancel()));
}

APDialog::~APDialog()
{
    delete ui;
}

void APDialog::addPoint()
{
    myX = ui->doubleSpinBoxx->value();
    myY = ui->doubleSpinBoxy->value();
    done(1);
}

void APDialog::cancel()
{
    done(0);
}

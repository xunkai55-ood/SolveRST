#include "gendialog.h"
#include "ui_gendialog.h"

#include <set>
#include <cstdlib>
#include <QDebug>

GenDialog::GenDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GenDialog)
{
    ui->setupUi(this);
    gen_p.clear();

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(calc()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(cancel()));
}

GenDialog::~GenDialog()
{
    delete ui;
}

void GenDialog::cancel()
{
    done(0);
}

void GenDialog::calc()
{
    gen_p.clear();
    int num = ui->numBox->value();
    double radius = ui->rangeBox->value();

    int demi = 1000, r1, r2;
    std::set< Point2D > points;

    srand(time(0));
    while (num)
    {
        r1 = rand(), r2 = rand();
        DTYPE x = r1 * r2 % ((int) radius * demi) / demi;
        r1 = rand(), r2 = rand();
        DTYPE y = r1 * r2 % ((int) radius * demi) / demi;
        Point2D p = mkPoint(x, y);

        if (points.count(p)) continue;
        points.insert(p);
        gen_p.push_back(p);
        //qDebug("%d %d", p.x, p.y);
        num--;
    }
    //qDebug("%d", gen_p.size());
    done(1);
}

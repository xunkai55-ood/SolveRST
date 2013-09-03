#ifndef GENDIALOG_H
#define GENDIALOG_H

#include <QDialog>
#include "rst.h"

namespace Ui {
class GenDialog;
}

class GenDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit GenDialog(QWidget *parent = 0);
    ~GenDialog();

    std::vector< Point2D > gen_p;

public slots:
    void calc();
    void cancel();
    
private:
    Ui::GenDialog *ui;
};

#endif // GENDIALOG_H

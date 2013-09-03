#ifndef APDIALOG_H
#define APDIALOG_H

#include <QDialog>

namespace Ui {
class APDialog;
}

class APDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit APDialog(QWidget *parent = 0);
    ~APDialog();
    double myX, myY;

public slots:
    void addPoint();
    void cancel();
    
private:
    Ui::APDialog *ui;
};

#endif // APDIALOG_H

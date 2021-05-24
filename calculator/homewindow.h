#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QDialog>
#include <mainwindow.h>

namespace Ui {
class homewindow;
}

class homewindow : public QDialog
{
    Q_OBJECT

public:
    explicit homewindow(QWidget *parent = nullptr);
    ~homewindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::homewindow *ui;
    MainWindow *calculatorWindow;
};

#endif // HOMEWINDOW_H

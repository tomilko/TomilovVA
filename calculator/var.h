#ifndef VAR_H
#define VAR_H

#include <QDialog>

namespace Ui {
class var;
}

class var : public QDialog
{
    Q_OBJECT

public:
    explicit var(QWidget *parent = nullptr);
    ~var();
signals:
    void firstWindow();
private slots:
    void on_pushButton_clicked();
private:
    Ui::var *ui;
};

#endif // VAR_H

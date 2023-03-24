#ifndef ENTEROWES_H
#define ENTEROWES_H

#include <QWidget>
#include "splitwise.h"
#include "outputscreen.h"
namespace Ui {
class enterOwes;
}

class enterOwes : public QWidget
{
    Q_OBJECT

public:
    explicit enterOwes(QWidget *parent = nullptr);
    void setProgram(Splitwise x)
    {
        myProgram = x;
    }
    void setList(QStringList l)
    {
        list_items = l;
    }
    QStringList list_items;
    ~enterOwes();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::enterOwes *ui;
    Splitwise myProgram;
    OutputScreen outputScreen;
};

#endif // ENTEROWES_H

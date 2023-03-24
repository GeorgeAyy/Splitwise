#ifndef ENTERNAME_H
#define ENTERNAME_H

#include <QWidget>
#include "splitwise.h"
#include "enterowes.h"
namespace Ui {
class enterName;
}

class enterName : public QWidget
{
    Q_OBJECT

public:
    explicit enterName(QWidget *parent = nullptr);
    ~enterName();
    void setProgram(Splitwise x)
    {
        myProgram = x;
    }
    int counter = 0;
private slots:
    void on_pushButton_clicked();

private:
    Ui::enterName *ui;
    enterOwes owesScreen;
    Splitwise myProgram;
    QStringList list;
};

#endif // ENTERNAME_H

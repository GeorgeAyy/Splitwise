#ifndef OUTPUTSCREEN_H
#define OUTPUTSCREEN_H

#include <QWidget>
#include "splitwise.h"
namespace Ui {
class OutputScreen;
}

class OutputScreen : public QWidget
{
    Q_OBJECT

public:
    explicit OutputScreen(QWidget *parent = nullptr);
    ~OutputScreen();
    void setProgram(Splitwise x)
    {
        myProgram = x;
    }

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::OutputScreen *ui;
    Splitwise myProgram;
};

#endif // OUTPUTSCREEN_H

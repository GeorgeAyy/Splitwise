#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsOpacityEffect>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->centralWidget()->setStyleSheet(
             "background-image:url(C:/Users/georg/Downloads/finaaal (1).jpg); background-position: center;" );
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
    effect->setOpacity(0);
    ui->pushButton->setGraphicsEffect(effect);
    this->setFixedSize(this->width(),this->height());
    this->setWindowTitle("Splitwise");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->comboBox->currentText()!="")
    {
        QString value = ui->comboBox->currentText();
        int x = value.toInt();
        myProgram.setNum(x);
        this->hide();
        enterScreen.setProgram(myProgram);
        enterScreen.show();
    }
}


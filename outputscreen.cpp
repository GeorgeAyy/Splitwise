#include "outputscreen.h"
#include "ui_outputscreen.h"
OutputScreen::OutputScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OutputScreen)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/georg/Downloads/Dscreen.jpg");
    ui->label->setPixmap(pix);
    this->setFixedSize(580,580);
    ui->pushButton_2->setVisible(false);
    ui->label_2->setVisible(false);
    this->setWindowTitle("Splitwise");
}

OutputScreen::~OutputScreen()
{
    delete ui;
}

void OutputScreen::on_pushButton_clicked()
{
    QStringList myList = myProgram.getText();
    ui->textBrowser->setPlainText(myList.join('\n'));
    ui->pushButton_2->setVisible(true);
    ui->pushButton->setVisible(false);
    ui->label_2->setVisible(true);
}


void OutputScreen::on_pushButton_2_clicked()
{
    this->close();
}


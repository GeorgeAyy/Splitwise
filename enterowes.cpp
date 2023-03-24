#include "enterowes.h"
#include "ui_enterowes.h"

enterOwes::enterOwes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::enterOwes)
{

    ui->setupUi(this);
    ui->pushButton->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->lineEdit->setValidator( new QDoubleValidator(0.00,10000.00,2,this) );
    ui->label_4->setStyleSheet("color : green;");
    QPixmap pix("C:/Users/georg/Downloads/Dscreen.jpg");
    ui->label_5->setPixmap(pix);
    this->setFixedSize(580,580);
    ui->label_6->setVisible(false);
    this->setWindowTitle("Splitwise");
}
enterOwes::~enterOwes()
{
    delete ui;
}
void enterOwes::on_pushButton_2_clicked()
{
    ui->comboBox->addItems(list_items);
    ui->comboBox_2->addItems(list_items);
    ui->pushButton->setVisible(true);
    ui->pushButton_2->setVisible(false);
    ui->label_6->setVisible(true);
}
void enterOwes::on_pushButton_clicked()
{
    if(ui->comboBox->currentText()!= ui->comboBox_2->currentText() && ui->lineEdit->text()!="")
    {
        ui->pushButton_3->setVisible(true);
        int index1 = ui->comboBox->currentIndex();
        int index2 = ui->comboBox_2->currentIndex();
        double amount = (ui->lineEdit->text()).toDouble();
        myProgram.enterAmount(index1,index2,amount);
        QString name1=ui->comboBox->currentText();
        QString name2=ui->comboBox_2->currentText();
        ui->label_4->setStyleSheet("color : green;");
        ui->label_4->setText(name1 + " owes " + name2 + " " + QString::number(amount));
        ui->lineEdit->setText("");
    }
    else
    {
        if(ui->comboBox->currentText()== ui->comboBox_2->currentText() && ui->lineEdit->text()=="")
        {

            ui->label_4->setStyleSheet("color : red;");
            ui->label_4->setText("Same name chosen and Amount is empty");
        }
        else if(ui->comboBox->currentText()!= ui->comboBox_2->currentText() && ui->lineEdit->text()=="")
        {
            ui->label_4->setStyleSheet("color : red;");
            ui->label_4->setText("Amount is empty");
        }
        else if(ui->comboBox->currentText()== ui->comboBox_2->currentText() && ui->lineEdit->text()!="")
        {
            ui->label_4->setStyleSheet("color : red;");
            ui->label_4->setText("Same name chosen");
        }
    }
}
void enterOwes::on_pushButton_3_clicked()
{
    myProgram.minCashFlow();
    outputScreen.setProgram(myProgram);
    this->hide();
    outputScreen.show();
}


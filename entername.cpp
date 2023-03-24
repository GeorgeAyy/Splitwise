#include "entername.h"
#include "ui_entername.h"

#include <qgraphicseffect.h>
enterName::enterName(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::enterName)
{
    ui->setupUi(this);
    ui->label_2->setStyleSheet("color : red;");
    ui->label_3->setStyleSheet("color: green;");
    QPixmap pix("C:/Users/georg/Downloads/finalll.jpg");
    ui->label_4->setPixmap(pix);
    this->setFixedSize(580,580);
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
    effect->setOpacity(0);
    ui->pushButton->setGraphicsEffect(effect);
    this->setWindowTitle("Splitwise");
}

enterName::~enterName()
{
    delete ui;
}

void enterName::on_pushButton_clicked()
{
    if(counter<myProgram.getNum())
    {
        if(ui->lineEdit->text()!="")
        {
            QString name = ui->lineEdit->text();
            list << name;
            myProgram.setName(name,counter); //myProgram is an instance of splitwise
            ui->label_2->setStyleSheet("color : red;");
            ui->label_2->setText(QString::number(myProgram.getNum()-counter-1) + " remaining");
            counter++;
            ui->lineEdit->setText("");
            ui->label_3->setStyleSheet("color:green");
            ui->label_3->setText(name + " was added.");
        }
        else
        {
            ui->label_3->setStyleSheet("color:red");
            ui->label_3->setText("Please enter a name.");
        }
    }
    if(counter==myProgram.getNum())
    {
        this->hide();
        owesScreen.setList(list);
        owesScreen.setProgram(myProgram);
        owesScreen.show();
    }

}




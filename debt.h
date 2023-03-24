#ifndef DEBT_H
#define DEBT_H
#pragma once
#include <QtCore/QString>
#include <iostream>
using namespace std;
class Debt
{
private:
    double AmountOwed = 0;
    QString name ="";
    QString owedTo="";
public:
    Debt();

    double getAmount();

    QString getOwesName();

    QString getOwedToName();

    void setOwesName(QString name);

    void setOwedName(QString name);

    void setAmountOwed(double amount);
};



#endif // DEBT_H

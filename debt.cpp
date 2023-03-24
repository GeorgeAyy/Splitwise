#include "debt.h"

#include <QtCore/QString>

Debt::Debt()
{
}

double Debt::getAmount()
{
    return AmountOwed;
}

//double Debt::getNetAmount()
//{
//	return netDebtAmount;
//}

QString Debt::getOwesName()
{
    return name;
}

QString Debt::getOwedToName()
{
    return owedTo;
}

void Debt::setOwesName(QString name)
{
    this->name = name;
}

void Debt::setOwedName(QString name)
{
    this->owedTo = name;
}

void Debt::setAmountOwed(double amount)
{
    this->AmountOwed += amount;
}


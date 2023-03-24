#ifndef SPLITWISE_H
#define SPLITWISE_H
#pragma once
#include <QList>
#include <QStringList>
#include <QString>
#include <iostream>
#include "Debt.h"
using namespace std;

class Splitwise
{
private:
    Debt** graph;
    int numOfUsers;
    QString* myNames;
    QString output;
    QStringList myList;
public:
    Splitwise();
    void setNum(int num);
    int getNum();
    void minCashFlow();
    // Given a set of persons as graph[] where graph[i][j] indicates
    // the amount that person i needs to pay person j, this function
    // finds and prints the minimum cash flow to settle all debts.
    int getMin(double* arr);
    // A utility function that returns index of minimum value in *arr

    int getMax(double* arr);
    // A utility function that returns index of maximum value in *arr

    double minOf2(double x, double y);
    // A utility function to return minimum of 2 values

    void minCashFlowRec(double* amount);
    // amount[p] indicates the net amount to be credited/debited
    // to/from person 'p'
    // If amount[p] is positive, then i'th person will amount[i]
    // If amount[p] is negative, then i'th person will give  -amount[i]
    void setName(QString x, int index);
    void enterAmount(int index1, int index2, double amount);
    QStringList getText();
};


#endif // SPLITWISE_H

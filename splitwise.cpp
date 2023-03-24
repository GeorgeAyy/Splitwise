#include "Splitwise.h"
#include "Debt.h"
#include <QString>
#include <QStringList>
#include <iostream>
using namespace std;
Splitwise :: Splitwise()
{

}
void Splitwise::setName(QString x,int index)
{
    for (int j = 0; j < numOfUsers; j++)
    {
        graph[index][j].setOwesName(x);
        graph[j][index].setOwedName(x);
    }
}
void Splitwise::enterAmount(int index1,int index2,double amount)
{
    graph[index1][index2].setAmountOwed(amount);
}
int Splitwise::getMin(double* arr)
{
    int minInd = 0;
    for (int i = 1; i < numOfUsers; i++)
        if (arr[i] < arr[minInd])
            minInd = i;
    return minInd;
}

int Splitwise::getMax(double* arr)
{
    int maxInd = 0; // arr[0]
    for (int i = 1; i < numOfUsers; i++)
        if (arr[i] > arr[maxInd])
            maxInd = i;
    return maxInd;
}
double Splitwise::minOf2(double x, double y)
{
    return (x < y) ? x : y;
}

void Splitwise::setNum(int num)
{
    numOfUsers= num;
    graph = new Debt* [numOfUsers];
    for (int i = 0; i < numOfUsers; i++) {
        // Declare a memory block
        // of size (numOfUsers)
        graph[i] = new Debt[numOfUsers];
    }
}
int Splitwise::getNum()
{
    return numOfUsers;
}
void Splitwise::minCashFlowRec(double* amount)
{
    // Find the indexes of minimum and maximum values in amount[]
    // amount[mxCredit] indicates the maximum amount to be given
    //                  (or credited) to any person .
    // And amount[mxDebit] indicates the maximum amount to be taken
    //                  (or debited) from any person.
    // So if there is a positive value in amount[], then there must
    // be a negative value
    int mxCredit = getMax(amount), mxDebit = getMin(amount);

    // If both amounts are 0, then all amounts are settled
    if (amount[mxCredit] == 0 && amount[mxDebit] == 0)
        return;
    // person 0 = 0
    // person 1 = 0
    // person 2 = 0
    // Find the minimum of two amounts
    double min = minOf2(-amount[mxDebit], amount[mxCredit]);
    amount[mxCredit] -= min;
    amount[mxDebit] += min;
    // If minimum is the maximum amount to be
    myList << graph[mxDebit][mxCredit].getOwesName()+ " owes " + QString::number(min) + " to " +  graph[mxDebit][mxCredit].getOwedToName();
    // Recur for the amount array.  Note that it is guaranteed that
    // the recursion would terminate as either amount[mxCredit]
    // or  amount[mxDebit] becomes 0
    minCashFlowRec(amount);
}
QStringList Splitwise::getText()
{
    return myList;
}
void Splitwise::minCashFlow()
{
    // Create an array amount[], initialize all value in it as 0.
    double* amount = new double[numOfUsers];
    for (int i = 0; i < numOfUsers; i++)
    {
        amount[i] = 0;
    }
    // Calculate the net amount to be paid to person 'p', and
    // stores it in amount[p]. The value of amount[p] can be
    // calculated by subtracting debts of 'p' from credits of 'p'
    for (int p = 0; p < numOfUsers; p++)
        for (int i = 0; i < numOfUsers; i++)
        {
            amount[p] += (graph[i][p].getAmount() - graph[p][i].getAmount());
        }
    minCashFlowRec(amount);
}

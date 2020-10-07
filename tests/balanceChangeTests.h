#ifndef BALANCECHANGETESTS_H
#define BALANCECHANGETESTS_H

#include "balancechange.h"
#include "unittests.h"

bool removeLastTest(QVector<BalanceChange> testVec)
{
    bool ans(true);
    for(auto &elem : testVec)
    {
        auto back = elem.getOperations().back();

        auto sizeBeforeRemove = elem.getOperations().size();
        auto removed = elem.removeLast();

        ans &= (back == removed) && ((sizeBeforeRemove - 1) == elem.getOperations().size());
    }

    return ans;
}

bool addOperationTest(QVector<BalanceChange> testVec)
{
    bool ans(true);
    Operation op(1.0f, QDateTime::currentDateTime(), "AGD", 153);
    for(auto &elem : testVec)
    {
        auto beforeAddBack = elem.getOperations().back();
        elem.addOperation(op);
        auto afterAddBack = elem.getOperations().back();

        ans &= (beforeAddBack != afterAddBack) && (afterAddBack == op);
    }

    return ans;
}

bool balanceChangeTests()
{
    QVector<BalanceChange> testVec;

    QVector<QVector<Operation>> operationVectors;

    float cnt = 1;
    QVector<Operation> tempVec;
    for(int i = 1; i < 16; ++i)
    {
        for(int i = 1; i < 16; ++i)
        {
            tempVec.push_back({cnt, QDateTime::currentDateTime(),
                               "RTV", i});
        }

        operationVectors.push_back(tempVec);
        tempVec.clear();
        ++cnt;
    }


    for(int i = 0; i < 15; ++i)
        testVec.push_back({operationVectors.at(i)});

    return UnitTests::serializationTest(testVec) && removeLastTest(testVec) && addOperationTest(testVec);
}


#endif // BALANCECHANGETESTS_H

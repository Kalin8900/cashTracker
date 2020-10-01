#ifndef OPERATIONTESTS_H
#define OPERATIONTESTS_H
#include "operation.h"
#include "tests/unittests.h"

bool operationTests()
{
    QVector<Operation> testVec;

    for(int i = 1; i < 16; ++i)
        testVec.push_back({static_cast<float>(i), QDateTime::currentDateTime(),
                           "RTV", i});

    return UnitTests::serializationTest(testVec);
}
#endif // OPERATIONTESTS_H

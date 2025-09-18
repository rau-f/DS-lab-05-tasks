#pragma once

#include <iostream>
#include "DLL.hpp"

class Task2
{
private:
    DLL list1, list2;
    DLL listUnion;

    int l1Len, l2Len;

public:
    Task2();

    void Execute();
    void GetValues(DLL& list, int len);
};
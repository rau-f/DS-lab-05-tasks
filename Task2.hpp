#pragma once

#include <iostream>
#include "DLL.hpp"

class Task2
{
private:
    DLL m_List1, m_List2;
    DLL m_ListUnion;

    int m_L1Len, m_L2Len;

public:
    Task2();

    void Execute();
    void GetValues(DLL& list, int len);
};
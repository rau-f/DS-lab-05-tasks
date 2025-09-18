#pragma once

#include "Task2.hpp"


Task2::Task2()
{
    std::cout << "Enter length of list 1: ";
    std::cin >> l1Len;
    GetValues(list1, l1Len);

    std::cout << "Enter length of list 2: ";
    std::cin >> l2Len;
    GetValues(list2, l2Len);
}


void Task2::Execute()
{
    Node* tN = list1.GetHead();
    for (int i = 0; i < l1Len; i++)
    {
        listUnion.Append(tN->data);
        tN = tN->next;
    }
    
    tN = list2.GetHead();
    
    
    listUnion.Print();
}


void Task2::GetValues(DLL& list, int len)
{
    std::cout << "Enter values: ";

    int value;
    for (int i = 0; i < len; i++)
    {
        std::cin >> value;
        list.Append(value);
    }
}
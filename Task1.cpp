#include "Task1.hpp"


Task1::Task1()
    : eCount(0), oCount(0), cmbs(0)
{
    std::cout << "Enter length of list: ";
    std::cin >> listLen;

    srand(time(NULL));
    for (int i = 0; i < listLen; i++)
    {
        list.Append(rand() % 10);
    }
    list.Print();
}


void Task1::Execute()
{
    list.CountEvenOdd(eCount, oCount);
    cmbs = (eCount * (eCount - 1)) / 2;
    cmbs += (oCount * (oCount - 1)) / 2;

    std::cout << "Even results: " << cmbs << std::endl;
}

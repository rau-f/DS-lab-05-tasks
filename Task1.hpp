#include <iostream>
#include <ctime>

#include "DLL.hpp"


class Task1
{
private:
    DLL list;
    int listLen;
    int eCount;
    int oCount;
    int cmbs;

public:
    Task1();

    void Execute();
};
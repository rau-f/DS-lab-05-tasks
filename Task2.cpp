#include "Task2.hpp"


Task2::Task2()
{
    std::cout << "Enter length of list 1: ";
    std::cin >> m_L1Len;
    GetValues(m_List1, m_L1Len);

    std::cout << "Enter length of list 2: ";
    std::cin >> m_L2Len;
    GetValues(m_List2, m_L2Len);
}


void Task2::Execute()
{
    Node* tN = m_List1.GetHead();
    for (int i = 0; i < m_L1Len; i++)
    {
        m_ListUnion.Append(tN->data);
        tN = tN->next;
    }
    
    tN = m_List2.GetHead();
    for (int i = 0; i < m_L2Len; i++)
    {
        if (m_List1.Search(tN->data))
        {
            tN = tN->next;
            continue;
        }
        
        m_ListUnion.Append(tN->data);
        tN = tN->next;
    }
    
    
    m_ListUnion.Print();
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
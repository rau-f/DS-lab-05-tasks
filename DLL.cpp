#include "DLL.hpp"


Node::Node(int data, Node* prev, Node* next)
{
    this->data = data;
    this->prev = prev;
    this->next = next;
}


bool Node::isEven()
{
    return !(data % 2);
}


DLL::DLL()
    : m_Head(nullptr)
{}


void DLL::Append(int value)
{
    if (m_Head == nullptr)
    {
        m_Head = m_Tail = new Node(value);

        if (isCircular())
        {
            m_Head->next = m_Head;
            m_Head->prev = m_Head;
        }

        return;
    }

    m_Tail->next = new Node(value, m_Tail);
    m_Tail = m_Tail->next;

    MakeCircle();
}


void DLL::CountEvenOdd(int& eCount, int& oCount)
{
    if (m_Head == nullptr)
    {
        std::cout << "list is Empty!" << std::endl;
        return;
    }

    Node* tN = m_Head;
    do
    {
        if (tN->isEven()) eCount++;
        else oCount++;

        tN = tN->next;
    } while (tN != m_Tail->next);
}


void DLL::MakeCircle()
{
    if (m_Head == nullptr)
    {
        std::cout << "list is Empty!" << std::endl;
        return;
    }

    if (isCircular()) return;

    m_Tail->next = m_Head;
    m_Head->prev = m_Tail;
}


void DLL::BreakCircle()
{
    if (m_Head == nullptr)
    {
        std::cout << "list is Empty!" << std::endl;
        return;
    }
    
    if (!isCircular()) return;

    m_Head->prev = nullptr;
    m_Tail->next = nullptr;
}


bool DLL::isCircular()
{
    return (m_Head->prev != nullptr);
}


void DLL::Print()
{
    if (m_Head == nullptr)
    {
        std::cout << "list is Empty!" << std::endl;
        return;
    }

    Node* tN = m_Head;
    do
    {
        std::cout << tN->data << " ";
        tN = tN->next;
    } while (tN != m_Tail->next);

    std::cout << std::endl;
}
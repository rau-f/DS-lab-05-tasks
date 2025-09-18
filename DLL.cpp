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
    : m_Head(nullptr), m_Tail(nullptr), m_Size(0)
{}


void DLL::Append(int value)
{
    if (m_Head == nullptr)
    {
        m_Head = m_Tail = new Node(value);
        m_Size++;
        return;
    }

    bool wasCrclr = isCircular();

    m_Tail->next = new Node(value, m_Tail);
    m_Tail = m_Tail->next;

    m_Size++;

    if (wasCrclr)
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


bool DLL::isPalindrome()
{
    if (m_Head == nullptr)
    {
        std::cout << "list is Empty!" << std::endl;
        return false;
    }

    Node* left = m_Head;
    Node* right = m_Tail;

    int dist = 0;
    int mid = m_Size / 2;

    while (left->data == right->data && dist <= mid)
    {
        left = left->next;
        right = right->prev;
        dist++;
    }
    
    return (dist >= mid);
}


Node* DLL::Search(int value)
{
    if (m_Head == nullptr)
    {
        std::cout << "list is Empty!" << std::endl;
        return nullptr;
    }

    Node* tN = m_Head;
    do
    {
        if (tN->data == value)
        {
            return tN;
        }
        tN = tN->next;
    } while (tN != m_Tail->next);
    
    return nullptr;
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
#pragma once
#include <iostream>

struct Node
{
    int data;
    Node* prev;
    Node* next;

    Node(int data, Node* prev = nullptr, Node* next = nullptr);
    bool isEven();
};


class DLL
{
private:
    Node* m_Head;
    Node* m_Tail;
    int m_Size;

public:
    DLL();

    void Append(int value);
    void CountEvenOdd(int& eCount, int& oCount);
    void MakeCircle();
    void BreakCircle();
    void Print();

    Node* Search(int value);
    
    bool isCircular();
    bool isPalindrome();
    
    Node* GetHead() { return m_Head; }
    Node* GetTail() { return m_Tail; }
};

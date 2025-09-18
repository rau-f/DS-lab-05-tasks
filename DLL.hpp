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

public:
    DLL();

    void CountEvenOdd(int& eCount, int& oCount);
    void Append(int value);

    void MakeCircle();
    void BreakCircle();
    bool isCircular();
    void Print();

    Node* GetHead() { return m_Head; }
    Node* GetTail() { return m_Tail; }
};

/*
 * https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list/problem
 */

#include <iostream>

class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class SinglyLinkedList
{
public:
    Node* head;
    Node* tail;

    SinglyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert(int data)
    {
        Node* newNode = new Node(data);
        if (!this->head)
        {
            this->head = newNode;
        }
        else
        {
            this->tail->next = newNode;
        }

        this->tail = newNode;
    }
};

void freeLinkedList(Node* node)
{
    while (node)
    {
        Node* temp = node;

        node = node->next;
        delete temp;
    }
}

void printLinkedList(Node* head)
{
    while (head)
    {
        std::cout << head->data << "\n";
        head = head->next;
    }
}

int main()
{
    SinglyLinkedList* list = new SinglyLinkedList();

    int listCount = 0;
    std::cin >> listCount;

    for (int i = 0; i < listCount; i++)
    {
        int data;
        std::cin >> data;

        list->insert(data);
    }

    printLinkedList(list->head);
    freeLinkedList(list->head);

    return 0;
}
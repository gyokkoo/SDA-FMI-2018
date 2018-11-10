/*
 * https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem
 */

#include <iostream>

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class SinglyLinkedList
{
public:
    SinglyLinkedListNode* head;

    SinglyLinkedList()
    {
        this->head = nullptr;
    }
};

void print(SinglyLinkedListNode* node)
{
    while (node)
    {
        std::cout << node->data << "\n";
        node = node->next;
    }
}

void clear(SinglyLinkedListNode* node)
{
    while (node)
    {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        delete temp;
    }
}

SinglyLinkedListNode* insertAtTheEnd(SinglyLinkedListNode* head, int data)
{
    SinglyLinkedListNode* node = new SinglyLinkedListNode(data);
    if (!head)
    {
        head = node;
    }
    else
    {
        SinglyLinkedListNode* last = head;
        while (last->next)
        {
            last = last->next;
        }

        last->next = node;
    }

    return head;
}

int main()
{
    SinglyLinkedList* list = new SinglyLinkedList();
    int count = 0;
    std::cin >> count;

    for (int i = 0; i < count; i++)
    {
        int data = 0;
        std::cin >> data;

        SinglyLinkedListNode* head = insertAtTheEnd(list->head, data);
        list->head = head;
    }

    print(list->head);
    clear(list->head);

    return 0;
}
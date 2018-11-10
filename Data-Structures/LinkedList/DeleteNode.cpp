/*
 * https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem
 */

#include <iostream>

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList
{
public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert(int node_data)
    {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

        if (!this->head)
        {
            this->head = node;
        }
        else
        {
            this->tail->next = node;
        }

        this->tail = node;
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

void free(SinglyLinkedListNode* node)
{
    while (node)
    {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        delete temp;
    }
}

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position)
{
    SinglyLinkedListNode* current = head;
    if (position == 0)
    {
        head = head->next;
        delete current;
        return head;
    }

    for (int i = 1; i < position; i++)
    {
        current = current->next;
    }

    SinglyLinkedListNode* nodeToDelete = current->next;
    current->next = nodeToDelete->next;
    delete nodeToDelete;

    return head;
}

int main()
{
    SinglyLinkedList* list = new SinglyLinkedList();

    int count;
    std::cin >> count;

    for (int i = 0; i < count; i++)
    {
        int data;
        std::cin >> data;

        list->insert(data);
    }

    int position;
    std::cin >> position;

    SinglyLinkedListNode* head = deleteNode(list->head, position);

    print(head);
    free(head);

    return 0;
}
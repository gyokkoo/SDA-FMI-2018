/*
 * https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse/problem
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

        void insert_node(int node_data)
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

void print_singly_linked_list(SinglyLinkedListNode* head)
{
    while (head)
    {
        std::cout << head->data << "\n";
        head = head->next;
    }
}

void deleteList(SinglyLinkedListNode *node)
{
    while (node)
    {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        std::free(temp);
    }
}

void reversePrint(SinglyLinkedListNode* head)
{
    SinglyLinkedListNode* current = head;
    SinglyLinkedListNode* prev = nullptr;

    while (current != nullptr)
    {
        SinglyLinkedListNode* next = current->next;

        current->next = prev;
        prev = current;

        current = next;
    }

    print_singly_linked_list(prev);
}

int main()
{
    int tests;
    std::cin >> tests;

    for (int tests_itr = 0; tests_itr < tests; tests_itr++)
    {
        SinglyLinkedList* list = new SinglyLinkedList();

        int listCount;
        std::cin >> listCount;

        for (int i = 0; i < listCount; i++)
        {
            int data;
            std::cin >> data;

            list->insert_node(data);
        }

        reversePrint(list->head);

        deleteList(list->head);
    }

    return 0;
}

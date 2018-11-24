/*
Рицарите от приказния свят Алгоритмия много обичат да се сражават и да измислят хитри стратегии и алгоритми,
с които да побеждават техните противници. Когато нямат битки те рашават да играят помежду си на следната игра:
рицарите, които са N на брой се нареждат в кръг.
Те са номерирани с числата от 1 до N, като рицаря стоящ отляво на 1 е номериран с числото 2,
рицаря стоящ отляво на 2 е номериран с числото 3 и т.н(отляво на рицаря с номер N стои рицаря с номер 1).
Играта започва с рицаря с номер 1, който трябва да елиминира рицаря стоящ отляво на него(в случая рицаря с номер 2).
След това следващия непобеден рицар стоящ отляво на 1 трябва да направи същия ход, като играта продължава докато
не остане само един непобеден рицар. Вашата задача е да изведете неговия номер.
На първия ред ще получите числото N - броя на рицарите.
Трябва да изведете на един ред номера на рицаря който печели.

Input Format
N - броя на рицарите
Constraints
1 <= N <= 20 000 000
Output Format
На единствен ред номера на рицаря, който печели

Пример 1:
Вход: 6
Изход: 5

Пример 2:
Вход: 4
Изход: 1
 */

#include <iostream>

struct Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
    }
};

Node* head = nullptr;
Node* tail = nullptr;

void insert(int data)
{
    Node* newNode = new Node(data);

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        newNode->next = head;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}

int getLastNode()
{
    while (head->data != head->next->data)
    {
        Node* nodeToDelete = head->next;
        head->next = head->next->next;
        head = head->next;

        delete nodeToDelete;
    }

    return head->data;
}

int main()
{
    int n = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i += 2)
    {
        insert(i);
    }

    int lastNode = getLastNode();
    std::cout << lastNode << "\n";

    return 0;
}
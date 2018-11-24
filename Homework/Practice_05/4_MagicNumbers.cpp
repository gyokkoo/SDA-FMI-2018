/*
Едно число ще наричаме магическо, ако всеки две негови съседни цифри имат разлика точно 2.
Например числата 246, 131 и 86 са магически. Всички едноцифрени числа са също магически.
По дадено число N трябва да изведете всички магически числа по-малки или равни на N във възходящ ред.

Input Format
На единствен ред ще получите числото N

Constraints
1 <= N <= 10^16

Output Format
На единствен ред изведете магическите числа по-малки или равни на N във възходящ ред разделени с интервал.

Пример 1:

Вход:
50

Изход:
1 2 3 4 5 6 7 8 9 13 20 24 31 35 42 46

Обяснение: Това са всички числа по-малки или равни на 50, които имат исканото свойство.
 */
#include <iostream>
#include <cmath>

struct Node 
{
    long long data;
    Node* next;

    Node(long long data) 
    {
        this->data = data;
    }
};

void printMagicNumbers(Node* head, long long N)
{
    for (long long i = 1; i < N; i++)
    {
        long long current = head->data;
        int lastDigit = current % 10;
        int left = lastDigit - 2 >= 0 ? lastDigit - 2 : -1;
        int right = lastDigit + 2 <= 9 ? lastDigit + 2 : -1;

        if (left != -1) {
            head->data = current * 10 + left;
            if (head->data > N) 
            {
                return;
            }
            std::cout << head->data << " ";
            if (right != -1) 
            {
                Node* newNode = new Node(current * 10 + right);
                std::cout << newNode->data << " ";
                if (newNode->data > N) 
                {
                    return;
                }
                newNode->next = head->next;
                head->next = newNode;
                head = head->next;
            }
        } 
        else 
        {
            if (right != -1) 
            {
                head->data = head->data * 10 + right;
                if (head->data > N) 
                {
                    return;
                }
                std::cout << head->data << " ";
            }
        }

        head = head->next;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    Node* head = new Node(1);
    Node* node = head;

    long long N = 0;
    std::cin >> N;

    if (N == 1) {
        std::cout << 1 << " ";
        return 1;
    }
    std::cout << 1 << " ";
    for (int i = 2; i <= 9; i++) 
    {
        node->next = new Node(i);
        node = node->next;
        std::cout << i << " ";
    }

    node->next = head;

    printMagicNumbers(head, N);
    return 0;
}
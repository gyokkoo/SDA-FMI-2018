/*
Създайте свързани списък, който чете поток от числа от входа ( четете докато ви се подават числа на входа ).
След това обходете линейно вашият списък и изведете като резултат: минималното,максималното и сумата от числата в списъка.

Input Format
Поток от числа ( не знаете предварително броят им ) 1
1
..
..
7
и т.н

Constraints
Общият брой на числата ще е < 100 000 000
Всяко едно число ще е между 1 и 10000
Гарантирано е че ще ви се подаде поне 1 число, тоест просто празен вход няма да получите.
Output Format

След прочитане на потока от числа от вас се иска да изведете: минималното число в потока, максималното число в потока,
сумата от числата в потока.

Пример: 1
2
3
4
5

Изход: 1 5 15 (Минималното число е 1, Максималното 5, Сумата от числата е 15)
 */

#include <iostream>

const int MAX_NUMBER_LIMIT = 10000;
const int MIN_NUMBER_LIMIT = 1;

struct Node
{
    int number;
    Node* next;
};

Node* head = nullptr;

int min = MAX_NUMBER_LIMIT;
int max = MIN_NUMBER_LIMIT;
long long sum = 0;

void insert(int number)
{
    Node* node = new Node;
    node->number = number;
    node->next = head;
    head = node;

    if (number < min)
    {
        min = number;
    }

    if (number > max)
    {
        max = number;
    }

    sum += number;
}

/*
 * Needed to clear used memory
 */
void clear()
{
    Node* current = head;
    Node* previous = head;

    while (current != nullptr)
    {
        previous = current;
        current = previous->next;
        delete previous;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    int number = 0;
    while (std::cin >> number)
    {
        insert(number);
    }

    std::cout << min << " " << max << " " << sum << std::endl;

    clear();

    return 0;
}
/*
Получавате като вход число N.

Следват N числа които трябва да ги прочетете и съхраните в собственоръчно написан Свързан Списък.
Следва число P. Следват P числа на нов ред. ( тях може да съхраните по начин който е най-удобен за вас ).
От вас се изисква да върнете броя на различните двойки елементи ( (1,2) и (2,1) е една и съща двойка )
които се срещат в масива P и са съседи във вашият свръзан списък.

Input Format
Число N ( размер на вашият свързан списък )
Следват N числа.
Число P.
Следват P числа.

Constraints
N <= 1 000 000
Всеки един елемент е между 1 и 1234 ( включително ).

P <= 3000 ( дължината на P )

Всяко едно число в масива P между 1 и 1 000 000 000.

Output Format

Число X: броят на двойките които удовлетворяват условието.

Пример:

4
1 2 3 4
5
6 1 2 3 4

Изход:
3

Пояснение:
1->2->3->4 ( 1->2, 2->3, 3->4 като числата 1,2,3,4 се срещат в P )
 */

#include <iostream>
#include <vector>

struct Node
{
    int data;
    Node* next;
};

Node* head = nullptr;

void insert(int number)
{
    Node* node = new Node;
    node->data = number;
    node->next = head;

    head = node;
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    int N = 0;
    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        int element = 0;
        std::cin >> element;
        insert(element);
    }
    
    int arr[1235] = { 0 };
    int P = 0;
    std::cin >> P;
    for (int i = 0; i < P; i++)
    {
        int number = 0;
        std::cin >> number;
        if (number > 1234) 
        {
            continue;
        }

        arr[number]++;
    }

    Node* current = head;
    std::vector<Node*> pairs;
    while (current && current->next != nullptr)
    {
        int first = current->data;
        int second = current->next->data;
        if (first > second) 
        {
            int temp = second;
            second = first;
            first = temp;
        }

        bool pairAlreadyExist = false;
        for (int i = 0; i < pairs.size(); i++)
        {
            if ((pairs[i]->data == first && pairs[i]->next->data == second) ||
                (pairs[i]->data == second && pairs[i]->next->data == first))
            {
                pairAlreadyExist = true;
                break;
            }
        }

        if (!pairAlreadyExist && (arr[first] != 0 && arr[second] != 0)) 
        {
            pairs.push_back(current);
        }

        current = current->next;
    }

    std::cout << pairs.size() << "\n";

    return 0;
}

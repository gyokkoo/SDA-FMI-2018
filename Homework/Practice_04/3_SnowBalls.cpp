/*
Зимата идва и студентите от Снежно Инженерство ( СИ ) решили всички заедно послучай Контролно
Номер 2 да си направят снежен човек. Студентите от СИ са създали специално клониращо устройство което клонира избран
от тях снежен човек ( тъй като мързела е източник на идеи ).
В началото те имат 0-лев снежен човек с 0 топки на него !!!

Input Format
На вход получавате N заявки:
p m - клониране на p-ия снежен човек ( 0 <= p < i ), където това е i-тата заявка.
След клониране добавяте топка с маса m върху новият клонинг. ГАРАНТИРАНО Е ЧЕ ЩЕ КЛОНИРАТЕ САМО СЪЩЕСТВУВАЩИ ТОПКИ.

p 0 - клониране на p-ия снежен човек и премахване на най-горната топка на новият клонинг.
ГАРАНТИРАНО Е ЧЕ НЯМА КЛОНИРАТЕ И ДА ПРЕМАХВАТЕ ТОПКА ОТ НУЛЕВ СНЕЖЕН ЧОВЕК. ГАНРАНТИРАН
След N-те заявки, изведете сумата на всичките създадени снежни човеци.

Constraints
1 <= N <= 1 000 000 масата m, на всяка нова топка която трябва да се добави 1 <= m <= 1000

Output Format
След N-те заявки, изведете сумата на всичките създадени снежни човеци.

Пример:
8
0 1
1 5
2 4
3 2
4 3
5 0
6 6
1 0

Изход:
74
 */

#include <iostream>
#include <vector>

struct SnowBall
{
    int weight;
    int index;

    SnowBall(int weight, int index)
    {
        this->weight = weight;
        this->index = index;
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    int N;
    std::cin >> N;

    std::vector<SnowBall> balls;
    SnowBall first(0, 0);
    balls.push_back(first);

    long long sum = 0;
    for (int i = 1; i <= N; i++)
    {
        int p;
        std::cin >> p;

        int m;
        std::cin >> m;

        if (m > 0)
        {
            int weight = m + balls[p].weight;
            SnowBall ball(weight, p);
            balls.push_back(ball);
        }
        else
        {
            balls[i] = balls[balls[p].index];
            balls.push_back(balls[i]);
        }

        sum += balls[i].weight;
    }

    std::cout << sum << "\n";

    return 0;
}
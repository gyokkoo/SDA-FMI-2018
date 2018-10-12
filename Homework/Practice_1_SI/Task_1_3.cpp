#include <iostream>
#include <iomanip>

void printTime(int minutes)
{
    std::cout << minutes / 60 << ":";
    if (minutes % 60 < 10)
    {
        printf("%02d", minutes % 60);
    }
    else
    {
        std::cout << minutes % 60;
    }
}

int main()
{
    int maxTime = 0;
    int minTime = 24 * 60;

    for (int i = 0; i < 3; ++i)
    {
        int hoursToGo = 0;
        int minutesToGo = 0;
        int hoursToArrive = 0;
        int minutesToArrive = 0;

        std::cin >> hoursToGo >> minutesToGo >> hoursToArrive >> minutesToArrive;

        if (hoursToGo > hoursToArrive) 
        {
            hoursToArrive += 24;
        }

        int time = (hoursToArrive - hoursToGo) * 60 + (minutesToArrive - minutesToGo);
        if (time > maxTime)
        {
            maxTime = time;
        }

        if (time < minTime)
        {
            minTime = time;
        }
    }

    printTime(minTime);
    std::cout << "\n";
    printTime(maxTime);

    return 0;
}
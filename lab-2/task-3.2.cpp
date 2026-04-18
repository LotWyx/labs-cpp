#include <iostream>
#include <string>

using namespace std;

void findWarmest(string days[], int temps[], bool precipitation[], int n)
{
    int maxIndex = 0;

    for (int i = 1; i < n; i++)
    {
        if (temps[i] > temps[maxIndex])
        {
            maxIndex = i;
        }
    }

    cout << "Самый тёплый день: " << days[maxIndex]
         << ", " << temps[maxIndex] << " °C"
         << ", осадки: " << (precipitation[maxIndex] ? "да" : "нет") << endl;
}

int main()
{
    setlocale(LC_ALL, "RU");

    const int DAYS = 7;

    string days[DAYS] = {
        "Понедельник",
        "Вторник",
        "Среда",
        "Четверг",
        "Пятница",
        "Суббота",
        "Воскресенье"
    };

    int temps[DAYS] = { 12, 15, 10, 18, 20, 9, 14 };

    bool precipitation[DAYS] = { false, false, true, false, false, true, false };

    cout << "Погода на неделю:" << endl;
    for (int i = 0; i < DAYS; i++)
    {
        cout << days[i] << ": "
             << temps[i] << " °C, осадки: "
             << (precipitation[i] ? "да" : "нет") << endl;
    }

    findWarmest(days, temps, precipitation, DAYS);

    return 0;
}

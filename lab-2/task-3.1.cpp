#include <iostream>
#include <string>

using namespace std;

enum Day 
{
    Monday = 1,
    Tuesday = 2,
    Wednesday = 3,
    Thursday = 4,
    Friday = 5,
    Saturday = 6,
    Sunday = 7
};

struct Weather 
{
    Day day;
    int temperature;
    bool precipitation;
};

string dayName(Day day) 
{
    switch(day) {
        case Monday: return "Понедельник";
        case Tuesday: return "Вторник";
        case Wednesday: return "Среда";
        case Thursday: return "Четверг";
        case Friday: return "Пятница";
        case Saturday: return "Суббота";
        default: return "Воскресенье";
    }
}

void findWarmest(Weather week[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) 
    {
        if (week[i].temperature > week[maxIndex].temperature)
            maxIndex = i;
    }
    cout << "Самый тёплый день: " << dayName(week[maxIndex].day)
         << ", " << week[maxIndex].temperature << " °C"
         << ", осадки: " << (week[maxIndex].precipitation ? "да" : "нет") << endl;
}

int main() 
{
    setlocale(LC_ALL, "RU");

    Weather week[7] = {
        {Monday, 12, false},
        {Tuesday, 15, false},
        {Wednesday, 10, true },
        {Thursday, 18, false},
        {Friday, 20, false},
        {Saturday, 9, true },
        {Sunday, 14, false}
    };

    cout << "Погода на неделю:" << endl;
    for (int i = 0; i < 7; i++) 
    {
        cout << dayName(week[i].day) << ": "
             << week[i].temperature << " °C, осадки: "
             << (week[i].precipitation ? "да" : "нет") << endl;
    }

    findWarmest(week, 7);

    return 0;
}

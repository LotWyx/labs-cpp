#include <iostream>
#include <string>

using namespace std;

struct Address
{
    string street;
    int house;
    int apartment;
};

struct Person
{
    string fio;
    int age;
    Address address;
};

struct PersonFlat
{
    string fio;
    int age;
    string street;
    int house;
    int apartment;
};

void inputPerson(Person &person)
{
    cout << "ФИО: ";
    cin >> person.fio;

    cout << "Возраст: ";
    cin >> person.age;

    cout << "Улица: ";
    cin >> person.address.street;

    cout << "Дом: ";
    cin >> person.address.house;

    cout << "Квартира: ";
    cin >> person.address.apartment;
}

void printAll(Person people[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        cout << "Человек №" << i + 1 << endl;
        cout << "ФИО: " << people[i].fio << endl;
        cout << "Возраст: " << people[i].age << endl;
        cout << "Улица: " << people[i].address.street << endl;
        cout << "Дом: " << people[i].address.house << endl;
        cout << "Квартира: " << people[i].address.apartment << endl;
    }
}

void searchByStreet(Person people[], int n, string target)
{
    bool found = false;

    cout << endl;
    cout << "Результаты поиска по улице " << target << ":" << endl;

    for (int i = 0; i < n; i++)
    {
        if (people[i].address.street == target)
        {
            cout << "Найден: " << people[i].fio
                 << ", дом " << people[i].address.house
                 << ", кв. " << people[i].address.apartment << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "Никого не найдено." << endl;
    }
}


int main()
{
    setlocale(LC_ALL, "RU");

    const int N = 3;
    Person people[N];

    for (int i = 0; i < N; i++)
    {
        cout << endl;
        cout << "Введите данные для человека №" << i + 1 << endl;
        inputPerson(people[i]);
    }

    cout << endl;
    cout << "Все записи:" << endl;
    printAll(people, N);

    cout << endl;
    cout << "Прямой доступ к полям:" << endl;
    cout << "people[0].fio = " << people[0].fio << endl;
    cout << "people[0].address.street = " << people[0].address.street << endl;
    cout << "people[0].address.house = " << people[0].address.house << endl;
    cout << "people[0].address.apartment = " << people[0].address.apartment << endl;
    cout << "people[1].address.street = " << people[1].address.street << endl;
    cout << "people[2].address.apartment = " << people[2].address.apartment << endl;

    string query;
    cout << endl;
    cout << "Введите улицу для поиска: ";
    cin >> query;
    searchByStreet(people, N, query);

    cout << endl;
    cout << "sizeof(Person) = " << sizeof(Person) << " байт" << endl;
    cout << "sizeof(PersonFlat) = " << sizeof(PersonFlat) << " байт" << endl;

    return 0;
}

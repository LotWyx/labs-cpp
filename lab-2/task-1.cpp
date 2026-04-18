#include <iostream>
#include <string>

using namespace std;

enum Status 
{
    Excellent = 5, 
    Good = 4, 
    Satisfactory = 3, 
    Unsatisfactory = 2
};

struct Student 
{
    int id;
    string name;
    Status status;
};

int main() 
{
    setlocale(LC_ALL, "RU");

    Student student;

    cout << "Номер зачётки: ";
    cin >> student.id;

    cout << "Имя: ";
    cin >> student.name;

    cout << "Статус (5 - Excellent, 4 - Good, 3 - Satisfactory, 2 - Unsatisfactory): ";
    int status;
    cin >> status;
    student.status = static_cast<Status>(status);

    cout << "Номер зачётки: " << student.id << endl;
    cout << "Имя: " << student.name << endl;
    cout << "Статус: " << student.status << endl;

    int arr[4];

    cout << "sizeof(Student) = " << sizeof(Student) << " байт" << endl;
    cout << "sizeof(int[4])  = " << sizeof(arr) << " байт" << endl;

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

const int COUNT = 5;

struct Book 
{
    string title;
    string author;
    int year;
};

void printAll(Book books[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << i + 1 << ". \"" << books[i].title << "\" — "
             << books[i].author << ", " << books[i].year << endl;
    }
}

void findByAuthor(Book books[], int n, string author) 
{
    bool found = false;

    for (int i = 0; i < n; i++) 
    {
        if (books[i].author == author) 
        {
            cout << "Найдено: \"" << books[i].title << "\", " << books[i].year << endl;
            found = true;
        }
    }

    if (!found) 
    {
        cout << "Книги не найдены." << endl;  
    } 
}

int main() 
{
    setlocale(LC_ALL, "RU");

    Book books[COUNT] = {
        {"Мастер и Маргарита", "Булгаков", 1967},
        {"Преступление и наказание", "Достоевский", 1866},
        {"Война и мир", "Толстой", 1869},
        {"Идиот", "Достоевский", 1869},
        {"Отцы и дети", "Тургенев", 1862}
    };

    cout << "Все книги:" << endl << endl;
    printAll(books, COUNT);
    cout << endl;

    cout << "Поиск по автору:" << endl << endl;
    findByAuthor(books, COUNT, "Достоевский");
    cout << endl;

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

const int COUNT = 5;

struct Book
{
    string title;
    string author;
};

struct Library
{
    Book books[COUNT];
    int years[COUNT];
};

void printAll(Library library, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". \"" << library.books[i].title << "\" — "
             << library.books[i].author << ", " << library.years[i] << endl;
    }
}

void findByAuthor(Library library, int n, string author)
{
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (library.books[i].author == author)
        {
            cout << "Найдено: \"" << library.books[i].title
                 << "\", " << library.years[i] << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Книги не найдены." << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "RU");

    Library library = {
        {
            {"Мастер и Маргарита", "Булгаков"},
            {"Преступление и наказание", "Достоевский"},
            {"Война и мир", "Толстой"},
            {"Идиот", "Достоевский"},
            {"Отцы и дети", "Тургенев"}
        },

        {1967, 1866, 1869, 1869, 1862}
    };

    cout << "Все книги:" << endl << endl;
    printAll(library, COUNT);
    cout << endl;

    cout << "Поиск по автору:" << endl << endl;
    findByAuthor(library, COUNT, "Достоевский");
    cout << endl;

    return 0;
}

#include <ctime>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void intInp(int& x, int a, int b) {
    x = a - 1;
    while (x < a || x > b) {
        cin >> x;
    }
}

enum VehicleType { Car, Truck, Motorcycle };

struct Engine {
    int power;
    double volume;
};

struct Vehicle {
    VehicleType type;
    string model;
    Engine engine;
};

struct SimpleVehicle {
    int type;
    string model;
    int power;
    double volume;
};

void inpVehicle(Vehicle& veh) {
    cout << "Создание Vehicle" << endl;
    cout << "Введите тип: 1-Car; 2-Truck; 3-Motorcycle: ";
    int numType;
    intInp(numType, 1, 3);

    switch (numType) {
    case 1: {
        veh.type = Car;
        break;
    }
    case 2: {
        veh.type = Truck;
        break;
    }
    case 3: {
        veh.type = Motorcycle;
        break;
    }
    }

    cout << "Введите модель: ";
    cin >> veh.model;
    cout << "Введите мощность двигателя: ";
    cin >> veh.engine.power;
    cout << "Введите объём двигателя: ";
    cin >> veh.engine.volume;
}

void printVehicle(Vehicle& veh) {
    string type;

    switch (veh.type) {
    case Car: {
        type = "Car";
        break;
    }
    case Truck: {
        type = "Truck";
        break;
    }
    case Motorcycle: {
        type = "Motorcycle";
        break;
    }
    }

    cout << "Транспорт: " << type << "; модель: " << veh.model
         << "; мощность: " << veh.engine.power
         << "; объём: " << veh.engine.volume << endl;
}

void printVehicles(Vehicle* vehs, int n) {
    for (int i = 0; i < n; i++) {
        printVehicle(vehs[i]);
    }
}

void printVehicles(Vehicle* vehs, int n, VehicleType type) {
    for (int i = 0; i < n; i++) {
        if (vehs[i].type == type) {
            printVehicle(vehs[i]);
        }
    }
}

void engineSort(Vehicle* vehicles, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vehicles[j].engine.power > vehicles[j + 1].engine.power) {
                Vehicle sub = vehicles[j];
                vehicles[j] = vehicles[j + 1];
                vehicles[j + 1] = sub;
            }
        }
    }
}

void engineSort(SimpleVehicle* vehicles, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vehicles[j].power > vehicles[j + 1].power) {
                SimpleVehicle sub = vehicles[j];
                vehicles[j] = vehicles[j + 1];
                vehicles[j + 1] = sub;
            }
        }
    }
}

void checkTimeVehicle() {
    Vehicle array[100];
    double time;

    for (int i = 0; i < 100; i++) {
        array[i].engine.power = 100 - i;
    }

    clock_t start = clock();
    engineSort(array, 100);
    time = (clock() - start) / (double)CLOCKS_PER_SEC;

    cout << time << " секунд на сортировку 100 элементов (Vehicle)" << endl;
}

void checkTimeSimpleVehicle() {
    SimpleVehicle array[100];
    double time;

    for (int i = 0; i < 100; i++) {
        array[i].power = 100 - i;
    }

    clock_t start = clock();
    engineSort(array, 100);
    time = (clock() - start) / (double)CLOCKS_PER_SEC;

    cout << time << " секунд на сортировку 100 элементов (SimpleVehicle)" << endl;
}

int main(int, char**) {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int COUNT = 5;

    Vehicle* vehicles = new Vehicle[COUNT]{
        {Car, "BMW", {200, 2.0}},
        {Truck, "Volvo", {350, 5.5}},
        {Motorcycle, "Honda", {120, 1.2}},
        {Truck, "KAMAZ", {400, 6.7}}
    };

    inpVehicle(vehicles[4]);

    cout << "Все транспортные средства типа Car:" << endl;
    printVehicles(vehicles, COUNT, Car);

    cout << endl;
    cout << "Транспорт до сортировки:" << endl;
    printVehicles(vehicles, COUNT);

    engineSort(vehicles, COUNT);

    cout << endl;
    cout << "Транспорт после сортировки по мощности двигателя:" << endl;
    printVehicles(vehicles, COUNT);

    delete[] vehicles;

    cout << endl;
    cout << "Проверка времени сортировки:" << endl;
    checkTimeVehicle();
    checkTimeSimpleVehicle();
    checkTimeVehicle();
    checkTimeSimpleVehicle();

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

class Airplane {
private:
    string type;        // Тип самолета
    int passengers;     // Текущее количество пассажиров
    int maxPassengers;  // Максимальная вместимость самолета

public:
    // Конструктор
    Airplane(const string& t, int p, int maxP)
        : type(t), passengers(p), maxPassengers(maxP) {
    }

    // Проверка на равенство типов самолетов (операция ==)
    bool operator==(const Airplane& other) const {
        return type == other.type;
    }

    // Увеличение количества пассажиров (операция ++ префиксная)
    Airplane& operator++() {
        if (passengers < maxPassengers) {
            ++passengers;
        }
        return *this;
    }

    // Увеличение количества пассажиров (операция ++ постфиксная)
    Airplane operator++(int) {
        Airplane temp = *this;
        if (passengers < maxPassengers) {
            ++passengers;
        }
        return temp;
    }

    // Уменьшение количества пассажиров (операция -- префиксная)
    Airplane& operator--() {
        if (passengers > 0) {
            --passengers;
        }
        return *this;
    }

    // Уменьшение количества пассажиров (операция -- постфиксная)
    Airplane operator--(int) {
        Airplane temp = *this;
        if (passengers > 0) {
            --passengers;
        }
        return temp;
    }

    // Сравнение самолетов по максимальной вместимости (операция >)
    bool operator>(const Airplane& other) const {
        return maxPassengers > other.maxPassengers;
    }

    // Метод для вывода информации о самолете
    void Print() const {
        cout << "Type: " << type
            << ", Passengers: " << passengers
            << ", Max Passengers: " << maxPassengers << endl;
    }
};

int main() {
    Airplane a1("Boeing", 100, 200);
    Airplane a2("Airbus", 150, 180);

    cout << "Initial state:\n";
    a1.Print();
    a2.Print();

    // Проверка на равенство типов
    if (a1 == a2) {
        cout << "The airplanes are of the same type.\n";
    }
    else {
        cout << "The airplanes are of different types.\n";
    }

    // Увеличение количества пассажиров
    ++a1;
    a1.Print();

    a1++;
    a1.Print();

    // Уменьшение количества пассажиров
    --a2;
    a2.Print();

    a2--;
    a2.Print();

    // Сравнение по максимальной вместимости
    if (a1 > a2) {
        cout << "Airplane 1 has a greater maximum capacity than Airplane 2.\n";
    }
    else {
        cout << "Airplane 2 has a greater or equal maximum capacity than Airplane 1.\n";
    }

    return 0;
}

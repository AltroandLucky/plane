#include <iostream>
#include <string>

using namespace std;

class Airplane {
private:
    string type;        // ��� ��������
    int passengers;     // ������� ���������� ����������
    int maxPassengers;  // ������������ ����������� ��������

public:
    // �����������
    Airplane(const string& t, int p, int maxP)
        : type(t), passengers(p), maxPassengers(maxP) {
    }

    // �������� �� ��������� ����� ��������� (�������� ==)
    bool operator==(const Airplane& other) const {
        return type == other.type;
    }

    // ���������� ���������� ���������� (�������� ++ ����������)
    Airplane& operator++() {
        if (passengers < maxPassengers) {
            ++passengers;
        }
        return *this;
    }

    // ���������� ���������� ���������� (�������� ++ �����������)
    Airplane operator++(int) {
        Airplane temp = *this;
        if (passengers < maxPassengers) {
            ++passengers;
        }
        return temp;
    }

    // ���������� ���������� ���������� (�������� -- ����������)
    Airplane& operator--() {
        if (passengers > 0) {
            --passengers;
        }
        return *this;
    }

    // ���������� ���������� ���������� (�������� -- �����������)
    Airplane operator--(int) {
        Airplane temp = *this;
        if (passengers > 0) {
            --passengers;
        }
        return temp;
    }

    // ��������� ��������� �� ������������ ����������� (�������� >)
    bool operator>(const Airplane& other) const {
        return maxPassengers > other.maxPassengers;
    }

    // ����� ��� ������ ���������� � ��������
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

    // �������� �� ��������� �����
    if (a1 == a2) {
        cout << "The airplanes are of the same type.\n";
    }
    else {
        cout << "The airplanes are of different types.\n";
    }

    // ���������� ���������� ����������
    ++a1;
    a1.Print();

    a1++;
    a1.Print();

    // ���������� ���������� ����������
    --a2;
    a2.Print();

    a2--;
    a2.Print();

    // ��������� �� ������������ �����������
    if (a1 > a2) {
        cout << "Airplane 1 has a greater maximum capacity than Airplane 2.\n";
    }
    else {
        cout << "Airplane 2 has a greater or equal maximum capacity than Airplane 1.\n";
    }

    return 0;
}

#include <iostream>
using namespace std;

class Drob
{
private:
    int x;
    int y;

public:
    Drob() : x(0), y(1) {}

    Drob(int a, int b) : x(a), y(b) {
        if (y == 0) {
            y = 1;
            cout << "Denominator cannot be zero. Set to 1." << endl;
        }
    }

    void Print() const {
        cout << x << "/" << y << endl;
    }

    Drob operator+(const Drob& other) const {
        return Drob(x * other.y + other.x * y, y * other.y);
    }

    Drob operator-(const Drob& other) const {
        return Drob(x * other.y - other.x * y, y * other.y);
    }

    Drob operator*(const Drob& other) const {
        return Drob(x * other.x, y * other.y);
    }

    Drob operator/(const Drob& other) const {
        if (other.x == 0) {
            cout << "Ошибка!" << endl;
            return *this;
        }
        return Drob(x * other.y, y * other.x);
    }
};

int main() {
    Drob a(3, 4);
    Drob b(5, 6);

    Drob sum = a + b;
    cout << "Сумма: ";
    sum.Print();

    Drob difference = a - b;
    cout << "Вычитание: ";
    difference.Print();

    Drob product = a * b;
    cout << "Умножение: ";
    product.Print();

    Drob quotient = a / b;
    cout << "Деление: ";
    quotient.Print();
}

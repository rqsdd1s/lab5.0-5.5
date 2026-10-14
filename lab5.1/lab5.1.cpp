// Lab_05_1.cpp
// Мигович Вячеслав Вадимович, група РІ-11
// Лабораторна робота № 5.1
// Функції, що містять арифметичний вираз
// Варіант 18

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// прототип функції
// g(x, y) = (sin^2 x + cos^2 y) / (1 + |x*y|)
double g(const double x, const double y);

int main()
{
    double r, s;           // вхідні дані

    cout << "r = "; cin >> r;
    cout << "s = "; cin >> s;

    // обчислення виразу:
    //      g^2(r, s^2 + 1) + g(1, r^2 + s)
    // c = ---------------------------------
    //           1 + g^2(1, r*s)
    double c = (pow(g(r, s * s + 1), 2) + g(1, r * r + s))
        / (1 + pow(g(1, r * s), 2));

    cout << fixed << setprecision(6);
    cout << "c = " << c << endl;

    return 0;
}

// визначення функції
double g(const double x, const double y)
{
    return (sin(x) * sin(x) + cos(y) * cos(y)) / (1 + fabs(x * y));
}

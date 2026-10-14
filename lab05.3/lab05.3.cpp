// Lab_05_3.cpp
// Мигович Вячеслав Вадимович, група РІ-11
// Лабораторна робота № 5.3
// Функції, що містять розгалуження та цикли з рекурентними співвідношеннями
// Варіант 18:
//   z(t) = f(1 + 2t) + f^2( f(1) + 2 f(2t) ),  де
//          (sin^2 x + sin x^2) / (1 + cos^2 x),                |x| >= 1
//   f(x) =
//          1 / (1 + x^2) * SUM(n=0..6) x^(4n+1) / (4n+1)!,     |x| <  1

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(const double x);

int main()
{
    double tp, tk, z;
    int n;                          // кількість відрізків розбиття

    cout << "tp = "; cin >> tp;
    cout << "tk = "; cin >> tk;
    cout << "n = ";  cin >> n;

    double dt = (tk - tp) / n;      // крок

    cout << fixed;
    cout << endl << "  z(t) = f(1 + 2t) + f^2(f(1) + 2f(2t))" << endl;
    cout << "------------------------------" << endl;
    cout << "|" << setw(9) << "t" << "   |"
        << setw(12) << "z" << "   |" << endl;
    cout << "------------------------------" << endl;

    double t = tp;
    // + dt/2 - щоб через похибку округлення не втратити останню точку
    while (t <= tk + dt / 2)
    {
        z = f(1 + 2 * t) + pow(f(f(1) + 2 * f(2 * t)), 2);

        cout << "|" << setw(9) << setprecision(3) << t << "   |"
            << setw(12) << setprecision(6) << z << "   |" << endl;
        t += dt;
    }
    cout << "------------------------------" << endl;

    return 0;
}

double f(const double x)
{
    if (abs(x) >= 1)
        return (sin(x) * sin(x) + sin(x * x)) / (1 + cos(x) * cos(x));
    else
    {
        int n = 0;
        double a = x;               // перший доданок (n = 0): x^1 / 1! = x
        double S = a;
        do
        {
            n++;
            // коефіцієнт рекурентності:
            // a(n) / a(n-1) = x^4 / ((4n-2)(4n-1)(4n)(4n+1))
            double R = x * x * x * x
                / ((4 * n - 2) * (4 * n - 1) * (4 * n) * (4 * n + 1));
            a *= R;
            S += a;
        } while (n < 6);
        return S / (1 + x * x);
    }
}

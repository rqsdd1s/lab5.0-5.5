// Lab_05_2.cpp
// Мигович Вячеслав Вадимович, група РІ-11
// Лабораторна робота № 5.2
// Обчислення суми ряду Тейлора за допомогою функцій
// Варіант 18:
//          inf  (-1)^n * (x-1)^(n+1)
// ln(x) =  SUM  ----------------------- ,   0 < x <= 2
//          n=0          n + 1

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// обчислення суми ряду s з точністю eps; n - кількість порахованих доданків
void S(const double x, const double eps, int& n, double& s);
// обчислення наступного доданку a за рекурентним співвідношенням
void A(const double x, const int n, double& a);

int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;     // 0 < xp
    cout << "xk = "; cin >> xk;     // xk <= 2
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << endl << "  Taylor series for ln(x)" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << "   |"
        << setw(10) << "ln(x)" << "   |"
        << setw(10) << "S" << "   |"
        << setw(8) << "n" << "  |"
        << endl;
    cout << "---------------------------------------------------" << endl;

    x = xp;
    // + dx/2 - щоб через похибку округлення не втратити останню точку
    while (x <= xk + dx / 2)
    {
        S(x, eps, n, s);

        cout << "|" << setw(7) << setprecision(2) << x << "   |"
            << setw(10) << setprecision(5) << log(x) << "   |"
            << setw(10) << setprecision(5) << s << "   |"
            << setw(8) << n << "  |"
            << endl;
        x += dx;
    }
    cout << "---------------------------------------------------" << endl;

    return 0;
}

void S(const double x, const double eps, int& n, double& s)
{
    n = 0;
    double a = x - 1;               // перший доданок (n = 0)
    s = a;
    do
    {
        n++;
        A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
}

void A(const double x, const int n, double& a)
{
    // коефіцієнт рекурентності: a(n) / a(n-1) = -(x - 1) * n / (n + 1)
    double R = -(x - 1) * n / (n + 1);
    a *= R;
}

#include <iostream>
#include <cmath>
using namespace std;

double formula(double x)
{
    const double epsilon = 1e-6;

    double result = 0.0;
    double term = 0.0;
    int n = 1;

    do {
        term = (pow(2, n) * pow(x, 2 * n)) / (n + 1);
        result += term;
        n++;
    } while (fabs(term) > epsilon);

    return result;
}

int main()
{
    setlocale(LC_ALL, "rus");
    double x;

    do {
        cout << "Введите значение x: ";
        if ((cin >> x)) {
            cout << "Значение ряда для x = " << x << " равно: " << formula(x) << endl;
            break;
        }
        else {
            cout << "Ошибка ввода! Пожалуйста, введите число." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!cin.fail());

    return 0;
}
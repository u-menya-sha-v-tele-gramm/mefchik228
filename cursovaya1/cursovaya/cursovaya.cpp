#include <iostream>
#include <cmath>

using namespace std;

// функция для решения квадратного уравнения методом дискриминанта
void solveByDiscriminant(double a, double b, double c)
{
    setlocale(LC_ALL, "Russian");
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
    {
        cout << "Корней нет" << endl;
    }
    else if (discriminant == 0)
    {
        double x = -b / (2 * a);
        cout << "Один корень: x = " << x << endl;
    }
    else
    {
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Два корня: x1 = " << x1 << ", x2 = " << x2 << endl;
    }
}

// функция для решения квадратного уравнения методом Виета
void solveByVieta(double a, double b, double c)
{
    setlocale(LC_ALL, "Russian");
    double x1, x2;
    x1 = x2 = 0.0;

    if (a == 0)
    {
        cout << "Ошибка: коэффициент a не может быть равен 0" << endl;
        return;
    }

    double D = b * b - 4 * a * c;
    if (D < 0)
    {
        cout << "Корней нет" << endl;
    }
    else if (D == 0)
    {
        x1 = -b / (2 * a);
        cout << "Один корень: x = " << x1 << endl;
    }
    else
    {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        cout << "Два корня: x1 = " << x1 << ", x2 = " << x2 << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    double a, b, c;
    cout << "Введите коэффициенты a, b и c для квадратного уравнения ax^2 + bx + c = 0:" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;

    // выбор метода решения уравнения
    cout << "Выберите метод решения уравнения:" << endl;
    cout << "1. Метод дискриминанта" << endl;
    cout << "2. Метод Виета" << endl;
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        solveByDiscriminant(a, b, c);
        break;
    case 2:
        solveByVieta(a, b, c);
        break;
    default:
        cout << "Ошибка: неправильный выбор метода" << endl;
        break;
    }
}
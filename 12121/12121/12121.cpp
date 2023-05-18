#include <iostream>
#include <cmath>

using namespace std;

// Функция для решения квадратного уравнения методом дискриминанта
void solveByDiscriminant(double a, double b, double c)
{
    setlocale(LC_ALL, "Russian");
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Два действительных корня: x1 = " << x1 << ", x2 = " << x2 << endl;
    }
    else if (discriminant == 0) {
        double x = -b / (2 * a);
        cout << "Один действительный корень: x = " << x << endl;
    }
    else {
        cout << "Нет действительных корней." << endl;
    }
}

// Функция для решения квадратного уравнения методом формулы Виета
void solveByVieta(double a, double b, double c)
{
    setlocale(LC_ALL, "Russian");
    double x1, x2;

    if (a != 0) {
        double sum = -b / a;
        double product = c / a;

        // Поиск корней по формулам Виета
        double root1 = (sum + sqrt(sum * sum - 4 * product)) / 2;
        double root2 = (sum - sqrt(sum * sum - 4 * product)) / 2;

        // Установка корней в порядке возрастания
        if (root1 < root2) {
            x1 = root1;
            x2 = root2;
        }
        else {
            x1 = root2;
            x2 = root1;
        }

        cout << "Два действительных корня: x1 = " << x1 << ", x2 = " << x2 << endl;
    }
    else {
        cout << "Коэффициент 'a' не может быть равным нулю." << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    double a, b, c;
    int mainChoice = 0;

    while (mainChoice != 3) {
        cout << "-------------------\n";
        cout << "Основная страница\n";
        cout << "-------------------\n";
        cout << "Выберите тип уравнения:\n";
        cout << "1. Квадратное уравнение\n";
        cout << "2. Линейное уравнение\n";
        cout << "3. Завершить программу\n";
        cout << "Введите ваш выбор: ";
        cin >> mainChoice;

        switch (mainChoice) {
        case 1: {
            int equationChoice = 0;

            while (equationChoice != 3) {
                cout << "-------------------\n";
                cout << "Тип уравнения: Квадратное\n";
                cout << "-------------------\n";
                cout << "Выберите метод решения:\n";
                cout << "1. Метод дискриминанта\n";
                cout << "2. Метод формулы Виета\n";
                cout << "3. Вернуться назад\n";
                cout << "4. Завершить работу\n";
                cout << "Введите ваш выбор: ";
                cin >> equationChoice;

                switch (equationChoice) {
                case 1:
                    cout << "Введите коэффициенты квадратного уравнения (a, b, c): ";
                    cin >> a >> b >> c;
                    solveByDiscriminant(a, b, c);
                    cout << endl;
                    break;
                case 2:
                    cout << "Введите коэффициенты квадратного уравнения (a, b, c): ";
                    cin >> a >> b >> c;
                    solveByVieta(a, b, c);
                    cout << endl;
                    break;
                case 3:
                    break;
                case 4:
                    cout << "Программа завершена." << endl;
                    return 0;
                default:
                    cout << "Некорректный выбор." << endl;
                    break;
                }
            }

            break;
        }
        case 2:
            cout << "Функционал для решения линейного уравнения еще не реализован." << endl;
            cout << endl;
            break;
        case 3:
            cout << "Программа завершена." << endl;
            return 0;
        default:
            cout << "Некорректный выбор." << endl;
            break;
        }
    }

    return 0;
}
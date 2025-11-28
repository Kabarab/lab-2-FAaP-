#include <iostream>
#include <cmath>

using namespace std;

long double power (long double base, int exp)
{
    if (exp == 0)
    {
        return 1;
    }
    else if (exp == 1)
    {
        return base;
    }
    else
    {
        for ( int i = 2; i <= exp; i++)
        {
            base *= base;
        }
        return base;
    }
}


template <typename T>
T get_value(const string& error_message)
{
    T value;
    do
    {
        if (cin >> value)
        {
            break;
        }

        cout << error_message << "\n";
        cout << "Введите значение снова: ";

        cin.clear();

        cin.ignore(99999999, '\n');

    } while (true);

    cin.ignore(99999999, '\n');

    return value;
}

int main()
{
    double a, b, z;
    cout << "Enter z: ";
    z = get_value<double>("z должно быть числом!\n");
    cout << "Enter a: ";
    a = get_value<double>("a должно быть числом!\n");
    cout << "Enter b: ";
    b = get_value<double>("b должно быть числом!\n");

    double x;
    if (z < 1)
    {
        cout << "так как z<1  x=z³+0,2\n";
        x = z * z * z + 0.2;
    }
    else
    {
        cout << "так как z≥1  x=z+lnz\n";
        x = z + log(z);
    }

    cout << "Промежуточное значение x = " << x << '\n';
    double phi;
    int choice;

    cout << "Выберите ϕ(x):\n";
    cout << "  1) 2x\n";
    cout << "  2) x²\n";
    cout << "  3) x/3\n";

    do
    {
        cout << "Ваш выбор (1-3): "; // Добавил пробел
        choice = get_value<int>("Ошибка. Введите число от 1 до 3. ");

        if (choice < 1 || choice > 3)
        {
            cout << "Ошибка. Введите число от 1 до 3. \n";
        }
    } while (choice < 1 || choice > 3);

    switch (choice)
    {
    case 1:
        cout << "ϕ(x)=2x\n";
        phi = 2.0 * x;
        break;
    case 2:
        cout << "ϕ(x)=x²\n";
        phi = x * x;
        break;
    case 3:
        cout << "ϕ(x)=x:3\n";
        phi = x / 3.0;
        break;
    default:
        cout << "Недопустимый выбор " << choice << ".\n";
        phi = 0.0;
        break;
    }

    const double x_sq = x * x;
    const double x_cub = x * x * x;
    double y;
    y = 2 * a * power(cos(x_sq), 2) + power(sin(x_cub), 2) - b * phi;
    cout << "Итоговый результат y = " << y << '\n';

    return 0;
}
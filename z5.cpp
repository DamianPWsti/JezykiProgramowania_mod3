#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

char sign;
int counter = 0;
int value;
int valueNext;
vector<char> signs;
vector<int> values;
vector<int> outs;

void print()
{
    cout << "Wykonano: " << counter << " dzialan" << endl;
    for(int c=0; c<counter;c++)
    {
        cout << c+1 << ".\t" << values.at((c*2)) << signs.at(c) << values.at((c*2)+1) << "=" << values.at(((c+1)*2)) << endl;
    }
}

int main()
{
    cout << "WSTI"
         << " --GRUPA-- " << 2 << "DZI "
         << "Damian"
         << " "
         << "Potoczny" << endl;
    cout << "Modul 3 "
         << "Tablice "
         << "Zadanie 5" << endl;

    cout << "Kalkulator wykonujacy dzialania ponizsze w kolejnosci wprowadzania" << endl;
    cout << "'+' -> dodawanie" << endl;
    cout << "'-' -> odejmowanie" << endl;
    cout << "':' -> dzielenie" << endl;
    cout << "'*' -> mnozenie" << endl;
    cout << "'@' -> pierwiastek kwadratowy" << endl;
    cout << "'%' -> procent" << endl;
    cout << "'r' -> reszta z dzielenia" << endl;
    cout << "'^' -> potegowanie" << endl << endl;
    cout << "'=' -> drukowanie wyniku" << endl;
    cout << "'w' -> wyjscie" << endl;

    cout << "Podaj liczbe calkowita: ";
    cin >> value;
    values.emplace_back(value);

    while (sign == '\0')
    {
        cout << "Podaj symbol(+ - : * @ % r ^ = w) : ";
        cin >> sign;
        switch (sign)
        {
        case '+':
            signs.emplace_back(sign);
            cout << "Podaj liczbe calkowita: ";
            cin >> valueNext;

            values.emplace_back(valueNext);
            value += valueNext;
            values.emplace_back(value);
            counter++;
            break;
        case '-':
        signs.emplace_back(sign);
            cout << "Podaj liczbe calkowita: ";
            cin >> valueNext;

            values.emplace_back(valueNext);
            value -= valueNext;
            values.emplace_back(value);
            counter++;
            break;
        case '*':
        signs.emplace_back(sign);
            cout << "Podaj liczbe calkowita: ";
            cin >> valueNext;

            values.emplace_back(valueNext);
            value *= valueNext;
            values.emplace_back(value);
            counter++;
            break;
        case ':':
        signs.emplace_back(sign);
            cout << "Podaj liczbe calkowita rozna od zera: ";
            while ((!(cin >> valueNext)) && (valueNext != 0))
                cout << "Podaj liczbe calkowita rozna od zera: ";

            values.emplace_back(valueNext);
            value /= valueNext;
            values.emplace_back(value);
            counter++;
            break;
        case '@':
        signs.emplace_back(sign);
            valueNext = 2;

            values.emplace_back(valueNext);
            value = sqrt(value);
            values.emplace_back(value);
            counter++;
            break;
        case '%':
        signs.emplace_back(sign);
            cout << "Podaj ile procent: ";
            cin >> valueNext;

            values.emplace_back(valueNext);
            value *= (float)valueNext / 100;
            values.emplace_back(value);
            counter++;
            break;
        case 'r':
        signs.emplace_back(sign);
            cout << "Podaj liczbe calkowita: ";
            cin >> valueNext;

            values.emplace_back(valueNext);
            value %= valueNext;
            values.emplace_back(value);
            counter++;
            break;

        case '^':
            signs.emplace_back(sign);
            cout << "Podaj liczbe calkowita: ";
            cin >> valueNext;

            values.emplace_back(valueNext);
            value = pow(value, valueNext);
            values.emplace_back(value);
            counter++;
            break;
        case '=':
            print();
            break;
        case 'w':
            return 0;
            break;
        default:
            break;
        }
        sign = '\0';
    }
}
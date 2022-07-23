#include <iostream>
using namespace std;

void task_1();

int main()
{
    setlocale(LC_ALL, "Russian");

    task_1();

    return 0;
}

void task_1()
{
    char symbol = ' ';
    cout << "Введите символ: ";
    symbol = getchar();
    int symbol_code = (int)symbol;
    if (((symbol_code >= 65) and (symbol_code <= 90)) or ((symbol_code >= 97) and (symbol_code <= 122)))
    {
        cout << "\nВведена буква\n\n";
    }
    else if ((symbol_code >= 48) and (symbol_code <= 57))
    {
        cout << "\nВведена цифра\n\n";
    }
    else if ((symbol_code == 33) or ((symbol_code >= 44) and (symbol_code <= 46)) or (symbol_code == 58) or (symbol_code == 59) or (symbol_code == 63))
    {
        cout << "\nВведен знак препинания\n\n";
    }
    else
    {
        cout << "\nВведен неизвестный символ\n\n";
    }
}
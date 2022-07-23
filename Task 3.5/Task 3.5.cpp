#include <iostream>
using namespace std;

void task_1();
void task_2();

int main()
{
    setlocale(LC_ALL, "Russian");

    task_2();

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
    else cout << "\nВведен неизвестный символ\n\n";    
}

void task_2()
{
    int user_operator = 0, abonent_operator = 0, call_duration = 0;
    double cost = 0;
    cout << "Мобильные операторы:\n";
    cout << "1 - Билайн\n";
    cout << "2 - Мегафон\n";
    cout << "3 - МТС\n";
    cout << "4 - Теле2\n";
    do
    {
        cout << "Введите своего оператора: ";
        cin >> user_operator;
    } while (user_operator < 1 or user_operator > 4);
    do
    {
        cout << "Введите оператора абонента: ";
        cin >> abonent_operator;
    } while (abonent_operator < 1 or abonent_operator > 4);
    do
    {
        cout << "Введите длительность звонка в минутах: ";
        cin >> call_duration;
    } while (call_duration < 1);
    if (user_operator == abonent_operator) cout << "Звонки внутри сети бесплатны\n";
    else
    {
        cost = ((double)(user_operator + abonent_operator) / 10) * call_duration;
        cout << "Стоимость звонка " << cost << " рублей\n";
    }
}
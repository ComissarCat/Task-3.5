#include <iostream>
using namespace std;

void task_1();
void task_2();
void task_3();
void number_of_rows_needed();
void number_of_delays_allowed();
void salary();

int main()
{
    setlocale(LC_ALL, "Russian");

    int task = 0;
    void(*list_of_tasks[3])() = { task_1, task_2, task_3 };
    do
    {
        do
        {
            cout << "Введите номер задачи, 0 - выход\n";            
            (cin >> task).get();
        } while (task < 0 or task > 3);
        if (task) list_of_tasks[task - 1]();
    } while (task);

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

void task_3()
{
    int task = 0;
    void(*list_of_tasks[3])() = { number_of_rows_needed, number_of_delays_allowed, salary };
    do
    {
        do
        {
            cout << "Вася работает программистом и получает 50$ за каждые 100 строк кода.За каждое третье опоздание на работу Васю штрафуют на 20$.\n\n";
            cout << "1 - определить необходимое количество строк кода в зависимости от желаемой зарплаты и количества опозданий\n";
            cout << "2 - определить количество возможных опозданий в зависимости от желаемой зарплаты и количества строк кода\n";
            cout << "3 - определить зарплату в зависимости от количества строк кода и количества опозданий\n";
            cout << "0 - выход\n";
            cin >> task;
        } while (task < 0 or task > 3);
        if (task) list_of_tasks[task - 1]();
    } while (task);
}

void number_of_rows_needed()
{
    int number_of_rows = 0, number_of_delays = 0, salary = 0;
    do
    {
        cout << "Введите желаемую зарплату: ";
        cin >> salary;
    } while (salary < 1);
    do
    {
        cout << "Введите количество опозданий: ";
        cin >> number_of_delays;
    } while (number_of_delays < 0);
    number_of_rows = -(double)(((number_of_delays / 3) * -20) - salary) / 50 * 100;
    cout << "Необходимо написать " << number_of_rows << " строк кода\n";
}

void number_of_delays_allowed()
{
    int number_of_rows = 0, number_of_delays = 0, salary = 0;
    do
    {
        cout << "Введите желаемую зарплату: ";
        cin >> salary;
    } while (salary < 1);
    do
    {
        cout << "Введите количество строк кода: ";
        cin >> number_of_rows;
    } while (number_of_rows < 0);
    if (salary >= number_of_rows * 0.5) cout << "Нельзя опаздывать\n";
    else
    {
        number_of_delays = -((salary - number_of_rows * 0.5) / 20 * 3) + 1;
        cout << "Можно опоздать " << number_of_delays << " раз\n";
    }
}

void salary()
{
    int number_of_rows = 0, number_of_delays = 0, salary = 0;
    do
    {
        cout << "Введите количество строк кода: ";
        cin >> number_of_rows;
    } while (number_of_rows < 0);
    do
    {
        cout << "Введите количество опозданий: ";
        cin >> number_of_delays;
    } while (number_of_delays < 0);
    salary = number_of_rows * 0.5 - number_of_delays / 3 * 20;
    if (salary >= 0) cout << "За работу заплатят $ " << salary << endl;
    else cout << "За \"работу\" оштрафуют на $ " << -salary << endl;
}
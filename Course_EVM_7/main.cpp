#include <iostream>
#include <string>
#include <ctime>
#include "Conveyor.h"
using namespace std;

Conveyor conveyor;

int input_number();
void menu();
void print_menu();
int input_number();

int main() {
	srand(time(0));
	setlocale(LC_ALL, "RUS");
    menu();
}

void menu() {
    int number_commands;
    while (1) {
        conveyor.clear();
        print_menu();
        int punkt_menu = input_number();
        if (punkt_menu <= 3 && punkt_menu >= 1) {
            switch (punkt_menu)
            {
            case 1:
                cout << "Задайте число команд. ";
                number_commands = input_number();
                conveyor.creat_conveyor_from_console(number_commands);
                conveyor.work_conveyor();
                break;
            case 2:
                cout << "Задайте число команд. ";
                number_commands = input_number();
                conveyor.creat_conveyor(number_commands);
                conveyor.work_conveyor();
                break;
            case 3:
                exit(0);
            }
        }
        else
            cout << "Введен не верный пункт меню. " << endl;
    }
}

void print_menu() {
	cout << "Выберите дейсивие" << endl;
	cout << "1. Задать команды с клавиатуры" << endl;
	cout << "2. Задать команды рандомом" << endl;
	cout << "3. Выход из программы" << endl;
}

int input_number() {
    string number_s;
    while (1)
    {
        cout << "Введите: " << endl;
        cin >> number_s;
        if (number_s.find_first_not_of("0123456789", 0) == string::npos)
        {
            int number = stoi(number_s);
            return number;
        }
        else
            cout << "Введено не верное значение. Повторите ввод." << endl;
    }
}
#include "Conveyor.h"

bool checkingFileName(string);

void Conveyor::creat_conveyor(int number_commands) {
	NumberCommands = number_commands;
	for (int i = 0; i < NumberCommands; i++)
	{
		Command C;
		C.create_command();
		commands.push_back(C);
	}
}

void Conveyor::creat_conveyor_from_console(int number_commands) {
	NumberCommands = number_commands;
	for (int i = 0; i < NumberCommands; i++)
	{
		cout << endl << "Создание " << i + 1 << " команды" << endl;
		Command C;
		C.create_command_from_console();
		commands.push_back(C);
	}
}

void Conveyor::work_conveyor() {
	string name_file;
	cout << "Введите название файла (с расширением): ";
	getline(cin, name_file);
	getline(cin, name_file);
	int flag = 0;
	if (checkingFileName(name_file) == true) {
		ofstream fout;
		fout.open(name_file);
		int max_numer_clock = calculating_maximum_number_clock();
		for (int i = 0; i <= max_numer_clock; i++)
		{
			if (i == 0)
				fout << "№" << "\t";
			else
				fout << i << "\t";
		}
		fout << endl;
		for (int i = 0; i < commands.size(); i++)
		{
			fout << i + 1 << "\t";
			for (int j = 0; j < i ; j++) 
				fout << "\t";
			if (i == 0) {
				commands[i].print_command(fout, 0);
			}
			else {
				if (commands[i - 1].getOperand2Type() == "R2")
				{
					flag++;
					commands[i].print_command(fout, flag);
				}
				else
					commands[i].print_command(fout, flag);
			}			
		}
		cout << "Данные в файле " << name_file << endl;
		int average_command_time = max_numer_clock / NumberCommands;
		cout << endl << "Среднее время выполнения команды: " << average_command_time << endl << endl;
		fout << endl << "Среднее время выполнения команды: " << average_command_time;
	}
	else
		cout << "Не верное имя файла или расширение." << endl;
}

int Conveyor::calculating_maximum_number_clock() {
	int max_numer_clock = 0, shift = 0;
	for (int i = 0; i < commands.size(); i++)
	{
		if (i == 0)
		{
			if (commands[i].getNumerClock() + i > max_numer_clock)
				max_numer_clock = commands[i].getNumerClock() + i;
		}
		else
		{
			if (commands[i - 1].getOperand2Type() == "R2")
			{
				if (commands[i].getNumerClock() + i + 1> max_numer_clock)
					max_numer_clock = commands[i].getNumerClock() + i + shift;
				shift++;
			}
			else
			{
				if (commands[i].getNumerClock() + i > max_numer_clock)
					max_numer_clock = commands[i].getNumerClock() + i + shift;
			}
		}
		
	}
	return max_numer_clock;
}

void Conveyor::clear() {
	commands.clear();
	NumberCommands = 0;
}

bool checkingFileName(string name_file) {
	if (name_file.size() < 4) {
		cout << "Имя файла короткое." << endl;
		return false;
	}
	name_file = name_file.substr(name_file.find_last_of(".") + 1);
	if (name_file == "txt" || name_file == "doc" || name_file == "xls")
		return true;
	else
	{
		cout << "Файл должен иметь формат .txt или .doc" << endl;;
		return false;
	}
}
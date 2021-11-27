#include "Command.h"

double Operand2Type1P[3]{ 0.9, 0.8, 0.6 }; // регист
double CommandType1P[3]{ 0.9, 0.7, 0.5 }; // тип 1

int AccessMemoryT[3]{ 2, 5, 10 }; // пам€ть 
int ExecutionCommandT[3]{ 4, 8, 16 }; // тип 2

double RandomProbability();
int input_number();

void Command::create_command() {
	SelectionOperand2();
	SelectionCommand();
	NumerClock = ReadingandDecryption + ReadingOperand1 + ReadingOperand2 + ExecutingCommand + WritingResult;
}

void Command::SelectionOperand2() {
	double random_number = RandomProbability();
	if (random_number == 0.9 || random_number == 0.8 || random_number == 0.6)
	{
		Operand2Type = "R2";
		ReadingOperand2 = 1;
	}
	else
	{
		Operand2Type = "M2";
		ReadingOperand2 = AccessMemoryT[rand() % 3];
	}
}

void Command::SelectionCommand() {
	double random_number = RandomProbability();
	if (random_number == 0.9 || random_number == 0.7 || random_number == 0.5)
	{
		CommandType = "C1";
		ExecutingCommand = 1;
	}
	else
	{
		CommandType = "C2";
		ExecutingCommand = ExecutionCommandT[rand() % 3];
	}
}

void  Command::print_command(ofstream& fout, int tmp) {
	fout << "RD" << "\t";
	for(int i = 0; i < tmp; i ++)
		fout << "--" << "\t";
	fout << "R1" << "\t";
	for (int i = 0; i < ReadingOperand2; i++)
		fout << Operand2Type << "\t";
	for (int i = 0; i < ExecutingCommand; i++)
		fout << CommandType << "\t";
	fout << "WR" << endl;
}

double RandomProbability() {
	srand(rand());
	int random = rand() % 10;
	double random_number = double(random) / 10.0;
	if (random_number == 0)
		random_number += 0.1;
	return random_number;
}

void Command::create_command_from_console() {
	InputOperand2();
	InputCommand();
	NumerClock = ReadingandDecryption + ReadingOperand1 + ReadingOperand2 + ExecutingCommand + WritingResult;
}

void Command::InputOperand2() {
	while (1) {
		print_menu_InputOperand2();
		int punkt_menu = input_number();
		if (punkt_menu == 1 || punkt_menu == 2) {
			switch (punkt_menu)
			{
			case 1:
				Operand2Type = "R2";
				ReadingOperand2 = 1;
				break;
			case 2:
				Operand2Type = "M2";
				InputReadingOperand2();
				break;
			}
			break;
		}
		else
			cout << "¬веден не верный пункт меню. " << endl;
	}
}

void Command::print_menu_InputOperand2() {
	cout << "¬ведите номер типа опреранда" << endl;
	cout << "1. R2 - регист" << endl;
	cout << "2. M2 - пам€ть" << endl;
}

void Command::InputReadingOperand2() {
	while (1) {
		print_menu_ReadingOperand2();
		int punkt_menu = input_number();
		if (punkt_menu <= 3 && punkt_menu >= 1) {
			switch (punkt_menu)
			{
			case 1:
				ReadingOperand2 = 2;
				break;
			case 2:
				ReadingOperand2 = 5;
				break;
			case 3:
				ReadingOperand2 = 10;
				break;
			}
			break;
		}
		else
			cout << "¬веден не верный пункт меню. " << endl;
	}
}

void Command::print_menu_ReadingOperand2() {
	cout << "¬ведите номер типа опреранда" << endl;
	cout << "1. 2 такта" << endl;
	cout << "2. 5 тактов" << endl;
	cout << "3. 10 тактов" << endl;
}

void Command::InputCommand() {
	while (1) {
		print_menu_InputCommand();
		int punkt_menu = input_number();
		if (punkt_menu == 1 || punkt_menu == 2) {
			switch (punkt_menu)
			{
			case 1:
				CommandType = "C1";
				ExecutingCommand = 1;
				break;
			case 2:
				CommandType = "C2";
				InputExecutingCommand();
				break;
			}
			break;
		}
		else
			cout << "¬веден не верный пункт меню. " << endl;
	}
}

void Command::print_menu_InputCommand() {
	cout << "¬ведите номер типа опреранда" << endl;
	cout << "1. C1 - первый тип команды" << endl;
	cout << "2. C2 - второй тип команды тип команды" << endl;
	cout << "3. ¬ыйти в главное меню" << endl;
}

void Command::InputExecutingCommand() {
	while (1) {
		print_menu_ExecutingCommand();
		int punkt_menu = input_number();
		if (punkt_menu <= 3 && punkt_menu >= 1) {
			switch (punkt_menu)
			{
			case 1:
				ExecutingCommand = 4;
				break;
			case 2:
				ExecutingCommand = 8;
				break;
			case 3:
				ExecutingCommand = 16;
				break;
			}
			break;
		}
		else
			cout << "¬веден не верный пункт меню. " << endl;
	}
}

void Command::print_menu_ExecutingCommand() {
	cout << "¬ведите номер типа опреранда" << endl;
	cout << "1. 4 такта" << endl;
	cout << "2. 8 тактов" << endl;
	cout << "3. 16 тактов" << endl;
}
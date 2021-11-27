#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

class Command
{
private:
	int ReadingandDecryption = 1;
	int ReadingOperand1 = 1;
	string Operand2Type;
	int ReadingOperand2;
	string CommandType;
	int ExecutingCommand;
	int WritingResult = 1;
	int NumerClock;

public:

	void create_command();
	void create_command_from_console ();
	void SelectionOperand2();
	void SelectionCommand();
	void print_command(ofstream&, int);
	void InputOperand2();
	void print_menu_InputOperand2();
	void InputReadingOperand2();
	void print_menu_ReadingOperand2();
	void InputCommand();
	void print_menu_InputCommand();
	void InputExecutingCommand();
	void print_menu_ExecutingCommand();
	int getNumerClock() { return NumerClock; }
	string getOperand2Type() { return Operand2Type; }
};


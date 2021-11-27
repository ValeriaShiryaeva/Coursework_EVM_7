#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include"Command.h"
using namespace std;

class Conveyor
{
private:
	vector<Command> commands;
	int NumberCommands;
public:
	void creat_conveyor(int);
	void creat_conveyor_from_console(int);
	void work_conveyor();
	int calculating_maximum_number_clock();
	void clear();
};


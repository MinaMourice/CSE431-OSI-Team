
#pragma once

#include <iostream>
#include <string>

using namespace std;
class Alter
{
	string base_message;
	int  changed_bit;
public:
	Alter(string, int);
	string getAlterOutput();

};
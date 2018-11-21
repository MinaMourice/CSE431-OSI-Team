#include <iostream>
#include <string>
#include "alter.h"
using namespace std;


Alter::Alter(string base_message, int changed_bit)
{
	this->base_message = base_message;
	this->changed_bit = changed_bit;
}

string Alter::getAlterOutput()
{
	if (base_message[changed_bit] == 0)
		base_message[changed_bit] = '1';
	else
		base_message[changed_bit] = '0';
	return base_message;
}
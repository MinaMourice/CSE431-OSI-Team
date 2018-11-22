#include <iostream>
#include <string>
#include "generator.h"
using namespace std;


Generator::Generator(string base_message, string generator_function)
{
	this->base_message = base_message;
	this->generator_function = generator_function;
}

string Generator::getGeneratorOutput()
{
	string transmitted_message = "", reminder;
	transmitted_message += base_message;
	for (int i = 0; i < generator_function.length() - 1; i++)
		transmitted_message += "0";

	for (int i = 0; i <= transmitted_message.length() - generator_function.length();)
	{
		for (int j = 0; j < generator_function.length(); j++)
		{
			transmitted_message[i + j] = transmitted_message[i + j] == generator_function[j] ? '0' : '1';
		}
		for (; i < transmitted_message.length() && transmitted_message[i] != '1'; i++);
	}
	reminder = transmitted_message.substr(transmitted_message.length() - generator_function.length() + 1);
	transmitted_message = base_message + reminder;
	return transmitted_message;
}
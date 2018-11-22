#include <iostream>
#include <string>
#include "verifier.h"
using namespace std;


Verifier::Verifier(string base_message, string generator_function)
{
	this->base_message = base_message;
	this->generator_function = generator_function;
}

bool Verifier::getVerifierOutput()
{
	string reminder;
	for (int i = 0; i <= base_message.length() - generator_function.length();)
	{
		for (int j = 0; j < generator_function.length(); j++)
		{
			base_message[i + j] = base_message[i + j] == generator_function[j] ? '0' : '1';
		}
		for (; i < base_message.length() && base_message[i] != '1'; i++);
	}
	reminder = base_message.substr(base_message.length() - generator_function.length() + 1);
	//cout << reminder << endl;
	if (0 == stoi(reminder))
		return true;
	return false;
}
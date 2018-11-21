#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "generator.h"
#include "alter.h"
#include "verifier.h"
using namespace std;
//string Generator(string base_message, string generator_function);
//void Alter(string& transmitted_message, int changed_bit);
//bool Verfier(string base_message, string generator_function);
int main()
{
	string line, message, generator_function;
	int counter = 0;
	ifstream myfile("message_generator.txt");
	
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			if (0 == counter)
			{
				counter++;
				message = line;
				//message = stoi(line);
			}
			else
			{
				generator_function = line;
				//generator_function = stoi(line);
			}
		}
		myfile.close();
	}
	else
		cout << "Unable to open file";

	Generator G(message, generator_function);
	string generator_output = G.getGeneratorOutput();
	Alter A(generator_output, 3);
	Verifier V(generator_output,generator_function);
	bool verifier_output = V.getVerifierOutput();
	
	cout <<"Transmitted Message :"<<generator_output <<endl;
	if (generator_output == A.getAlterOutput())
		cout << "Verifier Output :" << "Correct Message";
	else
		cout << "Wrong Message";
	//cout << CRC(base_message,generator_function,message_length,generator_length);
	cin >> counter;
	return 0;
}
/*
string Generator(string base_message, string generator_function) {
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
}*/

/*
bool Verfier(string base_message, string generator_function) {
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
	cout << reminder << endl;
	if (0 == stoi(reminder))
		return true;
	return false;
}*/
/*
void Alter(string& transmitted_message, int changed_bit)
{
	cout << "Before Verifier :" << transmitted_message<<endl;
	if (transmitted_message[changed_bit] == 0)
		transmitted_message[changed_bit] = '1';
	else
		transmitted_message[changed_bit] = '0';
	cout << "After Verifier :" << transmitted_message<<endl;
}*/
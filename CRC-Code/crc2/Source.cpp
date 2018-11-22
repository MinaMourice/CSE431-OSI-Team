#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include<algorithm>
#include <sstream>
#include<iterator>
#include "generator.h"
#include "alter.h"
#include "verifier.h"

using namespace std;
//string Generator(string base_message, string generator_function);
//void Alter(string& transmitted_message, int changed_bit);
//bool Verfier(string base_message, string generator_function);

void alter(string messahe,string generator_function);

string getToken(string command) {  
	string spearators = " | "; 
	string token = command.substr(command.find_first_of(spearators), command.find(spearators)-1);
	return token;
}

void removeToken(string &command) {
	string spearators = " | ";
	string token = command.erase(0, command.find_first_of(spearators));
}


template<typename T>
vector<T>  split(string &line)
{
	vector<string>S;
	istringstream is(line);
	string token;
	while (std::getline(is, token, '|'))
	{
		S.push_back(token);
	}
	return S;
}

int main()
{
	string line, message, generator_function, command, fileName, generator_output;
	int counter = 0;
	ifstream myfile;
	bool exit=false;
	int pos = 0;
	cout<<"(Type exit to exit)"<<endl;
	while (exit != true) {

		cout << "generator < ";
		getline(cin,command);
		
		size_t exit_found = command.find("exit");
		size_t found = command.find("|");
		if (exit_found != std::string::npos)
		{
			break;
		}
		else if (found == std::string::npos)
		{
			cout << "Invalid Input" << endl;
		}
		else {
			vector<string> vec = split<string>(command); //Split to vector string
			ifstream myfile(vec[0] + ".txt");
			if (myfile.is_open())
			{
				//cout << "Open file" << endl;
				while (getline(myfile, line))
				{
					if (0 == counter)
					{
						counter++;
						message = line;
					}
					else
					{
						generator_function = line;
					}
				}
				myfile.close();
			}
			else
			{
				cout << "Error file" << endl;
			}
			Generator G(message, generator_function);
			generator_output = G.getGeneratorOutput();
			cout <<"\""<<vec[0] <<".txt\" -> " << generator_output << endl;
			size_t pos_alter = vec[1].find("alter");
			
			// if command is exit
			if (pos_alter != std::string::npos){
				//cout << "There is alter"<<endl;
				Alter A(generator_output, stoi(vec[1].erase(pos_alter,5)));
				if (generator_output == A.getAlterOutput())
					cout << "Message -> " << "\"message is correct\""<<endl;
				else
					cout << "Message -> " << "\"message is not correct\"" << endl;
			}

			else {
				//Verifier
				Verifier V(generator_output, generator_function);
				bool verifier_output = V.getVerifierOutput();
				if (verifier_output == true)
					cout << "Message -> " << "\"message is correct\"" << endl;
				else
					cout << "Message -> " << "\"message is not correct\"" << endl;
			}
			

		}
	}
		/*	Generator G(message, generator_function);
			string generator_output = G.getGeneratorOutput();
			Alter A(generator_output, 3);
			Verifier V(generator_output, generator_function);
			bool verifier_output = V.getVerifierOutput();

			cout << "Transmitted Message :" << generator_output << endl;
			if (generator_output == A.getAlterOutput())
				cout << "Verifier Output :" << "Correct Message";
			else
				cout << "Wrong Message";*/
			//cout << CRC(base_message,generator_function,message_length,generator_length);

		
		
	
	

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
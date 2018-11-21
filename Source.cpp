#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
/*string CRC(string base_message, string generator_function, int message_length, int generator_length)
{
	for (int i = 0; i <= base_message.length() - generator_length;)
	{
		for (int j = 0; j < generator_length; j++)
		{
			base_message[i + j] = base_message[i + j] == generator_function[i] ? '0' : '1';
		}
		for (; i < base_message.length() && base_message[i] != '1'; i++);
	}

	return base_message.substr(base_message.length()-generator_length+1);
}*/
int main()
{
	string line, message, generator_function,base_message="";
	int counter = 0,message_length,generator_length;
	ifstream myfile("message_generator.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			if (0 == counter)
			{
				counter++;
				message_length = line.length();
				message = line;
				//message = stoi(line);
			}
			else
			{
				generator_length = line.length();
				generator_function = line;
				//generator_function = stoi(line);
			}
		}
		myfile.close();
	}
	else
		cout << "Unable to open file";

	base_message += message;
	for (int i = 0; i < generator_length-1; i++)
		base_message += "0";

	for (int i = 0; i <= base_message.length() - generator_length;)
	{
		for (int j = 0; j < generator_length; j++)
		{
			base_message[i + j] = base_message[i + j] == generator_function[j] ? '0' : '1';
		}
		for (; i < base_message.length() && base_message[i] != '1'; i++);
	}
	cout <<"Transmitted Message :"<< message+base_message.substr(base_message.length()-generator_length+1);
	//cout << CRC(base_message,generator_function,message_length,generator_length);
	cin >> counter;
	return 0;
}
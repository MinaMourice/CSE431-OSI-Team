#pragma once

#include <iostream>
#include <string>

using namespace std;
class Generator
{
	string base_message, generator_function;
public:
	Generator(string, string);
	string getGeneratorOutput();

};
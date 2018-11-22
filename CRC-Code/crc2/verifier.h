#pragma once
#include <iostream>
#include <string>

using namespace std;
class Verifier
{
	string base_message, generator_function;
public:
	Verifier(string,string);
	bool  getVerifierOutput();
};



#pragma once
#include <string>
#include <fstream>
#include <iostream>

class C_Dictionary;
class Parser
{

public:

	Parser();
	Parser(std::string file_string);	
	virtual ~Parser();

private:

	std::string file_string_;

public:

	void parseIt(std::string file_string);
	int count_size_of_file();
	void read_data(C_Dictionary *val);
};


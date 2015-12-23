#pragma once
#include <string>
#include <list>
#include <vector>
#include "Parser.h"



class C_Dictionary
{
public:

	C_Dictionary();
	C_Dictionary(std::string dict_file_string);
	virtual ~C_Dictionary();
	
	struct Element
	{
		std::string english_string_;
		std::string czech_string_;
	};

	Parser parser_parser;
private:

	std::vector<std::list<Element*>> dict_vector_;
	int size_of_table_i_;
	
public:

	void set_size_of_table_i(int size_of_table_i);
	void addElement(std::string english_string, std::string czech_string);
	int hashString(std::string val);
	void read_data();
};


#include "C_Dictionary.h"
#include "Parser.h"

C_Dictionary::C_Dictionary()
{
	size_of_table_i_ = 0;
}

C_Dictionary::C_Dictionary(std::string dict_file_string)
{	
	parser_parser = Parser(dict_file_string);
	size_of_table_i_ = parser_parser.count_size_of_file();
	std::cout << "Resizing vector. Start" << std::endl;
	dict_vector_.resize(size_of_table_i_);
	std::cout << "Resizing vector. Complete" << std::endl;
}


C_Dictionary::~C_Dictionary()
{
}

void C_Dictionary::addElement(std::string english_string, std::string czech_string)
{
	Element* temp = new Element();
	temp->english_string_ = english_string;
	temp->czech_string_ = czech_string;
	dict_vector_.at(hashString(english_string)).push_back( temp );
}

int C_Dictionary::hashString(std::string val)
{
	int result_i = 0;

	for (int i = 0; i < val.length(); i++)
	{
		result_i += val[i] * val[i];
	}

	result_i = result_i % size_of_table_i_;
	return result_i;
}

void C_Dictionary::read_data()
{
	parser_parser.read_data(this);
}

void C_Dictionary::get_from_table(std::string en_string)
{	
	for (auto i : dict_vector_.at(hashString( en_string )))
	{	
		if (i->english_string_ == en_string)
		{
			std::cout << "			"<< i->czech_string_ << std::endl;
		}
	}
	
}

void C_Dictionary::set_size_of_table_i(int size_of_table_i)
{
	size_of_table_i_ = size_of_table_i;
}

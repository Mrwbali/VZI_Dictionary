#include "Parser.h"
#include "C_Dictionary.h"
class C_Dictionary;
Parser::Parser()
{
}

Parser::Parser(std::string file_string)
{
	file_string_ = file_string;
}

Parser::~Parser()
{
}

int Parser::count_size_of_file()
{
	std::ifstream dictionary_file;
	std::string line;
	int number_of_lines_i = 0;
	std::cout << "Counting lines. Start" << std::endl;
	dictionary_file.open(file_string_, std::ifstream::in);
	while (dictionary_file.peek() != EOF)
	{
		std::getline(dictionary_file, line);
		number_of_lines_i++;
	}
	std::cout << "Counting lines. Complete" << std::endl;
	dictionary_file.close();
	return number_of_lines_i;
}

void Parser::read_data(C_Dictionary *val)
{	
	std::ifstream dictionary_file;
	std::string cz_string, en_string;
	dictionary_file.open(file_string_, std::ifstream::in);
	int i = 0;
	while (!dictionary_file.eof())
	{
		std::string line;
		std::getline(dictionary_file, line);
		std::size_t pos_t = 0;
		std::size_t pos_t2 = 0;
		pos_t = line.find('\t');
		pos_t2 = line.find('\t', pos_t+1);
		en_string = line.substr(0, pos_t);
		pos_t2 = line.find('\t');
		cz_string = line.substr(pos_t+1, pos_t2);
		std::cout <<en_string << "	" << cz_string << i << std::endl;
		i++;
		std::cout << en_string << " " << cz_string << i << std::endl;
		val->addElement(en_string, cz_string);
	}


}

void Parser::parseIt(std::string file_string)
{
	
}

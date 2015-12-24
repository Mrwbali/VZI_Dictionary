// Dictionary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include"C_Dictionary.h"

#include <locale.h>
#ifdef WIN32
#define DEFAULT_LOCALE ".852"
#else
#define DEFAULT_LOCALE ".UTF-8"
#endif




int _tmain(int argc, _TCHAR* argv[])
{	
	std::string en_string;
	C_Dictionary dictionary = C_Dictionary("../slovnik.txt");
	dictionary.read_data();
	std::cin >> en_string;
	dictionary.get_from_table(en_string);
	getchar();
	
	return 0;
}


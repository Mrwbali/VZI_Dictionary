// Dictionary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

#include"C_Dictionary.h"
#include "Parser.h"




int _tmain(int argc, _TCHAR* argv[])
{	

	C_Dictionary dictionary = C_Dictionary("../slovnik.txt");
	dictionary.read_data();

	getchar();
	
	return 0;
}


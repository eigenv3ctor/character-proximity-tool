#include <iostream>
#include <fstream>
#include <vector>

#include "Book.h"
#include "BookParser.h"

void clean(std::string* filepath)
{
	filepath->erase(
		std::remove(filepath->begin(), filepath->end(), '\"'),
		filepath->end());
}

int main() 
{
	
	// REPL: prompt for user input for filepath of pdf
	while (true)
	{
		std::cout << "Enter filepath (or type 'exit' to quit): ";
		std::string filepath;
		std::cin >> filepath;
		if (filepath == "exit") 
		{
			break;
		}
		clean(&filepath);
		std::ifstream file(filepath);
		if (!file.is_open()) 
		{
			std::cout << "Error: could not open file " << filepath << std::endl;
		}
		else
		{
			std::cout << "Parsing file: " << filepath << std::endl;
			Book* book = parseBookFromFile(file);
			std::cout << "Parsing completed." << std::endl;
			break;
		}
	}
}
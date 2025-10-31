#include "BookParser.h"

Book* parseBookFromFile(std::ifstream& file)
{
	Book* book = nullptr;
	std::string currLine;
	while (std::getline(file, currLine)) {
		currLine = currLine.substr(0, 8);
		std::transform(currLine.begin(), currLine.end(), currLine.begin(), ::toupper);
		if (currLine == "CONTENTS")
		{
			std::vector<Title> titles;
			while (std::getline(file, currLine)) {
				if (currLine.empty())
				{
					continue;
				}
				// V1.0: Prompt user to confirm each title
				std::cout << "Is this a section title? (Y/N/done) " << currLine << ": ";
				std::string response;
				std::cin >> response;
				if (response == "done")
				{
					break;
				}
				else if (response == "Y")
				{
					titles.push_back(currLine);
				}
			}
			book = new Book(titles);
		}
	}
	if (!book)
	{
		std::cout << "Unable to locate contents section in file." << std::endl;
	}
	return book;
}
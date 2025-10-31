#pragma once

#include <vector>
#include <map>
#include <string>

using Chapter = std::vector<std::string>; // a chapter is a vector of strings;
using Title = std::string;

class Book
{
public:
	std::vector<Title> contents;
	std::map<Title, Chapter> chapters;


	Book(std::vector<Title> contents) : contents(contents)
	{
		contents = std::vector<Title>(),
		chapters = std::map<Title, Chapter>();
	}

	void insertChapter(Title title, Chapter contents)
	{
		chapters.emplace(title, contents);
	}

};


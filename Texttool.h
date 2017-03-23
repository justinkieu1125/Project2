// Project 2
// Texttool.h
#pragma once
#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <list>
using namespace std;
class TextTool {
public:
	// default constructor
	TextTool()
	{

		wordlist = new list<string>();

	}
	// destructor
	~TextTool()
	{

		delete wordlist;

	}
	// Load information from a text file with the given filename.
	void loadListFromTextfile(string filename)
	{
		ifstream ifs;
		ifs.open(filename);
		if (ifs.is_open())
		{
			string aword;
			while (ifs >> aword)
			{
				addEntryBack(aword);
			}
			ifs.close();
		}
		else
			throw invalid_argument("Could not open file " + filename);
	}
	// return the number of words in the linked list
	int totalWords()
	{
		return wordlist->size();

	}
	// add entry at the back of the linked list
	void addEntryBack(const string& aword)
	{
		wordlist->push_back(aword);

	}
	
	const string listToString()
	{
		string printAll;
		for (list<string>::iterator print = wordlist->begin(); print != wordlist->end(); ++print)
		{
			printAll = printAll + *print + ' ';
		}
		return printAll;

	}
	// print duplicated words in the linked list
	void printDuplicates()
	{
		string duplicate;
		for (list<string>::iterator print = wordlist->begin(); print != wordlist->end(); duplicate = *print, ++print)
		{
			if (*print == duplicate)
			{
				cout << "duplicate word found: " << duplicate << endl;
			}

		}
	}
	// remove duplicated words in the linked
	void removeDuplicates()
	{
		wordlist->unique();

	}
	// determine the total number of duplicated words in the list
	int totalDuplicates()
	{
		
		string duplicates;
		int totalduplicates = 0;
		for (list<string>::iterator total = wordlist->begin(); total != wordlist->end(); ++total)
		{
			if (*total == duplicates)
			{
				totalduplicates++;
			}
			duplicates = *total;
		}
		return totalduplicates;
	}
	// check if the list is empty
	bool isEmpty()
	{
		return wordlist->empty();
	}
	// Empty the list
	void makeEmpty()
	{
		wordlist->erase(wordlist->begin(),wordlist->end());
	}
private:
	list<string> *wordlist;
};

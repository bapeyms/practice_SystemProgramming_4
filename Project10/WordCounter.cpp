#include "WordCounter.h"

void WordCounter::ReadFile(string filename)
{
	lock_guard<mutex>lock(flag);
	inputText.clear();
	ifstream file(filename);
	if (!file)
	{
		cout << "ERROR!" << endl;
		return;
	}

	string line;
	while (getline(file, line))
	{
		inputText.push_back(line);
	}
	file.close();
}

void WordCounter::Analize()
{
	lock_guard<mutex>lock(flag);
	lineCount = inputText.size();
	for (const string& line : inputText)
	{
		charCount += line.size();
		bool inWord = false;
		for (char c : line)
		{
			if (isspace(c))
			{
				inWord = false;
			}
			else if (!inWord)
			{
				wordCount++;
				inWord = true;
			}
		}
	}
}

void WordCounter::Save(string filename)
{
	lock_guard<mutex>lock(flag);
	ofstream file(filename, ios::trunc);
	if (!file)
	{
		cout << "ERROR!" << endl;
		return;
	}
	file << "Number of chars: " << to_string(charCount) << endl;
	file << "Number of words: " << to_string(wordCount) << endl;
	file << "Number of lines: " << to_string(lineCount) << endl;
	file.close();
}

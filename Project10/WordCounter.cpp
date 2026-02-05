#include "WordCounter.h"

void WordCounter::ReadFile(string filename)
{
	flag.lock();
	ifstream file(filename);
	if (!file)
	{
		cout << "ERROR!" << endl;
		return;
	}
	string line;
	while (!file.eof())
	{
		inputText.push_back(line);
	}
	file.close();
	flag.unlock();
}

void WordCounter::Analize()
{
}

void WordCounter::Save(string filename)
{
}

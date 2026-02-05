#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <mutex>
using namespace std;

class WordCounter
{
	int charCount;
	int wordCount;
	int lineCount;
	vector<string> inputText;
	mutex flag;
public:
	WordCounter() {};
	void ReadFile(string filename);
	void Analize();
	void Save(string filename);
};


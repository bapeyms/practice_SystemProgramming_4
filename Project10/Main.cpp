#include <iostream>
#include <thread>
#include "WordCounter.h"
using namespace std;

int main()
{
	WordCounter file;

	thread t1(&WordCounter::ReadFile, file, "input.txt");
	t1.join();

	thread t2(&WordCounter::Analize, file);
	t2.join();

	thread t3(&WordCounter::Save, file, "result.txt");
	t3.join();

	cout << "Finish" << endl;
}
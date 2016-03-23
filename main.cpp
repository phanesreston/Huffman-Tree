#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {

	int freq = 0;
	string line;
	map<char, map<int, int>> tempFreqMap;
	map<char, map<int, int>> freqMap;
	map<int, int>::iterator itr1;
	map<char, map<int, int>>::iterator itr2;

	ifstream input("input.txt");

	if (input.is_open())
	{
		while (getline(input, line))
		{
			for (char ch : line) {
				freq++;
				tempFreqMap[ch][freq];
			}
		}
		input.close();
	}
	else {
		cout << "Unable to open file";
	}

	for (itr2 = tempFreqMap.begin(); itr2 != tempFreqMap.end(); itr2++)
	{
		int count = 0;
		char letter;
		letter = itr2->first;

		for (itr1 = itr2->second.begin(); itr1 != itr2->second.end(); itr1++)
		{
			count++;
		}

		freqMap[letter][count];

	}

	cout << "--- Frequency Map ---" << "\n\n";

	for (itr2 = freqMap.begin(); itr2 != freqMap.end(); itr2++)
	{
		cout << "character: " <<  itr2->first << " - ";

		for (itr1 = itr2->second.begin(); itr1 != itr2->second.end(); itr1++)
		{
			cout << "frequency " << itr1->first << "\n\n";
		}

	}

	system("pause");
	return 0;
}
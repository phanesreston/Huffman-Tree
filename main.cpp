#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {

	string line;
	int freq = 0;
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
				freqMap[ch][freq];
			}
		}
		input.close();
	}
	else {
		cout << "Unable to open file";
	}


	for (itr2 = freqMap.begin(); itr2 != freqMap.end(); itr2++)
	{
		int count = 0;
		cout << itr2->first << " - ";

		for (itr1 = itr2->second.begin(); itr1 != itr2->second.end(); itr1++)
		{
			count++;
		}

		cout << "frequency: " << count << "\n\n ";

	}

	system("pause");
	return 0;
}

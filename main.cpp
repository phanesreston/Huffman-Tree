#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {

	string line;

	// create ifstream
	// open file
	ifstream input("input.txt");

	// read in file contents letter by letter

	if (input.is_open())
	{
		while (getline(input, line))
		{

			cout << line << '\n';
			for (char ch : line) {
				cout << ch << "-";
			}
			cout << "\n";
		}
		input.close();
	}

	else cout << "Unable to open file";

	// store frequency

	// create huffman tree

	// create ofstream

	// encode message

	// output encoded message to new file

	// decode encoded message

	// output to new file

	system("pause");
	return 0;
}
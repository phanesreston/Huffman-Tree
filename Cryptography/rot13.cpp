#include "rot13.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void rot13::encrypt()
{
	cout << "--ROT-13 CIPHER-- \n\n";
	// open poem.txt and go through the file line by line
	ifstream f("poem.txt");
	while (f) {
		getline(f, line);
		// loop for length of string
		for (size_t i = 0; i < line.length(); i++) {
			// if the char is between the first 13 letters of the alphabet
			if (line[i] >= 'a' && line[i] <= 'm' || line[i] >= 'A' && line[i] <= 'M') {
				// append the letter 13 spaces up in the alphabet
				encryptedLine += line[i] + 13;
			}
			// if the char is between the last 13 letters of the alphabet
			else if (line[i] >= 'n' && line[i] <= 'z' || line[i] >= 'N' && line[i] <= 'Z') {
				// append the letter 13 spaces down in the alphabet
				encryptedLine += line[i] - 13;
			}
			else {
				// if not a letter just append to string
				encryptedLine += line[i];
			}
		}
		// write to file
		ofstream o;
		o.open("encryptedPoem.txt", std::fstream::app);
		o << encryptedLine << "\n";
		o.close();

		cout << encryptedLine << "\n";
		encryptedLine = "";
	}
}

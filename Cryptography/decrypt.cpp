#include "decrypt.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void decrypt::decryptSecret()
{
	cout << "--Decryption of secret.txt-- \n\n";
	// open file secret.txt and get encrypted line
	ifstream f("secret.txt");
	while (f) {
		getline(f, line);
		// loop through each letter of the alphabet
		for (int count = 0; count < 26; count++) {
			// for the length of the string
			for (size_t i = 0; i < line.length(); i++) {
				// if the char is inbetween 'a' and 'z'
				if (line[i] >= 'a' && line[i] <= 'z') {
					// if char greater than or equal to 'z' change to 'a' and append to decryptedString
					if (line[i] >= 'z') {
						line[i] = 'a';
						decryptedLine += line[i];
					}
					// else move to next letter
					else {
						line[i]++;
						decryptedLine += line[i];
					}
				}
				// if the char is inbetween 'A' and 'Z'
				else if (line[i] >= 'A' && line[i] <= 'Z') {
					// if char greater than or equal to 'Z' change to 'A' and append to decryptedString
					if (line[i] >= 'Z') {
						line[i] = 'A';
						decryptedLine += line[i];
					}
					// else move to next letter
					else {
						line[i]++;
						decryptedLine += line[i];
					}
				}
				// if its not a letter just append to string
				else {
					decryptedLine += line[i];
				}
			}
			cout << decryptedLine << "\n";
			decryptedLine = "";
		}
	}
}

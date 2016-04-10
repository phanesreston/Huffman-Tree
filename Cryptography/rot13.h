#pragma once
#include <iostream>
#include <string>
using namespace std;

class rot13 {
private:
	string line;
	string encryptedLine;
public:
	void encrypt();
};

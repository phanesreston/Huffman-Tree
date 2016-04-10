#include "rot13.h"
#include "decrypt.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	rot13 rot;
	rot.encrypt();

	decrypt d;
	d.decryptSecret();
	system("pause");
	return 0;
}
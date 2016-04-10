#include "HuffmanTree.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string line;
	ifstream f("Huffman.txt");
	getline(f, line);
	HuffmanTree* ht = new HuffmanTree(line);
	cout << "original message: " << line << "\n\n";
	ht->buildTable();
	ht->buildHeap();
	ht->displayFreqTable();
	ht->displayHuffTable();
	ht->writeEncodedString();
	ht->decodeHuffman();
	ht->writeDecodedString();
	ht->compressEncodedString();
	ht->decompress();

	system("pause");
	return 0;

}
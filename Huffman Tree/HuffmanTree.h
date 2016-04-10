#pragma once
#include "HuffmanNode.h"
#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

class HuffmanTree {

private:
	string message;
	string encodedMessage;
	string decodedMessage;
	string bitMessage;
	string compressedMessage;
	string decompressedMessage;
	HuffmanNode* root;
	map<char, int> freqTable;
	map<char, string> huffTable;
	map<char, int>::iterator freqItr;
	map<char, string>::iterator huffItr;
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> heap;
public:
	HuffmanTree(string);
	void buildTable();
	void buildHeap();
	void encodeHuffman(HuffmanNode*, string);
	void writeEncodedString();
	void decodeHuffman();
	void writeDecodedString();
	void displayFreqTable();
	void displayHuffTable();
	void compressEncodedString();
	void decompress();
};
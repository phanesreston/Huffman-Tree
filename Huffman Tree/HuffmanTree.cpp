#include "HuffmanTree.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>
#include <algorithm>
using namespace std;

/***************************************************************************************
*    Title: An In-Depth Look At Huffman Encoding
*    Author: KYA
*    Date: 19 January 2011
*    Code version: <code version>
*    Availability: http://www.dreamincode.net/forums/blog/324/entry-3150-an-in-depth-look-at-huffman-encoding/
*
***************************************************************************************/

HuffmanTree::HuffmanTree(string s) {
	message = s;
}

void HuffmanTree::buildTable()
{
	// loop through string char by char
	for (size_t i = 0; i < message.length(); i++) {
		// get char at position (i)
		char c = message.at(i);
		if (freqTable.find(message.at(i)) == freqTable.end()) {
			// if char not exist in freqTable insert with freq of 1
			freqTable.insert(pair<char, int>(c, 1));
		}
		else {
			// if char exists in freqTable increase freq by 1
			freqTable[c]++;
		}
	}
}

void HuffmanTree::buildHeap()
{
	// iterate through freqTable map
	for (freqItr = freqTable.begin(); freqItr != freqTable.end(); freqItr++) {
		// insert node into queue
		heap.push(new HuffmanNode(freqItr->first, freqItr->second));
	}

	while (heap.size() != 1) {
		
		// node at top of queue stored in left node 
		HuffmanNode* l = new HuffmanNode(heap.top());
		// node removed from queue
		heap.pop();

		// node at top of queue stored in right node
		HuffmanNode* r = new HuffmanNode(heap.top());
		// node removed from queue
		heap.pop();

		// nodes combined to make new node
		HuffmanNode* combo = new HuffmanNode(l, r);
		// combined node inserted into queue
		heap.push(combo);
	}

	// last node in queue is the root
	root = heap.top();
	// encode the file contents starting at the root and working down
	encodeHuffman(root, " ");
	// remove from queue
	heap.pop();
}

void HuffmanTree::encodeHuffman(HuffmanNode* root, string code)
{
	// if left node is null, no more nodes in tree, so insert to huffTable
	if (root->left == NULL) {
		root->code = code;
		huffTable.insert(pair<char, string>(root->getLetter(), code));
		return;
	}
	else {
		// assign a 0 or 1 to nodes on left and right
		encodeHuffman(root->left, code + "0");
		encodeHuffman(root->right, code + "1");
	}
}

void HuffmanTree::writeEncodedString()
{
	// build encoded message into string
	for (size_t i = 0; i < message.length(); i++) {
		encodedMessage += huffTable[message.at(i)];
	}

	// removes spaces from string
	/***************************************************************************************
	*    Title: Remove spaces from a string in C++
	*    Author: Vaughn Cato
	*    Date: 2 May 2013
	*    Code version: <code version>
	*    Availability: http://stackoverflow.com/questions/16329358/remove-spaces-from-a-string-in-c
	*
	***************************************************************************************/
	encodedMessage.erase(std::remove(encodedMessage.begin(), encodedMessage.end(), ' '), encodedMessage.end());
	cout << "encoded message: " << encodedMessage << "\n";

	// write encoded message to file
	ofstream o("encodedHuffman.txt");
	o << encodedMessage;
	o.close();
}

void HuffmanTree::decodeHuffman()
{
	HuffmanNode* temp = root;
	for (size_t i = 0; i < encodedMessage.length(); i++) {
		// if char is 0 then pointer = left
		if (encodedMessage[i] == '0') {
			temp = temp->left;
		}

		// if char is 1 then pointer = right
		if (encodedMessage[i] == '1') {
			temp = temp->right;
		}

		// when no more nodes get letter and append to string
		if (temp->left == nullptr && temp->right == nullptr)
		{
			decodedMessage += temp->letter;
			// reset pointer to root to get remaining letters
			temp = root;
		}
	}
	cout << "decoded message: " << decodedMessage << "\n\n";
}

void HuffmanTree::writeDecodedString()
{
	// write decoded message to file
	ofstream o("decodedHuffman.txt");
	o << decodedMessage;
	o.close();
}

void HuffmanTree::displayFreqTable()
{
	// iterate through freqTable and output
	cout << "Frequency Table \n";
	for (freqItr = freqTable.begin(); freqItr != freqTable.end(); freqItr++) {
		cout << freqItr->first << "\t" << freqItr->second << "\n";
	}
}

void HuffmanTree::displayHuffTable()
{
	// iterate through huffTable and output
	cout << "\n";
	cout << "Huffman Table \n";
	for (huffItr = huffTable.begin(); huffItr != huffTable.end(); huffItr++) {
		cout << huffItr->first << "\t" << huffItr->second << "\n";
	}
	cout << "\n";
}

void HuffmanTree::compressEncodedString()
{
	// convert 8 bit to ascii char
	/***************************************************************************************
	*    Title: Convert a string of binary into an ASCII string (C++)
	*    Author: Dale Wilson
	*    Date: 28 April 2014
	*    Code version: <code version>
	*    Availability: http://stackoverflow.com/questions/23344257/convert-a-string-of-binary-into-an-ascii-string-c
	*
	***************************************************************************************/
	for (size_t i = 0; i < encodedMessage.length(); i++) {
		// take in codes from file until 8 bits long
		if (bitMessage.size() == 8) {
			stringstream sstream(bitMessage);
			while (sstream.good())
			{
				bitset<8> bits;
				sstream >> bits;
				char c = char(bits.to_ulong());
				compressedMessage += c;
			}
			bitMessage = "";
		}
		// append code to string until 8 bits long
		bitMessage += encodedMessage[i];
	}
	// if the last remaining numbers not 8 bits long, append '0' until string contains 8 numbers
	if (bitMessage.size() != 8) {
		for (size_t i = 0; i < ((8 - bitMessage.size()) + 1); i++) {
			bitMessage += "0";
		}
	}
	// convert last 8 bit string to ascii char
	stringstream sstream(bitMessage);
	while (sstream.good())
	{
		bitset<8> bits;
		sstream >> bits;
		char c = char(bits.to_ulong());
		compressedMessage += c;
	}

	bitMessage = "";
	// removes spaces from string
	/***************************************************************************************
	*    Title: Remove spaces from a string in C++
	*    Author: Vaughn Cato
	*    Date: 2 May 2013
	*    Code version: <code version>
	*    Availability: http://stackoverflow.com/questions/16329358/remove-spaces-from-a-string-in-c
	*
	***************************************************************************************/
	compressedMessage.erase(std::remove(compressedMessage.begin(), compressedMessage.end(), NULL), compressedMessage.end());
	cout << "compressed message: " << compressedMessage << "\n";
	ofstream o("compressedHuffman.txt");
	o << compressedMessage;
	o.close();
}

void HuffmanTree::decompress()
{
	// convert ascii char back to 8 bit 
	/***************************************************************************************
	*    Title: character to binary conversion in C++ two characters at a time to get 16 bit binary form
	*    Author: Dale Wilson
	*    Date: 7 November 2013
	*    Code version: <code version>
	*    Availability: http://stackoverflow.com/questions/19844122/character-to-binary-conversion-in-c-two-characters-at-a-time-to-get-16-bit-bin
	*
	***************************************************************************************/
	for (size_t i = 0; i < compressedMessage.length(); i++) {
		decompressedMessage += bitset<8>(compressedMessage[i]).to_string();
	}
	// removes spaces from string
	/***************************************************************************************
	*    Title: Remove spaces from a string in C++
	*    Author: Vaughn Cato
	*    Date: 2 May 2013
	*    Code version: <code version>
	*    Availability: http://stackoverflow.com/questions/16329358/remove-spaces-from-a-string-in-c
	*
	***************************************************************************************/
	decompressedMessage.erase(std::remove(decompressedMessage.begin(), decompressedMessage.end(), NULL), decompressedMessage.end());
	cout << "decompressed message: " << decompressedMessage << "\n";

	// write to file
	ofstream o("decompressedHuffman.txt");
	o << decompressedMessage;
	o.close();
}

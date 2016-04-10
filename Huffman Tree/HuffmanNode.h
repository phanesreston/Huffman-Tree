#include <iostream>
#include <string>
using namespace std;

class HuffmanNode {

	friend class HuffmanTree;
	friend class Compare;

private: 
	char letter;
	int frequency;
	string code="";
	HuffmanNode* left;
	HuffmanNode* right;

public:
	HuffmanNode();
	HuffmanNode(char, int);
	HuffmanNode(HuffmanNode*, HuffmanNode*);
	HuffmanNode(HuffmanNode* hn);
	~HuffmanNode();

	int getFrequency();
	char getLetter();

};
// compare class for comparing 2 nodes in the priority queue
/***************************************************************************************
*    Title: declaring a priority_queue in c++ with a custom comparator
*    Author: soon
*    Date: 19 April 2013
*    Code version: <code version>
*    Availability: http://stackoverflow.com/questions/16111337/declaring-a-priority-queue-in-c-with-a-custom-comparator
*
***************************************************************************************/
class Compare {
	friend class HuffmanTree;
public:
	bool Compare::operator()(HuffmanNode * hn1, HuffmanNode * hn2)
	{
		if (hn1->getFrequency() > hn2->getFrequency()) {
			return true;
		}
		else {
			return false;
		}
	}
};

#include "HuffmanNode.h"
using namespace std;

/***************************************************************************************
*    Title: An In-Depth Look At Huffman Encoding 
*    Author: KYA
*    Date: 19 January 2011
*    Code version: <code version>
*    Availability: http://www.dreamincode.net/forums/blog/324/entry-3150-an-in-depth-look-at-huffman-encoding/
*
***************************************************************************************/

HuffmanNode::HuffmanNode()
{
	letter = ' ';
	frequency = 0;
	left = NULL;
	right = NULL;
}

HuffmanNode::HuffmanNode(char c, int i)
{
	letter = c;
	frequency = i;
	left = NULL;
	right = NULL;
}

HuffmanNode::HuffmanNode(HuffmanNode * l, HuffmanNode * r)
{
	left = l;
	right = r;
	frequency = left->getFrequency() + right->getFrequency();
	letter = NULL;
}

HuffmanNode::HuffmanNode(HuffmanNode * hn)
{
	if (hn->left != nullptr) {
		left = hn->left;
	}

	if (hn->right != nullptr) {
		right = hn->right;
	}

	letter = hn->letter;
	frequency = hn->frequency;

}

HuffmanNode::~HuffmanNode()
{
	if (left != NULL) delete left;
	if (right != NULL) delete right;
}

int HuffmanNode::getFrequency()
{
	return frequency;
}

char HuffmanNode::getLetter()
{
	return letter;
}

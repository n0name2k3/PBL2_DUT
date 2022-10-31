#pragma once
#include "Node.h"
class BST {
public:
	BST();
	static int count;
	static int count1;
	Node* root;
	int insert(int x);
	int getLevel(int x);
	int returnCount();
	int left_height(Node* node);
	int right_height(Node* node);
	void print();
	void printNLR();
	void printNRL();
	void printRLN();
	void printRNL();
	void printLNR();
	void printLRN();
	void deleteNode(int x);
	Node* findNode(int x);
	Node* findMax();
	Node* returnVal();
	void update();
	void draw();
private:
	int _returnCount(Node* node);
	void print__private(Node* node);
	void print__NLR(Node* node);
	void print__NRL(Node* node);
	void print__RLN(Node* node);
	void print__RNL(Node* node);
	void print__LRN(Node* node);
	void print__LNR(Node* node);
	Node* _returnVal(Node*);
	Node* findMax__private(Node* node);
	Node* deleteNode__private(Node* node, int x);
	int getLevel__private(Node* currNode);
	void updatePositions__private(Node* currNode, int level, int col);
	void draw__private(Node* currNode);
	Node* FindMax(Node* r);
};



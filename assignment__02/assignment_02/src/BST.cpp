#include "BST.h"
#include "Node.h"
#include<algorithm>
#include<stdlib.h>
#include<iostream>

using namespace std;


BST::BST() {
	root = NULL;
}

int BST::getLevel(int x) {
	Node* currNode = root;
	while (currNode) {
		if (x == currNode->data)
			break;

		if (x < currNode->data)
			currNode = currNode->left;
		else
			currNode = currNode->right;
	}
	if (!currNode)
		cout << x << " node is not found" << endl;
	else
		cout << x << currNode->level << endl;

	return currNode->level;
}

int BST::count = 0;
int BST::count1 = 0;

int BST::insert(int x) {
	count += 1;
	Node* currNode = root;
	Node* r = root;
	while (currNode) {
		r = currNode;
		if (x < currNode->data)
			currNode = currNode->left;
		else
			currNode = currNode->right;
		
	}

	if(!r)
		root = new Node(x);
	else {
		currNode = new Node(x);
		if (x < r->data)
			r->left = currNode;
		else
			r->right = currNode;
	}
	

	cout << x << " node added" << endl;
	update();
	return 1;

}

int BST::returnCount() {
	return _returnCount(root);
}

int BST::_returnCount(Node* node) {
	
		if (node == NULL) {
			return 0;
		}
		else {
			return 1 + _returnCount(node->left) + _returnCount(node->right);
		}
	
}

void BST::print() {
	cout << "current tree\n";
	print__private(root);
}

void BST::printNLR() {
	cout << "Node - Left - Right\n";
	print__NLR(root);
}

void BST::printNRL() {
	cout << "Node - Right - Left\n";
	print__NRL(root);
}

void BST::printLNR() {
	cout << "Left - Node - Right\n";
	print__LNR(root);
}

void BST::printLRN() {
	cout << "Left - Right - Node\n";
	print__LRN(root);
}

void BST::printRNL() {
	cout << "Right - Node - Left\n";
	print__RNL(root);
}

void BST::printRLN() {
	cout << "Right - Left - Node\n";
	print__RLN(root);
}

void BST::print__private(Node* node) {
	if (node) {
		cout << endl;
		cout << "Node = " << node->data << endl;
		cout << "level = " << node->level << endl;
		cout << "col = " << node->col << endl;
		cout << "x = " << node->x << endl;
		cout << "y = " << node->y << endl;
		cout << endl;
		print__private(node->left);
		print__private(node->right);
	}
}

void BST::print__RLN(Node* node) {
	if (node) {
		{
			cout << node->data << " "; // xu?t d? li?u trong node
			print__RLN(node->right); // duy?t qua ph?i 
			print__RLN(node->left); // duy?t qua tr?i
		}
	}
}

void BST::print__RNL(Node* node) {
	if (node) {
		{
			print__RNL(node->right); // duy?t qua ph?i
			cout << node->data << "  "; // xu?t gi? tr? c?a node
			print__RNL(node->left); // duy?t qua ph?i
		}
	}

}

void BST::print__NLR(Node* node) {
	if (node) {
		{
			//count += 1;
			cout << node->data << " "; // xu?t d? li?u trong node
			print__NLR(node->left); // duy?t qua tr?i
			print__NLR(node->right); // duy?t qua ph?i
		}
	}
}

void BST::print__NRL(Node* node) {
	if (node) {
		{
			cout << node->data << " "; // xu?t d? li?u trong node
			print__NRL(node->right); // duy?t qua tr?i
			print__NRL(node->left); // duy?t qua ph?i
		}
	}
}

void BST::print__LRN(Node* node) {
	if (node) {
		{
			print__LRN(node->left); // duy?t qua tr?i
			print__LRN(node->right); // duy?t qua ph?i
			cout << node->data << "  "; // xu?t gi? tr? c?a node
		}
	}
}

void BST::print__LNR(Node* node) {
	if (node) {
		{
			print__LNR(node->left); // duy?t qua tr?i
			cout << node->data << "  "; // xu?t gi? tr? c?a node
			print__LNR(node->right); // duy?t qua ph?i
		}
	}
}

Node* BST::findNode(int x) {
	Node* currNode = root;

	while (currNode) {
		if (x == currNode->data)
			break;

		if (x < currNode->data)
			currNode = currNode->left;
		else
			currNode = currNode->right;
	}
	if (!currNode) 
		cout << x << " node is not found" << endl;
	else
		cout << x << " node is found" << endl;

	return currNode;
}

Node* BST::findMax() {
	return findMax__private(root);
}
Node* BST::findMax__private(Node* node) {
	
	while (node)
		node = node->right;

	return node;
}

void BST::deleteNode(int x) {
	//count -= 1;	
	Node* currNode = root;
	Node* r = root;

	while (currNode) {
		if (x == currNode->data)
			break;
		else if (x < currNode->data) {
			r = currNode;
			currNode = currNode->left;
		}
		else {
			r = currNode;
			currNode = currNode->right;
		}
	}

	if (!currNode) {
		cout << "Node is there to be deleted" << endl;
	}
	else if (currNode->left && currNode->right) {
		Node* maxLeft = currNode->left;
		Node* maxLeftRoot = currNode;

		while (maxLeft->right) {
			maxLeftRoot = maxLeft;
			maxLeft = maxLeft->right;
		}

		if (maxLeft == currNode->left) {//no max left
			//maxLeftRoot->right = NULL;
			//maxLeft->left = currNode->left;
			maxLeft->right = currNode->right;

			//if (currNode == root)
				//root = maxLeft;

			if (x < r->data) {
				r->left = maxLeft;
			}
			else {
				r->right = maxLeft;
			}

			if (currNode == root)
				root = maxLeft;

			delete currNode;
		}
		else {
			maxLeftRoot->right = NULL;
			maxLeft->left = currNode->left;
			maxLeft->right = currNode->right;

			if (currNode == root)
				root = maxLeft;

			if (x < r->data) {
				r->left = maxLeft;
			}
			else {
				r->right = maxLeft;
			}
			if (currNode == root)
				root = maxLeft;

			delete currNode;
		}
		

	}
	else if (currNode->left) {//left child
		if (x < r->data)
			r->left = currNode->left;
		else
			r->right = currNode->left;

		if (currNode == root)
			root = currNode->left;

		delete currNode;
	}
	else if (currNode->right) {//right child
		cout << "delete 1 child right " << endl;
		if (x < r->data)
			r->left = currNode->right;
		else
			r->right = currNode->right;

		if (currNode == root)
			root = currNode->right;

		delete currNode;
	}
	else {// no children
		if (x < r->data)
			r->left = NULL;
		else
			r->right = NULL;

		if (r == currNode)
			root = NULL;
		else
			delete currNode;
	}
	

	//root = deleteNode__private(root, x);
	update();
}

Node* BST::deleteNode__private(Node* r, int x) {
	
	if (r == NULL) return r;
	else if (x < r->data) {
		r->left = deleteNode__private(r->left, x);
	}
	else if (x > r->data) {
		r->right = deleteNode__private(r->right, x);
	}
	else {
		if (r->left == NULL && r->right) {
			delete r;
			r = NULL;
		}
		else if (r->right == NULL) {
			Node* tmp = r;
			r = r->left;
			delete tmp;
		}
		else if (r->left == NULL) {
			Node* tmp = r;
			r = r->right;
			delete tmp;
		}
		else {
			Node* tmp = FindMax(r->left);
			r->data = tmp->data;
			r->left = deleteNode__private(r->left, r->data);
		}
	}

	return r;

}

Node* BST::returnVal() {
	return _returnVal(root);
}

Node* BST::_returnVal(Node* r) {
	return r;
}

Node* BST::FindMax(Node* r) {
	if (r == NULL)
		return r;

	while (r->right)
		r = r -> right;

	return r;
}

// AVL 

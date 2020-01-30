// BinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Please do not use this file. It is buggy. 

#include <iostream>
#include "Node.h"
using namespace std;
int curr = -1;

void printOptions() {
	string separator = "______________/^\\______________";
	cout << "\n\n\n";
	cout << separator << "\n";
	cout << "0. Quit       " << "\n";
	cout << "1. Add node   " << "\n";
	cout << "2. Remove node" << "\n";
	cout << "3. Search     " << "\n";
	cout << "4. Print Tree " << "\n";
	cout << separator << endl;
}
//root = the node, data = data for the initial node
int findNextHighestOne(Node* root, int data, int currMax) { //-1000
	if (root == nullptr) {
		return -1;
	}
	int retval = -999;
	if (root->left != nullptr) {
		if (root->data < data)retval = root->data;
		retval = findNextHighestOne(root->left,data,retval);
	}
	if (root->right != nullptr && root->right->data<data) {
		int temp = findNextHighestOne(root->right, data, retval) < data;
		if(temp<data && temp>retval)retval = temp;
	}
	return retval;
}

void addNode(Node* root, int data) {
	if (data == root->data){
		cout << "Provided value already in tree. Returning with no changes made." << endl;
	}
	else {
		if (data > root->data) {
			if (root->right == nullptr) {
				root->right = new Node(data);
			}
			else {
				addNode(root->right, data);
			}
		}
		else {
			if (root->left == nullptr) {
				root->left = new Node(data);
			}
			else {
				addNode(root->left, data);
			}
		}
	}
	return;
}

void pruneTree(Node* root, int n) {
	if (root == nullptr) {
		return;
	}
	else {
		if (root->left != nullptr && root->left->data != n) {
			pruneTree(root->left,n);
		}
		else {
			root->left = nullptr;
		}
		if (root->right != nullptr && root->right->data != n) {
			pruneTree(root->right,n);
		}
		else {
			root->right = nullptr;
		}
	}
}

//in-order
void printTree(Node* root) {
	if (root == nullptr) {
		cout << "Empty tree." << endl;
		return;
	}
	if (root->left != nullptr) {
		printTree(root->left);
	}
	cout << root->data;
	if (root->right != nullptr) {
		printTree(root->right);
	}
	return;
}
void printpreTree(Node* root) {
	if (root == nullptr) {
		cout << "Empty tree." << endl;
		return;
	}
	cout << root->data;
	if (root->left != nullptr) {
		printpreTree(root->left);
	}
	if (root->right != nullptr) {
		printpreTree(root->right);
	}
	return;
}

void printpostTree(Node* root) {
	if (root == nullptr) {
		cout << "Empty tree." << endl;
		return;
	}
	if (root->left != nullptr) {
		printpreTree(root->left);
	}
	if (root->right != nullptr) {
		printpreTree(root->right);
	}
	cout << root->data;
	return;
}

void search(Node* root, int data) {
	if (root == nullptr) {
		cout << "Empty tree." << endl;
		return;
	}
	if (root->data == data) {
		cout << data << " was found!";
		return;
	}
	if (root->data < data) {
		if (root->right != nullptr) {
			search(root->right, data);
		}
		else {
			cout << data << " was not found.";
		}
	}
	else {
		if (root->left != nullptr) {
			search(root->left, data);
		}
		else {
			cout << data << " was not found.";
		}
	}
	return;
}
int nextHighestInWholeTree(Node* root, int max) {
	if (root == nullptr) {
		return curr;
	}
	if (root->left != nullptr) {
		return nextHighestInWholeTree(root->left, max);
	}
	if (root->data > curr&& root->data < max)curr = root->data;
	if (root->right != nullptr) {
		return nextHighestInWholeTree(root->right, max);
	}
	return -1;
}

Node* findNode(Node* root, int data) {
	if (root == nullptr) {
		cout << "Empty tree." << endl;
		return nullptr;
	}
	if (root->data == data) {
		return root;
	}
	if (root->data < data) {
		if (root->right != nullptr) {
			return findNode(root->right, data);
		}
		else {
			cout << data << " was not found.";
			return nullptr;
		}
	}
	else {
		if (root->left != nullptr) {
			return findNode(root->left, data);
		}
		else {
			cout << data << " was not found.";
			return nullptr;
		}
	}
}

Node* findNodeAbove(Node* root, int data) {
	if (root == nullptr || (root->left == nullptr && root ->right == nullptr)) {
		return nullptr;
	}
	if ((root->left != nullptr && root->left->data == data) or (root->right != nullptr and root->right->data == data)) {
		return root;
	}
	if (root->data < data) {
		if (root->right != nullptr) {
			return findNodeAbove(root->right, data);
		}
		else {
			return nullptr;
		}
	}
	else {
		if (root->left != nullptr) {
			return findNodeAbove(root->left, data);
		}
		else {
			return nullptr;
		}
	}
}

Node* removeNode(Node* root, int data) {
	Node* copy = findNode(root, data);
	if (copy == nullptr)return nullptr;
	if (copy->left == nullptr && copy->right == nullptr) {
		if (copy->data == root->data) {
			cout << copy->data << " " << root->data << endl;
			root->left = nullptr;
			root->right = nullptr;
			root->data = -999;
			return nullptr;
		}
		Node* temp = findNodeAbove(root, copy->data);
		if (temp->left != nullptr && temp->left->data == data)temp->left = nullptr;
		if (temp->right != nullptr  && temp->right->data == data)temp->right = nullptr;
		delete(copy); //it's a leaf
	}
	else {//not trivialest case
		if (copy->left == nullptr ^ copy->right == nullptr) { //it's the root
			if (copy->data == root->data) {
				if (copy->left == nullptr) {
					root->data = root->right->data;
					root->right = root->right->right;
					delete(root->right);
				}
				if (copy->right == nullptr) {
					root->data = root->left->data;
					root->left = root->left->left;
					delete(root->left);
				}
			}
			if (copy->left == nullptr) { //arbitrary non-leaf with 1 child
				Node* temp = findNodeAbove(root, copy->data);
				if (temp->left == copy) {
					temp->left = temp->left->right;
				}
				else {
					temp->right = temp->right->right;
				}
				return root;
			}
			if (copy->right == nullptr) { //arbitrary non-leaf with 1 child
				Node* temp = findNodeAbove(root, copy->data);
				if (temp->left == copy) {
					temp->left = temp->left->left;
				}
				else {
					temp->right = temp->right->left;
				}
				return root;
			}

		}
		if (copy->left != nullptr && copy->right != nullptr) {
			curr = -1;
			nextHighestInWholeTree(root, copy->data);
			int nextHighest = curr;
			cout << "next in line: " << nextHighest<<endl;
			Node* temp = findNode(root, nextHighest);
			removeNode(temp, nextHighest);
			root->data = nextHighest;
		}
	}
	return nullptr;
}


int main()
{
	int choice = -2;
	Node* root = nullptr;
	while (choice != 0) {
		choice = -2;
		printOptions();
		while (choice < 0 or choice>4) {
			cin >> choice;
		}
		int data = -1;
		switch (choice)
		{
		case 1: cout << "Payload?" << endl;
			cin >> data;
			if (root == nullptr) {
				root = new Node(data);
			}
			else {
				addNode(root, data);
			}
			break;

		case 2: cout << "Which node?" << endl;
			cin >> data;
			removeNode(root, data);
			if (root->data == -999)root = nullptr;
			pruneTree(root, -999);
			break;
		case 3: cout << "Which node?" << endl;
			cin >> data;
			search(root, data);
			break;
		case 4: printTree(root);
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

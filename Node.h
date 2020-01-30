#pragma once
#include<string>
class Node {
public:
	Node* left;
	Node* right;
	int data;
	Node(int s) {
		data = s;
	}
};
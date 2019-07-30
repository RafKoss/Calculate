#pragma once
#include "Node.h"
#include <iostream>
class Tree
{
private:
	Node * root;
	Node * lastPushed;
	std::string infixExpression;
	void insert(std::string data, Node * node);
	void print(Node * node, int space);
	void readInfix(Node * node);

public:
	Tree();
	~Tree();

	void insert(std::string data);
	void print();
	void readInfix();
	int calculate();
	std::string getInfix();
};


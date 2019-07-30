#include "pch.h"
#include "Node.h"


Node::Node(std::string d)
{
	data = d;
	left = nullptr;
	right = nullptr;
	parent = nullptr;
}

void Node::setData(std::string d)
{
	data = d;
}

void Node::setLeft(Node * l)
{
	left = l;
}

void Node::setRight(Node * r)
{
	right = r;
}

Node* Node::getLeft()
{
	return left;
}

Node* Node::getRight()
{
	return right;
}

Node* Node::getParent()
{
	return parent;
}

std::string Node::getData()
{
	return data;
}

void Node::setParent(Node * p)
{
	parent = p;
}

bool Node::isSign()
{
	if (data == "*" || data == "/" || data == "+" || data == "-")
		return true;
	else
		return false;
}

Node::~Node()
{
}

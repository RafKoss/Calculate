#pragma once
#include <string>

class Node
{
private:
	Node * left;
	Node * right;
	Node * parent;
	std::string data;
public:
	Node(std::string d);
	
	Node* getLeft();
	Node* getRight();
	Node * getParent();
	std::string getData();
	void setData(std::string d);
	void setLeft(Node * l);
	void setRight(Node * r);
	void setParent(Node * p);

	bool isSign();
	~Node();
};


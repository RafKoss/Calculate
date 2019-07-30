#include "pch.h"
#include "Tree.h"
using namespace std;

Tree::Tree()
{
	root = nullptr;
	lastPushed = nullptr;
	infixExpression.clear();
}


Tree::~Tree()
{
}

void Tree::insert(std::string data) //zmerguj te dwa insert!
{
	if (root == nullptr)
	{
		root = new Node(data);
		lastPushed = root;
	}
		
	else
		insert(data, lastPushed);
}


void Tree::insert(std::string data, Node * node) // paramet node niepotrzebny?
{
	if (lastPushed->isSign() == true) //jeœli ostatnio wstawiono znak, to wstawiamy wg³¹b
	{
		if (node->getLeft() == nullptr) //je¿eli node pusty, wstawiamy w lewo
		{
			Node * tempNode = new Node(data);
			node->setLeft(tempNode);
			tempNode->setParent(node);
			lastPushed = tempNode;
			//delete tempNode;
			//return?
		}
		else if (node->getRight() == nullptr)
		{
			Node * tempNode = new Node(data);
			node->setRight(tempNode);
			tempNode->setParent(node);
			lastPushed = tempNode;
			//delete tempNode;
		}
		else
		{
			lastPushed = node->getParent();
			insert(data, lastPushed);
		}

	}
	else
	{
		lastPushed = node->getParent();
		insert(data, lastPushed);
	}
}


void Tree::print()
{
	print(root, 0);
}

void Tree::print(Node * node, int space)
{
	if (node == nullptr)
		return;

	space += 5;
	print(node->getRight(), space);

	cout << endl;
	for (int i = 0; i < space; i++)
		cout << " ";
	
	cout << node->getData()<<endl;

	print(node->getLeft(), space);

}

void Tree::readInfix()
{
	readInfix(root);
	infixExpression.erase(infixExpression.begin());
	infixExpression.pop_back();
	infixExpression.pop_back();
	for (int i = 0; i < infixExpression.size(); i++)
	{
		cout << infixExpression[i];
	}
}


void Tree::readInfix(Node * node)
{
	if (node != nullptr)
	{
		infixExpression.append("(");
		readInfix(node->getLeft());
		infixExpression.pop_back();
		infixExpression.append(node->getData());
		readInfix(node->getRight());
		infixExpression.append(")");
	}
	
}

int Tree::calculate()
{
	int x = stoi(infixExpression);
	return x;
}

string Tree::getInfix()
{
	return infixExpression;
}

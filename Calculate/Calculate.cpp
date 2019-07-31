// Calculate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Tree.h"
#include "Functions.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char*argv[])
{
	vector<string> dataVector;
	string temp;
	//pobieranie danych z pliku
	ifstream file;
	file.open("input.txt", ifstream::in);
	if (file.is_open())
	{
		getline(file, temp);
		stringstream line(temp);

		while (getline(line, temp, ' '))
		{
			if (!valid(temp))
			{
				cout << "Nieprawidlowe dane\n";
				return 0;
			}
			if (isArgument(temp))
			{
				getline(file, temp);
			}

			dataVector.push_back(temp);
		}
		if(!(dataVector[0] == "+" || dataVector[0] == "-" || dataVector[0] == "*" || dataVector[0] == "/")) //pierwszy znak nie jest operatorem
			{
					cout << "Nieprawidlowe wyrazenie\n";
					return 0;
			}
			
		file.close();
	}
	else
	{
		cout << "Blad otwarcia pliku\n";
	}
	
	if (!checkExpression(dataVector))
	{
		cout << "Nieprawidlowe wyrazenie";
		return 0;
	}

	cout << "Wstepne wyrazenie prefix:\n";
	for (int i = 0; i < dataVector.size(); i++)
	{
		cout<<dataVector[i]<<" ";
	}
	

	//wpisywanie danych do drzewa
	Tree binaryTree = Tree();
	for (int i = 0; i < dataVector.size(); i++)
	{
		binaryTree.insert(dataVector[i]);
	}

	cout << "\n\nDrzewo:";
	binaryTree.print();

	cout << "\n\nWyrazanie infix:\n";
	binaryTree.readInfix();

	string expression = binaryTree.getInfix();

	cout << "\n\nPrzetwarzanie wyrazenia:";
	while (!isNumber(expression))
	{
		expression = reduceExpression(expression);
		cout << endl;
		for (int i = 0; i < expression.size(); i++)
		{
			cout << expression[i];
		}
	}

	cout << "\n\nWynik wyrazenia:\n";
	for (int i = 0; i < expression.size(); i++)
	{
		cout << expression[i];
	}
}
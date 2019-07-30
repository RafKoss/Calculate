// Calculate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Tree.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

bool valid(string);

bool isNumber(string);

bool isArgument(string);

string searchBracket(string);

int searchOperator(string);

int calculate(string, string, char);

string editString(string str, int begin, int end, int value);

int main()
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
			//cout << temp << endl;
		}
		if(!(dataVector[0] == "+" || dataVector[0] == "-" || dataVector[0] == "*" || dataVector[0] == "/")) //pierwszy znak nie jest operatorem
			{
					cout << "Nieprawidlowe dane\n";
					return 0;
			}
			
		file.close();
	}
	else
	{
		cout << "Blad otwarcia pliku\n";
	}
	
	//wpisywanie danych do drzewa
	Tree binaryTree = Tree();
	for (int i = 0; i < dataVector.size(); i++)
	{
		binaryTree.insert(dataVector[i]);
	}


	binaryTree.print();

	binaryTree.readInfix();

	string expression = binaryTree.getInfix();

	while (!isNumber(expression))
	{
		expression = searchBracket(expression);
		cout << endl;
		for (int i = 0; i < expression.size(); i++)
		{
			cout << expression[i];
		}
	}
}

bool valid(string str)
{
	if (str == "+" || str == "-" || str == "*" || str == "/" || str == "x")
		return true;
	else if (isNumber(str))
		return true;

	return false;
}

bool isNumber(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

bool isArgument(string str)
{
	if (str == "x")
		return true;
	return false;
}

string searchBracket(string str)
{
	int begin = 0;
	int end = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			begin = i;
		}

		if (str[i] == ')')
		{
			end = i;
			break;
		}
	}
	string innerStr;
	if (begin == 0 && end == 0)
	{
		innerStr = str;
		end = str.length();
	}
	else
		innerStr = str.substr(begin + 1, end - begin - 1);	
	string result = editString(str, begin, end, searchOperator(innerStr));
	return result;
}

int searchOperator(string str)
{
	int position = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-')
		{
			position = i;
			break;
		}
	}

	string str1 = str.substr(0, position); //pierwsza liczba
	string str2 = str.substr(position+1); //druga liczba
	char sign = str[position];
	
	return calculate(str1, str2, sign);
}

int calculate(string str1, string str2, char sign)
{
	int a = stoi(str1);
	int b = stoi(str2);
	int result = 0;

	switch (sign)
	{
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		result = a / b;
		break;
	}

	return result;
}
string editString(string str, int begin, int end, int value)
{
	str.replace(begin, end-begin+1, to_string(value));
	return str;
}

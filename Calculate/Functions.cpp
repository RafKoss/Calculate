#include "pch.h"
#include "Functions.h"

bool checkExpression(vector<string> vec)
{
	int size;
	for (int i = vec.size() - 1; i >= 0; i--)
	{
		if (isSign(vec[i]))
		{
			size = vec.size();
			if (i > size - 3) //pozcja znaku za bardzo na prawo - operator bez wystarczaj¹cej liczby arg
				return false;
			else if (vec[i] == "/")
			{
				if (vec[i + 1] == "0") //dzielenie przez 0
					return false;
			}
			else if (isNumber(vec[i + 1]) && isNumber(vec[i + 2]))
			{
				vec.erase(vec.begin() + i); //udajemy, ze wewnetrzne wyrazenie jest wyliczone, zastepujemy + 1 2 jedn¹ liczb¹, np. 2
				vec.erase(vec.begin() + i);
			}
			else
				return false;
		}
		else
		{
			continue;
		}
	}
	if (vec.size() != 1)
		return false;

	return true;
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
		{
			if (i == 0 && str[i] == '-')
				continue;
			return false;
		}
			
	}
	return true;
}

bool isSign(string str)
{
	if (str == "*" || str == "/" || str == "+" || str == "-")
		return true;
	else
		return false;
}

bool isArgument(string str)
{
	if (str == "x")
		return true;
	return false;
}

string reduceExpression(string str)
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
	string result = editString(str, begin, end, calculate2ArgExpression(innerStr));
	return result;
}

int calculate2ArgExpression(string str)
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
	string str2 = str.substr(position + 1); //druga liczba
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
	str.replace(begin, end - begin + 1, to_string(value));
	return str;
}

#include <string>
#include <vector>
using namespace std;

bool valid(string); //sprawdzanie poprawnosci danych w pliku
bool checkExpression(vector<string> vec); //sprawdzanie poprawnosci wyra¿enia
bool isNumber(string); //sprawdzanie czy argument jest liczb¹
bool isSign(string); //sprawdzanie czy argument jest znakiem
bool isArgument(string); //sprawdzanie czy argument jest argumenem wyrazenia
string reduceExpression(string); // znajduje wyra¿enie o 2 argumentach w wewnêtrznych nawiasach, zwraca wyra¿enie zredukowane
int calculate2ArgExpression(string); // znajude i oblicza wyra¿enie o 2 argumentach np 2+3
int calculate(string, string, char); //obliczanie wyra¿enia
string editString(string str, int begin, int end, int value); //edycja stringa
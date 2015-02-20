#include <iostream>
#include <string>

using namespace std;

string encrypt(const string& text, unsigned int rail);
string decrypt(const string& text, unsigned int rail);

int main()
{
	string text;
	cout << "Podaj tekst do zaszyfrowania: ";
	cin >> text;
	cout << "Podaj klucz: ";
	int key;
	cin >> key;
	string encrypted = encrypt(text, key);
	cout << "Tekst po zaszyfrowaniu: " << encrypted << endl;
	cout << "Podaj tekst do odszyfrowania: ";
	cin >> text;
	cout << "Podaj klucz: ";
	cin >> key;
	string decrypted = decrypt(text, key);
	cout << "Tekst po odszyfrowaniu: " << decrypted << endl;
}

string encrypt(const string& text, unsigned int rail)
{
	string *temp = new string[rail];
	int number = 0;
	int inc = 1;
	for (auto ch : text)
	{
		if (number + inc == rail) 
		{
			inc = -1;
		}
		else if (number + inc == -1)
		{
			inc = 1;
		}
		temp[number].push_back(ch);
		number += inc;
	}
	string result;
	for (unsigned int i = 0; i < rail; ++i)
	{
		result += temp[i];
	}
	delete[] temp;
	return result;
}

string decrypt(const string& text, unsigned int rail)
{
	string *temp = new string[rail];
	int number = 0;
	int inc = 1;
	for (unsigned int i = 0; i < text.length(); ++i)
	{
		if (number + inc == rail)
		{
			inc = -1;
		}
		else if (number + inc == -1)
		{
			inc = 1;
		}
		temp[number].push_back(i);
		number += inc;
	}

	int counter = 0;
	string result;
	result.resize(text.length());
	for (unsigned int i = 0; i < rail; i++)
	{
		for (unsigned int j = 0; j < temp[i].size(); ++j)
		{
			int index = temp[i][j];
			result[index] = text[counter];
			++counter;
		}
	}
	delete[] temp;
	return result;
}
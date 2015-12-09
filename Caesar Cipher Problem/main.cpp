#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string caesarCipherR(string code, int shiftAmt); // shifts right
string caesarCipherL(string code, int shiftAmt); // shifts left
string upperCaseToLowerCase(string code); // converts any uppercase letters in a string to lowercase letter

int main()
{
	string startCode = "EXXegoexsrgI"; // cipher string example was gotten from Wikipedia, so that I had test cases that could test that I knew were correct
	int x(1), y(4), z(25), a(27);
	string protectedCodeX = caesarCipherR(startCode, x);
	cout << protectedCodeX << endl; // prints fyyfhpfytshj

	string protectedCodeY = caesarCipherR(startCode, y);
	cout << protectedCodeY << endl; // prints ibbiksibwvkm

	string protectedCodeZ = caesarCipherR(startCode, z);
	cout << protectedCodeZ << endl;  // prints dwwdfndwrqfh

	string protectedCodeA = caesarCipherR(startCode, a);
	cout << protectedCodeA << endl; // prints fyyfhpfytshj
	system("pause");





	string protectedCodeXX = caesarCipherL(startCode, 1);
	cout << protectedCodeXX << endl; // prints dwwdfndwrqfh

	string protectedCodeYY = caesarCipherL(startCode, 4);
	cout << protectedCodeYY << endl; // prints attackatonce

	string protectedCodeZZ = caesarCipherL(startCode,5);
	cout << protectedCodeZZ << endl;  // prints zsszbjzsnmbd

	string protectedCodeAA = caesarCipherL(startCode, -1);
	cout << protectedCodeAA << endl; // prints fyyfhpfytshj
	system("pause");

}

string caesarCipherR(string code, int shiftAmt)
{
	string newCode = upperCaseToLowerCase(code); // uppercase letters are converted to lowercase letters
	vector<char> stringCharacters(newCode.begin(), newCode.end());
	vector<int> numbersForString;

	if (shiftAmt < 0)
	{
		shiftAmt = shiftAmt + 26; // deals with negative shift amounts
	}

	for (int i = 0; i < stringCharacters.size(); i++)
	{
		int valueOfChar = (stringCharacters[i] - 'a') + 1;
		numbersForString.push_back(valueOfChar);
	}

	stringCharacters.clear();

	for (int i = 0; i < numbersForString.size(); i++)
	{

			numbersForString[i] = ((numbersForString[i] + shiftAmt) % 26) ;

			char newCharacter = 'a' - 1 + numbersForString[i];
			if (newCharacter == '`')  // edge case for when characters are the exact shift amount away from the end of the alphabet
			{
				newCharacter = 'a' + numbersForString[i];
			}
			stringCharacters.push_back(newCharacter);
	}


	string finalString(stringCharacters.begin(), stringCharacters.end()); // recreates the string using the vector of updated values
	return finalString;
}

string caesarCipherL(string code, int shiftAmt)
{
	int offset = 26 - shiftAmt;  // offset helps to avoid using absolute value, and subtraction in later logic
	string newCode = upperCaseToLowerCase(code);
	vector<char> stringCharacters(newCode.begin(), newCode.end());
	vector<int> numbersForString;

	if (shiftAmt < 0)
	{
		shiftAmt = shiftAmt + 26; // deals with if negative
	}

	for (int i = 0; i < stringCharacters.size(); i++)
	{
		int valueOfChar = (stringCharacters[i] - 'a') + 1; // converts each of the characters to a number 1-26
		numbersForString.push_back(valueOfChar);
	}

	stringCharacters.clear();

	for (int i = 0; i < numbersForString.size(); i++)
	{

		numbersForString[i] = ((numbersForString[i] + offset) % 26);

		char newCharacter = 'a' - 1 + numbersForString[i]; // conversion from number to character, after the shift amount has been added
		
		if (newCharacter == '`') // edge case for when characters are the exact shift amount away from the beginning of the alphabet
		{
			newCharacter = 'z';
		}
		stringCharacters.push_back(newCharacter);
	}


	string finalString(stringCharacters.begin(), stringCharacters.end()); // recreates the string using the vector of updated values
	return finalString;
}

string upperCaseToLowerCase(string code)
{
	vector<char> inputString(code.begin(), code.end());
	vector<char> outputString;
	for (int i = 0; i < inputString.size(); i++)
	{
		if (inputString[i] >= 65 && inputString[i] <= 90) // converts uppercase letters into lowercase letters
		{
			char newChar = inputString[i] + 32;
			outputString.push_back(newChar);
		}
		else
			outputString.push_back(inputString[i]);
	}

	string lowerCaseString(outputString.begin(), outputString.end());
	return lowerCaseString;
}
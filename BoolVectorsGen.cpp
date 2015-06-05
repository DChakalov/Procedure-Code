//ZAD.1_Domashno 5

#include<iostream>
#include<string.h>

using namespace std;

void GetVector(char* stars, int numberOfStars);
void GenerateVectors(int numberOfStars, char* stars, int index);

const int maxLength = 100;

char* strCopy;
char str[maxLength];
char** finalPermsArr;

int numberOfVectors = 0;
int strLength = 0;
int currentPerm = 0;
int allPerms = 2;

int main()
{
	cout << "Enter string: " << endl;
	cin >> str;
	int numberOfStars = 0;
	strLength = strlen(str);

	strCopy = new char[strLength];
	
	for (size_t i = 0; i < strLength; i++)
	{
		if(str[i] == '*') numberOfStars++;

		if (str[i] != '1' && str[i] != '0' && str[i] != '*')
		{
			cout << "Invalid string!\nEnter new string: " << endl;	
			cin >> str;
		}
	}

	for (size_t i = 1; i < numberOfStars; i++)
	{
		allPerms *= 2;
	}

	finalPermsArr = new char*[allPerms + 1];

	for (size_t i = 0; i < allPerms+1; i++)
	{
		finalPermsArr[i] = new char[strLength];
	}

	char* stars;
	stars = new char[numberOfStars];
	GenerateVectors(numberOfStars, stars, 0);

	//cout << numberOfVectors << endl;
	cout << endl;
	cout << "All possible ways are: " << endl;

	for (size_t i = 0; i < allPerms; i++)
	{
		for (size_t j = 0; j < strLength; j++)
		{
			cout << finalPermsArr[i][j];
		}
		cout << endl;
	}

	delete[] stars;
	delete[] strCopy;

	for (size_t i = 0; i < allPerms; i++)
	{
		delete[] finalPermsArr[i];
	}

	delete[] finalPermsArr;

	return 0;
}

void GenerateVectors(int numberOfStars, char* stars, int index)
{
	if (index > numberOfStars-1)
	{
		numberOfVectors++;
		GetVector(stars, numberOfStars);
	}
	else
	{
		for (char i = '0'; i <= '1'; i++)
		{
			stars[index] = i;
			GenerateVectors(numberOfStars, stars, index + 1);
		}
	}

	return;
}

void GetVector(char* stars, int numberOfStars)
{
	int br = 0, index = 0;
	int length = strLength;

	while (length)
	{
		if (str[index] == '*')
		{
			strCopy[index] = stars[br];
			br++;
		}
		else
		{
			strCopy[index] = str[index];
		}

		length--;
		index++;
	}

	for (size_t col = 0; col < strLength; col++)
	{
		finalPermsArr[currentPerm][col] = strCopy[col];
	}

	currentPerm++;

	return;
}


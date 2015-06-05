//ZAD.3 Domashno 4.

#include<iostream>
#include<string.h>

using namespace std;

int countOfWord = 0;
int allSymbolsInRevSen = 0;
char* revSen;
int currentSymbolInRevSen = 0;

int FindNumberOfWordInSen(char* sentence);
void IsExistInDictonary(char* sentence, char** dictonary, int n);
void ReverseWord(char* word);
void ConstructReversedSentence();

int main()
{
	cout << "Enter number of words in dictonary: ";
	int n = 0;
	cin >> n;

	char** dictonary;
	dictonary = new char*[n];
	revSen = new char[n * 16];

	cout << "Enter words with max length 16 symbols:" << endl;
	cin.ignore();

	for (int i = 0; i < n; ++i)
	{
		dictonary[i] = new char[16];
		cin.getline(dictonary[i], 16);
	}
	
	cout << "Enter sentence:" << endl;
	int maxSymbols = 500;

	char* sentence;
	sentence = new char[maxSymbols];
	cin.getline(sentence, maxSymbols-1);
	sentence[strlen(sentence) - 1] = ' ';
	

	IsExistInDictonary(sentence, dictonary, n);
	
	for (size_t i = 0; i < n; i++)
	{
		delete[] dictonary[i];
	}

	delete[] dictonary;
	delete[] sentence;
	delete[] revSen;

	return 0;
}

void IsExistInDictonary(char* sentence, char** dictonary, int n)
{
	bool existWord = true;
	char* currentWord;
	currentWord = new char[strlen(sentence)];
	size_t i = 0, j = 0, index = 0;
	while (j < strlen(sentence))
	{
		while (sentence[j] != ' ')
		{
			currentWord[index] = sentence[j];
			index++;
			j++;
		}
		int sadadas = 0;
		index = 0;
		j++;

		for (i = 0; i < n; i++)
		{
			if (!strncmp(currentWord, dictonary[i], strlen(dictonary[i])-1))
			{
				ReverseWord(dictonary[i]);
			}
		}
	}

	ConstructReversedSentence();
}

void ReverseWord(char* currentWord)
{
	char currentChar = ' ';
	char* revWord;
	revWord = new char[strlen(currentWord)];
	size_t i = 0;
	countOfWord++;
	allSymbolsInRevSen += strlen(currentWord)+1;

	for (i = 1; i <= strlen(currentWord); i++)
	{
		revWord[i-1] = currentWord[strlen(currentWord) - i];
		revSen[currentSymbolInRevSen] = revWord[i-1];
		currentSymbolInRevSen++;
	}

	revSen[currentSymbolInRevSen] = ' ';
	currentSymbolInRevSen++;

	delete[] revWord;

	return;
}

void ConstructReversedSentence()
{
	char* newReversedSentence;
	newReversedSentence = new char[allSymbolsInRevSen+5];

	for (size_t j = 0; j < allSymbolsInRevSen; j++)
	{
		newReversedSentence[j] = revSen[j];
		cout << newReversedSentence[j];
	}

	cout << endl;

	delete[] newReversedSentence;

	return;
}


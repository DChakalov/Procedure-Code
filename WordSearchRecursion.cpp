//ZAD.1 Domashno 4.

#include<iostream>
#include<string.h>

using namespace std;

void RestoreElements(char matr[][100], char helpMatrix[][100], int copyVar, int M, int N);
int FindFirstChar(char helpMatrix[][100], char* word, int N, int M);
int IsExistWord(char helpMatrix[][100], int N, int M, char* word, int currentElX, int currentElY, int currentSymbol);

int main()
{
	cout << "Enter size of matrix: ";
	int N = 0, M = 0;
	cin >> N;
	cin >> M;

	cout << "Enter number of words: ";
	int numberOfWords = 0;
	cin >> numberOfWords;
	cout << endl;

	char matrix[100][100];
	char helpMatrix[100][100];
	char copyVar = ' ';

	char* word;
	word = new char[N*M];

	cout << "Enter elements of matrix:" << endl;

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			cin >> matrix[i][j];
			copyVar = matrix[i][j];
			helpMatrix[i][j] = copyVar;
		}
	}

	cout << endl;
	for (size_t i = 0; i < numberOfWords; i++)
	{
		cin >> word;

		if (FindFirstChar(helpMatrix, word, N, M))
		{
			cout << "YES" << endl;

		}
		else
		{
			cout << "NO" << endl;
		}

		RestoreElements(matrix, helpMatrix, copyVar, N, M);
	}

	delete[] word;
	
	return 0;
}
void RestoreElements(char matrix[][100], char helpMatrix[][100], int copyVar, int N, int M)		//Vyzstanovqvame izpozvanite simvoli v tablicata, 
{																								//za da zapochnem tyrsenoto na sledvashtata duma.
	for (size_t row = 0; row < N; row++)
	{
		for (size_t col = 0; col < M; col++)
		{
			copyVar = matrix[row][col];
			helpMatrix[row][col] = copyVar;
		}
	}
}

int FindFirstChar(char helpMatrix[][100], char* word, int N, int M)  //Tyrsim pyrviq simvol ot podadenata duma.
{
	char firstChar = ' ';
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			if (word[0] == helpMatrix[i][j])                          
			{
				firstChar = helpMatrix[i][j]; helpMatrix[i][j] = '0';   //Namerim li go, vremenno go promenqme, kato go pazim v druga promenliva, 
				if (IsExistWord(helpMatrix, N, M, word, i, j, 1))   // za da ne se vyrnem pak na nego, dokyto tyrsim ostanalite simvoli.
				{
					return 1;
				}
				helpMatrix[i][j] = firstChar;                    // Tuk vyzstanovqvame pyrviq element na tekushtata duma, 
			}												// zashtoto moje da potrqbva v sledvashtite dumi.
		}
	}

	return 0;
}

int IsExistWord(char helpMatrix[][100], int N, int M, char* word, int currentElX, int currentElY, int currentSymbol)
{
	if (currentSymbol >= strlen(word))		 // Ako promenlivata "currentSymbol" e ravna na dyljinata na dumata, 
	{										// to tq e namerena.
		return 1;
	}

	int possibleCoordX = 0;
	int possibleCoordY = 0;
	char currentChar = ' ';
	bool inOrders = false;

	int eightPossDirections[8][2] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 },		// Tova sa edinstvenite vyjmojni mesta,
										{ 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 } };		// kydeto mojem da potyrsim sledvashtiq element, v nai obshirniq sluchai te sa 8.

	for (int i = 0; i < 8; i++)
	{
		possibleCoordX = currentElX + eightPossDirections[i][0];        // Tova sa vyzmojnite indeksi na simvola 
		possibleCoordY = currentElY + eightPossDirections[i][1];		// koito tyrsim

		inOrders = possibleCoordX < N && possibleCoordX >= 0           // S promenlivata "inOrders" proverqvame  
					&& possibleCoordY < M && possibleCoordY >= 0;     // dali sme v granicite na matricata.

		if (inOrders && helpMatrix[possibleCoordX][possibleCoordY] == word[currentSymbol])
		{
			currentChar = helpMatrix[possibleCoordX][possibleCoordY];             //Zapazvame stoinostta na namereniq simvol.
			helpMatrix[possibleCoordX][possibleCoordY] = '0';			          // Promenqme stoinostta mu za da ne se cyrnem na nego, dokyto tyrsi ostanalie simvoli ot dumata
																		          //dokyto tyrsi ostanalie simvoli ot dumata.

			if (IsExistWord(helpMatrix, N, M, word, possibleCoordX, possibleCoordY, currentSymbol + 1))			//Izvikvame rekursivno metoda 
			{																									//s parametrite na noviq simvol, za da namerim sledvashtiq. 
				return 1;
			}

			helpMatrix[possibleCoordX][possibleCoordY] = currentChar;
		}
	}
	
	return 0;
}

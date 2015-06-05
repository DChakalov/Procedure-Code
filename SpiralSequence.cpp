/*ZAD_3. Napishete programa, koqto chete cqlo polojitelno chislo N, kydeto 2<N<128 i
sled tova syzdava matrica s razmer NxN, koqto sydyrja chislata ot 1 do N^2.
Obhodete matricata, zapochvaiki ot gorniq lqv ygyl, spiralovidno i izvedete
rezultata na ekrana.

Ideqta e da se dvijim po elementite na zadadenata matrica, s promenliva v koqto
pazim posokata po koqto se dvijim i pri nujda smenqme stoinostta (posokata).
Nachalnata stoinost na tazi promenliva e "right" (ili "r","l","u","d"), kakto e po uslovie. Izpolzvat se dve matrici
kato v ednata elementite se podrejdat v spiraloviden red, a drugata e standartna, kakto primernata v uslovieto*/

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int n = 0;

void EnterElementsOfMatrix(int** matrix, int** emptyMatrix, int currElement);
void PrintMatrix(int row, int col, int** matrix);
void generateSpiralOrder(int** matrix, int** emptyMatrix, int* rowsCoordinates, int* colsCoordinates, char* direction, int row, int col);


int main()
{

	cout << "Enter size of two dimensional array: ";
	cin >> n;
	bool validN = n > 2 && n < 128;

	if (!validN)
	{
		cout << "Invalid input!" << endl;
		return 1;
	}

	cout << endl;

	int** matrix;
	matrix = new int*[n];
	int** emptyMatrix;
	emptyMatrix = new int*[n];

	char direction[] = "r";

	int* rowsCoordinates;
	rowsCoordinates = new int[n*n];		 // V "rowsCoordinates" i "colsCoordinates" pazim koordinatite 
	int*colsCoordinates;				// za spiralovidnoto obhojdane na matricata "matrix".
	colsCoordinates = new int[n*n];

	int row = 0, col = 0, currElement = 1;

	for (size_t i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
		emptyMatrix[i] = new int[n];
	}

	EnterElementsOfMatrix(matrix, emptyMatrix, currElement);
	PrintMatrix(row, col, matrix);
	generateSpiralOrder(matrix, emptyMatrix, rowsCoordinates, colsCoordinates, direction, row, col);

	cout << endl;

	delete[] matrix;
	delete[] emptyMatrix;
	delete[] rowsCoordinates;
	delete[] colsCoordinates;

	return 0;
}

void EnterElementsOfMatrix(int** matrix, int** emptyMatrix, int currElement)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			matrix[i][j] = currElement;
			emptyMatrix[i][j] = 0;				// Zapylvame matricata "emptyMatrix" s nuli, 
			currElement++;						// zashtoto tova shte trqbva po nadolu, 
		}										// za da se proveri dali veche ima chislo na syotvetnoto 
	}											// mqsto ili nqma, i elementyt e raven na chisloto "0".

}

void PrintMatrix(int row, int col, int** matrix)
{
	for (row = 0; row < n; row++)
	{
		for (col = 0; col < n; col++)
		{
			cout << setw(3) << matrix[row][col];
		}
		cout << endl;
	}

}

void generateSpiralOrder(int** matrix, int** emptyMatrix, int* rowsCoordinates, int* colsCoordinates, char* direction, int row, int col)
{

	for (int rotateTimes = 1; rotateTimes <= n*n; rotateTimes++)
	{

		if (direction[0] == 'r')							// Vyv vynshnite "if" konstrukcii tuk i nadolu proverqvame kakva e momentnata posoka.
		{
			rowsCoordinates[rotateTimes - 1] = row;        // Zapisvame kordinatite po koito 
			colsCoordinates[rotateTimes - 1] = col;		  // shte byde obhodena matricata v dvata masiva "rowsCoordinates" i "colsCoordinates".
			emptyMatrix[row][col] = rotateTimes;
			col++;
			if (col == n - 1 || emptyMatrix[row][col + 1] != 0)			 // Tuk i pri vsichki podobni vlojeni proverki nadolu, 
			{															// proverqvame dali ne izlizame izvyn ramkite na matricata i														
				direction[0] = 'd';									   // ima li veche vyvedeno chislo na sledvshtata 	
			}														  // poziciq sprqmo momentnata posoka po koqto se dvijim, 	
		}															 // ako ima takyv element smenqme posokata.

		else if (direction[0] == 'd')
		{
			rowsCoordinates[rotateTimes - 1] = row;
			colsCoordinates[rotateTimes - 1] = col;
			emptyMatrix[row][col] = rotateTimes;
			row++;
			if (row == n - 1 || emptyMatrix[row + 1][col] != 0)
			{
				direction[0] = 'l';
			}

		}

		else if (direction[0] == 'u')
		{
			rowsCoordinates[rotateTimes - 1] = row;
			colsCoordinates[rotateTimes - 1] = col;
			emptyMatrix[row][col] = rotateTimes;
			row--;
			if (row == 0 || emptyMatrix[row - 1][col] != 0)
			{
				direction[0] = 'r';
			}

		}

		else if (direction[0] == 'l')
		{
			rowsCoordinates[rotateTimes - 1] = row;
			colsCoordinates[rotateTimes - 1] = col;
			emptyMatrix[row][col] = rotateTimes;
			col--;
			if (emptyMatrix[row][col - 1] != 0)
			{
				direction[0] = 'u';
			}
		}
	}

	cout << '\n' << "Elements in spiral order:\n";

	for (int j = 0; j < n*n; j++)
	{
		cout << matrix[rowsCoordinates[j]][colsCoordinates[j]] << " ";		// Izvejdame elementite po spiralovidniq nachin ot uslovieto s 
	}																	   // veche izvestnite koordinati.

}
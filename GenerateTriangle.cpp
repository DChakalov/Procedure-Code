//ZAD.3_Domashno 5

#include<iostream>

using namespace std;

void AllRows(int currentRow);
void RevAllRows(int currentRow);
int PrintElementsInRow(int currentRow, int elementsInRow);
int n;

int main()
{
	do
	{
		cout << "Enter valid \"n\": ";
		cin >> n;
	} while (n > 20 && n > 0);

	int currentRow = 1;
	AllRows(currentRow);

	currentRow = n-1;
	RevAllRows(currentRow);
	cout << endl;

	return 0;

}

void AllRows(int currentRow)
{
	if (currentRow > n)
	{
		return;
	}
	else
	{
		PrintElementsInRow(currentRow, 1);
		cout << endl;
		AllRows(currentRow + 1);
	}

	return;
}

int PrintElementsInRow(int currentRow, int elementsInRow)
{
	if (elementsInRow > currentRow)
	{
		return 1;
	}
	else
	{
		cout << elementsInRow << ' ';
		PrintElementsInRow(currentRow, elementsInRow + 1);
	}

	return 0;
}

void RevAllRows(int currentRow)
{
	if (currentRow <= 0)
	{
		return;
	}
	else
	{
		PrintElementsInRow(currentRow, 1);
		cout << endl;
		RevAllRows(currentRow - 1);
	}

	return;
}


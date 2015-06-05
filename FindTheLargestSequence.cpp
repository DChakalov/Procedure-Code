/*ZAD_2. Napishete programa, koqto chete ot konzolata cqlo polojitelno chislo N, kydeto 2<N<1024
i sled tova prochite N chisla. Namerete startoviq indeks i dyljinata na nai-dylgata ploshtadka v masiva.

Zabelejka: Vsqka poredica ot poredni ravni elementi narichame ploshtadka,
ako imame poveche ot edna ploshtadka s ednakva dyljina izvedete pyrvata namerena.*/

#include<iostream>

using namespace std;

void FindSequence(double* numbers, int n, int preStartIndex, int currStartIndex,
	int prelengthOfSeq, int currlengthOfSeq, int eqElementsIndex);

void PrintWantedSeq(double* numbers, int n, int preStartIndex, int prelengthOfSeq);

int main()
{
	cout << "Enter n of sequence: ";
	int n = 0;
	cin >> n;
	cout << "\nEnter elements: " << endl;
	bool validN = n > 2 && n < 1024 && cin;

	if (!validN)
	{
		cout << "Invalid input!" << endl;
		return 1;
	}

	double* numbers;
	numbers = new double[n];
	int eqElementsIndex = 0;

	int preStartIndex = 0;
	int currStartIndex = 0;
	int prelengthOfSeq = 1;
	int currlengthOfSeq = 1;

	for (int i = 0; i < n; ++i)
	{
		cin >> numbers[i];
	}

	FindSequence(numbers, n, preStartIndex, currStartIndex, prelengthOfSeq, currlengthOfSeq, eqElementsIndex);

	delete[] numbers;

	return 0;
}

void FindSequence(double* numbers, int n, int preStartIndex, int currStartIndex,
	int prelengthOfSeq, int currlengthOfSeq, int eqElementsIndex)
{
	for (int index = 1; index < n; ++index)
	{
		if (numbers[index - 1] == numbers[index])  //V sluchai, che popadnem na ravni chisla, zapochvame da gi smqtame za poredica.
		{
			eqElementsIndex = index;              // Zapazvame informaciqta, che imame nachalo na poredica.
			currStartIndex = index - 1;			 // Zapazvame nachalniq indeks na tekushtata poredicata.

			while (numbers[index - 1] == numbers[eqElementsIndex]) //Proverqvame dali ima oshte poredni ravni chisla na namerenite.
			{
				currlengthOfSeq++;                               //Namirame dyljinata na tekushtata poredicata.
				eqElementsIndex++;
			}

			if (currlengthOfSeq > prelengthOfSeq)               //Ako dyljinata na tekushtata poredica e po golqma ot dyljinata na predishnata,
			{													// zapazvame samo dyljina i nachalniq indeks na tekushtata poredica.
				prelengthOfSeq = currlengthOfSeq;
				preStartIndex = currStartIndex;
			}

			currlengthOfSeq = 1;
		}
	}

	cout << endl;
	cout << "The start index is: " << preStartIndex << endl;
	cout << "The length of sequence is: " << prelengthOfSeq << endl;
	cout << "Elements are: " << endl;

	PrintWantedSeq(numbers, n, preStartIndex, prelengthOfSeq);
}

void PrintWantedSeq(double* numbers, int n, int preStartIndex, int prelengthOfSeq)
{
	for (int i = preStartIndex; i < preStartIndex + prelengthOfSeq; ++i)
	{
		cout << numbers[i] << endl;
	}

	cout << endl;
}
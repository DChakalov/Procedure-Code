#include <iostream>
#include<iomanip>

using namespace std;

void CalcPyramid(int n, long long currentElement, int setOnPos, int elementsOfPyramid[100]);
int factorialCalc(int number);

int main()
{
	cout << "Enter wanted Layer: ";
	int n;
	cin >> n;
	cout << endl;
	long long currentElement = 0;
	int setOnPos = n*2+2;
	int elementsOfPyramid[100];

	CalcPyramid(n, currentElement, setOnPos, elementsOfPyramid);
	cout << endl;

	return 0;
}

void CalcPyramid(int n, long long currentElement, int setOnPos, int elementsOfPyramid[100])
{
	for (int m = 0; m <= n; m++)
	{
		cout << setw(setOnPos);
		for (int k = 0; k <= m; k++)
		{
			currentElement = (factorialCalc(n) / (factorialCalc(m) * factorialCalc(n - m))) *
				(factorialCalc(m) / (factorialCalc(k) * factorialCalc(m - k)));
			cout << currentElement << "   ";
		}
		setOnPos -= 2;
		cout << endl;
	}
}

int factorialCalc(int number)
{
	long long factorialOfNum = 1;
	for (int i = number; i > 0 ; i--)
	{
		factorialOfNum *= i;
	}
	return factorialOfNum;
}
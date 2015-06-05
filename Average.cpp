/*ZAD_1. Napishete programa, koqto chete ot konzolata cqlo polojitelno chislo N, kydeto 2<N<1024
i sled tova prochita N chisla. Namerete sredno aritmetichnoto na chislata.
Izvedete vsichki chisla po golemi ot nego.*/

#include<iostream>

using namespace std;

long double numbersInInterval(int n, double* selectNumsInInterval);
void PrintGreaterNums(int n, long double average, double* selectNumsInInterval);

int main()
{
	cout << "Enter N of numbers: " << endl;
	int n = 0;
	cin >> n;
	bool validN = n > 2 && n < 1024;
	long double average = 0.0;
	cout << endl;

	if (validN)
	{
		cout << "Enter numbers: " << endl;
		double * selectNumsInInterval;
		selectNumsInInterval = new double[n];

		average = numbersInInterval(n, selectNumsInInterval);

		if (average == 0)   //Pri nekorektni chisla funkciqta "numbersInInterval" vryshta na  "average" stoinost nula.
		{
			cout << "Invalid input!" << endl;
			return 1;
		}
		cout << endl;

		PrintGreaterNums(n, average, selectNumsInInterval);

		delete[] selectNumsInInterval;
	}
	else
	{
		cout << "Invalid input!" << endl;    //Pri nekorektno zadaden broi na chislata.
		return 1;
	}

	return 0;
}

long double numbersInInterval(int n, double* selectNumsInInterval)
{

	long long sumOfNums = 0;
	long double average = 0.0;

	for (size_t i = 0; i < n; ++i)
	{
		cin >> selectNumsInInterval[i];

		if (!cin)    //Proverqvame dali sa korektni chislata
		{
			return 0;
		}

		sumOfNums += selectNumsInInterval[i];
	}

	average = sumOfNums / (double)n;

	return average;
}

void PrintGreaterNums(int n, long double average, double* selectNumsInInterval)
{
	cout << "Numbers greater then average: " << endl;

	for (size_t i = 0; i < n; ++i)
	{
		if (selectNumsInInterval[i] > average)
		{
			cout << selectNumsInInterval[i] << endl;
		}
	}
}
#include<iostream>
#include<cmath>

using namespace std;

void FindNumbers(int m, int n, int sum, int PrimeSumsOfDiv);
int isPrime(int currentNumber);

int main()
{
	int m, n, sum = 0, PrimeSumsOfDiv = 0;
	cout << "Enter first number from interval: ";
	cin >> m;
	cout << "Enter last number from interval: ";
	cin	>> n;
	//cout << "Numbers with prime sum of divisors:" << endl; 

	FindNumbers(m, n, sum, PrimeSumsOfDiv);

	return 0;
}

void FindNumbers(int m, int n, int sum, int PrimeSumsOfDiv)
{
	for (; m <= n; m++)
	{
		for (int i = 1; i < m; i++)
		{
			if (m % i == 0)
			{
				sum += i;
			}
		}

		int prime = isPrime(sum);
		if (prime && sum != 1)
		{
			//cout << m << endl; //Print numbers with prime sum of divisors.
			PrimeSumsOfDiv++;
		}
		sum = 0;
	}
	cout << endl;
	cout << "All numbers with prime sum of divisors in interval are: " << PrimeSumsOfDiv << endl;
	cout << endl;

	return;
}

int isPrime(int primeNum)
{
	int o = 0;
	for (int i = 2; i < primeNum; i++)
	{
		o = i;
		if (primeNum % i == 0)
		{
			return 0;
		}
	}

	return primeNum;
}
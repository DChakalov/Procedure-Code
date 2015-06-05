#include<iostream>
#include<iomanip>

using namespace std;

int number = 0;

void EvenNumsRomb(int number);
void PrimeNumsRomb(int number);

int main()
{
	cout << "Enter length of diagonal: ";
	int number;
	cin >> number;
	cout << endl;
	if (number%2==0)
	{
		EvenNumsRomb(number);
	}
	else
	{
		PrimeNumsRomb(number);
	}

	cout << endl;

	return 0;
}

void EvenNumsRomb(int number)
{
	int firstDivOfNum = number / 2;
	int secDivOfNum = firstDivOfNum + 1;
	int setByPosition = number;

	cout << setw(setByPosition) << firstDivOfNum
		<< " " << secDivOfNum << endl;

	for (size_t i = 1; i < number/2; i++)
	{
		setByPosition-=2;
		cout << setw(setByPosition);
		for (size_t j = firstDivOfNum-i; j <= secDivOfNum + i; j++)
		{
			cout << j <<" ";
		}
		cout << endl;
	} 

	setByPosition = 0;

	for (int i = number/2-1; i >= 0 ; i--)
	{
		setByPosition+=2;
		cout << setw(setByPosition);
		for (size_t j = firstDivOfNum - i; j <= secDivOfNum + i; j++)
		{
			cout << j <<" ";
		}
		cout << endl;
	}

	return;
}

void PrimeNumsRomb(int number)
{
	int firstDivOfNum = number / 2 + 1;
	int setByPosition = number + 1;
	if (firstDivOfNum > 9)
	{
		cout << setw(setByPosition + 1) << firstDivOfNum << endl;
	}
	else
	{
		cout << setw(setByPosition) << firstDivOfNum << endl;
	}
	
	for (size_t i = 1; i < number/2+1; i++)
	{
		setByPosition -= 2;
		cout << setw(setByPosition);
		for (size_t j = firstDivOfNum - i; j < firstDivOfNum + i + 1; j++)
		{
			cout << j << " ";
		}
		cout << endl;
	}
	
	setByPosition = 1+1;

	for (int i = number/2; i > 0; i--)
	{
		setByPosition += 2;
		cout << setw(setByPosition);
		for (size_t j = firstDivOfNum - i + 1; j < firstDivOfNum + i; j++)
		{
			cout << j << " ";
		}
		cout << endl;
	}

	return;
}
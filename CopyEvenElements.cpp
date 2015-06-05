//ZAD.2_Domashno 5

#include<iostream>

using namespace std;

int n = 0;
int* numsArray;
int* copyOfNumsArray;
int allElements = 0;
int currentValue = 0;

void CopyElements(int index);

int main()
{
	do
	{
		cout << "Enter valid \"n\" of numbers: ";
		cin >> n;
		if (n > 1000)
		{
			cout << "\"n\" must be smaller than 1000!" << endl;
			cout << endl;
		}
	} while (n > 1000 && n > 0);

	numsArray = new int[n];
	copyOfNumsArray = new int[n];

	cout << "Enter numbers: " << endl;
	for (size_t i = 0; i < n; i++)
	{
		cin >> numsArray[i];
		if (numsArray[i] > 1000000)
		{
			cout << "Numbers must be smaller than 1000000!" << endl;
			return 1;
		}
	}

	cout << endl;

	CopyElements(0);

	delete[] numsArray;
	delete[] copyOfNumsArray;

	return 0;
}

void CopyElements(int index)
{
	if (index >= n)
	{
		cout << "Even elements in array: " << endl;
		for (size_t i = 0; i < allElements; i++)
		{
			cout << copyOfNumsArray[i] << endl;
		}

		return;
	}
	else
	{
		currentValue = numsArray[index];
		if (currentValue % 2 == 0)
		{
			copyOfNumsArray[allElements] = currentValue;
			allElements++;
		}

		CopyElements(index + 1);
	}

	return;
}

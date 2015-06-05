//ZAD. 3
//Da se izvedyt pyrvite N na broi avtomorfni chisla.

#include<iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	unsigned long long autoMorphNum = 0;
	unsigned long long poweredTen = 0;
	string autoMorphPart;
	cout << "Enter N of numbers: ";
	cin >> n;

	while (n>0)
	{
		bool possibleNums = autoMorphNum % 10 == 5 || autoMorphNum % 10 == 6 || autoMorphNum % 10 == 1 || autoMorphNum % 10 == 0;
		if (possibleNums)
		{
			autoMorphPart = to_string(autoMorphNum);
			poweredTen = pow(10, autoMorphPart.size());
			bool isAutomorphic = (autoMorphNum*autoMorphNum - autoMorphNum) % poweredTen == 0;
			if (isAutomorphic)
			{
				cout << autoMorphNum << "\n";
				n--;
			}
		}
		autoMorphNum++;
	}
}


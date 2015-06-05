//ZAD.1
//Chrez kordinatite po abcisa i ordinata, da se opredeli dali dadena tochka popada v zadadenata siva chast.

#include <iostream>

using namespace std;

int main()
{

	double x, y;
	cout << "Enter x: ";
	cin >> x;
	cout << "Enter y: ";
	cin >> y;
	bool inHalfCircle = (y >= 0) && (x*x + y*y <= 4);
	bool inRectangle =  (y < 0) && (y>=-2) && (x <= 1) && (x >= -1);

	if (inRectangle || inHalfCircle)
	{
		cout << "Point is in the grey part !" << endl;
	}
	else
	{
		cout << "Point is out of the grey part !" << endl;
	}
	

}
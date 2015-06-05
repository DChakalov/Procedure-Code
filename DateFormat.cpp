// Homework1.cpp : Defines the entry point for the console application.
///*ZAD. 2 Napishete programa, koqto chete ot konzolata 3 celi chisla obrazuvashti data, vyv formatdd/mm/yyyy. Ako datata e validna izvedete na ekrana predhodnata data, otnovo v syshtiq format(ne zabravqite visokosnite godini).  */

#include <iostream>
#include<string>
#include <sstream>

using namespace std;
void DateFormat(int var)
{
	if (var<10)
	{
		cout << '0' << var << '/';
	}
	else
	{
		cout << var << '/';
	}
}

int main()
{

	int day, month, year;
	cout << "Enter day: ";
	cin >> day;
	cout << "Enter month: ";
	cin >> month;
	cout << "Enter year: ";
	cin >> year;
	
	if (month > 12 || month <= 0)
	{
		cout << "Incorrect month!" << endl;
		return 1;
	}
	
	bool leapY = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
	int daysInMonthCommYear[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int daysInMonthLeapYear[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	bool correctDayLeapY = day <= daysInMonthLeapYear[month - 1] && day > 0;
	bool correctDayCommY = day <= daysInMonthCommYear[month - 1] && day > 0;

	day -= 1;
	if (day == 0 && correctDayCommY && correctDayLeapY)
	{
		if (month == 1)
		{
			year -= 1;
			month = 12;
			day = 31;
		}
		else
		{
			month -= 1;
			day = leapY ? daysInMonthLeapYear[month - 1] : daysInMonthCommYear[month - 1];
		}
	}

	if (leapY)
	{
		if (correctDayLeapY)
		{
			DateFormat(day);
			DateFormat(month);
			cout << year << endl;
		}
		else
		{
			cout << "Incorrect day!" << endl;
		}
	}
	else
	{
		if (correctDayCommY)
		{
			DateFormat(day);
			DateFormat(month);
			cout << year<<endl;
		}
		else
		{
			cout << "Incorrect day!" << endl;
		}
	}
}


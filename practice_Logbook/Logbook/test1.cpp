//--------------------------------------------------------------------
//
//  Laboratory 1                                           test1.cpp
//
//  Test program for the operations in the Logbook ADT
//
//--------------------------------------------------------------------

#include <iostream>
#include "Logbook.h"

using namespace std;

int main()
{
	int month,   // Input month
		year,    // Input year
		day,     // Input day
		entry,   // Input logbook entry
		dofw,    // Day of the week
		stop,    // Signals end of test
		j;       // Loop counter

				 // Create a logbook (not used in Test 4).


	cout << endl << endl << "Enter the month" << endl;
	cin >> month;
	cout << endl << endl << "Enter the year" << endl;
	cin >> year;

	Logbook testLog(month, year);

	// Test 1 : Tests the month, year, and daysInMonth operations.

	cout << "Month : " << testLog.getMonth() << endl;
	cout << "Year  : " << testLog.getYear() << endl;
	cout << "# days in month : " << testLog.getDaysInMonth() << endl;


	while (true)
	{
		cout << endl;
		cout << "------------ Logbook ------------" << endl;
		cout << "1. putEntry" << endl;
		cout << "2. displayCalendar" << endl;
		cout << "0. exit" << endl;
		cout << "---------------------------------" << endl;

		int input;
		cin >> input;

		switch (input)
		{
		case 1: cout << endl << "Enter day and entry (0 0 to exit Test 2) : ";
			cin >> day >> entry;
			if (day != 0 && entry != 0)
			{
				testLog.putEntry(day, entry);
			}
			break;

		case 2: testLog.displayCalendar();
			break;

		case 0: exit(0);
		}

	}
	


	return 0;
}
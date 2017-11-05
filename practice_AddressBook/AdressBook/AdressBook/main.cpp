#include "addressbook.h"


void main()
{
	AddressBook book; // 林家废 积己 


	while (true)
	{
		cout << endl;
		cout << "------------ AddressBook ------------" << endl;
		cout << "1. Add a new entry" << endl;
		cout << "2. Remove an entry" << endl;
		cout << "3. Select a month" << endl;
		cout << "0. exit" << endl;
		cout << "---------------------------------" << endl;

		int input;
		cin >> input;

		switch (input)
		{
		case 1: book.addAddress();
			break;

		case 2: book.delAddress();
			break;

		case 3: book.displayMonth();
			break;

		case 0: exit(0);
		}

		cout << "Number of persons in address book : " << book.getCount() << endl;

	}
}
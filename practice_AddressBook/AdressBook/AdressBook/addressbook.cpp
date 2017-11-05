#include "addressbook.h"

using namespace std;

// ** 주소록 생성자 **
AddressBook::AddressBook()
{
	initAddressBook();
}

// ** 주소록 소멸자 **
AddressBook::~AddressBook()
{
}

// ** 주소록 초기화 **
void AddressBook::initAddressBook()
{
	address = new Address[defMaxSize];	// maxSize로 주소록 array 설정
	count = 0;							// count 변수 0으로 초기화
}

// ** 주소 추가 함수 **
void AddressBook::addAddress()
{	
	getline(cin, address[count].name, '\n');			// string 변수인 이름, 전화번호는 getline으로 받고
	cout << endl << "Enter his(her) name: ";
	getline(cin, address[count].name, '\n');
	cout << endl << "Enter his(her) phone number: ";
	getline(cin, address[count].phoneNo, '\n');
	cout << endl << "Enter his(her) birth year: ";		// 생년월일은 cin으로 받아서 address 객체에 저장
	cin >> address[count].birthYear;
	cout << endl << "Enter his(her) birth month: ";
	cin >> address[count].birthMonth;
	cout << endl << "Enter his(her) birth day: ";
	cin >> address[count].birthDay;

	count ++;											// count 변수 증가
}

// ** 주소 제거 함수 **
void AddressBook::delAddress()
{
	int j = -1;											// count변수와 비교하기 위한 변수 j
	string name;										// 이름을 입력받아서 해당하는 이름이 있는 경우 삭제
	getline(cin, name, '\n');
	cout << "Enter the name to delete: ";
	getline(cin, name, '\n');
	
	for (int i=0;  i <= count; i++)
	{
		if (address[i].name == name)					// 입력값과 이름이 같을 경우
		{
			for (i; i < count; i++)						// 해당 인덱스까지 Address 객체들 한칸씩 이동
			{
				address[i] = address[i + 1];
			}

			count--;									 // 주소 카운트 감소
		}
		else
			j++;										// 입력값과 이름이 다르면 j 변수 증가
	}
	if (j == count)
		cout << "There is no such name." << endl;		// count와 j가 같으면 해당 이름이 주소록에 없다는 메시지 출력
}

// ** 월별 생일자 출력 함수 ** 
void AddressBook::displayMonth() const				
{
	int month;
	string monthLetter;
	cout << endl << "Enter Month: ";
	cin >> month;
	int personCount = 0;
	
	for (int i = 0; i < count; i++)
	{
		if (month == address[i].birthMonth)							// 입력값과 달이 같을 경우
		{									
			cout << endl;
			cout << "Name: " << address[i].name << endl;			// 해당 주소 출력
			cout << "PhoneNo: " << address[i].phoneNo << endl;
			cout << "BirthDate: " << address[i].birthYear << "/";
			cout << address[i].birthMonth << "/" ;
			cout << address[i].birthDay <<  endl;
			personCount++;											// 생일자 수를 카운트 함
		}
	}

	switch (month)													// 월에 해당하는 영문 출력
	{
	case 1:monthLetter = "January"; break;
	case 2:monthLetter = "Feburary"; break;
	case 3:monthLetter = "March"; break;
	case 4:monthLetter = "April"; break;
	case 5:monthLetter = "May"; break;
	case 6:monthLetter = "June"; break;
	case 7:monthLetter = "July"; break;
	case 8:monthLetter = "August"; break;
	case 9:monthLetter = "September"; break;
	case 10:monthLetter = "October"; break;
	case 11:monthLetter = "November"; break;
	case 12:monthLetter = "December"; break;
	}
	cout << "Total number of birthdays in Month " <<   monthLetter << ": "<< personCount <<  endl;
}

// ** get count : private 값인 count 변수를 불러옴 **
int AddressBook::getCount()
{
	return count;
}

// ** Adress 객체 생성자 **
Address::Address()
{
	initAddress();
}

// ** Adress 객체 소멸자 **
Address::~Address()
{
	
}

// ** Adress 객체 초기화 **
void Address::initAddress()
{
	char name = 0;
	char phoneNo = 0;
	char birthYear = 0;
	char birthMonth = 0;
	char birthDay = 0;
}


#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

const int defMaxSize = 100;			// 주소록 크기

class AddressBook;

class Address
{
public:
	Address();
	virtual ~Address();
	void initAddress();

private:	
	string name;					// string 변수 이름, 전화번호
	string phoneNo;
	int birthYear;					// int 변수 생년월일
	int birthMonth;
	int birthDay;

	friend class AddressBook;		// Adressbook을 friend class로 설정하여 주소록에서 접근을 허용함
};

class AddressBook				
{
public:
	AddressBook();					// 주소록 생성자
	virtual ~AddressBook();			// 주소록 소멸자
	void initAddressBook();			// 주소록 초기화
	void addAddress();				// 주소 추가
	void delAddress();				// 주소 삭제
	void displayMonth() const;		// 월별 생일자 출력
	int getCount();					

private:
	int count;
	Address * address;				// 주소록은 주소를 가지고 있음
	
};




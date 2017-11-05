// Logbook.cpp: implementation of the Logbook class.
//
//////////////////////////////////////////////////////////////////////

#include "Logbook.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// 생성자 ; 객체 생성 및 엔트리 초기화
Logbook::Logbook()
{
	setCurrentTime();
	initEntry();
}

Logbook::~Logbook()
{

}

// 생성자 ; 객체 생성 및 엔트리 초기화, 연도 및 달 입력
Logbook::Logbook(int month, int year)
{
	setCurrentTime();
	// Implementation here
	this->logMonth = month;
	this->logYear = year;

	initEntry();
}

// 엔트리에 값 입력
void Logbook::putEntry(int day, int value)
{
	// Implementation here
	entries[day - 1] = value;
}

// 엔트리에 저장된 값 출력
int Logbook::getEntry(int day) const
{
	// Implementation here
	return entries[day - 1];
}

// 달 출력
int Logbook::getMonth() const
{
	// Implementation here
	return logMonth;
}

// 연도 출력
int Logbook::getYear() const
{
	// Implementation here
	return logYear;
}

// 해당하는 달의 일수 출력
int Logbook::getDaysInMonth() const
{
	// Implementation here
	if (isLeapYear(logYear) == 1)	// Leap year
		return DaysOfMonth[1][this->logMonth - 1];
	else
		return DaysOfMonth[0][this->logMonth - 1];
}

// 윤년 계산. 윤년이면 1, 평년이면 0 리턴
int Logbook::isLeapYear(int year) const
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		return 1;		// Leap year
	else
		return 0;		// Normal years
}

// 엔트리에 값 입력
void Logbook::putEntry(int value)
{
	entries[(currentTime->tm_mday - 1)] = value;
}

void Logbook::setCurrentTime()
{
	// tm structure Used by asctime, gmtime, localtime, mktime, 
	// and strftime to store and retrieve time information.  

	// tm은 구조체로 시간 정보를 저장하고 불러오기 위해 asctime, gmtime, localtime, mktime,
	// 그리고 strftime 에 의해서 사용됩니다.

	time_t		now;
	time(&now);
	currentTime = localtime(&now);

	logYear = currentTime->tm_year + 1900;
	logMonth = currentTime->tm_mon + 1;
}

// 엔트리 초기화
void Logbook::initEntry()
{
	int iDays = getDaysInMonth();
	for (int i = 0; i < iDays; i++)
		entries[i] = 0;
}

// 엔트리(달력) 콘솔화면에 출력
void Logbook::displayCalendar() const
{
	//In-Lab
	int day = 1;
	cout << "Logbook:" << endl;
	for (day = 1; day <= getDaysInMonth(); day++)
	{
		cout << day << " " << getEntry(day) << '\t';
		if (day % 7 == 0)
			cout << endl;
	}
	cout << endl;
}

// 해당하는 날이 무슨 요일인지 리턴
int Logbook::getDayOfWeek(int day) const
{
	tm		when;
	time_t	result;

	when = *currentTime;
	when.tm_mday = day;

	if ((result = mktime(&when)) != (time_t)-1)
	{
		// Implementation here
		when.tm_year = logYear;
		when.tm_mon = logMonth;
		return when.tm_wday;
	}

	else
	{
		// Implementation here
		
		return 0;
	}
}



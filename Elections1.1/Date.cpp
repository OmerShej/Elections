#include "General.h"
#include "Date.h"


//c'tor
Date::Date(int i_Day, int i_Month, int i_Year)	//c'tor
{
	while (!setDay(i_Day))
	{
		cout << "Invalid Input, please choose a day between 1 to 31 " << endl;
		cin >> i_Day;
	}
	while (!setMonth(i_Month))
	{
		cout << "Invalid Input, please choose a month between 1 to 12 " << endl;
		cin >> i_Month;
	}
	while (!setYear(i_Year))
	{
		cout << "Invalid Input, please choose a year between 1900 to 2020 " << endl;
		cin >> i_Year;
	}
	
}

//getters
int Date::getDay() const
{
	return m_Day;
}

int Date::getMonth() const
{
	return m_Month;
}

int Date::getYear() const
{
	return m_Year;
}

//setters
bool Date::setDay(int i_Day) // valid days are only between 1 to 31.
{
	if (i_Day < 1 || i_Day > 31)
	{
		return false;
	}
	m_Day = i_Day;
	return true;
}

bool Date::setMonth(int i_Month)//valid months are only between 1 to 12
{
	if (i_Month < 1 || i_Month > 12)
	{
		return false;
	}
	m_Month = i_Month;
	return true;
}

bool Date::setYear(int i_Year) //valid years are only between 1900 to 2020
{
	if (i_Year < 1900 || i_Year > 2020)
	{
		return false;
	}
	m_Year = i_Year;
	return true;
}

//other
void Date::show()	const
{
	cout << m_Day << " / " << m_Month << " / " << m_Year << endl;
}
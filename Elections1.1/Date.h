#ifndef __DATE_H
#define __DATE_H
#include "General.h"

class Date
{
private:
	int m_Day = 0;
	int m_Month = 0;
	int m_Year = 0;
public:
	//constructors
	Date(int i_Day, int i_Month, int i_Year);
	//getters
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	//setters
	bool setDay(int i_Day=0);
	bool setMonth(int i_Month=0);
	bool setYear(int i_Year=0);
	//others
	void show()	const;
	
};

#endif //__DATE_H

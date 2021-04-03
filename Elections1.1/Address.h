#ifndef __ADDRESS_H
#define __ADDRESS_H
#include <iostream>
#include <string>
using namespace std;


class Address
{
private:
	string m_City;
	string m_Street;
	int m_HouseNumber = 0;
public:
	//constructors
	Address(string& i_City, string& i_Street, int i_HouseNumber);
	Address();
	Address(Address& other);
	Address(Address&& other);
	
	//assigment operators
	const Address& operator=(const Address& copy);
	const Address& operator=(Address&& move);

	//getters
	const string& getCity() const;
	const string& getStreet() const;
	int getHouseNumber() const;

	//setters
	bool setCity(const string& i_City);
	bool setStreet(const string& i_Street);
	bool setHouseNumber(int i_HouseNumber=0);

	//others
	friend ostream& operator <<(ostream& os, const Address& address);
};

#endif //__ADDRESS_H

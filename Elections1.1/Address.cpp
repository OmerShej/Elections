#include "General.h"
#include "Address.h"
using namespace std;

//c'tor
Address::Address(string& i_City, string& i_Street, int i_HouseNumber)
{
	
	while (!setCity(i_City))
	{
		cout << "Invalid Input, please enter city's name correctly. " << endl;
		cin >> i_City;
	}
	while (!setStreet(i_Street))
	{
		cout << "Invalid Input, please enter street's name correctly. " << endl;
		cin >> i_Street;
	}
	while (!setHouseNumber(i_HouseNumber))
	{
		cout << "Invalid Input, please enter house number correctly. " << endl;
		cin >> i_HouseNumber;
	}
	
	
}
//default c'tor
Address::Address()
{

}
//copy c'tor
Address::Address(Address& other)
{
	*this = other;
}
//move c'tor
Address::Address(Address&& other)
{
	m_City = other.m_City;
	m_Street = other.m_Street;
	m_HouseNumber = other.m_HouseNumber;
	other.m_City = nullptr;
	other.m_Street = nullptr;
}

//assigment operators
const Address& Address::operator=(const Address& copy)
{
	if (this != &copy)
	{

		m_City = copy.m_City;
		m_Street = copy.m_Street;
		m_HouseNumber = copy.m_HouseNumber;
	
	}
	return *this;
}
const Address& Address::operator=(Address&& move)
{
	if (this != &move)
	{
	
		this->m_City = move.m_City;
		this->m_Street = move.m_Street;
		this->m_HouseNumber = move.m_HouseNumber;
		//move.m_City = nullptr;
		//move.m_Street = nullptr;
	}
	return *this;
}

//getters
const string& Address::getCity() const
{
	return m_City;
}

const string& Address::getStreet()const
{
	return m_Street;
}

int Address::getHouseNumber() const
{
	return m_HouseNumber;
}

//setters
bool Address::setCity(const string& i_City)
{
	
	int citySz = i_City.size();
	for (int i = 0; i < citySz; i++)
	{//checks each and every char in the string, to see if its a "valid" char.
		if ((i_City[i] < 'a' || i_City[i] > 'z') && (i_City[i] < 'A' || i_City[i] > 'Z') && (i_City[i] < ' ' || i_City[i] > ' ') && (i_City[i] < '-' || i_City[i] > '-'))
		{
			return false;
		}
	}
	m_City = i_City;
	return true;
}

bool Address::setStreet(const string& i_Street)
{
	int streetSz = i_Street.size();
	for (int i = 0; i < streetSz; i++)
	{//checks each and every char in the string, to see if its a "valid" char.
		if ((i_Street[i] < 'a' || i_Street[i] > 'z') && (i_Street[i] < 'A' || i_Street[i] > 'Z') && (i_Street[i] < ' ' || i_Street[i] > ' ') && (i_Street[i] < '-' || i_Street[i] > '-'))
		{
			return false;
		}
	}
	m_Street = i_Street;
	return true;
}

bool Address::setHouseNumber(int i_HouseNumber)
{
	if (i_HouseNumber < 0 || i_HouseNumber > 1000)
	{
		return false;
	}
	m_HouseNumber = i_HouseNumber;
	return true;
}

//other

ostream& operator <<(ostream& os, const Address& address)
{
	os << "Address: " << address.getStreet();
	os << " ," << address.getHouseNumber();
	os << " " << address.getCity();
	return os;
}

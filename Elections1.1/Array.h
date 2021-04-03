#ifndef __ARRAY_H
#define __ARRAY_H
#include <iostream>
using namespace std;

template<class T>
class Array
{
private:
	int physicalSize = 10;
	int	logicalSize;
	T* arr;
public:
	Array();
	Array(const Array& other);
	~Array();
	const Array& operator=(const Array& other);
	const Array& operator+=(const T& newVal);
	const T& operator[](int index)const;
	friend ostream& operator<<(ostream& os, const Array& arr)
	{
		for (int i = 0; i < arr.logicalSize; i++)
		{
			os << arr.arr[i] << " ";
		}
		return os;
	}
};

template<class T>
Array<T>::Array() : physicalSize(10), logicalSize(0)
{
	arr = new T[physicalSize];
	//this->delimiter = delimiter;
}


template <class T>
Array<T>::Array(const Array& other) : arr(nullptr)
{
	delete[] arr;
	if (this != other)
	{
		*this = other;
	}
	other = nullptr;
	return *this;
}


template<class T>
Array<T>::~Array()
{
	//delete just the arr 
	if (arr != NULL || arr != nullptr)
	{
		delete[] arr;
	}

}

template<class T>
const Array<T>&Array<T>:: operator+=(const T& newVal)
{
	if (logicalSize == physicalSize)
	{
		physicalSize *= 2;
		T* temp = new T[physicalSize];
		for (int i = 0; i < logicalSize; i++)
		{
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
	}
	arr[logicalSize++] = newVal;
	logicalSize++;
	return *this;
}

template<class T>
const Array<T>&Array<T>::operator=(const Array& other)
{
	
	delete[] arr;
	physicalSize = other.physicalSize;
	logicalSize = other.logicalSize;
	//delimiter = other.delimiter;
	arr = new T[physicalSize];
	for (int i = 0; i < logicalSize; i++)
		arr[i] = other.arr[i];
	
	return *this;
}

template <class T>
const T&Array<T>::operator[](int index) const
{
	return arr[index];
}

#endif // !__ARRAY_H
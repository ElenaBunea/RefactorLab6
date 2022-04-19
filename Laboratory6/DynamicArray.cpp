#include "DynamicArray.h"
#include <iostream>
using namespace std;


DynamicArray::DynamicArray(int cap) {
	length = 0;
	this->capacity = cap;
	dynarr = new ElementType[cap];

	if (dynarr == nullptr) {
		cerr << "DynamicArray(): failed to allocate memory" << endl;
		exit(-1);
	}
}

DynamicArray::~DynamicArray() {
	delete[] dynarr;						//?free the allocated memory
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {		//! data

	if (this != &other) { 												//? self assignment check
		//?deep copy of other
		length = other.length;
		capacity = other.capacity;

		delete[] this->dynarr;
		 
		// data = other.data; NOO! this is shallow copy
		// deep copy of data
		dynarr = new ElementType[other.capacity]();

		if (dynarr == nullptr) {
			cerr << "operator=(): failed to allocate memory" << endl;
			exit(-1);
		}

		for (unsigned int i = 0; i < length; i++)
			dynarr[i] = other.dynarr[i];
	}
	return *this;					 									//! the type of this is DynamicArray* -> dereferencing
}

// ! data = other.data; NOO! this is shallow copy

DynamicArray::DynamicArray(const DynamicArray& other) {					//! data 
	
	//?deep copy of other
	length = other.length;
	capacity = other.capacity;

	dynarr = new ElementType[other.capacity]();						//?deep copy of data

	if (dynarr == nullptr) {
		cerr << "DynamicArray(const DynamicArray& other): failed to allocate memory" << endl;
		exit(-1);
	}

	for (unsigned int i = 0; i < length; i++)						//?copying/assigning elements to the other 
		dynarr[i] = other.dynarr[i];
}

void DynamicArray::append(ElementType v, bool* err)
{
	// todo 
	// check if the length < capacity
	if (length == capacity) {
		// double the capacity
		resize(capacity * 2);
	}
	dynarr[length] = v;
	length++;
}

ostream& operator<<(ostream& s, const DynamicArray& arr) {
	// [1 2 3 4 5 ]
	s << "[";
	for (unsigned int i = 0; i < arr.length; i++) {
		//s << arr.data[i] << " ";
	}
	s << "]";
	return s;
}

ElementType DynamicArray::popBack() {							//?deletes + returns the last element in the array

	if (length == 0) {
		// unfriendly way of handling corner cases
		cerr << "Precondition does not hold: popBack()" << endl;
		exit(-1);
	}

	ElementType v = dynarr[length];
	length--;

	return v;
}

ElementType DynamicArray::remove(unsigned int index)
{

	if (index >= 0 && index < length) {								//? index verified in order to be valid and used
		ElementType v = dynarr[index];
		for (unsigned int i = index; i < length - 1; i++)
			dynarr[i] = dynarr[i + 1];
		length--;
		return v;
	}
	else {
		// unfriendly way of handling corner cases
		cerr << "Precondition does not hold: remove()" << endl;
		exit(-1);
	}
}


ElementType& DynamicArray::get(unsigned int index) {
	if (index >= 0 && index < length) {							//? index verified in order to be valid and used
		return dynarr[index];
	}
	else {
		// unfriendly way of handling corner cases
		cerr << "Precondition does not hold: get()" << endl;
		exit(-1);
	}
}

void DynamicArray::resize(unsigned int newCapacity) {			//!no realloc  in c++
	this->capacity = newCapacity;							
	ElementType* newData = new ElementType[newCapacity]();
	if (newData == nullptr) {
		cerr << "resize(): failed to allocate memory" << endl;
		exit(-1);
	}

	for (unsigned int i = 0; i < length; i++) {			//?previous elements are copied in newData
		newData[i] = this->dynarr[i];
	}

	delete[] this->dynarr;
	this->dynarr = newData;
}


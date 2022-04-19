#pragma once
#include <string>
#include <ostream>
#include "Offer.h"
using namespace std;

typedef Offer ElementType; //?renaming int to element type => generic type

class DynamicArray
{
public:
	DynamicArray(int capacity = 100); 		//?default param

	// RULE OF THREE 
	// destructor
	~DynamicArray();

	// copy constructor
	DynamicArray(const DynamicArray& other);

	// assignment operator
	DynamicArray& operator=(const DynamicArray& other);
	// end RULE OF THREE 

	
	inline unsigned int getLength() const { return length; }			//? getter for the length/capacity
	inline unsigned int getCapacity() const { return capacity; }		//?inline has to be implemented in the header

	void append(ElementType v, bool* err = nullptr);					//? adds an element at the end
	ElementType popBack();												//? remove the element from the end, when the array is not empty

	ElementType remove(unsigned int index);								//? removes element from a given position i

	ElementType& get(unsigned int index);								//? gets element at a given valid index, else -1

	friend ostream& operator<<(ostream& s, const DynamicArray& arr);		//?printing the array

	void resize(unsigned int newCapacity);

private:
	static int count;
	unsigned int length;
	unsigned int capacity;
	ElementType* dynarr;					//?array itself
};


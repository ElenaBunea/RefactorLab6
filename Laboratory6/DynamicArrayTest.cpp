#include "DynamicArrayTest.h"
#include <cassert>
bool DynamicArrayTest::verbose = false;

void DynamicArrayTest::testLength()
{
	
}

void DynamicArrayTest::runAllTests()
{
	DynamicArray* arr = new DynamicArray(5);
	assert(arr->getCapacity() == 5);
}

#pragma once
class DynamicArrayTest
{
public:
	static void runAllTests();
	static void testLength();
	static void setVerbose(bool);		//! setter for verbose

private:
	static bool verbose;
};

//void DynamicArrayTest::testLength();
#include "DateTest.h"


void DateTest::runAllTests()
{
	Date d;

	d.setday(1);
	assert(d.getday() == 1);

	d.setmonth(2);
	assert(d.getmonth() == 2);

	d.setyear(3);
	assert(d.getyear() == 3);
}

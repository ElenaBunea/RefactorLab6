#pragma once
#include "Offer.h"

class OfferTest
{
    static int test_create();
    static int test_getprice();
    static int test_getdate();
    static int test_getid();
    static int test_getdeparture();
    static int test_getdestination();

    static int test_setdate();
    static int test_setdeparture();
    static int test_setdestination();
    static int test_setprice();
    static int test_equals();

public:
	static void runAllTests();
};


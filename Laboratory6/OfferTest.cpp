#include "OfferTest.h"
#include "Date.h"
#include <cassert>

int OfferTest::test_create() {
    Offer o1;
    assert(o1.getId() == "0");
    assert(o1.getPrice() == 0);
    assert(o1.getDate() == Date());
    assert(o1.getDeparture().empty());
    assert(o1.getDestination().empty());

    Offer o2("1", "d1", "a1", "t1", 2, Date(1, 1, 2001));
    assert(o2.getId() == "1");
    assert(o2.getPrice() == 2);
    assert(o2.getDate() == Date(1, 1, 2001));
    assert(o2.getDeparture() == "d1");
    assert(o2.getDestination() == "a1");

    return 0;
}

int OfferTest::test_getprice() {
    Offer o2("1", "d1", "a1", 2, Date(1, 1, 2001));
    assert(o2.getprice() == 2);

    Offer o3("1", "d1", "a1", 12, Date(1, 1, 2001));
    assert(o3.getprice() == 12);
    return 0;
}

int OfferTest::test_getdate() {
    Offer o2("1", "d1", "a1", 2, Date(1, 1, 2001));
    assert(o2.getdate() == Date(1, 1, 2001));

    Offer o3("1", "d1", "a1", 12, Date(5, 2, 2005));
    assert(o3.getdate() == Date(5, 2, 2005));
    return 0;
}

int OfferTest::test_getid() {
    Offer o2("1", "d1", "a1", 2, Date(1, 1, 2001));
    assert(o2.getid() == "1");

    Offer o3("2", "d1", "a1", 12, Date(5, 2, 2005));
    assert(o3.getid() == "2");
    return 0;
}

int OfferTest::test_getdeparture() {
    Offer o2("1", "d1", "a1", 2, Date(1, 1, 2001));
    assert(o2.getdeparture() == "d1");

    Offer o3("2", "d2", "a1", 12, Date(5, 2, 2005));
    assert(o3.getdeparture() == "d2");
    return 0;
}

int OfferTest::test_getdestination() {
    Offer o2("1", "d1", "a1", 2, Date(1, 1, 2001));
    assert(o2.getdestination() == "a1");

    Offer o3("2", "d2", "a2", 12, Date(5, 2, 2005));
    assert(o3.getdestination() == "a2");
    return 0;
}


int OfferTest::test_setdate() {
    Date d1(2, 3, 2002);
    Offer o1;
    o1.setdate(d1);
    assert(o1.getdate() == d1);
    return 0;
}

int OfferTest::test_setid() {
    Offer o1;
    o1.setid("i1");
    assert(o1.getid() == "i1");
    return 0;
}

int OfferTest::test_setdeparture() {
    Offer o1;
    o1.setdeparture("d1");
    assert(o1.getdeparture() == "d1");
    return 0;
}

int OfferTest::test_setdestination() {
    Offer o1;
    o1.setdestination("a1");
    assert(o1.getdestination() == "a1");

    return 0;
}

int OfferTest::test_setprice() {
    Offer o1;
    o1.setprice(4);
    assert(o1.getprice() == 4);

    return 0;
}


int OfferTest::test_equals() {
    Offer o1;
    Offer o2;
    assert(o1 == o1);
    assert(o1 == o2);

    Offer o3("1", "d1", "a1", 2, Date(1, 1, 2001));
    Offer o4("1", "d1", "a1", 2, Date(1, 1, 2001));
    Offer o5("1", "d1", "a1", 3, Date(1, 1, 2002));
    Offer o6("1", "d1", "a2", 3, Date(1, 1, 2001));
    Offer o7("1", "d2", "a3", 3, Date(1, 1, 2001));
    Offer o8("1", "d3", "a3", 3, Date(1, 1, 2001));
    Offer o9("2", "d3", "a3", 3, Date(1, 1, 2001));

    assert(o3 == o4);
    assert(o3 == o3);
    assert(!(o3 == o1));
    assert(!(o4 == o5));
    assert(!(o5 == o6));
    assert(!(o6 == o7));
    assert(!(o7 == o8));
    assert(!(o8 == o9));

    return 0;
}

void OfferTest::runAllTests()
{
    test_create();
    test_getprice();
    test_getdate();
    test_getid();
    test_getdeparture();
    test_getdestination();
    test_setdate();
    test_setid();
    test_setdeparture();
    test_setdestination();
    test_setprice();
    test_equals();
}

#pragma once
#include <iostream>

class Date {
public:
    Date();
    Date(int, int, int);

    int getday() const;
    int getmonth() const;
    int getyear() const;

	inline void setday(int d) {this->day = d;}
	inline void setmonth(int m) {this->month = m;}
	inline void setyear(int y) {this->year = y;}

    static bool dateVal(int d, int m, int y) ;
    bool operator==(const Date& other) const;
    friend std::ostream& operator<<(std::ostream& out, const Date&);
private:
    int day;
    int month;
    int year;
};

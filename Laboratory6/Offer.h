#pragma once
#include "Date.h" //added
#include <string>
using namespace std;

class Offer
{
public:
	//constructor
	Offer();

	//id 
	inline void setid(string id) { this->id = id; }
	inline string getid() { return this->id; }

	//departure 
	inline void setdeparture(string departure) { this->departure = departure; }
	inline string getdeparture() { return this->departure; }

	//destination 
	inline void setdestination(string destination) { this->destination = destination; }
	inline string getdestination() { return this->destination; }

	//price 
	inline void setprice(float price) { this->price = price; }
	inline float getprice() { return this->price; }

	//departure date 
	inline void setdate(Date d) { this->departureday = d; }
	inline Date getDate() { return this->departureday; }

	//return day
	inline void setDater(Date r) { this->returnday = r; }
	inline Date getDater() { return this->returnday; }

	friend std::ostream& operator<<(std::ostream& s, const Offer&);
    bool operator==(const Offer &other) const;

private:
	string id;
	string departure;
	string destination;
	float price;

	//from class date:
	Date departureday;
	Date returnday;
};

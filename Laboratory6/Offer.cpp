#include "Offer.h"

Offer::Offer() {
	Date d;

	this->id = "0";
	this->departure = "home";
	this->destination = "dest";
	this->departureday = d;
	this->returnday = d;

}

std::ostream& operator<<(std::ostream &s, const Offer& offer) {
    s<<"Offer " << offer.id << " from " << offer.departure << " to " << offer.destination << ", price: "
     << offer.price << " date: " << offer.date;
    return s;
}

bool Offer::operator==(const Offer &other) const {
    return this->destination == other.destination && this->departure == other.departure &&
            this->id == other.id && this->price == other.price;
}
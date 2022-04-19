#include "OfferTest.h"
#include "FilteringTest.h"
#include "DynamicArrayTest.h"
#include "Date.h"
#include "DateTest.h"
#include "Offer.h"
#include "OfferTest.h"

#include <iostream>
using namespace std;

#include "DynamicArray.h"

Offer readoffer()
{
    string id;
    string depart;
    string dest;
    //string type;
    float price;
    int yy;
    int mm;
    int dd;
    cout<<"Id: ";
    cin>>id;
    cout<<"Departure: ";
    cin>>depart;
    cout<<"Destination: ";
    cin>>dest;
    //cout<<"Type: ";
    //cin>>type;
    cout<<"Price: ";
    cin>>price;
    cout<<"Year: ";
    cin>>yy;
    cout<<"Month: ";
    cin>>mm;
    cout<<"Day: ";
    cin>>dd;
    Date d(dd, mm, yy);
    Offer o(id, depart, dest, price, d);
    return o;
}


void displayMenu() {
	string message = "Please select your option:\n";
    message += "A|a add an offer\n";
    message += "S|s show all offers\n";
    message += "P|p filter offers by price\n";
    //message += "T|t filter offers by type\n";
    message += "B|b filter offers by type and price\n";
    message += "Q|q quit\n";

    cout<<"\n\n"<<message;

    bool running = true;
    char answer;

	while(running)
    {
        cout<<"\nOption: ";
        cin>>answer;
        if(answer == 'A' || answer == 'a'){
            Offer offer = readoffer();
            da.append(offer);
        }
        else if(answer == 'S' || answer == 's'){
            cout<<da;
        }
        else if(answer == 'P' || answer == 'p'){
            float price;
            cout<<"Price: ";
            cin>>price;
            FilterPrice fil(price);
            DynamicArray da1 = fil.filter(da);
            cout<<da1;
        }
        /*else if(answer == 'T' || answer == 't'){
            string type;
            cout<<"Type: ";
            cin>>type;
        }*/
        else if(answer == 'B' || answer == 'b'){
            float price;
            cout<<"Price: ";
            cin>>price;
            DynamicArray da1 = ftp.filter(da);
            cout<<da1;
        }
        else if(answer == 'Q' || answer == 'q'){
            cout<<"Quitting...\n";
            running = false;
        }
        else{
            cout<<"Invalid option\n";
        }
    }

}

int main() {

	DateTest::runAllTests();
	OfferTest::runAllTests();
	//FilteringTest::runAllTests();
	DynamicArrayTest::runAllTests();

	DynamicArray arr;
	//arr.append("DynamicArray class");
	//arr.append("NOT");
	//arr.append("tested");

	Date date;
	date.setday(10);
	date.setmonth(11);
	date.setyear(2022);

	Offer offer1;
	offer1.setdate(date);

	cout << arr << endl;
	
	displayMenu();
	
	return 0;
}
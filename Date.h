//
// Created by Daniel Pepin on 11/17/18.
//

#ifndef INC_9_4_DATE_H
#define INC_9_4_DATE_H

using namespace std;
    class Date
    {
    private:
        int  month;	//a private data field of Date class
        int  day;	//a  private data field of Date class
        int  year;	//a  private data field.
//All of these fields can only be accessed by
        //member-functions of the class.
    public:
        Date ();	// default constructor
        Date (int, int, int);  	//assignment constructor
        ~Date();          //destrictor
        int getMonth();
        int getDay();
        int getYear();
        void getDate();  //to get a date from the user and store it in a Date object.
        void setDate(int, int, int);	//for constructing and storing data
        void displayDate();	//to display an object on the screen
        void copyDate(Date);  //to copy a Date object to another
        int difference(Date);	//for subtraction operation
    };
    Date :: Date ()   // When called, it creates an object of this class and
    {		// initializes the data members of the object with zero.
        month = 0;
        day = 0;
        year = 0;
    }
    Date :: Date (int m, int d, int y)   //When called, it creates an object of this class
    {			// and initializes components with the received values.
        month = m;
        day = d;
        year = y;
    }
    Date:: ~Date()
    {

    }
//continued class implementation section
    int Date :: getMonth()  //to extract month component of a Date object
    {
        return month;
    }
    int Date :: getDay()  //to extract day component of a Date object
    {
        return day;
    }
    int Date :: getYear()  //to extract year component of a Date object
    {
        return year;
    }
    void Date :: getDate()
    {
        cout << "Enter the month, day and year separated by a space: ";
        cin >> month >> day >> year;
    }
    void Date :: displayDate()	// When called, it displays the date
    {
        cout  << month << "/" << day  << "/" << year << endl;
    }
    void  Date :: setDate (int mo, int da, int yr)	//to assign a date to a Date object
    {
        month = mo;
        day = da;
        year = yr;
    }
    void Date :: copyDate (Date d)
    {
        month = d.getMonth();
        day = d.getDay();
        year = d.getYear();
    }



#endif //INC_9_4_DATE_H

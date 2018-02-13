// Header --> Function Declarations

#include <iostream>
#include <string>

using namespace std;

#ifndef Person_H
#define Person_H

class Person{
	public:
		//Default Constructor
		Person();
		
		//Overload Constructor
		Person(string, string, int, string);
		
		//Destructor
		~Person();
		
		//Accessor Functions
		string getPhoneNumber() const;  
				//returns phone number
		string getAddress() const;
				//returns address
		int getAge() const;
				//returns age
		string getName() const;
				//returns name
		
	private:
		//Member Variables
		string newPhoneNumber;
		string newAddress;
		int newAge;
		string newName;
};

#endif

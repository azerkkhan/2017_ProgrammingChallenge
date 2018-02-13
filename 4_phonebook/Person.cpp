/*
create a phone book
search by name will pop information of phone number, address, age, and name
(hint, use “map" and "class")
please input at least 3 people in phone book
search one available in the phone book, 
search one unavailable
*/

#include "Person.h" //Function Definitions

Person::Person(){
	int newAge = 0;
	//String are automatically null when <string> is included.
}

Person::Person(string phoneNumber, string address, int age, string name){
	newPhoneNumber = phoneNumber;
	newAddress = address;
	newAge = age;
	newName = name;
}

Person::~Person(){}   

string Person::getPhoneNumber() const{
	return newPhoneNumber;
}

string Person::getAddress() const{
	return newAddress;
}

int Person::getAge() const{
	return newAge;
}

string Person::getName() const{
	return newName;
}
	


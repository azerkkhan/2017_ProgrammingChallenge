/*
create a phone book
search by name will pop information of phone number, address, age, and name
(hint, use “map" and "class")
please input at least 3 people in phone book
search one available in the phone book, 
search one unavailable
*/

#include<iostream>
#include<string>
#include <map>
#include "Person.h"

using namespace std;

int main(){
	//Information Variables
	string phoneNumber = "";
	string address = "";
	int age;
	string name = "";
	
	
	//Searching Variable.
	string searchName;
	
	//Create three Person objects.
	Person Person_1("8453384705", "266 Albany Ave", 23, "Azer"); //Create a Person 1 object.
	Person Person_2("8453995468", "147 Downs St.", 30, "Richard"); //Create a Person 2 object.
	Person Person_3("5184705635", "1 Plattekill Ave", 40, "Chen"); //Create a Person 3 object.
			
	//Unbreakable while statement to search.
	while(true){
			cout<<"Please search a name: ";
			getline(cin, searchName);
			
			if(searchName == "Azer"){
				cout<<endl<< "Number: "<< Person_1.getPhoneNumber()<<endl<<
				"Address: "<< Person_1.getAddress() << endl <<
				"Age: "<< Person_1.getAge() << endl <<
				"Name: " << Person_1.getName()<<endl;
			}
			else if (searchName == "Richard"){
				cout<<endl<< "Number: "<< Person_2.getPhoneNumber()<<endl<<
				"Address: "<< Person_2.getAddress() << endl <<
				"Age: "<< Person_2.getAge() << endl <<
				"Name: " << Person_2.getName()<<endl;
			}
			else if (searchName == "Chen"){
				cout<<endl<< "Number: "<< Person_3.getPhoneNumber()<<endl<<
				"Address: "<< Person_3.getAddress() << endl <<
				"Age: "<< Person_3.getAge() << endl <<
				"Name: " << Person_3.getName()<<endl;
			}
			else if(searchName != "Azer" && searchName != "Richard" && searchName != "Chen")	
				cout<<"Sorry, this name was not found. Please search again!"<<endl;
			cout<<endl;
		}
		
	
	
	
	
}
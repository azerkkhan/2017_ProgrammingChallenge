/*

---------
backpack (Knapsack) problem:
Given a set of different items, each one with an associated value and weight, 
determine which items you should pick in order to maximize the value of the 
items without surpassing the capacity of your backpack.

          First         Second         Third			Fourth		  Fifth
Value:  $5              $10             $3              $2              $3
Weight: 4 kg             8 kg           3 kg            5 kg   		  2 kg

backpack's weight limit is 10kg
---------

*/

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(){
	//array 1 holds price
	//array 2 holds weight at same index value as price
	vector<int> price  = {5, 10, 3, 2, 3};
	vector<int> weight = {4, 8, 3, 5, 2};
	
	vector<string> itemNames = {"First", "Second", "Third", "Fourth", "Fifth"}; 
	
	//create a count which detracts from the weight limit
	int currentWeight = 10; //Initialize this to a user input of the backpack's weight limit.
	int weightLimit = currentWeight;
	int itemPrice = price[0];
	int itemPriceIndex;
	int bagValue = 0;
	int itemWeight;
	
	//Assign the highest priced item's amount to the itemPrice variable.
	for (int i = 0; i<price.size(); i ++){
		if(itemPrice <= price[i]){ 
		itemPrice = price[i];
		itemPriceIndex = i;
		}
	}
	//cout<<"The most expensive item is "<<itemPrice<<" dollars."<<endl;
	//cout<<"The index of the most expensive item is "<<itemPriceIndex<<endl;
	
	bagValue = itemPrice; 
	currentWeight = currentWeight - weight[itemPriceIndex];
	
	while(currentWeight != 0){ //Pick items which will give your bag the greatest value.		 
		for(int i = 0; i<weight.size(); i++){
			if(weight[i] <= currentWeight){
				itemWeight = weight[i];
				itemPrice = price[i];
			}
		}
		bagValue = bagValue + itemPrice;
		currentWeight = currentWeight - itemWeight;
	}
	
	cout<<"The value of the bag is: "<<bagValue<<endl;
	cout<<"The weight of the bag is: "<< weightLimit<<endl;
	
	
	//find most expensive
	
}
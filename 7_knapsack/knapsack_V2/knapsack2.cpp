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
#include<vector>


using namespace std;

int	knapSack(int size, vector<int> weight, vector<int> price, int numberOfItems);
int Max(int a , int b);

int main(){
	int value = 0; //start off with no bag value.
	int size = 10; //size of item.
	int numberOfItems = 5;
	vector<int> price  = {5, 10, 3, 2, 3};
	vector<int> weight = {4, 8, 3, 5, 2};
	
	cout<<"The optimal value is: "<<knapSack(size, weight, price, numberOfItems)<<endl;
	return 0;

}

int	knapSack(int size, vector<int> weight, vector<int> price, int numberOfItems){
	//Building a table in bottom-up manner.
	int K[numberOfItems+1][size+1];
	
	for(int i = 0; i<=numberOfItems; i++){ //These for loops creates a bottom up 2-D table (K).
		for(int j = 0; j <= size; j++){
			if(i==0 || j==0){ //If there is no item or weight, the index of K is 0.
				K[i][j] = 0;
			}
			else if (weight[i-1] <= j){ //If the weight array's i-1 index is <= j
				K[i][j] = Max((price[i-1] + K[i-1][j-weight[i-1]]), K[i-1][j]); //Max(Exclude item, include item) Keeping track of value. 
			}
			else K[i][j] = K[i-1][j];
		}
	}
	return K[numberOfItems][size];
}

int Max(int a , int b){
	if (a>b) return a;
	else return b;
}

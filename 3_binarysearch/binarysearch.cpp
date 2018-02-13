#include<iostream>
#include<vector>

using namespace std;


vector<int> populateVector(vector<int> v);
void BinarySearch(vector<int> v, int beginning, int end, int val);
void printMatrix(vector<int> v);

int numberOfSteps = 1;
int beginning = 0;
int end = 0;

int main(){
	vector<int> myVector(90); //Create a vector.		
	myVector = populateVector(myVector); //Populate the vector with sorted list 10-99
	//printMatrix(myVector); //Print numbers from 10-99
	BinarySearch(myVector, 0, myVector.size(), 69); //Perform a binary search.
	cout<<"Count of number of steps: "<<numberOfSteps<<endl;
	}	

	void BinarySearch(vector<int> v, int beginning, int end, int val){ //Performs a binary search.
		int middle = (beginning+end)/2;
		//cout<<beginning<<", "<<end<<endl; Print beginnng and end to track right-leaning and left-leaning edge cases.
		//cout<<middle<<endl; print the new middle index.
		if((beginning+1==end) && v[middle] != val){
			cout<<"Value not found"<<endl;
		}
		else if(v[middle]<val){ //check if 69 is less than the value at index half.
			beginning = middle; //divide half, add that amount and check again.
			numberOfSteps++;
			BinarySearch(v, beginning, end, val); 
		}
		else if(v[middle]>val){ //check if 69 is greater than the value at index.
			end = middle;					
			numberOfSteps++;
			BinarySearch(v,beginning, end, val);
		}
		else if(v[middle] == val){ //If the value is found, print the location.
			cout<<"Index position: "<<middle<<endl;
		}
	}
	
	vector<int> populateVector(vector<int> v){
		int digits = 10;
		for(int i = 0; i<v.size(); i++){
			v[i] = digits;
			digits++;
		}
		return v;
	}
	
	void printMatrix(vector<int> v){
		for(int i=0; i<v.size(); i++){
				cout<<v[i]<<" , ";
		}
	}
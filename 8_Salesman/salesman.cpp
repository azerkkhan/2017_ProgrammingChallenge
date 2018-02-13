/*
Q8 Travelling Salesman Problem
Given a set of cities and distance between every pair of cities, the
 problem is to find the shortest possible route that visits every city 
 exactly once and returns to the starting point


*/
#include <bits/stdc++.h> //to retrive int_max
#include <vector>
using namespace std;
#define V 4


int travelingSalesman(vector<vector<int>> graph, int startingPt); //declare method to be used later.


int main(){
    // matrix representation of graph (4x4)
    vector<vector<int> > graph = { 
	{ 0, 10, 15, 20 },
    { 20, 0, 35, 25 },                       
	{ 15, 20, 0, 30 },
	{ 20, 25, 5, 0 }, 
	{ 10, 5, 35, 25 },
    { 10, 0, 35, 25 },
	{ 20, 15, 30, 0 },
	{ 0, 10, 15, 20 },
    { 10, 0, 35, 25 },                       
	{ 15, 35, 0, 30 },
	};
	//travelingSalesman(graph);
	int s = 0;
	cout<<travelingSalesman(graph, s)<<endl;
	
	
    return 0;
}

//Create a method that will find the shortest possible route that visits every city exactly once and returns to the starting point.
//naiive recursive, memoize, then bottom-upify
//How? Guessing. we want the shortest path from s to v (s is v).
//
int travelingSalesman(vector<vector<int>> graph, int s){
	
	//store all vertex apart from source vertex
	vector<int> vertex;
	for(int i = 0; i<V; i++)
		if(i != s)
			vertex.push_back(i);
	
	int min_path = INT_MAX; //not sure what this means.
	
	do{	
	int pathweight = 0; //assign a value.
	
	int k = s; //computing current path weight.
	for(int i = 0; i< vertex.size(); i++){
		pathweight += graph[k][vertex[i]];
		k = vertex[i];
	}
	pathweight += graph[k][s];
	
	//update minimum
	min_path = min(min_path, pathweight);
	
	} while(next_permutation(vertex.begin(), vertex.end()));
	
	return min_path;
}

	

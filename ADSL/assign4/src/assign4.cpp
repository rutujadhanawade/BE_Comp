//============================================================================
// Name        : assign4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define MAX 20
using namespace std;



class Stack
{
	string data[MAX];
	int top;
public:
	Stack()
	{
		top=-1;
	}
	bool full()
	{
		if(top==MAX-1)
			return true;
		else
			return false;
	}
	bool empty()
	{
		if(top==-1)
			return true;
		else
			return false;
	}
	void push(string x)
	{
		if(!full())
		{
			top++;
			data[top]=x;
		}
	}
	string pop()
	{
		if(!empty())
		{
			string x=data[top];
			top--;
			return x;
		}
	}
};
class city{
	string name;
	city* down;
	city* next;

	city(string X){
		name= X;
		next= NULL;
		down = NULL;

	}
friend class graph;

};
class plane{
	string name;
	plane* next;
	int time;

	plane(){
		next=NULL;
		time=0;
	}
	friend class graph;
	friend class city;

};
class graph{
	plane* p1;
	city * c1;
public:
	void create();


};
void graph::create(){
	int n,i;
	cout<<"enter number of cities and name of first city";
	cin>>n>>c1->name;

	city* temp;
	for(i=0;i<n;i++){

		cout<<"enter name of city";
		cin>>temp->name;


	}

}
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

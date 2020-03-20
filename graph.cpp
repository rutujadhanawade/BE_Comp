//============================================================================
// Name        : graph.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define max 3
using namespace std;

template <typename T>
class stack{

	T data[max];
	int top;
public:
	stack(){
		top=-1;
	}

	int isfull(){
		if(top==max-1) return 1;
		else return 0;
	}
	int isEmpty(){
		if(top==-1) return 1;
		else return 0;
	}
	void push(T a){
		if(!isfull()) data[++top]=a;

	}
	int pop(){
		T a;
		if(!isEmpty()) {
			a=data[top];
			top--;
		}
		return a;
	}
};
int main() {
	stack <int> s1;
	s1.push(10);
	s1.push(6);
	int a;
	a=s1.pop();
	cout<<a;
	a=s1.pop();
	cout<<a;
	s1.push(10);
	s1.push(9);
	s1.push(8);
	s1.push(4);
	
	a=s1.pop();cout<<a;
	return 0;
}


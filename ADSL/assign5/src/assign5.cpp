//============================================================================
// Name        : assign5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define MAX 20
#define inf 999
using namespace std;

class Stack {
	string data[MAX];
	int top;
public:
	Stack() {
		top = -1;
	}
	bool full() {
		if (top == MAX - 1)
			return true;
		else
			return false;
	}
	bool empty() {
		if (top == -1)
			return true;
		else
			return false;
	}
	void push(string x) {
		if (!full()) {
			top++;
			data[top] = x;
		}
	}
	string pop() {
		if (!empty()) {
			string x = data[top];
			top--;
			return x;
		}
	}
};

class graph {
	int Gmat[MAX][MAX];
	int cost, n;

public:
	void create();
	void display();
	void prims();
};

void graph::create() {
	int i, j;
	cout << "enter no. of offices  ";
	cin >> n;
	cout << "enter number of vertices";

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			Gmat[i][j] = 0;
	}
	int flag;
	do {
		cout << "enter offices which are connected(i,j)";
		cin >> i >> j;
		cout << "enter cost";
		cin >> cost;
		Gmat[i][j] = Gmat[j][i] = cost;
		cout << "do u want to add another?(enter 1)";
		cin >> flag;

	} while (flag == 1);
}
void graph::prims() {
	int i, j, min, i1, j1;
	int result[n][n], G[n][n], visited[n];

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			G[i][j] = Gmat[i][j];
	}

	for (i = 0; i < n; i++){

		visited[i] = 0;
	for (j = 0; j < n; j++) {
		if (G[i][j] == 0)
			G[i][j] = inf;
		result[i][j] = 0;
	}
	}

	visited[0] = 1;
	for (int k = 0; k < n - 1; k++) {
		min = inf;
		for (i = 0; i < n; i++) {
			if (visited[i] == 1) {

				for (j = 0; j < n; j++)
					if (min > G[i][j]) {
						min = G[i][j];
						i1 = i;
						j1 = j;
					}
			}
		}
		visited[j1] = 1;
		result[i1][j1]=min;
		result[j1][i1]=min;

	}

	cout<<"MST using prims algorithm is:"<<endl;
	int total=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++) {
			cout<<result[i][j]<<"  ";
			total+=result[i][j];
		}
		cout<<endl;
	}
	cout<<"total cost is:"<<total/2;

}
void graph::display() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << Gmat[i][j] << " ";

		cout << endl;
	}
}

int main() {

	graph g1;
	g1.create();
	g1.display();
	g1.prims();
	return 0;
}

//============================================================================
// Name        : assign7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define max 26
using namespace std;

class bucket {
	string symbol;
	string value;
	int chain;
public:
	bucket() {
		chain = -1;
	}
	friend class SymbolT;
};

class SymbolT {
	bucket T[max];
	int ascii;
	int visited[max];
public:
	SymbolT() {
		for (int i = 0; i < max; i++)
			visited[i] = 0;
		ascii = 0;

	}
public:
	int adjust(string x);
	void ins_without_replc();
	void ins_with_replc();
};

int SymbolT::adjust(string x) {
	int asci;
	if (x[0] >= 97)
		asci = x[0] - 97;
	else
		asci = x[0] - 65;
	ascii = ascii % max;
	return asci;
}
void SymbolT::ins_without_replc() {
	int c = 1;
	string key, key2;
	do {
		cout << "enter symbol";
		cin >> key;
		cout << "enter attribute;";
		cin >> key2;

		ascii = adjust(key);

		if (visited[ascii] == 0) {
			T[ascii].symbol = key;
			T[ascii].value = key2;
			visited[ascii] = 1;

		} else {
			while (T[ascii].chain != -1) {
				ascii = T[ascii].chain;
			}

			for (int i = ascii + 1; i != ascii; i = (i + 1) % 26) {
				if (i == max)
					i = 0;
				if (visited[i] == 0) {
					T[i].symbol = key;
					T[i].value = key2;
					visited[i] = 1;
					T[ascii].chain = i;
					break;
				}

			}
		}
		cout << "want to add more(enter 1)";
		cin >> c;

	} while (c == 1);
	for (int i = 0; i < 10; i++)
		cout << i << " " << T[i].symbol << " " << T[i].chain << endl;
}
void SymbolT::ins_with_replc() {
	int c = 1;
	string key, key2;
	do {
		cout << "enter symbol";
		cin >> key;
		cout << "enter attribute;";
		cin >> key2;

		ascii = adjust(key);

		if (visited[ascii] == 0) {
			T[ascii].symbol = key;
			T[ascii].value = key2;
			visited[ascii] = 1;

		}

		else if (ascii == adjust(T[ascii].symbol)) {
			while (T[ascii].chain != -1) {
				ascii = T[ascii].chain;
			}

			for (int i = ascii + 1; i != ascii; i = (i + 1) % 26) {
				if (i == max)
					i = 0;
				if (visited[i] == 0) {
					T[i].symbol = key;
					T[i].value = key2;
					visited[i] = 1;
					T[ascii].chain = i;
					break;
				}

			}
		} else {
			int act = adjust(T[ascii].symbol);
			//actual index
			int before = act;

			while (T[act].symbol != T[ascii].symbol) {
				before = act;
				act = T[act].chain;
			}
			for (int i = ascii + 1; i != ascii; i = (i + 1) % 26) {
				if (i == max)
					i = 0;
				if (visited[i] == 0) {
					T[i].symbol = T[ascii].symbol;
					T[i].value = T[ascii].value;
					visited[i] = 1;
					T[before].chain=i;
					T[i].chain = T[act].chain;
					break;
				}

			}

			T[ascii].symbol=key;
			T[ascii].value=key2;


		}
		cout << "want to add more(enter 1)";
		cin >> c;

	} while (c == 1);
	for (int i = 0; i < 10; i++)
		cout << i << " " << T[i].symbol << " " << T[i].chain << endl;
}
int main() {
	SymbolT t1;
	//t1.ins_without_replc();
 t1.ins_with_replc();
	return 0;
}

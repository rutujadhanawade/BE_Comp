#include<iostream>
#define max 10
using namespace std;

class hashtable {
	string dict[max];
	int visited[max];
	string key;
	int ascii;
	int T;

public:
	hashtable(int a) {
		T = a;
		ascii = 0;
		for (int i = 0; i < max; i++) {
			visited[i] = 0;

		}

	}
	int adjust(string x);
	void ins_without_replc();//without replacement
	void insert_with(); //with replacement
	void ins(int,string);
	void search(string key);
	void del(string k);
	void display();

};
void hashtable::ins(int ascii, string k){
	for (int i = 0; i < max; i++) {

						if (visited[ascii] == 0) {
							dict[ascii] = k;
							visited[ascii] = 1;
							break;
						}
						ascii = (ascii + 1) % T;
					}
}
int hashtable::adjust(string x) {
	int asci;
	if(x[0]>=97)
	 asci = x[0] - 97;
	else asci= x[0]-65;
	return asci;
}
void hashtable::insert_with() {
	int c = 1;
	do {
		cout << "enter keyword";
		cin >> key;
		ascii = adjust(key);
		ascii = ascii % T;

		if (visited[ascii] == 0) {
			dict[ascii] = key;
			visited[ascii] = 1;
		} else {
			if (ascii == (adjust(dict[ascii]) % T)) {
				ascii = (ascii + 1) % T;
				ins(ascii,key);
			}
			else {
				string temp = dict[ascii];
				dict[ascii] = key;

				ascii = (ascii + 1) % T;
				ins(ascii,temp);
			}

		}
		cout<<"do u want to add another(enter 1)";
		cin >> c;
	} while (c == 1);
	for (int i = 0; i < 10; i++)
		cout << dict[i] << endl;

}


void hashtable::ins_without_replc() {
	int c = 1;
	do {
		cout << "enter keyword";
		cin >> key;
		ascii = adjust(key);
		ascii = ascii % T;
		ins(ascii,key);
		cout << "want to add more(enter 1)";
		cin >> c;
	} while (c == 1);
	for (int i = 0; i < 10; i++)
		cout << dict[i] << i << endl;
}
void hashtable::search(string k) {
	ascii=adjust(k);
	ascii = ascii % T;
	int flag = 0;
	for (int i = 0; i < max; i++) {
		if(dict[ascii] == k) {
			cout<<"found "<<dict[ascii];
			flag=1;
			break;
		}
		else ascii=(ascii+1) % T;
} if(flag!=1) cout<<"NOTFOUND";
}
void hashtable::del(string k) {
	ascii=adjust(k);
	ascii = ascii % T;
	int flag = 0;
	for (int i = 0; i < max; i++) {
		if(dict[ascii] == k) {

			visited[ascii]=0;
			cout<<"SUCCESSFULLY DELETED";

			flag=1;
			break;
		}
		else ascii=(ascii+1) % T;
} if(flag!=1) cout<<"NOTFOUND";
for (int i = 0; i < 10; i++)
		cout << dict[i] << i << endl;
}
void hashtable::display(){
	for (int i = 0; i < 10; i++)
			cout << i <<"--"<< dict[i] << endl;
	}

int main() {

	int n,c,d;
	string k;
	cout << "enter table size\n";
	cin >> n;
	hashtable H1(n);

	cout<<"1. linear probing  without replacement\n2.linear probing with replacement";
	cin>>c;
	switch(c){
	case 1: H1.ins_without_replc();
	break;
	case 2:H1.insert_with();
	break;
	}
	cout<<"1.search \n2.delete \n3.Display";
	cin>>d;
	switch(d){
	case 1:cout<<"enter key";
	cin >> k;
	H1.search(k);
	break;
	case 2:cout<<"enter key;";
	cin >> k;
	H1.del(k);
	break;
	case 3:
		H1.display();
		break;
	}


	return 0;
}

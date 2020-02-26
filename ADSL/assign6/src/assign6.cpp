#include<iostream>
#define max 10
using namespace std;

class hashtable{
	string dict[max];
	string key;
	 int ascii;
	 int T;

public:
	 hashtable(int a){
		 T=a;
	ascii=0;

	 }
	 void insert();
	 void search(string key);
	 void del(string k);


};
void hashtable::insert(){
	int c=1;
do{
	cout<<"enter keyword";
	cin>>key;
	ascii= key[0]%T;
	for(int i=ascii;i<max;i++){

	if(dict[ascii].length()==0){
		dict[ascii]=key;
		cout<<dict[ascii]<<" "<<ascii;
	break;
	}
	}
	cout<<"want to add more??(enter 1)";
	cin>>c;
	}while(c==1);
for(int i=0;i<10;i++) cout<<dict[i]<<endl;
}
void hashtable::search(string k){
	ascii=k[0]%T;
	int flag=0;
	do{

	if(k==dict[ascii]){
		cout<<dict[ascii]<<" "<<ascii;
		flag=1;
	}
	else ascii++;
}while(flag==0||ascii!=T);
}
int main(){

	int n;
	cout<<"enter table size\n";
	cin>>n;
	hashtable H1(n);
	H1.insert();
	string k;
	cin>>k;
	H1.search(k);
	return 0;
}

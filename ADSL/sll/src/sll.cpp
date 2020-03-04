//============================================================================
// Name        : sll.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class sll {
public:

	struct node {
		int data;
		node *next;
	}*head;

	sll() {
		head = NULL;
	}
	void create();
	void add_beg();
	void add_end();

	void del();
	void display();
	void total();

};

void sll::create() {
	cout << "create linked list " << endl;

	int n;
	char s;
	do{
		cout << "enter data";
		cin >> n;
		node *temp = new node;
		temp->data = n;
		temp->next = NULL;

		if (head == NULL)
			head = temp;
		else {
			node *r = new node;
			r = head;
			while (r->next != NULL) r = r->next;

			r->next = temp;
		}
		cout << "do u want to enter another?(Y for yes) ";
		cin>>s;
	} while (s == 'Y');

}
void sll::add_beg() {
	node *temp = new node;
	int n;
	cout << "enter data ";
	cin >> n;
	temp->data = n;
	temp->next = head;
	head = temp;
}

void sll::add_end() {
	node *temp = new node;
	temp = head;
	int n;
	while (temp != NULL) {
		temp = temp->next;
	}
	node *r = new node;
	cout << "enter data";
	cin >> n;
	r->data=n;
	r->next = NULL;
	temp->next = r;
}

void sll::del() {
 int n;
	cout<<"enter element to be deleted ";
 cin>>n;


}
void sll::display() {
	node *temp = new node;
	temp = head;
	while (temp->next!= NULL) {
		cout << temp->data << endl;
		temp = temp->next;
	}
}
void sll::total(){
	node *temp = new node;
		temp = head;
		int tot=0;
		while (temp->next!= NULL) {
			temp = temp->next;
			tot++;
		}
		cout<<"total number of elements is "<<tot<<endl;
}
int main() {
	sll o1;
	o1.create();
	o1.display();
	o1.add_beg();
	o1.display();
	o1.total();
	o1.add_end();
	o1.display();

	return 0;
}

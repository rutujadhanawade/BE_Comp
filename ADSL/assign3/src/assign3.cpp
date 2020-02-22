//============================================================================
// Name        : assign3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node {
	node *left;
	node *right;
	int data;
	int rflg;
	int lflg;

	node() {
		left = NULL;
		right = NULL;
		rflg = 0;
		lflg = 0;

	}

	friend class TBT;
};

class TBT {
public:
	node *root;
	TBT() {
		root = NULL;
	}

	node* create();
	void inorder(node *);
	void preorder(node *);

};
node* TBT::create() {
	node *p = new node;
	cout << "enter data";
	cin >> p->data;
	if (root == NULL) {
		root = p;

	}

	else {
		int flag = 0;
		node * q = new node;
		q = root;
		do {
			if (p->data < q->data) {
				if (q->left == NULL || q->lflg == 1) {
					p->left = q->left;
					p->lflg = q->lflg;
					q->lflg = 0;
					q->left = p;
					p->right = q;
					p->rflg = 1;
					flag = 1;
				} else
					q = q->left;

			} else if (p->data > q->data) {
				if (q->right == NULL || q->rflg == 1) {
					p->right = q->right;
					p->rflg = q->rflg;
					q->rflg = 0;
					q->right = p;
					p->left = q;
					p->lflg = 1;
					flag = 1;
				} else
					q = q->right;
			}
		} while (flag != 1);
	}

	return root;
}

void TBT::inorder(node * root) {
	node * q = new node;
	q = root;

	while (q->left != NULL && q->lflg != 1) { //go to leftmost
		q = q->left;
	}
	while (q != NULL) {
		cout << q->data << endl;

		if (q->right != NULL && q->rflg == 1) { //follow right thread
			q = q->right;

		} else if (q->right == NULL)
			break; //last
		else {
			while (q->left != NULL && q->lflg != 1) //go to leftmost of right
				q = q->left;
		}

	}

}
void TBT::preorder(node *root) {
	node *q = new node;
	q = root;
	while (q != NULL) {
		cout << q->data << " ";
		if (q->left != NULL && q->lflg != 1)
			q = q->left;

		else if (q->rflg == 0)
			q = q->right;

		else {

			while (q->rflg == 1)
				q = q->right;
			if (q->right == NULL)
				break;
			else
				q = q->right;

		}
	}

}

int main() {

	TBT b1;
	int n;
	cout << "enter number of elements in tree  ";
	cin >> n;
	for (int i = 0; i < n; i++)
		b1.create();
	cout << "inorder is:" << endl;
	b1.inorder(b1.root);
	cout << "preorder is:" << endl;
	b1.preorder(b1.root);
	return 0;
}

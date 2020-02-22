//============================================================================
// Name        : assign2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class node {
	string keyw;
	int num;
	string meaning[5];
	node* left;
	node * right;

	friend class BST;
};

class BST {
public:
	node *root;
	BST() {
		root = NULL;
	}

	node* create() {
		int i = 0, j;
		node* p = new node;
		cout << "enter keyword";
		cin >> p->keyw;
		do {
			cout << "\nenter meaning";
			cin >> p->meaning[i];
			i++;
			cout << "want to add another meaning?(enter 1)";
			cin >> j;
		} while (j == 1);
		p->num = i;
		if (root == NULL)
			root = p;
		else {
			node* q = new node;
			int flag = 0;
			q = root;
			do {
				if (p->keyw < q->keyw) {
					if (q->left != NULL)
						q = q->left;
					else {
						q->left = p;
						flag = 1;
					}
				} else if (p->keyw > q->keyw) {
					if (q->right != NULL)
						q = q->right;
					else {
						q->right = p;
						flag = 1;
					}
				}
			} while (flag != 1);
		}
		return root;
	}
	void inorder(node *root) {
		if (root) {
			inorder(root->left);
			cout << root->keyw;
			for (int i = 0; i < root->num; i++)
				cout << "\t--" << root->meaning[i] << endl;
			inorder(root->right);
		}
	}
	
	void update(node *root) {
		string s;
		int flag = 0, n;
		cout << "enter word to be updated";
		cin >> s;
		node * q = new node;
		q = root;

		do {
			int i = q->num;
			if (s == q->keyw) {
				flag = 1;
				cout
						<< "want to\n1. add new meaning?\n2.delete the existing meaning ??";
				cin >> n;
				if (n == 1) {
					cout << "add new meaning to word";
					cin >> q->meaning[i];
					q->num = i + 1;
				} else if (n == 2) {
					for (int i = 0; i < q->num; i++)
						cout << "\t--" << q->meaning[i] << endl;
					cout << "enter meaning u want to delete";
					cin >> s;
					for (int i = 0; i < q->num; i++) {

						if (s == q->meaning[i]) {
							while (i < q->num) {
								q->meaning[i] = q->meaning[i + 1];
								i++;
							}

							q->num = i - 1;
							break;
						}
					}
				}
			} else if (s < q->keyw)
				q = q->left;
			else if (s > q->keyw)
				q = q->right;
			else {
				cout << "word not found";
				flag = 1;
			}

		} while (flag == 0);
	}
	node * delet(node* root, string s) {
		node *q = new node;

		//root=search(root,s);
		//if(!root) cout<<"elements doesnt exist";

		if (s > root->keyw)
			root->right = delet(root->right, s);
		else if (s < root->keyw)
			root->left = delet(root->left, s);

		else {
			if (root->left == NULL && root->right == NULL) {
				delete (root);
				return NULL;
			} else if (root->left == NULL) {
				q = root->right;
				delete (root);

				return q;
			} else if (root->right == NULL) {
				q = root->left;
				delete (root);

				return q;
			}
			q = in_suc(root->right);
			root->keyw = q->keyw;
			root->right = delet(root->right, s);
		}

		return root;
	}
	node* in_suc(node* temp) {			//calcs inorder successor

		while (temp->left != NULL)
			temp = temp->left;

		return temp;
	}

	void operator=(BST t) {
		root = copy(t.root);
	}
	node* copy(node *root) {
		node *q = new node;
		if (root) {
			q->keyw = root->keyw;
			q->num = root->num;
			for (int i = 0; i < root->num; i++)
				q->meaning[i] = root->meaning[i];
			q->left = copy(root->left);
			q->right = copy(root->right);
			return q;
		}
		return NULL;
	}
	node* search(node *root, string);

};

node* BST::search(node* root, string s) {
	if (root == NULL || root->keyw == s)
		return root;
	else if (root->keyw > s)
		return search(root->right, s);
	else if (root->keyw < s)
		return search(root->left, s);
}

int main() {
	BST b1, b2;
	int n, i;
	string s;
	cout << "create a dictionary\nenter no. of words in dictonary";
	cin >> n;
	for (i = 0; i < n; i++) {
		b1.create();
	}
	do {
		cout << "enter 1.add word 2.update 3.delete 4.search 5.display 6.copy";
		cin >> i;

		switch (i) {
		case 1:
			b1.create();
			cout << "added successfully\n";
			break;
		case 2:
			b1.update(b1.root);
			break;

		case 3:

			cout << "enter word to be deleted";
			cin >> s;
			b1.root = b1.delet(b1.root, s);
			break;

		case 4:
			cout << "enter word to be searched";
			cin >> s;
			b2.root = b1.search(b1.root, s);
			if (b2.root)
				cout << "found";
			else
				cout << "not found";
			break;

		case 5:
			b1.inorder(b1.root);
			break;

		case 6:
			b2 = b1;
			cout << "copied successfully";
			b2.inorder(b2.root);
			break;
		default:
			cout << "WRONG CHOICE";
			break;
		}
	} while (1);

	return 0;
}

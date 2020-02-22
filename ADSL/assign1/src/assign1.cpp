//============================================================================
// Name        : assign1.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stack>
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
class node {	
	int data;
	node* left;
	node* right;
	friend class binary_tree;
};
class binary_tree {
public:
	node *root, *root1;
	binary_tree() {
		root = NULL;
		root1 = NULL;
	}
	stack<node*> s1, s2;
	node * create() {
		node *p = new node;
		cout << "enter number";
		cin >> p->data;
		p->left = NULL;
		p->right = NULL;
		if (root == NULL)
			root = p;
		else {
			char c;
			node* q = new node;
			int flag = 0;
			q = root;
			do {
				cout<< "would you like to enter number to left(l) or right(r)??";
				cin >> c;

				if (c == 'l') {
					if (q->left == NULL) {
						q->left = p;
						flag = 1;
					} else
						q = q->left;

				}
				if (c == 'r') {
					if (q->right == NULL) {
						q->right = p;
						flag = 1;
					} else
						q = q->right;
				}
			} while (flag == 0);
		}
		return root;
	}

	void inorder(node *root1) {
		if (root1) {
			inorder(root1->left);
			cout << root1->data << " ";
			inorder(root1->right);
		}
	}
	void in_nonrec(node *root) {

		node * temp = new node;
		temp = root;

		do {
			while (temp != NULL) {
				s1.push(temp);
				temp = temp->left;

			}
			temp = s1.top();
			s1.pop();
			cout << temp->data << "  ";
			temp = temp->right;

		} while (temp != NULL || !s1.empty());

	}
	void post_nonrec(node* root) {
		node * temp = new node;
		if (root == NULL)
			return;

		s1.push(root);
		while (!s1.empty()) {
			temp = s1.top();
			s1.pop();
			s2.push(temp);
			if (root->right)
				s2.push(temp->right);
			if (root->left)
				s2.push(temp->left);
		}
		while (!s2.empty()) {
			temp = s2.top();
			s2.pop();
			cout << temp->data << " ";

		}
	}
	void pre_nonrec(node *root) {
		node * q = new node;
		q = root;
		do {
			while (q != NULL) {
				cout << q->data << " ";
				s1.push(q);
				q = q->left;
			}
			q = s1.top();
			s1.pop();
			q = q->right;
		} while (q != NULL || !s1.empty());
	}
	void preorder(node *root1) {
		if (root1) {
			cout << root1->data << " ";
			preorder(root1->left);
			preorder(root1->right);
		}

	}
	void postorder(node *root1) {
		if (root1) {
			postorder(root1->left);
			postorder(root1->right);
			cout << root1->data << " ";
		}
	}

	void leaf(node *root) {
		if (root) {
			leaf(root->left);
			if (root->right == NULL)
				cout << root->data << " ";
			else
				leaf(root->right);

		}
	}
	void inter(node *root1) {
		if (root1) {
			inter(root1->left);
			if (root1->left == NULL && root1->right == NULL)
				return;
			else if (root1 != root)
				cout << root1->data << " ";
			inter(root1->right);
		}
	}
	void operator =(binary_tree t1) {
		root = copy(t1.root);
	}
	node* copy(node *root) {
		node *rot1 = new node;
		if (root) {
			rot1->data = root->data;
			rot1->left = copy(root->left);
			rot1->right = copy(root->right);
			return rot1;

		}
		return NULL;
	}
	void delet(node * root) {

		if (root) {
			delet(root->left);
			delet(root->right);
			cout << "deleting " << root->data << endl;
			delete root;
		}

		return;
	}
	void mirror(node * root) {
		if (root == NULL)
			return;
		else {
			mirror(root->left);
			mirror(root->right);
			node *emp = root->left;
			root->left = root->right;
			root->right = emp;
		}
	}
	int equal(node* root, node *root1) {
		if ((root == NULL && root1 == NULL))
			return 1;
		else if (((root != NULL) && (root1 == NULL))
				|| ((root1 != NULL) && (root == NULL)))
			return 0;
		else
			return (equal(root->left, root1->left)
					&& equal(root->right, root1->right)
					&& root->data == root1->data);

	}
};

int main() {
	int n, m, x;
	binary_tree t1, t2;
	cout << "create binary tree\nenter number of elements in binary tree";
	cin >> n;

	for (int i = 0; i < n; i++) {
		t1.root = t1.create();
	}

	do {
		cout<< "enter your choice\n1.inordertraversal\n2.postorder traversal\n3.preorder traversal\n4.internal nodes& leaf nodes\n5.mirror image of tree\n6.compare tree\n7.assign to another tree\n8.delete tree";

		cin >> m;
		switch (m) {
		case 1:
			cout << "inorder traversal is(recursive)" << endl;
			t1.inorder(t1.root);
			cout << endl;
			cout << "inorder traversal is(non recursive)" << endl;
			t1.in_nonrec(t1.root);

			break;
		case 2:
			cout << "preorder traversal is(recursive)" << endl;
			t1.preorder(t1.root);
			cout << endl;
			cout << "preorder traversal is(nonrecursive)" << endl;
			t1.pre_nonrec(t1.root);
			break;

		case 3:
			cout << "postorder traversal is(recursive)" << endl;
			t1.postorder(t1.root);
			cout << endl;
			cout << "postorder traversal is(nonrecursive)" << endl;
			t1.post_nonrec(t1.root);

			break;

		case 4:
			cout << "internal nodes are :";
			t1.inter(t1.root);
			cout << endl;
			cout << "leaf nodes are: ";
			t1.leaf(t1.root);
			cout << endl;
			break;

		case 5:
			cout << "mirror image of tree is(inorder): ";
			t1.mirror(t1.root);
			t1.inorder(t1.root);
			cout << endl;
			break;

		case 6:
			cout<< "enter another tree :\nenter number of elements in binary tree";
			cin >> x;

			for (int i = 0; i < x; i++) {
				t2.root = t2.create();
			}
			if (t1.equal(t1.root, t2.root))
				cout << "both trees are equal" << endl;
			else
				cout << "not equal" << endl;
			break;
		case 7:

			t2 = t1;
			t2.inorder(t2.root);
			break;
		case 8:
			t1.delet(t1.root);
			cout << "tree deleted";
			break;
		}
	} while (1);

	return 0;
}


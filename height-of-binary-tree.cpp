#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
	Node(int var){
		this->data = var;
		this->left = this->right = NULL;
	}
}

int height(struct Node *root){
	if (root == NULL) return 0;
	int l = height(root->left);
	int r = height(root->right);
	return 1 + max(l, r);
}

int main(){
	Node *root = new Node(0);
	cout << height(root) << "\n";
	return 0;
}
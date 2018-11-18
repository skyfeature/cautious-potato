#include <iostream>
#include <vector>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
	Node(int val){
		this->data = val;
		this->left = this->right = NULL;
	}
};

Node *lca_bst_recursive(Node *root, n1, n2){
	if (n1 > n2) return lca_bst(root, n2, n1);
	if (root == NULL) return NULL;
	if (n1 < root->data && n2 < root->data) return lca_bst(root->left, n1, n2);
	else if (n1 > root->data && n2 > root->data) return lca_bst(root->right, n1, n2);
	else return root;
}

Node *lca_bst_iterative(Node *root, int n1, int n2){
	if (n1 > n2) return lca_bst(root, n2, n1);
	if (root == NULL) return NULL;
	while(root != NULL){
		if (n1 < root->data && n2 < root->data)
			root = root->left;
		else if (n1 > root->data && n2 > root->data)
			root = root->right;
		else break;
	}
	return root;
}

int main(){
	return 0;
}
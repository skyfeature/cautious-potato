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

bool find(Node *root, int key){
	if (root == NULL) return false;
	if (root->data == key) return true;
	if (find(root->left, key) || find(root->right, key))
		return true;
	return false;
}

Node *lca_help(Node *root, int n1, int n2){
	if (root == NULL) return NULL;
	if (root->data == n1 || root->data == n2) return root;
	Node *left_lca = lca_help(root->left, n1, n2);
	Node *right_lca = lca_help(root->right, n1, n2);
	if (left_lca && right_lca) return root;
	else if (left_lca) return lca_help(root->left, n1, n2);
	else return lca_help(root->right, n1, n2);
}

Node *lca(Node *root, int n1, int n2){
	if (find(root, n1) && find(root, n2)){
		return lca_help(root, n1, n2);
	}
	else{
		return NULL;
	}
}

int main(){
	return 0;
}
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

bool printPath(Node *root, Node *leaf){
	if (root == NULL) return false;
	if (root == leaf || printPath(root->left, leaf) || printPath(root->right, leaf)){
		cout << root->data << " ";
		return true;
	}
	return false;
}

pair<int, Node *> maxLeaf(Node *root){
	if (root == NULL) return make_pair(0, root);
	if (root->left == NULL && root->right == NULL)
		return make_pair(root->data, root);
	else{
		if (maxLeaf(root->left).first > maxLeaf(root->right).first){
			return make_pair(maxLeaf(root->left).first + root->data, maxLeaf(root->left).second);
		}
		else{
			return make_pair(maxLeaf(root->right).first + root->data, maxLeaf(root->right).second);
		}
	}
}

int main(){
	Node *root = new Node(1);
	root->left  = new Node(2); 
	root->right = new Node(3); 
	root->left->left  = new Node(8); 
	root->left->right = new Node(4);
	root->right->left  = new Node(5);
	root->right->right = new Node(6);
	root->left->right->left = new Node(10);
	root->right->left->left  = new Node(7);
	root->right->left->right = new Node(9);
	root->right->right->right = new Node(5);
	pair<int, Node*> p = maxLeaf(root);
	printPath(root, p.second);
	return 0;
}
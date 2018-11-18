#include <iostream>
#include <vector>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
	Node(int val){
		this->data = val;
		this->left = NULL;
		this->right = NULL;
	}
}

pair<int, int> diameter(Node *root){
	if (root == NULL) return make_pair(0, 0);
	pair<int, int> l = diameter(root->left);
	pair<int, int> r = diameter(root->right);
	int maxLengthToLeaf = root->data + max(l.first, r.first);
	int maxDiameter = root->data + l.first + r.first;
	maxDiameter = max(maxDiameter, max(l.second, r.second));
	return make_pair(maxLengthToLeaf, maxDiameter);
}

int main(){

	Node *root = new Node(0);
	pair<int, int> p = diameter(root);
	cout << "maxLengthToLeaf: " << p.first << "\n";
	cout << "maxDiameter: " << p.second << "\n";
	return 0;
}
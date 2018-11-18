#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
	Node(int val){
		this->data = val;
		this->left = this->right = NULL;
	}
};

bool findPath(Node *root, int key, vector<int> &path){
	if (root == NULL) return false;
	path.push_back(root->data);
	if (root->data == key) return true;
	if (findPath(root->left, key, path) || findPath(root->right, key, path)) {
		return true;
	}
	path.pop_back();
	return false;
}


int main(){
	int key;
	Node *root = new Node(0);
	root->left = new Node(2); 
	root->right = new Node(3); 
	root->left->left = new Node(4); 
	root->left->right = new Node(5); 
	root->right->left = new Node(6); 
	root->right->right = new Node(7);
	vector<int> path;
	cout << findPath(root, 6, path) << "\n";
	for (int i = 0; i < path.size(); i++)
		cout << path[i] << " ";
	cout << "\n";
	return 0;
}

// vector<int> findPathFromRootToNode(Node *root, int key){
// 	stack<Node *> st;
// 	st.push(root);
// 	while(!st.empty()){
// 		Node *node = st.top();
// 		if (node->data == key) 
// 			break;
// 		if (node->left != NULL)
// 			st.push(node->left);
// 		if (node->right != NULL)
// 			st.push(node->right);
// 		if (node->left == NULL && node->right == NULL)
// 			st.pop();
// 	}
// }
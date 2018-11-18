#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
	Node(int val){
		this->data = val;
		this->left = NULL;
		this->right = NULL;
	}
};

int main(){
	struct Node *root = new Node(1);
	// struct Node *l_root = (struct Node *)malloc(sizeof(struct Node));
	cout << root->data << "\n";
	return 0;
}
#include <iostream>
#include <vector>
#include <climits>
#include <list>
using namespace std;

struct Node{
	int idx;
	Node *left, *right;
};

Node* createNode(int idx){
	Node *t = new Node;
	t->idx = idx;
	t->left = NULL;
	t->right = NULL;
	return t;
}

void traverseHeight(Node *root, int arr[], int &res){
	if (root == NULL || (root->left == NULL && root->right == NULL))
		return;
	if (res > arr[root->left->idx] && root->left->idx != root->idx){
		res = arr[root->left->idx];
		traverseHeight(root->right, arr, res);
	}
	else if (res > arr[root->right->idx] && root->right->idx != root->idx){
		res = arr[root->right->idx];
		traverseHeight(root->left, arr, res);
	}
}

void findSecondMin(int arr[], int n){
	list<Node *>li;
	Node *root = NULL;
	for (int i = 0; i < n; i += 2){
		Node *t1 = createNode(i);
		Node *t2 = NULL;
		if (i + 1 < n){
			t2 = createNode(i+1);
			root = (arr[i] < arr[i+1])? createNode(i) : createNode(i+1);
			root->left = t1;
			root->right = t2;
			li.push_back(root);
		}
		else
			li.push_back(t1);
	}
	int lsize = li.size();

	while(lsize != 1){
		int last = (lsize & 1)? (lsize - 2) : (lsize - 1);
		for (int i = 0; i < last; i += 2){
			Node *f1 = li.front();
			li.pop_front();
			Node *f2 = li.front();
			li.pop_front();

			root = (arr[f1->idx] < arr[f2->idx])? createNode(f1->idx) : createNode(f2->idx);
			root->left = f1;
			root->right = f2;
			li.push_back(root);
		}

		if (lsize & 1){
			li.push_back(li.front());
			li.pop_front();
		}
		lsize = li.size();
	}
	int res = INT_MAX;
	traverseHeight(root, arr, res);
	cout << "Minimum: " << arr[root->idx] << ", Second minimum: " << res << "\n";
}

int main(){
	int arr[] = {61, 6, 100, 9, 10, 12, 17};
	int n = sizeof(arr)/sizeof(arr[0]);
	findSecondMin(arr, n);
	return 0;
}
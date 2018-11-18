#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node *next;
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

int ar[] = {3, 5, 2, 6, 4, 8, 0, 7};

Node *createList(int ar[], int n){
	Node *node = NULL;
	Node *rootNode = NULL;
	Node *lastNode = NULL;
	for (int i = 0; i < n; i++){
		if (!node){
			node = new Node(ar[i]);
			if (!rootNode)
				rootNode = node;
			if (lastNode)
				lastNode->next = node;
		}
		lastNode = node;
		node = node->next;
	}
	return rootNode;
}

void printList(Node *root){
	while (root != NULL){
		cout << root->data << " ";
		root = root->next;
	}
	cout << "\n";
}

void deleteList(Node *root){
	if (root){
		Node *newRoot = root->next;
		delete root;
		deleteList(newRoot);
	}
}

Node *findMid(Node *root){
	int count = 0;
	Node *move_half = root;
	while (root != NULL){
		root = root->next;
		count++;
		if (count%2 == 0)
			move_half = move_half->next;
	}
	return move_half;
}

int findNfromBack(Node *root, int n){
	int count = 0;
	Node *nthBack = root;
	while (root != NULL){
		root = root->next;
		count++;
		if (count >= n+1)
			nthBack = nthBack->next;
	}
	if (count >= n)
    	return nthBack->data;
    else
        return -1;
}

Node *reverseList(Node *root){
	if (root == NULL)
		return root;
	Node *rhead = NULL;
	int loop = 0;
	while (root->next != NULL){
		loop++;
		Node *temp = root->next;
		// cout << loop << " temp " << temp->data << "\n";
		root->next = rhead;
		// cout << loop << " root " << root->data << "\n";
		rhead = root;
		// cout << loop << " rhead " << rhead->data << "\n";
		root = temp;
		// cout << loop << " root__l " << root->data << "\n";
		// cout << "\n";
	}
	root->next = rhead;
	rhead = root;
	return rhead;
}

void reverseList1(Node *root){
	Node *temp = root;
	printf("jdjs\n");
	root->next = NULL;
	printf("sda\n");
	root = temp->next;
	printf("aiwq\n");
	// cout << root->data << " OuttempNextData\n";
	return;
}

Node *rotateList(Node *root, int k){
	Node *head = root;
	Node *kthEnd = NULL;
	Node *kthStart = NULL;
	Node *End = NULL;
	int count = 0;
	while(root->next != NULL){
		count++;
		if (count == k){
			kthEnd = root;
			kthStart = root->next;
			kthEnd->next = NULL;
			root = kthStart;
		}
		else{
			root = root->next;
		}
	}
	if (k <= 0)
		return head;
	if (count == 1)
		return head;
	if (k>count){
		return head;
	}
	root->next = head;
	head = kthStart;
	return head;
}

int main(){
	Node *root = createList(ar, sizeof(ar)/sizeof(int));
	printList(root);
	cout << findMid(root)->data << "\n";
	cout << findNfromBack(root, 1) << "\n";
	// Node *rroot = reverseList(root);
	// printList(rroot);
	// reverseList1(root);
	Node *rotroot = rotateList(root, 0);
	printList(rotroot);
	return 0;
}
/*
1
9
9 8 6 19 12 3 26 18 5
9
*/

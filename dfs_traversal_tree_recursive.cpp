#include <iostream>
#include <stack>
using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
    Node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};

void printPreorder(struct Node *root){
    if (root == NULL)
        return;
    printf("%d ", root->data);
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(struct Node *root){
    if (root == NULL)
        return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

void printPostorder(struct Node *root){
    if (root == NULL)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->data);
}

void printInorderStack(struct Node *root){
    if (root == NULL)
        return;
    stack<struct Node*> s;
    struct Node *curr = root;
    while(curr != NULL || s.empty() == false){
        while(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

int main(int argc, char *argv[]){
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    printf("PreOrder traversal of binary tree is \n");
    printPreorder(root);
    printf("\n");

    printf("InOrder traversal of binary tree is \n");
    printInorder(root);
    printf("\n");

    printf("PostOrder traversal of binary tree is \n");
    printPostorder(root);
    printf("\n");

    printf("InOrderStack traversal of binary tree is \n");
    printInorderStack(root);
    printf("\n");

    return 0;
}
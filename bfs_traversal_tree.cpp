#include <iostream>
#include <queue>
using namespace std;

struct node{
    int data;
    struct node *left, *right;
};

struct node *makeNode(int data){
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void printBFS(struct node *root){
    if (root == NULL)
        return;
    queue<struct node*> q;
    q.push(root);
    while(!q.empty()){
        struct node *node = q.front();
        printf("%d ", node->data);
        q.pop();

        if (node->left != NULL)
            q.push(node->left);
        
        if (node->right != NULL)
            q.push(node->right);
    }
}

int main(int argc, char const *argv[]){
    node *root = makeNode(1);
    root->left = makeNode(2);
    root->right = makeNode(3);
    root->left->left = makeNode(4);
    root->left->right = makeNode(5);
    
    printf("Level Order traversal of binary tree is \n");
    printBFS(root);
    printf("\n");

    return 0;
}

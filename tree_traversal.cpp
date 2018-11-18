#include <iostream>
#include <vector>
using namespace std;


struct node{
    int data;
    struct node *left, *right;
};

int height(struct node *root){
    if (root == NULL)
        return 0;
    else{
        int lheight = height(root->left);
        int rheight = height(root->right);
        return max(lheight, rheight)+1;
    }
}

void printGivenLevel(struct node *root, int level){
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1){
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

void printLevelOrder(struct node *root){
    int h = height(root);
    for (int i = 1; i <= h; i++){
        printGivenLevel(root, i);
    }
}

struct node *makeNode(int data){
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int main(int argc, char const *argv[]){
    struct node *root = makeNode(1);
    root->left = makeNode(2);
    root->right = makeNode(3);
    root->left->left = makeNode(4);
    root->left->right = makeNode(5);

    printf("Level Order traversal of binary tree is \n");
    printLevelOrder(root);
    printf("\n");
    return 0;
}

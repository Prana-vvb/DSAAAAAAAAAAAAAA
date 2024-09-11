#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    char val;
    struct NODE *prev;
    struct NODE *left;
    struct NODE *right;
}node;

node *create(char data) {
    node *newnode = (node*)malloc(sizeof(node));
   
    newnode->val = data;
    newnode->prev = NULL;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

void genTree(node *root) { //Example binary tree
    node *temp = root;

    temp->left = create('B');
    temp->right = create('G');
    temp->left->prev = temp->right->prev = root;
    temp = temp->left;

    temp->left = create('A');
    temp->right = create('D');
    temp->left->prev = temp->right->prev = temp;
    temp = temp->right;

    temp->left = create('C');
    temp->right = create('E');
    temp->left->prev = temp->right->prev = temp;
    temp = root->right;

    temp->right = create('I');
    temp->right->prev = temp;
    temp = temp->right;

    temp->left = create('H');
    temp->left->prev = temp;

    return;
}

void preTrav(node *root) { //Root->Left->Right
    if(root != NULL) {
        printf("%c ", root->val);
        preTrav(root->left);
        preTrav(root->right);
    }
}

void inTrav(node *root) { //Left->Root->Right
    if(root != NULL) {
        inTrav(root->left);
        printf("%c ", root->val);
        inTrav(root->right);
    }
}

void postTrav(node *root) { //Left->Right->Root
    if(root != NULL) {
        postTrav(root->left);
        postTrav(root->right);
        printf("%c ", root->val);
    }
}

int main() {
    node *root = create('F');
    genTree(root);

    preTrav(root);
    printf("\n");

    inTrav(root);
    printf("\n");

    postTrav(root);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

typedef struct BNODE {
    char val;
    struct BNODE *prev, *left, *right;
}bNode;

typedef struct NNODE {
    char dat;
    struct NNODE *prev, *sibling, *child;
}nNode;

bNode *createB(char data) {
    bNode *newnode = (bNode*)malloc(sizeof(bNode));
   
    newnode->val = data;
    newnode->prev = newnode->left = newnode->right = NULL;

    return newnode;
}

nNode *createN(char data) {
    nNode *newnode = (nNode*)malloc(sizeof(nNode));

    newnode->dat = data;
    newnode->prev = newnode->sibling = newnode->child = NULL;

    return newnode;
}

bNode *genTree(bNode *root) { //Example binary tree
    root = createB('F');
    bNode *temp = root;

    temp->left = createB('B');
    temp->right = createB('G');
    temp->left->prev = temp->right->prev = root;
    temp = temp->left;

    temp->left = createB('A');
    temp->right = createB('D');
    temp->left->prev = temp->right->prev = temp;
    temp = temp->right;

    temp->left = createB('C');
    temp->right = createB('E');
    temp->left->prev = temp->right->prev = temp;
    temp = root->right;

    temp->right = createB('I');
    temp->right->prev = temp;
    temp = temp->right;

    temp->left = createB('H');
    temp->left->prev = temp;

    return root;
}

void preTrav(bNode *root) { //Root->Left->Right
    if(root != NULL) {
        printf("%c ", root->val);
        preTrav(root->left);
        preTrav(root->right);
    }
}

void inTrav(bNode *root) { //Left->Root->Right
    if(root != NULL) {
        inTrav(root->left);
        printf("%c ", root->val);
        inTrav(root->right);
    }
}

void postTrav(bNode *root) { //Left->Right->Root
    if(root != NULL) {
        postTrav(root->left);
        postTrav(root->right);
        printf("%c ", root->val);
    }
}

int main() {
    bNode *root = NULL;
    root = genTree(root);

    preTrav(root);
    printf("\n");

    inTrav(root);
    printf("\n");

    postTrav(root);
    return 0;
}


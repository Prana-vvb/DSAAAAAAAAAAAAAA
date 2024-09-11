#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int val;
    struct NODE *prev;
    struct NODE *left;
    struct NODE *right;
}node;

node *create(int data) {
    node *newnode = (node*)malloc(sizeof(node));
   
    newnode->val = data;
    newnode->prev = NULL;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

void preTrav(node *root) { //Root->Left->Right
}

void inTrav(node *root) { //Left->Root->Right
}

void postTrav(node *root) { //Left->Right->Root
}

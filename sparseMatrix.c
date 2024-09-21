//Not really a sparse matrix. It's a linked list storing all the data required to build a sparse matrix
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int val, row, col;
    struct NODE *next;
}node;

node *createNewNode(node*root, int dat, int row, int col) {
    node *temp = root;
    node *newNode = (node*)malloc(sizeof(node));

    newNode->val = dat;
    newNode->row = row;
    newNode->col = col;
    newNode->next = NULL;

    if (root == NULL) { root = newNode; }
    else {
        while (temp->next != NULL) { temp = temp->next; }
        temp->next = newNode;
    }

    return root;
}

void printList(node* root) {
    node* temp = root;

    printf("Row\tCol\tValue\n");
    while (temp != NULL) {
        printf("%d\t%d\t%d\n", temp->row, temp->col, temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int mat[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    node *root = NULL;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (mat[i][j] != 0) {
                root = createNewNode(root, mat[i][j], i, j);
            }
        }
    }

    printList(root);

    return 0;
}


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

node *insertAtBeg(node *head, int data) {
    node *newnode = create(data);

    if(head == NULL) {
        head = newnode;
        return head;
    }

    newnode->next = head;
    head->prev = newnode;
    head = newnode;

    return head;
}

node *insertAtEnd(node *head, int data) {
    node *newnode = create(data);
    node *temp = head;

    if(head == NULL) { 
        head = newnode;
        return head;
    }

    while(temp->next != NULL) { temp = temp->next; }
    temp->next = newnode;
    newnode->prev = temp;

    return head;
}

node *insertAtPos(node *head, int data, int pos, int l) {
    if(pos < 0 || pos > l) {
        printf("Invalid position\n");
        return head;
    }

    if(pos == 0) { return insertAtBeg(head, data); }

    node *newnode = create(data);
    node *temp = head;


    for(int i = 0;i < pos - 1;i++) {
        if(temp == NULL) {
            printf("Invalid position\n");
            free(newnode);
            return head;
        }
        temp = temp->next;
    }
    
    if(temp == NULL) {
        printf("Invalid position\n");
        free(newnode);
        return head;
    }

    if(temp->next == NULL) { return insertAtEnd(head, data); }

    node *temp0 = temp->next;
    temp->next = newnode;
    temp0->prev = newnode;
    newnode->prev = temp;
    newnode->next = temp0;

    return head;
}

node *freeStart(node *head) {
    if(head == NULL) { return NULL; }
    
    if(head->next == NULL) {
        free(head);
        return NULL;
    }

    node *temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);

    return head;
}

node *freeEnd(node *head) {
    if(head == NULL) { return NULL; }

    if(head->next == NULL) {
        free(head);
        return NULL;
    }

    node *temp = head;

    while(temp->next->next != NULL) { temp = temp->next; }
    
    free(temp->next);
    temp->next = NULL;

    return head;
}

node *freeAtPos(node *head, int pos, int l) {
    if(pos < 0 || pos >= l) {
        printf("Invalid position\n");
        return head;
    }

    if(pos == 0) { return freeStart(head); }
    else if(pos == l - 1) { return freeEnd(head); }

    node *temp = head;
    for(int i = 0;i < pos;i++) { temp = temp->next; }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);

    return head;
}

node *freeAll(node *head){
    while(head != NULL && head->next != NULL) { head = freeStart(head); }

    if(head != NULL) { free(head); }
    return NULL;
}

void display(node *head) {
    node *temp = head;

    if (temp == NULL) {
      printf("List is empty.\n");
      return;
    }
    
    while(temp != NULL) {
      printf("%d ", temp->dat);
      temp = temp->next;
    }
    printf("\n");
}

int size(node *head) {
    node *temp = head;
    int l = 0;

    while(temp != NULL && temp->next != NULL) {
        l++;
        temp = temp->next;
    }
    
    l++;
    return l;
}


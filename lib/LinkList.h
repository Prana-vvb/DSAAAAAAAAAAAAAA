#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int dat;
    struct node *next;
}NODE;

NODE *create(int data) {
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
   
    newnode->dat = data;
    newnode->next = NULL;

    return newnode;
}

NODE *insertAtBeg(NODE *head, int data) {
    NODE *newnode = create(data);

    if(head == NULL) {
        head = newnode;
        return head;
    }

    newnode->next = head;
    head = newnode;

    return head;
}

NODE *insertAtEnd(NODE *head, int data) {
    NODE *newnode = create(data);
    NODE *temp = head;

    if(head == NULL) { 
        head = newnode;
        return head;
    }

    while(temp->next != NULL) { temp = temp->next; }
    temp->next = newnode;

    return head;
}

NODE *insertAtPos(NODE *head, int data, int pos, int l) {
    if(pos < 0 || pos > l) {
        printf("Invalid position\n");
        return head;
    }

    if(pos == 0) {return insertAtBeg(head, data); }

    NODE *newnode = create(data);
    NODE *temp = head;

    for(int i = 0;i < pos -1;i++) {
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

    NODE *temp0 = temp->next;
    temp->next = newnode;
    newnode->next = temp0;

    return head;
}

NODE *freeStart(NODE *head) {
    if(head == NULL) { return NULL; }

    if(head->next == NULL) {
        free(head);
        return NULL;
    }

    NODE *temp = head;
    head = head->next;
    free(temp);

    return head;
}

NODE *freeEnd(NODE *head) {
    if(head == NULL) { return NULL; }

    if(head->next == NULL) {
        free(head);
        return NULL;
    }

    NODE *temp = head;

    while(temp->next->next != NULL) { temp = temp->next; }
    
    free(temp->next);
    temp->next = NULL;

    return head;
}

NODE *freeAtPos(NODE *head, int pos, int l) {
   if(pos < 0 || pos >= l) {
        printf("Invalid position\n");
        return head;
    }

    if(pos == 0) { return freeStart(head); }
    else if(pos == l - 1) { return freeEnd(head); }
    
    NODE *temp = head;
    NODE *tempPrev;

    for(int i = 0;i < pos;i++) {
        tempPrev = temp;
        temp = temp->next;
    }

    tempPrev->next = temp->next;
    free(temp);

    return head;
}

NODE *freeAll(NODE *head){
    while(head != NULL && head->next != NULL) { head = freeStart(head); }

    if(head != NULL) { free(head); }
    return NULL;
}

void display(NODE *head) {
    NODE *temp = head;

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

int size(NODE *head) {
    NODE *temp = head;
    int l = 0;

    while(temp != NULL && temp->next != NULL) {
        l++;
        temp = temp->next;
    }
    
    l++;
    return l;
}


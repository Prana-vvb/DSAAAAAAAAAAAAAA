#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int dat;
    struct node *prev;
    struct node *next;
}NODE;

NODE *create(int data) {
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
   
    newnode->dat = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    return newnode;
}

NODE *insertAtBeg(NODE *head, int data) {
    NODE *newnode = create(data);

    if(head == NULL) {
        newnode->prev = newnode;
        newnode->next = newnode;
        return newnode;
    }

    NODE *temp = head;
    while(temp->next != head) { temp = temp->next; }
    newnode->prev = temp;
    newnode->next = head;
    head->prev = newnode;
    temp->next = newnode;
    head = newnode;

    return head;
}

NODE *insertAtEnd(NODE *head, int data) {
    NODE *newnode = create(data);

    if(head == NULL) {
        newnode->prev = newnode;
        newnode->next = newnode;
        return newnode;
    }

    NODE *temp = head;
    while(temp->next != head) { temp = temp->next; }
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = head;
    head->prev = newnode;

    return head;
}

NODE *insertAtPos(NODE *head, int data, int pos, int l) {
    if(pos < 0 || pos > l) {
        printf("Invalid position\n");
        return head;
    }

    if(pos == 0) { return insertAtBeg(head, data); }
    else if(pos == l - 1) { return insertAtEnd(head, data); }

    NODE *newnode = create(data);
    NODE *temp = head;

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

    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;

    return head;
}

NODE *freeStart(NODE *head) {
    if(head == NULL) { return NULL; }

    if(head->next == head) {
        free(head);
        return NULL;
    }

    NODE *tail = head;
    while(tail->next != head) { tail = tail->next; }
    
    tail->next = head->next;
    head->next->prev = tail;
    NODE *temp = head;
    head = head->next;

    free(temp);

    return head;
}

NODE *freeEnd(NODE *head) {
    if(head->next == head) {
        free(head);
        return NULL;
    }

    NODE *temp = head;
    while(temp->next->next != head) { temp = temp->next; }
    
    free(temp->next);
    temp->next = head;
    head->prev = temp;

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
    for(int i = 0;i < pos - 1;i++) { temp = temp->next; }

    NODE *temp0 = temp->next;
    temp->next = temp0->next;
    temp0->next->prev = temp;
    free(temp0);

    return head;
}

NODE *freeAll(NODE *head){
    while(head != NULL && head->next != head) { head = freeStart(head); }

    if(head != NULL) { free(head); }
    return NULL;
}

void display(NODE *head) {
    if (head == NULL) {
      printf("List is empty.\n");
      return;
    }
    
    NODE *temp = head;
    do {
      printf("%d ", temp->dat);
      temp = temp->next;
    } while(temp != head);
    printf("\n");
}

int size(NODE *head) {
    NODE *temp = head;
    int l = 0;

    while(temp != NULL && temp->next != head) {
        l++;
        temp = temp->next;
    }
    
    l++;
    return l;
}


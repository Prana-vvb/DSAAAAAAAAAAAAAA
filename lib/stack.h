#include <stdio.h>
#include <stdlib.h>


typedef struct STACK {
    char val;
    struct STACK *next;
} stack;

stack *create(char data) {
    stack *newnode = (stack*)malloc(sizeof(stack));
    newnode->val = data;
    newnode->next = NULL;
    return newnode;
}

void push(stack **top, char data) {
    stack *newnode = create(data);
    newnode->next = *top;
    *top = newnode;
}

char pop(stack **top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        return '\0';
    }

    stack *temp = *top;
    char c = temp->val;
    *top = (*top)->next;
    free(temp);

    return c;
}

//Old stack that directly prints popped values instead of returning
/*typedef struct STACK{*/
/*    char val;*/
/*    struct STACK *next;*/
/*}stack;*/
/**/
/*stack *create(char data) {*/
/*    stack *newnode = (stack*)malloc(sizeof(stack));*/
/**/
/*    newnode->val = data;*/
/*    newnode->next = NULL;*/
/**/
/*    return newnode;*/
/*}*/
/**/
/*stack *push(stack *top, char data) {*/
/*    stack *newnode = create(data);*/
/**/
/*    if(top == NULL) {*/
/*        top = newnode;*/
/*        return top;*/
/*    }*/
/**/
/*    newnode->next = top;*/
/*    top = newnode;*/
/**/
/*    return top;*/
/*}*/
/**/
/*stack *pop(stack *top) {*/
/*    if(top == NULL) {*/
/*        printf("Stack underflow\n");*/
/*        return NULL;*/
/*    }*/
/**/
/*    if(top->next == NULL) {*/
/*        printf("%c", top->val);*/
/*        free(top);*/
/*        return NULL;*/
/*    }*/
/**/
/*    stack *temp = top;*/
/*    top = top->next;*/
/*    printf("%c", temp->val);*/
/*    free(temp);*/
/**/
/*    return top;*/
/*}*/

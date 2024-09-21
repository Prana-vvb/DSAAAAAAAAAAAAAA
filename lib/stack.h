#include <stdio.h>
#include <stdlib.h>

typedef struct STACK{
    char val;
    struct STACK *next;
}stack;

stack *create(char data) {
    stack *newnode = (stack*)malloc(sizeof(stack));
   
    newnode->val = data;
    newnode->next = NULL;

    return newnode;
}

stack *push(stack *top, char data) {
    stack *newnode = create(data);

    if(top == NULL) {
        top = newnode;
        return top;
    }

    newnode->next = top;
    top = newnode;

    return top;
}

stack *pop(stack *top) {
    if(top == NULL) {
        printf("Stack underflow\n");
        return NULL;
    }

    if(top->next == NULL) {
        printf("%c", top->val);
        free(top);
        return NULL;
    }

    stack *temp = top;
    top = top->next;
    printf("%c", temp->val);
    free(temp);

    return top;
}

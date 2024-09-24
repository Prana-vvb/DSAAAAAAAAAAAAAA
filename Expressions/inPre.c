//Infix to Prefix expression converter
//Reverse input string -> Dijkstra's Shunting Yard algorithm(Convert to Postfix) -> Reverse resulting string to get Prefix expression
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Modified stack that returns popped value instead of directly printing
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

int precedence(char symb) {
    switch(symb) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

int isNotOp(char c) {
   switch(c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
            return 0;
        default:
            return 1;
    }
}

char* reverse(char* str) {
    int n = strlen(str);
    char* rev = (char*)malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; i++) { rev[i] = str[n - i - 1]; }
    rev[n] = '\0';
    return rev;
}

char* shYard(stack **top, char *inp, int l) {
    char* out = (char*)malloc((2 * l + 1) * sizeof(char));
    out[0] = '\0';

    for (int i = 0; i < l; i++) {
        char symb = inp[i];

        if (isNotOp(symb)) {
            char temp[2] = {symb, '\0'};
            strcat(out, temp);
        }
        else if (symb == '(') { push(top, symb); }
        else if (symb == ')') {
            while (*top != NULL && (*top)->val != '(') {
                char op = pop(top);
                char temp[2] = {op, '\0'};
                strcat(out, temp);
            }
            pop(top);
        } else {
            while (*top != NULL && precedence(symb) < precedence((*top)->val)) {
                char op = pop(top);
                char temp[2] = {op, '\0'};
                strcat(out, temp);
            }
            push(top, symb);
        }
    }

    while (*top != NULL) {
        char op = pop(top);
        char temp[2] = {op, '\0'};
        strcat(out, temp);
    }

    return out;
}

int main() {
    char inp[100];
    printf("Enter infix expression: ");
    scanf("%s", inp);

    char* revInp = reverse(inp);
    stack *top = NULL;
    char* res = shYard(&top, revInp, strlen(revInp));
    char* finalRes = reverse(res);

    printf("Prefix expression: %s\n", finalRes);

    free(revInp);
    free(res);
    free(finalRes);

    return 0;
}

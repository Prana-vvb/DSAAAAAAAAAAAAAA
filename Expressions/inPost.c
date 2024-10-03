//Infix to Postfix expression converter using Dijkstra's Shunting Yard algorithm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/stack.h"

int precedence(char symb) {
    switch(symb) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

char associativity(char c) {
    if(c == '^') { return 'R'; }
    return 'L';
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

    stack *top = NULL;
    char *res = shYard(&top, inp, strlen(inp));
    printf("Postfix Expression: %s\n", res);

    return 0;
}

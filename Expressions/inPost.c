//Infix to Postfix expression converter using Dijkstra's Shunting Yard algorithm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../lib/stack.h"

int precedence(char symb) {
    switch (symb) {
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

void shYard(stack **top, char *inp, int l) {
    for (int i = 0; i < l; i++) {
        char symb = inp[i];

        if (isdigit(symb)) { printf("%c", symb); }
        else if (symb == '(') { *top = push(*top, symb); }
        else if (symb == ')') {
            while (*top != NULL && (*top)->val != '(') { *top = pop(*top); }
            *top = pop(*top);
        }
        else {
            while (*top != NULL && precedence(symb) <= precedence((*top)->val)) { *top = pop(*top); }
            *top = push(*top, symb);
        }
    }

    while (*top != NULL) { *top = pop(*top); }
}

int main() {
    char inp[100];
    printf("Enter infix expression: ");
    scanf("%s", inp);

    stack *top = NULL;
    printf("Postfix Expression: ");
    shYard(&top, inp, strlen(inp));
    printf("\n");

    return 0;
}

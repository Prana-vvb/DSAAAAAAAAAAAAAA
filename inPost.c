//Infix to Postfix expression converter using Dijkstra's Shunting Yard algorithm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "lib/stack.h"

int prec(stack *top, char symb) {
    if(((top->val == '+' || top->val == '-' || top->val == '/') && symb == '*') || ((top->val == '+' || top->val == '-') && symb == '/') || (top->val == '-' && symb == '+')) { return 0; }
    return 1;
}

int main() {
    int l = 0;
    printf("Enter expression length: ");
    scanf("%d", &l);
    char inp[l];
    printf("Enter infix expression: ");
    scanf("%s", inp);

    stack *top = NULL;
    for(int i = 0;i < l;i++) {
        char symb = inp[i];

        if(isdigit(symb)) { printf("%c", symb); }
        else if(symb == '(') { top = push(top, symb); }
        else if(symb == ')') {
            while(top != NULL && top->val != '(') { top = pop(top); }
            top = pop(top);
        }
        else {
            while(top != NULL && prec(top, symb)) { top = pop(top); }
            top = push(top, symb);
        }
    }

    while(top != NULL) { top = pop(top); }

    return 0;
}

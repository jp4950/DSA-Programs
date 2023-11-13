
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mystack.h"

int precedence(char operator){
    if(operator == '+' || operator == '-'){return 1;}
    else if(operator == '*' || operator == '/'){return 2;}
    else if(operator == '^'){return 3;}
    else{return -1;}
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}


char* infixToPostfix(char* infix) {
    int i, j;
    int len = strlen(infix);
    char* postfix = (char*)malloc(sizeof(char) * (len + 2));
    mystackp stack = new();
    
    for (i = 0, j = 0; i < len; i++) {
        if (infix[i] == ' ' || infix[i] == '\t')
            continue;

        // If the scanned character is an operand, add it to the postfix expression
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }

        // If the scanned character is '(', push it onto the stack
        else if (infix[i] == '(') {
            push(stack, infix[i]);
        }

        // If the scanned character is ')', pop the stack and add it to the output string until empty or '(' found
        else if (infix[i] == ')') {
            while (!isEmpty(stack) && top(stack) != '(') {
                postfix[j++] = top(stack);
                pop(stack);
            }
            if (!isEmpty(stack) && top(stack) != '(') {
                free(postfix);
                return "Invalid Expression";
            } else {
                pop(stack); // Pop the '('
            }
        }

        // If the scanned character is an operator, push it onto the stack
        else if (isOperator(infix[i])) {
            while (!isEmpty(stack) && precedence(top(stack)) >= precedence(infix[i])) {
                postfix[j++] = top(stack);
                pop(stack);
            }
            push(stack, infix[i]);
        }
    }

    while (!isEmpty(stack)) {
        if (top(stack) == '(') {
            free(postfix);
            return "Invalid Expression";
        }
        postfix[j++] = top(stack);
        pop(stack);
    }

    postfix[j] = '\0';
    free(stack);
    return postfix;
}

int main(){
    char infix[] = "A+B*(C-D)/E"; //Example Infix

    char* postfix = infixToPostfix(infix);
    printf("%s\n", postfix);
    return 0;
}

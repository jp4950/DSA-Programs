#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mystack.h"

mystackp new() {
    mystackp stack;
    stack = (mystackp)malloc(sizeof(struct mystack));
    stack->top = -1;
    stack->maxsize = 100;
    return stack;
}

int size(mystackp stack) {
    return stack->top + 1;
}

bool isEmpty(mystackp stack) {
    return (stack->top == -1);
}

void push(mystackp stack, int data) {
    if (size(stack) == stack->maxsize - 1) {
        printf("Stack is full");
        return;
    }
    stack->S[++stack->top] = data;
}

void pop(mystackp stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty");
        return;
    }
    stack->top--;
}

int top(mystackp stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty");
        return -1;
    }
    return stack->S[stack->top];
}

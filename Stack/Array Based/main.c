#include <stdio.h>
#include "mystack.h"

int main() {
    mystackp stack;
    stack = new();

    push(stack, 5);
    push(stack, 10);
    push(stack, 15);
    push(stack, 20);

    printf("%d\n", top(stack));

    pop(stack);
    printf("%d\n", top(stack));
    pop(stack);
    printf("%d\n", top(stack));

    return 0;
}

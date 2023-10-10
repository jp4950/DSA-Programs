#include <stdio.h>
#include <stdbool.h>

struct mystack {
    int S[100];
    int top;
    int maxsize;
};

typedef struct mystack* mystackp;

mystackp new();

void push(mystackp, int);

void pop(mystackp);

int top(mystackp);

bool isEmpty(mystackp);

int size(mystackp);


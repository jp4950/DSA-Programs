#include <stdio.h>
#include "myqueue.h"

int main(){
    myqueuep queue;
    queue = new();
    
    Enqueue(queue,5);
    Enqueue(queue,10);
    Enqueue(queue,15);
    Enqueue(queue,15);
    Enqueue(queue,15);
    
    printf("%d",Front(queue));
    
}
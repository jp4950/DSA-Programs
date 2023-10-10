#include "mystack.h"
#include <stdio.h>

void toh(int n,mystackp s,mystackp a,mystackp d){
    if(n == 1){
        push(d,top(s)); pop(s);
        return;
    }
    toh(n-1,s,d,a);
    push(d,top(s)); pop(s);
    toh(n-1,a,s,d);
    
}

int main(){
    mystackp source; source = new();
    mystackp auxillary; auxillary = new();
    mystackp destination; destination = new();
    
    //Considering there are 4 discs in the Source Stack
    push(source,1); 
    push(source,2);
    push(source,3);
    push(source,4);
    
    //Calling the function
    toh(4,source,auxillary,destination);
    
    //Ensuring that Source Stack becomes empty
    if(isEmpty(source)){
        printf("Source is Empty\n");
    }
    
    //Printing all the elements in the Destination Stack
    for(int i=0;i<4;i++){
        printf("%d ",top(destination)); pop(destination);
    }
    
    return 0;
}
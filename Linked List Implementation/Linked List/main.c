#include <stdio.h>
#include "linkedlist.h"


int main() {
    arrayL *al = Create_AL();
    
    InsertAtBeg_AL(&al, 5);
    InsertAtBeg_AL(&al, 10);
    InsertAtBeg_AL(&al, 15);
    InsertAtPos_AL(&al, 7, 2);
    
    Print_AL(al);
    
    DeleteAtBeg_AL(&al);
    DeleteAtPos_AL(&al, 2);
    
    Print_AL(al);
    
    return 0;
}

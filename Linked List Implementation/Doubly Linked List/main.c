#include <stdio.h>
#include "doublylinked.h"


int main() {
    arrayDL *dl = Create_DL();
    
    InsertAtBeg_DL(&dl, 5);
    InsertAtBeg_DL(&dl, 10);
    InsertAtBeg_DL(&dl, 15);
    InsertAtPos_DL(&dl, 7, 2);
    
    Print_DL(dl);
    
    DeleteAtBeg_DL(&dl);
    DeleteAtPos_DL(&dl, 2);
    
    Print_DL(dl);
    
    return 0;
}

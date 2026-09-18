// #include "stackArray.h"
// #include "stackLinked.h"
// #include "queueArray.h"
//#include "queueLinked.h"
// #include "listArray.h"
// #include "listLinked.h"
#include "cursor.h"

#include <stdio.h>
#include <string.h>

// void insertBottom(Stack *A, char val){
//     Stack temp;
//     initStack(&temp);

//     while(isEmpty(*A) != TRUE){
//         push(&temp, top(*A));
//         pop(A);
//     }
//     push(A, val);

//     while(isEmpty(temp) != TRUE){
//         push(A, top(temp));
//         pop(&temp);
//     }
// }

int main(){
    Student studrec[] = {
        {2510, {"Ashley", 'S', "Munoz"}, "BSIS"},
        {2382, {"Benedict", 'T', "Nielson"}, "BSIT"},
        {5102, {"John", 'U', "Olsen"}, "BSIT"},
        {3822, {"Cara", 'V', "Danvers"}, "BSCS"},
        {1023, {"Lena", 'W', "Luthor"}, "BSIT"},
        {8225, {"John", 'X', "Munoz"}, "BSIS"},
        {2511, {"Shane", 'B', "Cadiz"}, "BSN"},
    };
    int len = sizeof(studrec)/sizeof(studrec[0]);

    List L;
    initList(&L);

    for(int i = 0; i < len; i++){
        insertLast(&L, studrec[i]); //use for list
        // push(&L, studrec[i]); //use for stack
        // Enqueue(&L, studrec[i]); //use for queue
    }
    displayList(L);

    deleteAll(&L, "BSIT");
    displayList(L);

    deleteElem(&L, 5102);
    displayList(L);
    return 0;
}
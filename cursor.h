#ifndef cursor
#define cursor
#include "student.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX 10


typedef struct node{
    Student stud[MAX];
    int Avail;
}VirtualHeap;

typedef struct list{
    VirtualHeap VH;
    int start;
}*List;

/*===================
1. initializeList
2. displayList
3. allocSpace
4. deallocSpace
5. insertLast
6. deleteLast
7. deleteElem
8. deleteAll
=====================*/

#endif
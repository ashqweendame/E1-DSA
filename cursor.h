#ifndef cursor
#define cursor
#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct stud{
    Student stud;
    int link;
}StudNode;

typedef struct node{
    StudNode Nodes[MAX];
    int Avail;
}VirtualHeap;

typedef struct list{
    VirtualHeap VH;
    int start;
}List;

/*===================
1. initializeList
2. allocSpace
3. deallocSpace
4. displayList
5. insertLast
6. deleteLast
7. deleteElem
8. deleteAll
=====================*/

void initList(List* A){
    A->VH.Avail = MAX - 1;
    A->start = -1;
    for(int i =0; i < MAX; i++){
        A->VH.Nodes[i].link = i-1;
    }
}

int allocSpace(List* A){
    int temp = A->VH.Avail;
    if(temp != -1){
        A->VH.Avail = A->VH.Nodes[temp].link;
    }
    return temp;
}

void deallocSpace(List* A, int ndx){
    if(ndx > -1 && ndx < MAX){
        A->VH.Nodes[ndx].link = A->VH.Avail;
        A->VH.Avail = ndx; 
    }
}

void displayList(List A){
    displayHeader();
    for(;A.start != -1; A.start = A.VH.Nodes[A.start].link){
        displayStudent(A.VH.Nodes[A.start].stud);
    }
    printf("----------------------------------------------------------------------\n");
}

void insertLast(List* A, Student s){
    int* ptr;

    for(ptr = &A->start; *ptr != -1; ptr = &A->VH.Nodes[*ptr].link){}

    int temp = allocSpace(A);
    if(temp != -1){
        A->VH.Nodes[temp].stud = s;
        A->VH.Nodes[temp].link = -1;
        *ptr = temp;
    }
}

void deleteLast(List* A){
    int* ptr;
    if(A->start != -1){
        for(ptr = &A->start; *ptr != -1; ptr = &A->VH.Nodes[*ptr].link){}
        int temp = *ptr;
        *ptr = A->VH.Nodes[temp].link;
        deallocSpace(A, temp);

        printf("\nSuccessfully deleted the last Student!\n");
    }else printf("\nThe List is empty! There is nothing to delete!\n");
}

void deleteElem(List* A, int givenID){
    int* ptr;
    for(ptr = &A->start; *ptr != -1 && A->VH.Nodes[*ptr].stud.studID != givenID; ptr = &A->VH.Nodes[*ptr].link){}
    if(*ptr != -1){
        int temp = *ptr;
        *ptr = A->VH.Nodes[temp].link;
        deallocSpace(A, temp);

        printf("\nID number \"%d\" was Successfully Deleted!\n", givenID);
    }else printf("\nID number \"%d\" was not found!\n", givenID);
}

void deleteAll(List* A, char course[]){
    if(A->start != -1){
        int* ptr;
        for(ptr = &A->start; *ptr!=-1; ){
            if(strcmp(A->VH.Nodes[*ptr].stud.course, course)==0){
                int temp = *ptr;
                *ptr = A->VH.Nodes[temp].link;
                deallocSpace(A, temp);
            }else ptr= &A->VH.Nodes[*ptr].link;
        }
        printf("\n%s Students were Successfully Removed!\n", course);
    }else printf("\nThe List is Empty!\n");
}
#endif
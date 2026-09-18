#ifndef listArray
#define listArray

#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct node{
    Student stud[MAX];
    int count; //count of how many students
}List;

/*===================
1. initList
2. displayList
3. insertLast
4. deleteLast
5. deleteElem
6. deleteAll
=====================*/


void initList(List* A){
    A->count = 0;
}

void displayList(List A){

    displayHeader();
    for(int i = 0;i < A.count; i++){
        displayStudent(A.stud[i]);
    }
    printf("----------------------------------------------------------------------\n");
}

void insertLast(List* A, Student s){
    if(A->count < MAX){
        A->stud[A->count++] = s;
    }else printf("\nThe List is Full! Cannot insert!\n");
}

void deleteLast(List*A){
    if(A->count > 0){
        A->count--;
        printf("\nLast Element Successfully Removed!\n");
    }else printf("\nThe List is Empty!\n");
}

void deleteElem(List* A, int givenID){
    int i;
    if(A->count > 0){
        for(i= 0; i<A->count && givenID != A->stud[i].studID; i++){}
        if(i < A->count--){
            for(;i < A->count; i++){
                A->stud[i] = A->stud[i+1];
            }
            printf("\nID number \"%d\" was deleted Successfully!\n", givenID);
        }else printf("\nID number \"%d\" was not Found!\n", givenID);
        
    }else printf("\nThe List is Empty!\n");
}

void deleteAll(List* A, char course[]){
    if(A->count > 0){
        int i;
        for(i = 0; i< A->count;){
            if(strcmp(A->stud[i].course, course)==0){
                A->count--;
                for(int j=i;j < A->count; j++){
                    A->stud[j] = A->stud[j+1];
                }
            }else i++;
        }
        printf("\n%s Students were Successfully Removed!\n", course);
    }else printf("\nThe List is Empty!\n");
}
#endif
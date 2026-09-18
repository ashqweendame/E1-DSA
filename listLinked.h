#ifndef listLinked
#define listLinked

#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    Student stud;
    struct node* link;
}*List;
/*===================
1. initializeList
2. displayList
5. insertLast
6. deleteLast
7. deleteElem
8. deleteAll
=====================*/

void initList(List* A){
    *A = NULL;
}

void displayList(List A){
    displayHeader();
    if(A != NULL){
        for(;A!=NULL; A=A->link){
            displayStudent(A->stud);
        }
    }else printf("\nList is empty! Nothing to show.\n");
    printf("----------------------------------------------------------------------\n");
}

void insertLast(List* A, Student s){
    List* ptr;
    for(ptr = A; *ptr!= NULL; ptr = &(*ptr)->link){}
    List temp = (List)malloc(sizeof(struct node));
    temp->stud = s;
    temp->link = *ptr;
    *ptr = temp;
}

void deleteLast(List* A){
    List* ptr;
    if(*A != NULL){
        for(ptr = A; *ptr!=NULL; ptr = &(*ptr)->link){}
        List temp = *ptr;
        *ptr = temp->link;
        free(temp);
        printf("\nSuccessfully deleted the last Student!\n");
    }else printf("\nThe List is empty! There is nothing to delete!\n");
}

void deleteElem(List* A, int givenID){
    List* ptr;
    for(ptr = A; *ptr != NULL && givenID != (*ptr)->stud.studID; ptr = &(*ptr)->link){}
    if(*ptr!= NULL){
        List temp = *ptr;
        *ptr = temp->link;
        free(temp);

        printf("\nID number \"%d\" was Successfully Deleted!\n");
    }else printf("\nID number \"%d\" was not found!\n");
}

void deleteAll(List* A, char course[]){
    if(*A != NULL){
        List* ptr;
        for(ptr = A; *ptr!=NULL;){
            if(strcmp((*ptr)->stud.course, course) == 0){
                List temp = *ptr;
                *ptr = temp->link;
                free(temp);
            }else ptr = &(*ptr)->link;
        }
        printf("\n%s Students were Successfully Removed!\n", course);
    }else printf("\nThe List is Empty!\n");
}

#endif
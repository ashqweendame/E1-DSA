#ifndef stackLinked
#define stackLinked

#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    Student stud;
    struct node* link;
}*Stack, *List;

/*===================
1. initList
2. push
3. pop
4. displayList
5. peek
6. deleteElem
7. deleteAll
=====================*/

void initList(Stack* A){
    *A = NULL;
}

void push(Stack* A, Student s){
    Stack temp = (Stack)malloc(sizeof(struct node));
    temp->stud = s;
    temp->link = *A;
    *A = temp;
}

void pop(Stack* A){
    if(*A != NULL){
        Stack temp = *A;
        *A = temp->link;
        free(temp);
    }
}

Student peek(Stack A){
    return A->stud;    
}

void displayList(Stack* A){
    displayHeader();
    Stack temp;
    initList(&temp);

    while(*A!=NULL){
        push(&temp, (*A)->stud);
        pop(A);
    }

    while(temp != NULL){
        displayStudent(temp->stud);
        push(A, temp->stud);
        pop(&temp);
    }
    printf("----------------------------------------------------------------------\n");
}

void deleteElem(Stack* A, int givenID){
    Stack temp;
    initList(&temp);
    
    while(*A!= NULL && (*A)->stud.studID != givenID){
        push(&temp, (*A)->stud);
        pop(A);
    }

    if(*A!= NULL){
        pop(A);
        printf("\nID number \"%d\" was Successfully Deleted!\n", givenID);
    }else printf("\nID number \"%d\" was not found!\n", givenID);

    while(temp!=NULL){
        push(A, temp->stud);
        pop(&temp);
    }
}

void deleteAll(Stack* A, char course[]){
    if(*A!=NULL){
        Stack temp;
        initList(&temp);

        while(*A!=NULL){
            if(strcmp((*A)->stud.course, course) == 0){
                pop(A);
            }else {
                push(&temp, (*A)->stud);
                pop(A);
            }
        }

        while(temp!=NULL){
            push(A, temp->stud);
            pop(&temp);
        }
        printf("\n%s Students were Successfully Removed!\n", course);
    }else printf("\nThe List is Empty!\n");
}

#endif
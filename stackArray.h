#ifndef stackArray
#define stackArray

#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 10

typedef struct stack{
    Student stud[MAX];
    int top;
}Stack, List;


/*===================
1. initList
2. displayList
3. push
4. pop
5. peek
6. deleteElem
7. deleteAll
=====================*/

void initList(Stack* A){
    A->top = -1;
}
void push(Stack* A, Student s){
    if(A->top < MAX-1){
        A->stud[++A->top] = s;
    }else printf("\nThe List is full! Cannot insert!\n");
}

void pop(Stack* A){
    if(A->top > -1){
        A->top--;
    }
}
void displayList(Stack* A){
    displayHeader();
    Stack temp;
    initList(&temp);

    while(A->top > -1){
        push(&temp, A->stud[A->top]);
        pop(A);
    }

    while(temp.top > -1){
        displayStudent(temp.stud[temp.top]);
        push(A, temp.stud[temp.top]);
        pop(&temp);
    }
    printf("----------------------------------------------------------------------\n");
}

Student peek(Stack A){
    if(A.top > -1){
        return A.stud[A.top];
    }
}

void deleteElem(Stack* A, int givenID){
    if(A->top > -1){
        Stack temp;
        initList(&temp);
        
        while(A->top > -1 && A->stud[A->top].studID != givenID){
            push(&temp, A->stud[A->top]);
            pop(A);
        }

        if(A->top > -1){
            pop(A);
            printf("\nID number \"%d\" was Successfully Deleted!\n", givenID);
        }else printf("\nID number \"%d\" was not found!\n", givenID);

        while(temp.top > -1){
            push(A, temp.stud[temp.top]);
            pop(&temp);
        }
    }else printf("\nThe List is Empty!\n");
}

void deleteAll(Stack* A, char course[]){
    if(A->top > -1){
        Stack temp;
        initList(&temp);

        while(A->top > -1){
            if(strcmp(A->stud[A->top].course, course) == 0){
                pop(A);
            }else {
                push(&temp, A->stud[A->top]);
                pop(A);
            }
        }

        while(temp.top > -1){
            push(A, temp.stud[temp.top]);
            pop(&temp);
        }
        printf("\n%s Students were Successfully Removed!\n", course);
    }else printf("\nThe List is Empty!\n");
}

#endif
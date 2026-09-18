#ifndef queueLinked
#define queueLinked

#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    Student stud;
    struct node* link;
}*QueueType;

typedef struct node{
    QueueType front;
    QueueType rear;
}Queue;

/*===================
1. initList
2. Enqueue
3. Dequeue
4. displayList
5. deleteElem
6. deleteAll
=====================*/

void initList(Queue* A){
    A->front = NULL;
    A->rear = NULL;
}

void Enqueue(Queue* A, Student s){
    QueueType temp = (QueueType)malloc(sizeof(struct node));
    if(temp!= NULL){
        temp->stud = s;
        temp->link = NULL;

        if(A->rear != NULL){
            A->rear->link = temp;
        }else A->front = temp;

        A->rear = temp;
    }
}
void Dequeue(Queue* A){
    if(A->front!=NULL){
        QueueType temp = A->front;
        A->front = temp->link;
        if(A->front!=NULL){
            free(temp);
        }else A->rear = A->front;
    }
}

void displayList(Queue A){
    displayHeader();
    Queue temp;
    initList(&temp);

    while(A.front!=NULL){
        Enqueue(&temp, A.front->stud);
        Dequeue(&A);
    }

    while(temp.front!=NULL){
        displayStudent(temp.front->stud);
        Enqueue(&A, temp.front->stud);
        Dequeue(&temp);
    }
    printf("----------------------------------------------------------------------\n");
}

void deleteElem(Queue* A, int givenID){
    if(A->front!=NULL){
        Queue temp;
        initList(&temp);

        while(A->front!=NULL && A->front->stud.studID != givenID){
            Enqueue(&temp, A->front->stud);
            Dequeue(A);
        }
        if(A->front!=NULL){
            Dequeue(A);
            printf("\nID number \"%d\" was Successfully Deleted!\n", givenID);
        }else printf("\nID number \"%d\" was not found!\n", givenID);
        while(temp.front != NULL){
            Enqueue(A, temp.front->stud);
            Dequeue(&temp);
        }
    }else printf("\nThe List is Empty! Cannot Remove!\n");
}

void deleteAll(Queue* A, char course[]){
    if(A->front!=NULL){
        Queue temp;
        initList(&temp);

        while(A->front!=NULL){
            if(strcmp(A->front->stud.course, course)==0){
                Dequeue(A);
            }else {
                Enqueue(&temp, A->front->stud);
                Dequeue(A);
            }
        }

        while(temp.front!=NULL){
            Enqueue(A, temp.front->stud);
            Dequeue(&temp);
        }
        printf("\n%s Students were Successfully Removed!\n", course);
    }else printf("\nThe List is Empty! Cannot Remove!\n");
}

#endif
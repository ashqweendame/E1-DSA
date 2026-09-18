#ifndef queueArray
#define queueArray

#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct node{
    Student stud[MAX];
    int rear;
    int front;
}Queue, List;

/*===================
1. initList
2. displayList
3. Queue
4. Dequeue
5. deleteElem
6. deleteAll
=====================*/

/*-------------------
Indications: 
FULL: front is ahead by 2 from rear
A->rear + 2 % MAX != A->front

EMPTY: front is ahead by 1 from rear
A->rear + 1 % MAX != A->front

TO MOVE: 
rear = (rear + 1) % MAX
front = (front + 1) % MAX
---------------------*/

void initList(Queue* A){
    A->front = 0;
    A->rear = MAX - 1;
}

void Enqueue(Queue* A, Student s){
    if((A->rear + 2 % MAX) != A->front){
        A->rear = (A->rear + 1) % MAX;
        A->stud[A->rear] = s;
    }else printf("\nThe List is full!. Cannot insert anymore!\n");
}

void Dequeue(Queue* A){
    if((A->rear + 1) % MAX != A->front){
        A->front = (A->front + 1) % MAX;
    }
}

Student front(Queue A){
    return A.stud[A.front];
}

void displayList(Queue A){
    displayHeader();
    Queue temp;
    initList(&temp);

    while((A.rear + 1)% MAX != A.front){
        Enqueue(&temp, A.stud[A.front]);
        Dequeue(&A);
    }

    while((temp.rear + 1)% MAX != temp.front){
        displayStudent(temp.stud[temp.front]);
        Enqueue(&A, temp.stud[temp.front]);
        Dequeue(&temp);
    }
    printf("----------------------------------------------------------------------\n");
}
/*----------------
DELETE ELEM

1. transfer all to temp
2. enqueue to temp
3. dequeue from current
4.if found only dequeue from current
5. dequeue, enqueue the rest

6. enqueue to current
7. dequeue from temp

------------------*/
void deleteElem(Queue* A, int givenID){
    if((A->rear + 1) % MAX != A->front){
        Queue temp;
        initList(&temp);

        while((A->rear + 1) % MAX != A->front && A->stud[A->front].studID != givenID){
            Enqueue(&temp, A->stud[A->front]);
            Dequeue(A);
        }
        if((A->rear + 1) % MAX != A->front){
            Dequeue(A);
            printf("\nID number \"%d\" was Successfully Deleted!\n", givenID);
        }else printf("\nID number \"%d\" was not found!\n", givenID);

        while((A->rear + 1) % MAX != A->front && A->stud[A->front].studID != givenID){
            Enqueue(&temp, A->stud[A->front]);
            Dequeue(A);
        }

        while((temp.rear + 1) % MAX != temp.front){
            Enqueue(A, temp.stud[temp.front]);
            Dequeue(&temp);
        }
    }else printf("\nThe List is Empty!\n");
}

/*----------------
DELETE ALL

1. transfer all to temp
2. if found dequeue only
3. if not 
    enqueue  to temp
    dequeue from current

4. enqueue to current
5. dequeue from temp
------------------*/

void deleteAll(Queue* A, char course[]){
    if((A->rear + 1) % MAX != A->front){
        Queue temp;
        initList(&temp);

        while((A->rear + 1) % MAX != A->front){
            if(strcmp(A->stud[A->front].course, course) == 0){
                Dequeue(A);
            }else {
                Enqueue(&temp, A->stud[A->front]);
                Dequeue(A);
            }
        }

        while((temp.rear + 1)% MAX != temp.front){
            Enqueue(A, temp.stud[temp.front]);
            Dequeue(&temp);
        }
        printf("\n%s Students were Successfully Removed!\n", course);
    }else printf("\nThe List is empty!\n");
}

#endif
#ifndef student
#define student

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct name{
    char firstName[24];
    char middleIn;
    char lastName[16];
}NameType;

typedef struct student{
    int studID;
    NameType name;
    char course[4];
}Student;

void displayHeader(){
    printf("----------------------------------------------------------------------\n");
    printf("%-12s %-25s %-5s %-18s %-5s\n", "ID", "First Name", "MI", "Last Name", "Course");
    printf("----------------------------------------------------------------------\n");
}

void displayStudent(Student s){
    printf("%-12d %-25s %-5c %-18s %-5s\n", s.studID, s.name.firstName, s.name.middleIn, s.name.lastName, s.course);
}

#endif
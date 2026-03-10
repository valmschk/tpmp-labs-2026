#ifndef INTERFACE_H
#define INTERFACE_H

typedef struct {
    char name[50];
    int kurs;
    int ses[5];
    float average;
} STUDENT;

void input_students(STUDENT *students, int n);
void sort_students(STUDENT *students, int n);

#endif
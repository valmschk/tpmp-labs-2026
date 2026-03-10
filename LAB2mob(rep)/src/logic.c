#include <stdio.h>
#include <string.h>
#include "interface.h"

void sort_students(STUDENT *students, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(students[j].name, students[j+1].name) > 0) {
                STUDENT temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}

void input_students(STUDENT *students, int n) {
    for (int i = 0; i < n; i++) {
        printf("Student %d name: ", i + 1);
        scanf("%s", students[i].name);
        printf("Course: ");
        scanf("%d", &students[i].kurs);
        printf("5 grades: ");
        for (int j = 0; j < 5; j++) scanf("%d", &students[i].ses[j]);
    }
}
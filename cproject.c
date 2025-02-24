#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    char subjects[150];
} Major;

Major majors[] = {
    {"Mechanical Engineering / Aerospace Engineering", "Mathematics, Physics, English"},
    {"Computer Engineering / Software Engineering", "Mathematics, Physics, Programming Basics"},
    {"Civil Engineering / Architecture and Design", "Mathematics, Physics, Drafting"},
    {"Business Administration – Management", "Mathematics, English, Economics"}
};

void toLowerCase(char *str)
{
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void displayMajors() {
    printf("Available Majors at Turin Polytechnic University:\n");
    for (int i = 0; i < sizeof(majors) / sizeof(majors[0]); i++) {
        printf("%d. %s\n", i + 1, majors[i].name);
    }
}

int main() {
    char choice[100];

    displayMajors();

    printf("\nSelect a major by number or name: ");
    fgets(choice, sizeof(choice), stdin);
    choice[strcspn(choice, "\n")] = 0; 

    int isNumber = 1;
    for (int i = 0; choice[i] != '\0'; i++) {
        if (!isdigit(choice[i])) {
            isNumber = 0;
            break;
        }
    }

    int found = 0;
    
    if (isNumber) {
        int index = atoi(choice); 
        if (index >= 1 && index <= sizeof(majors) / sizeof(majors[0])) {
            printf("\nSelected Major: %s\n", majors[index - 1].name);
            printf("Required Exam Subjects: %s\n", majors[index - 1].subjects);
            found = 1;
        }
    } else {
        toLowerCase(choice);

        for (int i = 0; i < sizeof(majors) / sizeof(majors[0]); i++) {
            char majorNameLower[100];
            strcpy(majorNameLower, majors[i].name);
            toLowerCase(majorNameLower);  

            if (strcmp(choice, majorNameLower) == 0) {
                printf("\nSelected Major: %s\n", majors[i].name);
                printf("Required Exam Subjects: %s\n", majors[i].subjects);
                found = 1;
                break;
            }
        }
    }

    if (!found) {
        printf("\nMajor not found. Please select one from the list.\n");
    }

    return 0;
}

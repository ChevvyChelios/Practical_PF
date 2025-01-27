#include<stdio.h>
#include<string.h>
#define MAX 5

typedef struct{
    int rollNo;
    char name[50];
    int age;
} Student;

void add(Student st[], int *count){
    if (*count >= MAX) {
        printf("Student database is full\n");
        return;
    }
    Student newSt;
    printf("Enter roll number: ");
    scanf("%d", &newSt.rollNo);
    printf("Enter name: ");
    scanf(" %[^\n]", newSt.name);
    printf("Enter age: ");
    scanf("%d", &newSt.age);
    st[*count] = newSt;
    *count += 1;
    printf("Student added successfully\n");
}

void display(Student st[], int count){
    if (count == 0) {
        printf("Student database is Empty\n");
        return;
    }
    int roll;
    printf("Enter Student roll no.:\n");
    scanf("%d", &roll);
    for (int i=0; i<count; i++){
        if (st[i].rollNo == roll){
            printf("Roll No: %d\n", st[i].rollNo);
            printf("Name: %s\n", st[i].name);
            printf("Age: %d\n", st[i].age);
            return;
        }
    }
}

int main(){
    Student st[MAX];
    int count = 0, choice;

    printf("\nstudent Database Menu:\n");
    printf("1. Add student\n");
    printf("2. Display student\n");
    printf("3. Exit\n");

    while(choice != 3){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add(st, &count);
                break;
            case 2:
                display(st, count);
                break;
            case 3:
                printf("\nExiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <string.h>
#define MAX 10

struct Employee{
    int id;
    char name[20];
    float salary;
    char department[20];
};

void add(struct Employee employees[], int *count);
void delete(struct Employee employees[], int *count);
void display(struct Employee employees[], int count);

int main(){
    struct Employee employees[MAX];
    int count = 0;
    int choice;

    printf("\nEmployee Database Menu:\n");
    printf("1. Add Employee\n");
    printf("2. Delete Employee\n");
    printf("3. Display Employees\n");
    printf("4. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add(employees, &count);
                break;
            case 2:
                delete(employees, &count);
                break;
            case 3:
                display(employees, count);
                break;
            case 4:
                printf("\nExiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}

void add(struct Employee employees[], int *count){
    if (*count >= MAX) {
        printf("Employee database is full\n");
        return;
    }
    struct Employee newEmp;
    printf("\nEnter employee details:\n");    
    printf("ID: ");
    scanf("%d", &newEmp.id);
    printf("Name: ");
    scanf(" %[^\n]", newEmp.name);
    printf("salary: ");
    scanf("%f", &newEmp.salary);
    printf("Department: ");
    scanf(" %[^\n]", newEmp.department);

    employees[*count] = newEmp;
    (*count)++;
    printf("Employee added \n");

}
void delete(struct Employee employees[], int *count){
    if (*count == 0) {
        printf("Employee database is empty\n");
        return;
    }
    int id, i, found=0;
    printf("Enter the ID of the employee you want to delete: ");
    scanf("%d", &id);

    for (i=0; i<*count; i++){
        if (employees[i].id == id){
            found = 1;
            for (int j=i; j<*count-1; j++)
                employees[j] = employees[j+1];
            (*count)--;
            printf("Employee deleted \n");
            return;
        }
    }
    if (!found){
        printf("Employee not found\n");
    }
}
void display(struct Employee employees[], int count){
    if (count == 0) {
        printf("Employee database is empty\n");
        return;
    }

    printf("\nEmployee Records\n");
    printf("ID\tName\tSalary\tDepartment:\n");
    printf("---------------------------------------------------------\n");
    for (int i=0; i<count; i++){
        printf("%d\t%s\t%.2f\t%s\n", employees[i].id, employees[i].name,employees[i].salary,employees[i].department);
    }
}
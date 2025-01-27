
#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

// Structure to hold student information
typedef struct
{
    char name[NAME_LENGTH];
    int roll_number;
    float marks;
} Student;

// Function to write student information to a file
void write_students_to_file(const char *filename, Student students[], int count)
{
    FILE *file = fopen(filename, "wb"); // Open file in binary write mode
    if (file == NULL)
    {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }
    fwrite(students, sizeof(Student), count, file); // Write student array to file
    fclose(file);                                   // Close the file
}

// Function to read student information from a file
void read_students_from_file(const char *filename)
{
    FILE *file = fopen(filename, "rb"); // Open file in binary read mode
    if (file == NULL)
    {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    Student student;
    printf("Student Information:\n");
    printf("Name\t\tRoll Number\tMarks\n");
    printf("------------------------------------------------\n");

    // Read and display each student record
    while (fread(&student, sizeof(Student), 1, file))
    {
        printf("%-15s\t%d\t\t%.2f\n", student.name, student.roll_number, student.marks);
    }

    fclose(file); // Close the file
}

int main()
{
    Student students[MAX_STUDENTS];
    int count, i;

    // Input number of students
    printf("Enter the number of students (max %d): ", MAX_STUDENTS);
    scanf("%d", &count);

    // Input student information
    for (i = 0; i < count; i++)
    {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name); // Read name
        printf("Roll Number: ");
        scanf("%d", &students[i].roll_number); // Read roll number
        printf("Marks: ");
        scanf("%f", &students[i].marks); // Read marks
    }

    // Write student information to a file
    write_students_to_file("students.dat", students, count);

    // Read and display student information from the file
    read_students_from_file("students.dat");

    return 0; // Successful execution
}
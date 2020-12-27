#include <stdio.h>
#include <string.h>

#define STUDENTS 10
#define SUBJECTS 5

char calc_grade(double percent_marks) {
    if (90 <= percent_marks && percent_marks <= 100) {
        return 'A';
    } else if (80 <= percent_marks) {
        return 'B';
    } else if (70 <= percent_marks) {
        return 'C';
    } else if (60 <= percent_marks) {
        return 'D';
    } else if (33.3 <= percent_marks) {
        return 'E';
    } else {
        return 'F';
    }
}

int main() {
    int i;
    char name[25];
    int marks;
    int marks_arr[SUBJECTS];
    int total_marks = 0;
    double avg_marks = 0;
    FILE *file = fopen("stu.dat", "w"); // with write more, the file contents are cleared

    // open for both appending and reading
    file = fopen("stu.dat", "a+");

    for (int i = 0; i < STUDENTS; ++i) {
        printf("Enter student %d name and marks of each of 5 subjects respectively: ", i+1);
        scanf(" %s", name);
        // write each student in file
        fprintf(file, "%s", name);
        for (int j = 0; j < SUBJECTS; ++j) {
            scanf(" %d", &marks);
            fprintf(file, "\t%d", marks);
        }

        // one line represents one student
        fprintf(file, "\n");
    }

    // Reading students from file
    // print name, total, average and grade
    printf("Name\tTotal\tAverage\tGrade\n");

    // set the file pointer at the beginning of file
    fseek(file, 0, SEEK_SET); // 0 offset, and SEEK_SET in whence is constant for start of file 
    for (int i = 0; i < STUDENTS; ++i) {
        fscanf(file, "%s", name);

        total_marks = 0;
        for (int j = 0; j < SUBJECTS; ++j) {
            fscanf(file, " %d", &marks);
            total_marks += marks;
        }

        // move the cursor to next line
        fscanf(file, " "); // any white space (includes \n) after the 5th marks

        // print student's name, total, average and grade
        avg_marks = ((double) total_marks)/5; // same for percent marks as each subject are of 100 marks
        printf("%s\t%d\t%.2lf\t%c\n", name, total_marks, avg_marks, calc_grade(avg_marks));
    }

    return 0;
}
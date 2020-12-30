#include <stdio.h>
#include <stdlib.h>

struct Registration {
    int enrol_num;
    int cur_sem;
    int fee_per_sem;
    int course_fee;
    char *stu_centre;
    char *reg_centre;
};


void fill_reg(struct Registration *r, int enrol_num, int cur_sem, int fee_per_sem, int course_fee, char *stu_centre, char *reg_centre) {
    r->enrol_num = enrol_num;
    r->cur_sem = cur_sem;
    r->fee_per_sem = fee_per_sem;
    r->course_fee = course_fee;
    r->stu_centre = stu_centre;
    r->reg_centre = reg_centre;
}

void print_reg(struct Registration *r) {
    printf("\nEnrollment Number: %d\nCurrent Semester: %d\nFee per semester: %d\nCourse Fee: %d\nStudy Centre: %s\nRegional Centre: %s\n", r->enrol_num, r->cur_sem, r->fee_per_sem, r->course_fee, r->stu_centre, r->reg_centre);
}

int main() {
    int option;
    int reg_num;
    struct Registration r1, r2, r3;
    

    // initial prompt
    printf("1) Registration Status\n2) Courses in the Current Semester\n3) Assignment Submission Schedules\n4) Assignment Marks\n5) Term End Exam Marks\n6) Quit\nEnter your choice: ");
    scanf(" %d", &option);

    switch (option) {
        case 1:
            fill_reg(&r1, 45, 1, 10000, 120000, "0516P", "05");
            fill_reg(&r2, 67, 3, 12000, 72000, "0147D", "11");
            fill_reg(&r3, 23, 6, 6000, 36000, "0884E", "08");
            
            printf("Enter enrollment number: ");
            scanf(" %d", &reg_num);

            switch (reg_num) {
                case 45:
                    print_reg(&r1);
                    break;
                case 67:
                    print_reg(&r2);
                    break;
                case 23:
                    print_reg(&r3);
                    break;
                default:
                    printf("There is no registration corresponding to the enrollment number you entered");
            }
            break;
        case 2:
            printf("\nCurrent Semester: 1st\nCourses:\nMCS-011\nMCS-012\nMCS-013\nMCS-014\nMCS-015\nMCSL-016\nMCSL-017\n");
            break;
        case 3:
            printf("\nThe last date for submission for assignments is 2020-12-31\n");
            break;
        case 4:
            printf("\nAssignment marks: 173\n");
            break;
        case 5:
            printf("\nTerm End Exam Marks: 455\n");
            break;
        case 6:
            return 0;
        default:
            printf("\nWrong option chosen\n");
            return -1;
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    struct Date_record {
        char date[11]; // use format yyyy-mm-dd
        int hours;
    };

    struct Worker {
        char name[36]; // name can't be more than 35 chars long
        int hourly_rate;
        struct Date_record *date_records[10]; // can hold at most 10 records  
    } w1;

    int days_worked = 0;
    struct Date_record date_record1, date_record2;
    struct Date_record *date_record_ptr;

    sprintf(w1.name, "John Smith");
    w1.hourly_rate = 1200;

    
    // 1st record
    // Enter date and hours worked
    sprintf(date_record1.date, "2020-12-18");
    date_record1.hours = 4;
    w1.date_records[days_worked] = &date_record1;
    ++days_worked;

    
    // 2nd record
    // Enter date and hours worked
    sprintf(date_record2.date, "2020-12-19");
    date_record2.hours = 2;
    w1.date_records[days_worked] = &date_record2;
    ++days_worked;

    // print name date total wages for that day
    for (int i = 0; i < 2; ++i) {
        date_record_ptr = w1.date_records[i];
        printf("Name: %s, date: %s, wage: %d\n", w1.name, date_record_ptr->date, date_record_ptr->hours * w1.hourly_rate);
    }

    return 0;
}
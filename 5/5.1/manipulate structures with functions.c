/*
In this problem you will continue developing the data feature which you started implementing in the previous problem. You will implement a "tomorrow" feature in the C programming language via a function called "advanceDay()". The function advanceDay() should take as input a date (stored in a struct date) and return the date of the following day. You do not have to take into account leap years (although you may if you wish to). That is, it is okay for your function to always return March 1 as the day following February 28, no matter the year.

You are provided with a familiar date structure definition, a main function as well as the function prototypes for the readDate(), printDate(), and advanceDay() functions. Do not modify any of the given code. Simply add your function definitions underneath the main() function. For the readDate() and printDate() functions you may simply copy and paste the code you developed in the previous task.

 

Examples
Input:
2018 10 2
Output:
10/02/2018                                                                      

10/03/2018
 

Input:
2018 10 31
Output:
10/31/2018                                                                      

11/01/2018
 

Input:
2018 11 30
Output:
11/30/2018                                                                      

12/01/2018                                                                      
 

Input:
2018 12 31
Output:
12/31/2018                                                                      

01/01/2019
*/


// try to do it with the leap years!

#include <stdio.h>

struct date {
    int year;
    int month;
    int day;
};

/* function prototypes */
void printDate(struct date);
void readDate(struct date *);
struct date advanceDay(struct date);

int main(void) {
    struct date today, tomorrow;
    readDate(&today);
    printDate(today);
    tomorrow = advanceDay(today);
    printDate(tomorrow);
    return 0;
}

void readDate(struct date *d) {
    scanf("%d %d %d", &d->year, &d->month, &d->day);
}

void printDate(struct date d) {
    printf("%02d/%02d/%d\n", d.month, d.day, d.year);
}

struct date advanceDay(struct date d) {
    // The maximum days in each month, ignoring leap years
    int maxDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Increase the day by 1
    d.day++;

    // Handle month and year transitions
    if (d.day > maxDays[d.month]) {
        d.day = 1;
        d.month++;
        if (d.month > 12) {
            d.month = 1;
            d.year++;
        }
    }

    return d;
}



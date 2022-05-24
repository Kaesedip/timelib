#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "timelib.h"
/**
 *Thomas Siedler
 *timelib Project
 **/


struct date{
    int year;
    int month;
    int day;
};

int main(){

    struct date datum ;
    int checkForRightDate = 0;

    while(checkForRightDate == 0){

        printf("\nGeben Sie das Jahr ein: ");
        scanf("%i", &datum.year);

        is_leapyear(datum.year);

        printf("\nGeben Sie den Monat ein: ");
        scanf("\n %i", &datum.month);

        printf("\nGeben Sie den Tag ein: ");
        scanf("\n %i", &datum.day);

        checkForRightDate = exists_date(datum.day, datum.month, datum.year);
    }
    printf("%i Tage des Jahres .", day_of_the_year(datum.month, datum.day, datum.year));

    return 0;
}

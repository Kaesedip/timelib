#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "timelib.h"
/**
 *
 *
 **/


int main()
{
    int year, month, day;
    int result = 0;
    int checkForRightDate = 0;
    while(checkForRightDate == 0){

        printf("\nGeben Sie das Jahr ein: ");
        scanf("%i", &year);

        is_leapyear(year);

        printf("\nGeben Sie den Monat ein: ");
        scanf("\n %i", &month);

        printf("\nGeben Sie den Tag ein: ");
        scanf("\n %i", &day);
        checkForRightDate = exists_date(day,month,year);
    }
    result = day_of_the_year(month,day,year);
    printf("%i Tage des Jahres .",result);

    return 0;
}

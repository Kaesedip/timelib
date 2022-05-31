#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "timelib.h"

/**
 *Thomas Siedler
 *timelib Project
 **/

int main()
{

    struct date datum ;
    int checkForRightDate = 0;

    do
    {

        printf("\nGeben Sie das Jahr ein: ");
        scanf("%i", &datum.year);

        //prueft ob das eingebene Jahr ein Schaltjahr ist.
        is_leapyear(datum);

        printf("\nGeben Sie den Monat ein: ");
        scanf("\n %i", &datum.month);

        printf("\nGeben Sie den Tag ein: ");
        scanf("\n %i", &datum.day);

        //prueft ob der Monat und der Tag existiert
        checkForRightDate = exists_date(datum);

    }
    while(checkForRightDate == 0) ;


    printf("%i Tage des Jahres .", day_of_the_year(datum));

    return 0;
}

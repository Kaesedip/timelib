#include "timelib.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der
Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden berücksichtigt.*/
int get_days_for_month(int month, int year){




        int days_per_month = 0;
        for (int i = 1 ; i< month; i++){

                if(i == 2 && is_leapyear(year) == 1){
                days_per_month += 29;
                continue;
            }
                if (i % 2 == 0 ){
                days_per_month += 30;
                continue;
            }
                else if(i % 2 != 0 || month == 8){
                days_per_month += 31;
                continue;
            }
        }

        return days_per_month;
}

// Die Funktion überprüft, ob ein gegebenes Jahr nach den Regeln des gregorianischen
// Kalender ein Schaltjahr ist. Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zurückgegeben.
int is_leapyear(int year){
    if(year < 1582){
        return -1;
    }

    if (year % 4 == 0)
    {
        if (year % 100){
            if (year % 400 == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

/*Die Funktion überprüft, ob ein eingegebenes Datum gültig ist. Daten vor dem 1.1.1582 sind ungültig, genauso
wie alle Daten nach dem 31.12.2400.
*/
int exists_date(int day, int month, int year){


        if (month > 12 || month < 1 || year < 1582 || year > 2400 || day > 31 || day < 1){
            printf("Ungueltiges Datum");
            return  0;
        }

        else if (is_leapyear(year) == 1 && day >= 30 && month == 2 || day >= 29 && month == 2 && is_leapyear(year) == 0){

            printf("Ungueltiges Datum");
            return  0;
        }

        else
        {
             return  1;
        }
}

/*Die Funktion berechnet für ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat
und Jahr die Nummer des Tages, gezählt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der
Berechnung berücksichtigt. Ist das übergebene Datum ungültig, beträgt der Rückgabewert -1.*/
int day_of_the_year(int month, int day, int year){
    int days_of_year ;
    if(month == 1){
            return day;
        }
        else{

            days_of_year = get_days_for_month(month,year) + day;
            return days_of_year ;
        }
}


#include "timelib.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*Die Funktion bestimmt fuer einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der
Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden beruecksichtigt.*/

int get_days_for_month(struct date datum)
{

    int days_per_month = 0;
    for (int i = 1 ; i< datum.month; i++)
    {

        if(i == 2 && is_leapyear(datum) == 1)
        {
            days_per_month += 29;
            continue;
        }
        if (i % 2 == 0 )
        {
            days_per_month += 30;
            continue;
        }
        else if(i % 2 != 0 || datum.month == 8)
        {
            days_per_month += 31;
            continue;
        }
    }

    return days_per_month;
}

// Die Funktion ueberprueft, ob ein gegebenes Jahr nach den Regeln des gregorianischen
// Kalender ein Schaltjahr ist. Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zurueckgegeben.

int is_leapyear(struct date datum)
{
    if(datum.year < 1582)
    {
        return -1;
    }

    if (datum.year % 4 == 0)
    {
        if (datum.year % 100)
        {
            if (datum.year % 400 == 0)
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

/*Die Funktion ueberprueft, ob ein eingegebenes Datum gueltig ist. Daten vor dem 1.1.1582 sind ungueltig, genauso
wie alle Daten nach dem 31.12.2400.
*/
int exists_date(struct date datum)
{


    if (datum.month > 12 || datum.month < 1 || datum.year < 1582
            || datum.year > 2400 || datum.day > 31 || datum.day < 1)
    {
        printf("Ungueltiges Datum");
        return  0;
    }

    else if (is_leapyear(datum) == 1 && datum.day >= 30 &&
             datum.month == 2 || datum.day >= 29 && datum.month == 2 && is_leapyear(datum) == 0)
    {

        printf("Ungueltiges Datum");
        return  0;
    }

    else
    {
        return  1;
    }
}

/*Die Funktion berechnet fuer ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat
und Jahr die Nummer des Tages, gezaehlt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der
Berechnung beruecksichtigt. Ist das uebergebene Datum ungueltig, betraegt der Rueckgabewert -1.*/

int day_of_the_year(struct date datum)
{
    int days_of_year ;
    if(datum.month == 1)
    {
        return datum.day;
    }
    else
    {

        days_of_year = get_days_for_month(datum) + datum.day;
        return days_of_year ;
    }
}


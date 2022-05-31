#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED

//Timelib Bibliothek

struct date{
    int year;
    int month;
    int day;
};

int get_days_for_month(struct date datum );

int is_leapyear(struct date datum );

int exists_date(struct date datum );

int day_of_the_year(struct date datum);

#endif // TIMELIB_H_INCLUDED

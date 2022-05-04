/**
 *
 *
 *
 **/

#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 **/
int tageProMonat [12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int jahr, monat, tag;
    int gesamtTage = 0;
    int checkForRightDate = 1;


    //Funktion zum Überprüfen, ob das Jahr ein Schaltjahr ist.
    int isSchaltjahr(int schaltJahr){
        if (schaltJahr % 4 == 0){
                if( schaltJahr % 100 == 0){
                        if ( schaltJahr % 400 == 0){
                            tageProMonat[1] = 29;
                            return true;
                        } else {
                            return false;
                        }

                } else {
                    tageProMonat[1] = 29;
                    return true;
                }
            } else {
                return false;
            }

    }

    //Nutzer gibt Daten ein
    while(checkForRightDate){

        printf("\nGeben Sie das Jahr ein: ");
        scanf("%i", &jahr);

        isSchaltjahr(jahr);

        printf("\nGeben Sie den Monat ein: ");
        scanf("\n %i",&monat);


        printf("\nGeben Sie den Tag ein: ");
        scanf("\n %i", &tag);

        //Ueberprüfen ob die Eingaben korrekt sind
        if(monat > 12){
            printf("Ungueltiger Wert fuer den Monat.");
        }else if(tag > 31){
            printf("Ungueltiger Wert fuer den Tag.");
        } else if (isSchaltjahr(jahr) && tag > 29 && monat == 2){
            printf("Ungueltiger Wert fuer den Tag.");
        } else if(tag > 28 && monat == 2 && !isSchaltjahr(jahr)){
            printf("Ungueltiger Wert fuer den Tag.");
        }
        else{
            checkForRightDate = 0;
        }
    }



    int tagDesJahres(int monat, int tag){

        if(monat == 1){
            return tag;
        }
        else{

            for (int i = 1 ; i< monat; i++){
            gesamtTage += tageProMonat[i-1];
        }
         return gesamtTage += tag;
        }
    }

    printf("Heute ist der %i. Tag des Jahres. Datum %i.%i.%i",tagDesJahres(monat,tag),tag,monat,jahr);



int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    return 0;
}

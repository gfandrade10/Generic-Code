#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1

typedef struct {
char fullDate[25];
char fdBuffer[25];
char month[10];
int intDay;
int intYear;
int intMonth;
}Date;

void setDate(Date *d1, char date[25]){
    strcpy(d1->fullDate,date);
    strcpy(d1->fdBuffer,date);
}

void splitter(Date *d1){
    char delim [] = " ";
    char *token = strtok(d1->fullDate,delim);
    int i = 0;

    Loop:
        switch (i){
            case 0:
            strcpy(d1->month,token);
            i++;
            token = strtok(NULL,delim);
            goto Loop;

            case 1:
            d1->intDay = atoi(token);
            i++;
            token = strtok(NULL,delim);
            goto Loop;

            case 2:
            d1->intYear = atoi(token);
            i++;
            token = strtok(NULL,delim);
            goto Loop;

            default:
            goto End;
        }
    End:
    token = NULL;
}

void setMonth(Date *d1){
    if(strcmp(d1->month,"January") == 0){
        d1->intMonth = 0;
    }
    if(strcmp(d1->month,"February") == 0){
        d1->intMonth = 31;
    }
    if(strcmp(d1->month,"March") == 0){
        d1->intMonth = 59;
    }
    if(strcmp(d1->month,"April") == 0){
        d1->intMonth = 90;
    }
    if(strcmp(d1->month,"May") == 0){
        d1->intMonth = 120;
    }
    if(strcmp(d1->month,"June") == 0){
        d1->intMonth = 151;
    }
    if(strcmp(d1->month,"July") == 0){
        d1->intMonth = 181;
    }
    if(strcmp(d1->month,"August") == 0){
        d1->intMonth = 212;
    }
    if(strcmp(d1->month,"September") == 0){
        d1->intMonth = 243;
    }
    if(strcmp(d1->month,"October") == 0){
        d1->intMonth = 273;
    }
    if(strcmp(d1->month,"November") == 0){
        d1->intMonth = 304;
    }
    if(strcmp(d1->month,"December") == 0){
        d1->intMonth = 334;
    }
}

int dayGap(Date d1, Date d2){

    if (d1.intYear > d2.intYear){
        return ((d1.intYear-d2.intYear)*365 + (d1.intMonth+d1.intDay)-(d2.intMonth+d2.intDay));
    }
    if (d1.intYear < d2.intYear){
        return -1*((d1.intYear-d2.intYear)*365 + (d1.intMonth+d1.intDay)-(d2.intMonth+d2.intDay));
    }
    if (d1.intYear == d2.intYear){
        return abs((d1.intMonth+d1.intDay)-(d2.intMonth+d2.intDay));
    }
}

void Operate(Date *d1){
splitter (d1);
setMonth(d1);
}

void DatePrinter(Date d1){
    printf("%s",d1.fdBuffer);
    printf("\nMonth: %s",d1.month);
    printf("\nDay: %i",d1.intDay);
    printf("\nYear: %i",d1.intYear);
    printf("\nDay of Year: %i\n",d1.intMonth+d1.intDay);
}

int main(){

Date d1, d2;
setDate(&d1,"September 21, 1989");
setDate(&d2,"December 31, 2020");
Operate(&d1);
Operate(&d2);

printf("DATE #1\n\n");
DatePrinter(d1);
printf("\n\nDATE #2\n\n");
DatePrinter(d2);
printf("\nDay gap between dates: %i days",dayGap(d1,d2));
printf("\n\n\nEND\n");

return 0;
}

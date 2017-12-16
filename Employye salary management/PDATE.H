#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<dos.h>
class pdate
{
public:
friend void time(void);
};
void time()
 {
   struct date d;
   getdate(&d);
   printf(" %d/%d/%d", d.da_day, d.da_mon, d.da_year);
   struct  time t;
   gettime(&t);
   printf("\t\t\t\t\t\ttime:%2d:%02d:%02d\n",t.ti_hour, t.ti_min, t.ti_sec);

 }

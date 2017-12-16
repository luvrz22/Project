#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include"pslip.cpp"
#include"pdate.h"
#include<string.h>

void main()
{
   char ch;
   while(1)
   {
      clrscr();
      time();
      header();
      cout<<"\n\nMain Menu";
      cout<<"\n1. EMPLOYEE DETAILS";
      cout<<"\n2. PAY SLIP GENERATION";
      cout<<"\n0. Exit";
      cout<<"\n____________________________";
      cout<<"\nEnter Option : ";
      fflush(stdin);
      ch=getche();
      switch(ch)
      {
	 case '0':
		   exit(0);
	 case '1':
		   emp();
		   break;
	 case '2':
		   pslip();
		   break;
      }
   }
   getch();
}


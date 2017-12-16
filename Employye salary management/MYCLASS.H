#include<dos.h>
#include<iostream.h>
#include<conio.h>

void header(void)
{
   gotoxy(30,2);
   cout<<"PAYSLIP GENERATION";
   gotoxy(34,4);
   cout<<"Developed By";
   gotoxy(34,6);
   cout<<"Aditya Rana";
   gotoxy(34,8);
   cout<<"Mohit Thapa";
   gotoxy(1,9);
   for(int i=1;i<=70;i++)
   {
	cout<<"_";
   }
}


class mydate
{
 int d,m,y;
 public:
       friend mydate input_date(void);
       friend mydate cur_date(void);
       void show_date(void);
};
mydate cur_date(void)
{
 mydate t;
 struct date cd;
 getdate(&cd);
 t.d=cd.da_day;
 t.m=cd.da_mon;
 t.y=cd.da_year;
 return(t);
}
mydate input_date(void)
{
 mydate t;
 top:
 cout<<"\n input date (dd mm yyyy)format:";
 cin>>t.d>>t.m>>t.y;
 if(t.d<1||t.d>31)
 {
  cout<<"\nwrong day inputted";
  goto top;

 }
  if(t.m<1||t.m>12)
 {
  cout<<"\nwrong month inputted";
  goto top;

 }
  if(t.y<1000||t.y>9999)
 {
  cout<<"\nwrong year inputted";
  goto top;
 }
 return(t);
}
void mydate::show_date(void)
{
 cout<<d<<"/"<<m<<"/"<<y;
}



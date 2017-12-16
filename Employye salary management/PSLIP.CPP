#include<iostream.h>
#include<process.h>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include"employee.h"
#include"myclass.h"
class salary
{
   int ins,empid;
   double loan;
   double basic;
   double net_amt,g_amt,ded;
   float thra,tda,tta,tsalary,tpf,ttax;
   int MM,YY;
   mydate dt;
	public:
	friend int readdata1(int);
	void input_data(int);
	friend void cal();
	void display();
// friend void get_val(int ,double ,int,int,int);
};

void salary::input_data(int no)
{
	ins=0;
	loan=0;
	empid=no;
	int HRA,TA,DA;

	get_val(empid,basic,TA,DA,HRA);
       dt=input_date();
	cout<<"Salary generation month:";
	cin>>MM;
	cout<<"Salary generation year:";
	cin>>YY;
	cout<<"DEDUCTION MENU\n";
	cout<<"\nEnter income tax in percentage:";
	int tax;
	cin>>tax;
	cout<<"PF in percentage:";
	int PF;
	cin>>PF;
	cout<<"Any insurence(y/n):";
	char ch;
	cin>>ch;
	if(ch=='y'||ch=='Y')
	{
		cout<<"Enter insurence amount:";
		cin>>ins;
	}
	cout<<"Any loan(y/n):";
	char ch1;
	cin>>ch;
	if(ch=='y'||ch=='Y')
	{
		cout<<"Enter the loan amount:";
		cin>>loan;
	}
	tpf=(basic*PF)/100;
	thra=(basic*HRA)/100;
	tta=(basic*TA)/100;
	tda=(basic*DA)/100;
	tsalary=(basic+thra+tta+tda);
	ttax=(tsalary*12*tax)/100;
	ded=(tpf+loan+ins+(ttax/12));
	net_amt=tsalary-ded;
}
void salary::display()
{
	 cout<<"\nGeneration Date:";
	 dt.show_date();
	 cout<<"\nSalary month :"<<MM<<"\n"<<"Year :"<<YY;
	 cout<<"\n____________________________________";
	 cout<<"\n\t\tEmployee id: "<<empid;
	 cout<<"\nBasic: Rs."<<basic;
	 cout<<"\nHRA= Rs."<<thra;
	 cout<<"\nTA= Rs."<<tta;
	 cout<<"\nDA= Rs."<<tda;
	 cout<<"\n____________________________________";
	 cout<<"\nDeductions:";
	 cout<<"\nProvident Fund: Rs."<<tpf;
	 cout<<"\nTAX(Yearly): Rs. "<<ttax;
	 cout<<"\nINSURENCE: Rs."<<ins;
	 cout<<"\nLoan: Rs."<<loan;
	 cout<<"\n_____________________________________";
	 cout<<"\nGross Salary= Rs."<<tsalary;
	 cout<<"\nDeduction= Rs."<<ded;
	 cout<<"\nNet Amount= Rs."<<net_amt;

}
int readdata1(int id)
{
	 int i=0;
	 salary s;
	 fstream fp1;
	 fp1.open("pslip.dat",ios::in| ios::binary);
	 if(fp1.fail())
	 {
		  cout<<"\nUnable to open file.";
		  getch();
		  return(i);
	 }
	 fp1.seekp(0,ios::beg);
	 char ch;

	 while(1)
	 {
		  clrscr();
		  fp1.read((char *) &s,sizeof(s));
		  if(fp1.eof())
		  {
			   break;
		  }
		  if(id==s.empid)
		  {

		  i++;
		  cout<<"\nRecord No. #"<<i;
		  s.display();
		  cout<<"\n\nPress 'c' to continue ...";
		  ch=getche();
		  if(ch!='c')
			   break;


		  }
	 }
	 return(i);
}



void pslip()
{
	clrscr();
	employee b;
	salary sal;

	fstream fp1,fp2;
	fp1.open("prod.dat",ios::in|ios::out|ios::binary);
	if(fp1.fail())
	{
	cout<<"unable to open ....check path";
	exit(0);
	}
	fp2.open("pslip.dat",ios::in|ios::out|ios::binary);
	if(fp2.fail())
	{
		fp2.open("pslip.dat",ios::out|ios::binary);
		if(fp2.fail())
		{
			cout<<"unable to open file";
			exit(0);
			fp2.close();
			fp2.open("pslip.dat",ios::in|ios::out|ios::binary);
		}
	}
		char op;
		while(1)
		{
			clrscr();
			header();
			cout<<"\nPAYSLIP GENERATION MENU";
			cout<<"\n__________________________";
			cout<<"\n1.Entry\n";
			cout<<"2.Display\n";
			cout<<"3.Edit Employee\n";
			cout<<"0.Home";
			cout<<"\n__________________________";
			cout<<"\nEnter your option:";
			op=getche();
			switch(op)
			{
				case '0':
				fp1.close();
				return ;
				case '1':
					clrscr();
					int no,f;
					cout<<"\nEnter emp id: ";
					cin>>no;
					f=searchID(no);
					if(f!=0)
					{
					sal.input_data(no);
					fp2.seekp(0,ios::end);
					fp2.write((char *)&sal,sizeof(sal));
					fp2.close();
					fp2.open("pslip.dat",ios::in|ios::out|ios::binary);
					cout<<"\nRecord saved";
					}
					else
					{
					cout<<"Record Does not exists.";

					}
					getch();
					break;
					case '2':
					cout<<"\nEnter emp id:";
					cin>>no;
						f=searchID(no);
					if(f!=0)
					{
						readdata1(no);
					}
					else
					{
					cout<<"Record Does not exists.";

					}



					break;
					case '3':
					emp();
					break;
			}
		}
getch();
}



class employee
{
	int empid;
	char emp_name[50];
	char address[100],desig[50];
	int dd,mm,yy;
	double basic;
	int HRA,TA,DA;

//mydate dt;
   public:
	void inputdata(void);
    void inputdata1(void);
       //	friend void modify();
	void display(void);
	friend int readdata();
	friend void savedata(employee &, fstream &fp);
	friend int searchID(int);
	friend void get_val(int,double &,int &,int &,int &);

};

void employee::inputdata()
{
	 cout<<"Employee id: ";
	 cin>>empid;
	 cout<<"Enter Name: ";
	 gets(emp_name);
	 cout<<"\nEnter address: ";
	 gets(address);
	 cout<<"\nEnter designation: ";
	 gets(desig);
	 cout<<"\nDate of joining in the for dd/mm/yyyy: ";
	 cin>>dd>>mm>>yy;
	 cout<<"\nEnter basic salary:";
	 cin>>basic;
	 cout<<"\nEnter HRA,TA,DA in percentage:";
	 cin>>HRA>>TA>>DA;
 //dt.inputdate();
}
void get_val(int id,double &b ,int &ta,int &da,int &hra)
{
employee a;
fstream fp;
fp.open("proj.dat",ios::in|ios::binary);
while(1)
{
fp.read((char *)&a,sizeof(a));
if(fp.eof())
break;
if(id==a.empid)
{
b=a.basic;
ta=a.TA;
da=a.DA;
hra=a.HRA;
break;
}
}
fp.close();
}

void employee::inputdata1()
{

	 cout<<"\nEnter name: ";
	 gets(emp_name);
	 cout<<"\nEnter address: ";
	 gets(address);
	 cout<<"\nEnter designation: ";
	 gets(desig);
	 cout<<"\nDate of joining in the for dd/mm/yyyy: ";
	 cin>>dd>>mm>>yy;
	 cout<<"\nEnter basic salary:";
	 cin>>basic;
	 cout<<"\nEnter HRA,TA,DA in percentage:";
	 cin>>HRA>>TA>>DA;
 //dt.inputdate();
}
void employee::display()
{
	 cout<<"\nEmpplyee id: "<<empid;
	 cout<<"\nEmployee name:"<<emp_name;
	 cout<<"\nEddress:"<<address;
	 cout<<"\nDessignation:"<<desig<<" \ndoj"<<dd<<"/"<<mm<<"/"<<yy;
	 cout<<"\nBASIC SALARY :"<<basic;
	 cout<<"\n HRA="<<HRA<<"%\t"<<"\n TA="<<TA<<"%\t"<<"\nDA="<<DA<<"%\t";
 //cout<<"\nDate:";
 //dt.displaydate();
}

void savedata(employee &obj, fstream &fp)
{
	 int flag=0;
	 flag=searchID(obj.empid);
	 if(flag!=0)
	  {
		  cout<<"\n ID already exit";
	  }
	 else
	 {
		  fp.seekp(0,ios::end);
		  fp.write((char *) &obj,sizeof(obj));
fp.close();
fp.open("proj.dat",ios::in|ios::out|ios::binary);
		  cout<<"\n record saved";
	 }
}

int searchID(int x)
{
	 int i=0;
	 employee obj;
	 fstream fp1;
	 fp1.open("proj.dat",ios::in| ios::binary);
	 if(fp1.fail())
	 {
		  cout<<"\nUnable to open file.";
		  getch();
		  return(i);
	 }
	 fp1.seekp(0,ios::beg);
	 while(1)
	 {
		  fp1.read((char *) &obj,sizeof(obj));
		  if(fp1.eof())
		  {
			   return(0);
		  }
		  i++;
		  if(obj.empid==x)
		  {
			   return(i);
		  }
	 }
}

int readdata(void)
{
	 int i=0;
	 employee obj;
	 fstream fp1;
	 fp1.open("proj.dat",ios::in| ios::binary);
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
		  fp1.read((char *) &obj,sizeof(obj));
		  if(fp1.eof())
		  {
			   break;
		  }
		  i++;
		  cout<<"\nRecord No. #"<<i;
		  obj.display();
		  cout<<"\n\nPress 'c' to continue ...";
		  ch=getche();
		  if(ch!='c')
			   break;
	 }
	 return(i);
}


emp()
{
	 clrscr();
	 employee obj;
	 fstream fp;

	 fp.open("proj.dat",ios::in|ios::out|ios::binary);
	 if(fp.fail())
	 {
		  fp.open("proj.dat",ios::out|ios::binary);
		  if(fp.fail())
		  {
			   cout<<"\n unable to create file";
			   getch();
			   exit(0);
		  }
		  fp.close();
		  fp.open("proj.dat",ios::in|ios::out|ios::binary);
	 }
	 char op;
	 while(1)
	{
		  clrscr();

		  cout<<"\nEMPLOYEE MENU";
		  cout<<"\n________________________";
		  cout<<"\n1.Add new employee";
		  cout<<"\n2.Display employee";
		  cout<<"\n3.Search employee";
		  cout<<"\n4.Modify employee";
		  cout<<"\n5.Delete";
		  cout<<"\n6.Home";
		  cout<<"\n_________________________";
		  cout<<"\nEnter your option";
		  op=getche();
		  switch(op)
		  {
			  case '1':
				 char ch;
				 do
				 {
					 clrscr();
					 obj.inputdata();
					 savedata(obj,fp);
					 cout<<"\nDo you want to add more(Y/N)?";
					 ch=getche();
				 }while(ch=='Y'||ch=='y');
			  break;
			  case '2':
				  clrscr();
				  readdata();
			  break;
			  case '3':
				clrscr();
		 int no,f;
		 cout<<"\nEnter emp id: ";
		 cin>>no;
		 f=searchID(no);
		 if(f!=0)
		 {
clrscr();
		    fp.seekp((f-1)*sizeof(obj),ios::beg);
		    fp.read((char *)&obj,sizeof(obj));
		    obj.display();

		 }
		 else
		 {
		    cout<<"Record Does not exists.";

		 }
getch();
		 break;

			case '4':
				clrscr();

		 cout<<"\nEnter emp id ";
		 cin>>no;
		 f=searchID(no);
		 if(f!=0)
		 {
clrscr();
		    fp.seekp((f-1)*sizeof(obj),ios::beg);
		    fp.read((char *)&obj,sizeof(obj));
		    obj.display();
		    cout<<"\nEnter new data";
		    obj.inputdata1();
		    fp.seekp((f-1)*sizeof(obj),ios::beg);
		    fp.write((char *)&obj,sizeof(obj));


		    fp.close();
		    fp.open("proj.dat",ios::in|ios::out|ios::binary);
		    getch();
		 }
		 else
		 {
		    cout<<"Record Does not exists.";
		    getch();
		 }
		 break;
case '5':

		 cout<<"\n empid: ";
    int id;
    cin>>id;
    f=searchID(id);
    if(f==0)
    {
     cout<<"\n ID not Found";
    }
    else
    {
     clrscr();
     fp.seekp((f-1)*sizeof(obj), ios::beg);
     fp.read((char *)&obj, sizeof(obj));
     obj.display();
     cout<<"\n\n Do you want to delete this record?(Y/N): ";
     ch=getche();

     if(ch=='Y'||ch=='y')
     {
	  int i=0;
	  ofstream np;
	  np.open("temp.dat",ios::out|ios::binary);
	  fp.seekp(0, ios::beg);
	  while(1)
	  {
	   fp.read((char *)&obj, sizeof(obj));
	   if(fp.eof())
	   {
	fp.close();
	np.close();
	remove("proj.dat");
	rename("temp.dat", "proj.dat");
       fp.open("proj.dat", ios::in|ios::out|ios::binary);
	cout<<"\n Record Deleted";
	break;
	   }

	   i++;

	   if(i!=f)
	   {
		np.write((char *)&obj,sizeof(obj));
	   }
	  }
	 }
    }
  getch();
  break;
  case '6':
return 0;
  default:
  cout<<"\n Invalid Entry";
	}
}
}

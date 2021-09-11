/*Shop Management System Project Source Code
Developed using concepts of file handling and oops concepts
Username: Admin
Password: Shop21
*/
#include<iostream>
#include<fstream>
#include<conio.h>
#include<process.h>              // exit() fuction
#include<string.h>              // strcmp() and strcpy() function
#include<stdio.h>
#include<iomanip>               //to use setw manipulator
#include<iostream>
using namespace std;              // gets() and puts()
class earn
{
    protected:
    static int profit;
     int profitx;
     int salary;
    public:
        void dis()
        {
        cout<<"\n###################################################\n\n";
        cout<<"\nTOTAL MONTHLY PROFIT: "<<profit<<"$"<<endl;
        cout<<"\n###################################################\n\n";
        }
};
int earn::profit;
class manager:public earn                 // 1st class for manager for products and details
{
    private:
	int pcode;              //Product code
	char pname[20];         //Product name
	long long int cost_price; //Product Cost price
	long long int sell_price;  //Product Sell price
	        //Profit
	int pquantity;          //Product Quantity
   public:
	void input();           //Adding data of products
	void output();          //displaying data of product
	void readfile();        //reading the manager.dat file
	void writefile();       //writing into the manager.dat file
	void modifile();        //modify the manager.dat file
	void deletefile();      //delete into the manager.dat file
	void searchfile();      //search onto the manager.dat file
};

void manager :: input()         // Function 1.1
{
    cout<<"\nEnter the Product Code: ";
	cin>>pcode;
	cout<<"Enter the Product Name: ";
	cin>>pname;
	cout<<"Enter the cost price of Product: ";
	cin>>cost_price;
	cout<<"Enter the Sell price of Product: ";
	cin>>sell_price;
	cout<<"Enter the Quantity of Product: ";
	cin>>pquantity;
	cout<<"\n--------------------------------";
}
void manager :: output()        // Function 1.2
{
	cout<<"\n Product Code: "<<pcode;
	cout<<"\n Product Name : "<<pname;
	cout<<"\n Product Cost Price: "<<cost_price;
	cout<<"\n Product Sell Price: "<<sell_price;
	cout<<"\n Product Quantity: "<<pquantity;
	profitx=(sell_price-cost_price)*pquantity;
	cout<<"\n Profit on the Product: "<<profitx;
	profit+=profitx;
	cout<<"\n--------------------------------";
}
void manager :: readfile()      // Function 1.3
{
	manager c;
	ifstream ifile("manager.dat",ios::binary|ios::in|ios::app);
	if(!ifile)
		cout<<"!!File Does Not Exist!!";
	else
	{
		cout<<"!!Total Products in the Shop!!\n";
		while(ifile.read((char*)&c,sizeof(manager)))
		{
			c.output();
		}
		ifile.close();
	}
}
void manager :: writefile()     // Function 1.4
{
	int i,n;
	cout<<"!!Enter total Number of Products to Insert: !!\n";
	cin>>n;
	manager c[n];
	ofstream ofile("manager.dat",ios::binary|ios::out|ios::app);
	for(i=0;i<n;i++)
	{
		c[i].input();
		ofile.write((char*)&c[i],sizeof(manager));
	}
	ofile.close();
}
void manager :: modifile()      // Function 1.5
{
	manager c1,c2;
	int f=0;
	ifstream ifile("manager.dat",ios::binary|ios::in);
	ofstream ofile("temp.dat",ios::binary|ios::out);
	if(!ifile)
		cout<<"!!File Does Not Exist!!";
	else
	{
		cout<<"!!Enter Product Code That Need To Be Modified!!\n";
		c1.input();
		while(ifile.read((char*)&c2,sizeof(c2)))
		{
			if(c1.pcode==c2.pcode)
			{
				f=1;
				ofile.write((char*)&c1,sizeof(c1));
			}
			else
				ofile.write((char*)&c2,sizeof(c2));
		}
		ifile.close();
		ofile.close();
		if(f==1)
		{
			remove("manager.dat");
			rename("temp.dat","manager.dat");
		}
		else
			cout<<"!!Information Does Not Exist!!";
	}
}
void manager :: deletefile()    // Function 1.6
{
	manager c;
	int f=0,PC;
	ifstream ifile("manager.dat",ios::binary|ios::in);
	ofstream ofile("temp.dat",ios::binary|ios::out);
	if(!ifile)
		cout<<"!!File Does Not Exist!!";
	else
	{
		cout<<"!!Enter Any Product Code That Need To Be Deleted!!: \n";
		cin>>PC;
		while(ifile.read((char*)&c,sizeof(c)))
		{
			if(c.pcode==PC)
			  {
				f=1;
				c.output();
			  }
			else
				ofile.write((char*)&c,sizeof(c));
		}
		ifile.close();
		ofile.close();
		if(f==1)
		{
			remove("manager.dat");
			rename("temp.dat","manager.dat");
			cout<<"\n\n!!Record Delete!!";
		}
		else
			cout<<"!!Information Does Not Exist!!";
	}
}
void manager :: searchfile()    // Function 1.7
{
	int PC,f=0;
	manager c;
	ifstream ifile("manager.dat",ios::binary|ios::in);
	if(!ifile)
		cout<<"!!File Does Not Exist!!";
	else
	{
		cout<<"!!Enter Any Product Code That Need To Be Seached!!: \n";
		cin>>PC;
		while(ifile.read((char*)&c,sizeof(c))&&(f==0))
		{
			if(PC==c.pcode)
			{
				c.output();
				f=1;
			}
		}
		ifile.close();
		if(f==0)
			cout<<"!!Information Does Not Exist!!";
	}
}
class employee:public earn	// 2nd class for employee details
{
    private:
	int c_code;             //Employee code
	char c_name[20];        //Employee name
	char phnumber[20];      //Employee phone number
	char address[100];      //Employee address
	char doj[10];           //Employee Date of joining
	      //salary of  employee
   public:
	void input();           //Adding data of employees
	void output();          //displaying data of employees
	void readfile();        //reading the employee.dat file
	void writefile();       //writing into the employee.dat file
	void modifile();        //modify the employee.dat file
	void deletefile();      //delete into the employee.dat file
	void searchfile();      //search onto the employee.dat file
};
void employee :: input()        // Function 1.1
{
	cout<<"\nEnter Employee Code: ";
	cin>>c_code;
	cout<<"Enter Employee Name: ";
	cin>>c_name;
	cout<<"Enter Employee Phone Number: ";
	cin>>phnumber;
	cout<<"Enter Employee Address: ";
	cin>>address;
	cout<<"Enter D.O.J: ";
	cin>>doj;
	cout<<"Enter the Salary of the employee: ";
	cin>>salary;
	cout<<"\n--------------------------------";
}
void employee :: output()       // Function 1.2
{
	cout<<"\nEmployee Code: "<<c_code;
	cout<<"\nEmployee Name: "<<c_name;
	cout<<"\nEmployee Phone Number: "<<phnumber;
	cout<<"\nEmployee Address: "<<address;
	cout<<"\nEnter D.O.J: "<<doj;
	cout<<"\nSalary of the employee: "<<salary;
	profit=(profit-salary);
	cout<<"\n--------------------------------";
}
void employee :: readfile()     // Function 1.3
{
	ifstream ifile("employee.dat",ios::binary|ios::in);
	employee c;
	if(!ifile)
		cout<<"!!File Does Not Exist!!";
	else
	{
		cout<<"!!Total Number Of Employee Entered!!\n";
		while(ifile.read((char*)&c,sizeof(employee)))
		{
			c.output();
		}
		ifile.close();
	}
}
void employee :: writefile()    // Function 1.4
{
	int i,n;
	cout<<"!!Enter total Number of Employees!!: \n";
	cin>>n;
	employee c[n];
	ofstream ofile("employee.dat",ios::binary|ios::out|ios::app);
	for(i=0;i<n;i++)
	{
		c[i].input();
		ofile.write((char*)&c[i],sizeof(employee));
	}
	ofile.close();
}
void employee :: modifile()     // Function 1.5
{
	employee c1,c2;
	int f=0;
	ifstream ifile("employee.dat",ios::binary|ios::in);
	ofstream ofile("temp.dat",ios::binary|ios::out);
	if(!ifile)
		cout<<"!!File Does Not Exist!!";
	else
	{
		cout<<"!!Enter Employee Number That Need To Be Modified!!\n";
		c1.input();
		while(ifile.read((char*)&c2,sizeof(c2)))
		{
			if(c1.c_code==c2.c_code)
			{
				f=1;
				ofile.write((char*)&c1,sizeof(c1));
			}
			else
				ofile.write((char*)&c2,sizeof(c2));
		}
		ifile.close();
		ofile.close();
		if(f==1)
		{
			remove("employee.dat");
			rename("temp.dat","croma.dat");
		}
		else
			cout<<"!!Information Does Not Exist!!";
	}
}
void employee :: deletefile()   // Function 1.6
{
	employee c;
	int f=0,CC;
	ifstream ifile("employee.dat",ios::binary|ios::in);
	ofstream ofile("temp.dat",ios::binary|ios::out);
	if(!ifile)
		cout<<"!!File Does Not Exist!!";
	else
	{
		cout<<"!!Enter Any Employee Code That Need To Be Deleted!!: \n";
		cin>>CC;
		while(ifile.read((char*)&c,sizeof(employee)))
		{
			if(c.c_code==CC)
			  {
				f=1;
				c.output();
			  }
			else
				ofile.write((char*)&c,sizeof(employee));
		}
		ifile.close();
		ofile.close();
		if(f==1)
		{
			remove("employee.dat");
			rename("temp.dat","employee.dat");
			cout<<"\n\n!!Record Delete!!";
		}
		else
			cout<<"!!Information Does Not Exist!!";
	}
}
void employee :: searchfile()   // Function 1.7
{
	int CC,f=0;
	employee c;
	ifstream ifile("employee.dat",ios::binary|ios::in);
	if(!ifile)
		cout<<"!!File Does Not Exist!!";
	else
	{
		cout<<"!!Enter Any employee Code That Need To Be Seached!!";
		cin>>CC;
		while(ifile.read((char*)&c,sizeof(c))&&(f==0))
		{
			if(CC==c.c_code)
			{
				c.output();
				f=1;
			}
		}
		ifile.close();
		if(f==0)
			cout<<endl<<"!!Information Does Not Exist!!";
	}
}
int main()
{
// manager`s object
 manager c1;
 // employee`s object
 employee C1;
 earn e1;
 int choice,ch1,ch2,f=1,i=0,j=0;
 char ch3[4];
 system("cls");
				//mains screen
 cout<<setw(100)<<"DEVELOPED BY \n "<<setw(97)<<"Navneet Gupta"<<endl;
 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
 cout<<setw(105)<<"********************************************"<<endl;
 cout<<setw(92)<<"WELCOME TO THE "<<endl;
 cout<<setw(97)<< "NAV ELECTRONICS MEGASTORE"<<endl;
 cout<<setw(105)<<"********************************************"<<endl;
 cout<<"\n\n\n\n\n\n\n\n\nPRESS ANY KEY TO CONTINUE ";
 getch();				//1st login screen
 do{
 system("cls");
 char username[20],password[20];
 cout<<"\n\n\n\n\n\t\t LOGIN ";
 cout<<"\n\t\t\t USERNAME:- ";
 cin>>username;
 cout<<"\n\t\t\t PASSWORD:-";
while(i<=5)
{
password[i]=getch();
cout<<"*";
++i;
}
 password[i]='\0';
 getch();
 if(strcmp(username,"Admin")==0 && strcmp(password,"shop21")==0)
  {
   f=0;
   goto I;
  }
 else
 {
  cout<<setw(60)<<"\nINVALID USERNAME OR PASSWORD!!";
  cout<<setw(60)<<"\n\n\n\n\n\nDO YOU WANT TO EXIT(y/n):- ";
  cin>>ch3;
  if(strcmp(ch3,"y")==0)
   {
    exit(0);
   }
 }
 }while(f!=0);
 getch();
 system("cls");
 do
 {
     I:
         system("cls");
         cout<<"\n\t\t\t\t\t 1.Manager"<<endl;
         cout<<"\n\t\t\t\t\t 2.EXIT"<<endl;
         cout<<"\nEnter your choice: "<<endl;
         cin>>choice;
         switch(choice)
         {
             A:
         case 1:
            do
            {
                system("cls");
                cout<<"\n 1.Product"<<endl;
                cout<<"\n 2.Employee"<<endl;
                cout<<"\n 3.Profit"<<endl;
                cout<<"\n 4.Exit"<<endl;
                cout<<"\nEnter your choice: "<<endl;
                cin>>ch1;
                switch(ch1)
                {
                case 1:
                    do
	    {
				// 2nd menu
	   system("cls");
	     cout<<"\n\n\n\n\t\t================================";
	     cout<<"\n\n\n\n\t\t 1.ADD PRODUCTS";
	     cout<<"\n\t\t 2.DETAILS OF PRODUCTS";
	     cout<<"\n\t\t 3.EDIT PRODUCTS DETAILS";
	     cout<<"\n\t\t 4.DELETE PRODUCTS";
	     cout<<"\n\t\t 5.SEARCH PRODUCTS";
	     cout<<"\n\t\t 6.EXIT";
	     cout<<"\n\n\n\t\t=====================================";
	     cout<<"\n\t\tENTER YOUR CHOICE:-";
	     cin>>ch2;
	     system("cls");
	     switch(ch2)
	     {
	      case 1:
		  system("cls");
		     c1.writefile();
		     getch();
		     break;
	      case 2:
		     system("cls");
		     c1.readfile();
		     getch();
		     break;
	      case 3:
		    system("cls");
		     c1.modifile();
		     getch();
		     break;
	      case 4:
		    system("cls");
		     c1.deletefile();
		     getch();
		     break;
	      case 5:
		  system("cls");
		     c1.searchfile();
		     getch();
		     break;
          case 6:
            goto I;
            }
                }while(ch2!=6);
          case 2:
              do
	    {
				//3rd menu
	    system("cls");
	     cout<<"\n\n\n\t\t===============EMPLOYEE===============";
	     cout<<"\n\n\t\t1.ADD EMPLOYEE";
	     cout<<"\n\t\t2.DETAILS OF EMPLOYEE ";
	     cout<<"\n\t\t3.EDIT EMPLOYEE";
	     cout<<"\n\t\t4.DELETE EMPLOYEE";
	     cout<<"\n\t\t5.SEARCH EMPLOYEE";
	     cout<<"\n\t\t6.BACK";
	     cout<<"\n\n\n\t\t======================================";
	     cout<<"\n\t\tENTER YOUR CHOICE:-";
	     cin>>ch2;
	    system("cls");
	     switch(ch2)
	     {
	      case 1:
		    system("cls");
		     C1.writefile();
		     getch();
		     break;
	      case 2:
		    system("cls");
		     C1.readfile();
		     getch();
		     break;
	      case 3:
		   system("cls");
		     C1.modifile();
		     getch();
		     break;
	      case 4:
		   system("cls");
		     C1.deletefile();
		     getch();
		     break;
	      case 5:
		  system("cls");
		     C1.searchfile();
		     getch();
		     break;
          case 6:
            goto I;
	   }

            }while(ch2!=6);
          case 3:
              system("cls");
              e1.dis();
            getch();
            break;
          case 4:
            system("cls");
         }
 }while(ch1!=4);
          case 2:
           system("cls");
	   cout<<setw(60)<<"END OF PROGRAM"<<endl;
	   cout<<setw(62)<<"BY NAVNEET GUPTA"<<endl;
	   cout<<setw(60)<<"UID: 20BCS4148"<<endl;
	    cout<<setw(62)<<"THANKS FOR USING"<<endl;
}
}while(choice!=2);
}


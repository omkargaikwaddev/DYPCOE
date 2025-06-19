/*
Madhur Jaripatke
Roll No. 56
SE A Computer
RMDSSOE, Warje, Pune
*/
/*
Develop a program in C++ to create a database of student’s information system containing the
following information: Name, Roll number, Class, Division, Date of Birth, Blood group, Contact
address, Telephone number, Driving license no. and other. Construct the database with
suitable member functions. Make use of constructor, default constructor, copy constructor,
destructor, static member functions, friend class, this pointer, inline code and dynamic
memory allocation operators-new and delete as well as exception handling.
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Person
{
	char name[50],dob[10],bg[5];
	int h,w;
	public:
	static int count;
	friend class Personal;
	Person()
	{
		char *name=new char [50];
		char *dob=new char [10];
		char *bg=new char [5];
		h=w=0;
	}
	static void recordcount()
	{
		cout<<"\nTotal Number of Records: "<<count<<endl;
	}
};		
class Personal
{
	char add[70],num[15],policy_num[15];
	public:
	Personal()
	{
		strcpy(add,"");
		strcpy(num,"");
		strcpy(policy_num,"");
	}
	void getdata(Person *P1);		
	void display(Person *P1);
	friend class Person;
};
int Person::count=0;
void Personal::getdata(Person *P1)
{
	cout<<"\nEnter Name ";
	cin>>P1->name;
	cout<<"\nEnter DOB in DD/MM/YYYY format ";
	cin>>P1->dob;
	cout<<"\nEnter Blood Group ";
	cin>>P1->bg;
	cout<<"\nEnter Height (in cm) ";
	cin>>P1->h;
	cout<<"\nEnter Weight (in kg) ";
	cin>>P1->w;
	cout<<"\nEnter Address (No Spaces) ";
	cin>>this->add;
	cout<<"\nEnter Phone Number ";
	cin>>this->num;
	cout<<"\nEnter Policy Number ";
	cin>>this->policy_num;
	P1->count++;
}
void Personal::display(Person *P1)
{
	cout<<"\n";
	cout<<P1->name<<"\t"<<P1->dob<<"\t"<<P1->bg<<"\t\t"<<P1->h<<"\t"<<P1->w<<"\t"<<this->num<<"\t"<<this->policy_num<<"\t"<<this->add;
}
int main()
{
	int n=0,ch,i;
	Personal *p1[30];
	Person *p2[30];
	while(true)
	{
		cout<<"Welcome\nPlease Enter Your Choice\n1.Enter Data\t2.Display Data\n3.Exit\n";
		cin>>ch;
		switch(ch)
		{
		case 1:
		cout<<"Please Enter The Following Information ";
		p1[n]=new Personal;
		p2[n]=new Person;
		p1[n]->getdata(p2[n]);
		n++;

		Person::recordcount();
		break;
		case 2:
		cout<<"\nNAME\tDATE OF BIRTH\tBLOOD GROUP\tHEIGHT\tWEIGHT\tNUMBER\t\tPOLICY NO.\tADDRESS";
		for(i=0;i<n;i++)
		{
		p1[i]->display(p2[i]);
		}
		Person::recordcount();
		break;
		case 3:
		exit(0);
		}
	}
	return 0;
}

/*

Classes Defined:

1. Person: Stores basic personal information like name, date of birth, blood group, height, and weight. It has a static member count to keep track of how many records exist.
Personal: Contains additional information such as address, phone number, and policy number. It also has functions to get and display data for a Person.
Member Functions:

2. Constructor: Both classes have constructors to initialize their attributes. The Person constructor attempts to create dynamic character arrays (although it doesn’t store them correctly).
getdata: A function in the Personal class that collects data from the user and stores it in the associated Person object.
display: Another function in the Personal class that prints out the details of the Person.
Static Function:

3. recordcount in the Person class displays the total number of records.
Dynamic Memory Allocation:

4. The program uses new to allocate memory for Personal and Person objects, allowing it to create multiple entries.
Main Loop:

5. The main function provides a simple text interface for users to enter or display student data. It continues until the user chooses to exit.
Exception Handling: The code doesn’t explicitly include exception handling, which could be added to manage potential errors (like invalid input).

6. Summary
In short, this program allows users to enter and view student information using classes to manage data. It utilizes dynamic memory for creating multiple records and uses static members to keep count of these records. The design allows for expansion, such as adding more student details or improving error handling.

*/
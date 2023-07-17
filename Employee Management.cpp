#include <bits/stdc++.h>
using namespace std;
// Declare here an employee structure and a vector of employee to store the information
struct employee{
	string firstName,lastName,dateOfBirth,title,kerberosid;
	char *startDate=NULL;
	char endDate[11]="99-99-9999";// for making infinity
};
vector<employee>emp(1000);
//struct employee vector<string>emp;
int i=0;
void addEmployeeInput(string &firstName,string &lastName,string &dateOfBirth,string &title) 
{
// Code for user prompt to input the required values
cout<<"enter the first name"<<endl;
cin>>firstName;
//getline(cin,firstName);
cout<<"enter the last name"<<endl;
cin>>lastName;
//getline(cin,lastName);
cout<<"enter the dob"<<endl;
cin>>dateOfBirth;
cout<<"enter the title"<<endl;
//getline(cin,title);
cin>>title;
}
void addEmployee(string firstName, string lastName,string dateOfBirth, string title) 
{ 
 // Code to add employee in system
   emp[i].firstName=firstName;
   emp[i].lastName=lastName;
   emp[i].dateOfBirth=dateOfBirth;
   emp[i].title=title;
   int j=2,k=emp.size();
   string id=(emp[i].firstName).substr(0,2)+(emp[i].lastName).substr(0,j);
   while(k--)
   {
   if(emp[k].kerberosid==id)
   {
   	j++;
   	id=(emp[k].firstName).substr(0,2)+(emp[k].lastName).substr(0,j);
   }
  }
   emp[i].kerberosid=id;
   // for start date we use system date below is program for finding system date.
   char d[100];
   time_t ct;
   tm*c;
   time(&ct);
   c=localtime(&ct);
   strftime(d,50,"%d-%m-%Y",c);
   emp[i].startDate=d;
   cout<<"kerberos-id\t"<<id<<endl;//<<emp[i].startDate<<endl;
   i++;
}
void filter(int filterChoice) 
{
//Code to filter employees based on selected filter
// filter 1 is for how many employees are active till the given date.
int m=i;
if(filterChoice==1)
{
	char idate[100];
    cout<<"enter user date of employee in Y-m-d"<<endl;
    cin>>idate;
    int j=0;
    while(m--)
    {
    	if(strcmp(idate,(emp[j].endDate))<=0)
    	{
    	 cout<<emp[j].firstName<<"\t";
	     cout<<emp[j].lastName<<endl;
		}
		j++;
    }
}
// filter 2 is for how many employees are there with that required title.
if(filterChoice==2)
{
	string reqtitle;
	cout<<"required title"<<endl;
	cin>>reqtitle;
	int j=0;
	while(m--) // i is no.of records in the system;
	{
		if(emp[j].title==reqtitle)
		{
		cout<<emp[j].firstName<<"\t";
	    cout<<emp[j].lastName<<endl;
		}
		j++;
	}
}

}
void searchEmployee(string kerberos) 
{
//Code to search the employee with given kerberos
int j=0,found=0;
while(1)
{
	if(emp[j].kerberosid==kerberos)
	{
	cout<<emp[j].firstName<<"\t";
	cout<<emp[j].lastName<<"\t";
	cout<<emp[j].dateOfBirth<<"\t";
	cout<<emp[j].title<<endl;
	found =1;
	break;
   }
   j++;
}
// no such employee exists
if(found==0)
{
	cout<<"There is no employee with given kerberos id\n";
}
}
void terminate(string kerberos)
{
//Code to terminate the employee with givenkerberos that is updating end date with today's date.
   char d[100];
   time_t ct;
   tm*c;
   time(&ct);
   c=localtime(&ct);
   strftime(d,50,"%Y-%m-%d",c);
   int j=0;
   while(1)
  {
    if(emp[j].kerberosid==kerberos)
	{
		strcpy(emp[j].endDate,d);
		break;
   }
   j++;
  }
  cout<<"updated details of employee\n";
  	cout<<emp[j].firstName<<"\t";
	cout<<emp[j].lastName<<"\t";
	cout<<emp[j].title<<"\t";
	cout<<emp[j].endDate<<endl;
}
int main() 
{
cout<<"\n------------------Employee Management----------------------\n"<<endl;
cout<<"Press 1 to Add an Employee\n"<<endl;
cout<<"Press 2 to Search an Employee\n"<<endl;
cout<<"Press 3 to Filter Employees\n"<<endl;
cout<<"Press 4 to Terminate an Employee\n"<<endl;
while(1)
{
 int choice;cin>>choice;
string firstName,lastName, dateOfBirth, title, kerberos;
switch(choice) 
{
case 1: addEmployeeInput(firstName, lastName, dateOfBirth, title);
       addEmployee(firstName, lastName, dateOfBirth, title);
	   break;
case 2:cout<<"Enter a kerberos id to search: "<<endl;
      cin>>kerberos;
	  searchEmployee(kerberos);
	  break;
case 3:cout<<"Press 1 to filter by isActive as ofa date\n"<<endl;
      cout<<"Press 2 to filter by title\n"<<endl;
	  int filterChoice;cin>>filterChoice;
	  filter(filterChoice);
	  break;
case 4:cout<<"Enter a kerberos id to terminate: "<<endl;
      cin>>kerberos;
	  terminate(kerberos);
	  break;
default:cout<<"Please select a valid choice"<<endl;
        break;
}
}
}

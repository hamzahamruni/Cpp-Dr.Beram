// 
//                                             Name:Hamza Hamruni
//                                             IdNumber:213010793
//                                                    Pg3
#include<fstream>
#include <iostream>
#include <iomanip>
#include<stdlib.h>
#include<cstring>
using namespace std;
struct Student
{
    int id;
	char name[50];
};
Student st;
void enter_id(void)
{
	cout<<"Enter id Number Of Student = ";
	cin>>st.id;
	while(st.id<0)
	{
		cout<<"Agen Enter id Number =";
		cin>>st.id;
	}
}
void enter_name(void)
{
	cout<<"Enter Name Students : ";
	cin.getline(st.name,49,'\n');
	
}
int system(void)
{
	//system("cls");
	int x;
	cout<<endl<<"                Nema          : HAMZA HAMRONI "<<endl<<"                Student Number: 213010793  "<<endl;
	cout<<"\n\n [1] - Add Student In Formation"<<"\n [2] - Display Student In Formation"<<"\n [3] - Update"<<"\n [4] - EndProgram"<<endl<<endl<<endl;
		cout<<"Enter your choice ?"<<endl;
		cin>>x;
		return x;
		    
}
void add(void)
{
	system("cls");
	ofstream file;
	file.open("student",ios::out | ios::app);
	if(!file)
	{
		cout<<"File Is Not Found ";
		
		exit(1);
	}
	
	
	enter_id();
	cin.ignore();
	enter_name();
	file.write((char *)&st, sizeof(Student));
	file.close();
}
void print(void)
{
	system("cls");
    ifstream file;
    char ch;
	file.open("student",ios::in);
	if(!file)
	{
		cout<<"File Is Not Found ";
		exit(1);
	}
	cout<<"id          Name"<<endl<<"______________________________________________________"<<endl;
	while(file.read((char *)&st,sizeof(Student)))
	{
	    cout<<setw(10)<<left<<st.id<<"  "<<setw(50)<<left<<st.name<<endl;
	}
	file.close();
}
void update(void)
{
	fstream file;
	long  location;
    char ok;
	file.open("student",ios::in | ios::out);
	if(!file)
	{
		cout<<"File Is Not Found ";
		exit(1);
	}
	int key;
	cout<<"Enter Id Number You Wante Update = ";
	cin>>key;
	while(file.read((char *)&st,sizeof(Student)))
	{
		if(st.id>0 && st.id==key)
		{
			cout<<st.id<<"     "<<st.name<<endl;
			 location = file.tellg();
			 cout<<" location = "<<location<<endl;
			cout<<"Do You Wante Update Data [Y/N]?";
			cin>>ok;
			cin.ignore();
			if(ok=='y' || ok=='Y')
			{
	     		enter_id();
	            cin.ignore();
				enter_name();
			   file.seekp(location -  sizeof(Student));
               file.write((char *)&st, sizeof(Student));
				break;
			}
		}
	}
	file.close();
}
int main()
{
	int choice;
	while((choice=system()))
	{
		switch (choice)
		{
			case 1:
				add();
				break;
			case 2:
				print();
				break;
			case 3:
				update();
				break;
			case 4:
				cout<<"**************END****************"<<endl;
				exit(1);
		}
	}
	
   return 0;
	
}


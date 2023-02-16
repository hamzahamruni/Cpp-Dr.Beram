//
//														Hamza Hamruni
//														  213010793
//														 Test_1 Q(4)
#include<fstream>
#include <iostream>
#include <iomanip>
#include<stdlib.h>
#include<cstring>
using namespace std;
struct student {
       long id;
       float exam[3];
};

//---------------------------------------------------------------------------------

void Add(const char filename[])
{
	system("cls");
	student stu;
	ofstream file;
	file.open(filename,ios::out | ios::app);
	cout<<"Enter Id Number Of Student :  ";
	cin>>stu.id;
	while(stu.id<=0)
	{
		cout<<"Plase Agane Enter Id Number : ";
		cin>>stu.id;
	}
	cout<<"Enter Exam 1 [0 - 100]: ";
	cin>>stu.exam[0];
	while(stu.exam[0]<0 || stu.exam[0]>100)
	{
		cout<<"plase Agane Enter Exam 1 [0 - 100]";					// 	Add Student
		cin>>stu.exam[0];
	}
	cout<<"Enter Exam 2 [0 - 100]: ";
	cin>>stu.exam[1];
	while(stu.exam[1]<0 || stu.exam[1]>100)
	{
		cout<<"plase Agane Enter Exam 2 [0 - 100]";
		cin>>stu.exam[1];
	}
	cout<<"Enter Exam 3 [0 - 100]: ";
	cin>>stu.exam[2];
	while(stu.exam[2]<0 || stu.exam[2]>100)
	{
		cout<<"plase Agane Enter Exam 3 [0 - 100]";
		cin>>stu.exam[2];
	}
	file.write((char *)&stu,sizeof(student));
	file.close();
}

//---------------------------------------------------------------------------------------------
void displayRec(const char filename[])
{
	system("cls");
	student stu;
	ifstream file;
	file.open(filename,ios::in);
	if(!file)
	{
		cout<<"\t\t\t\tFile IS Not Found ";
		return;																// Print
	}
	cout<<"Id Number     Exam 1     Exam 2     Exam 3 \n__________________________________________________________________________"<<endl;
	while(file.read((char *)&stu,sizeof(student)))
	{
		cout << setw(10) <<left<< stu.id << "     "
              << setw(6) << left <<stu.exam[0]<< "     "
              << setw(6) << left <<stu.exam[1]<< "     "
              << setw(6) << left <<stu.exam[2]<< "     "
              << endl;
	}
	file.close();
}
//-------------------------------------------------------------------------------------------
//													test 
void search(const char filename[],const long stdNo)
{
	system("cls");// 
	float final_grade;
	ifstream file;
	file.open(filename,ios::in);// ; 
	if(!file)
	{
		cout<<"File Is Not Fount"<<endl;
		return;
	}
	int flag=0;
	student ST;
	while(file.read((char *)&ST,sizeof(student)))
	{
		if(ST.id==stdNo)
		{
			flag=1;
			cout<<"student id = "<<ST.id<<endl;
			final_grade=(ST.exam[0]+ST.exam[1]+ST.exam[2])/3;// ST.
			cout<<"Final grade = "<<final_grade<<endl;
			if(final_grade>=85 && final_grade<=100)
			{
				cout<<"grade = excellent "<<endl;
				break;
			}
			if(final_grade>=75 && final_grade<85)
			{
				cout<<"grade = v.good "<<endl;
				break;
			}
			if(final_grade>=65 && final_grade<75)
			{
				cout<<"grade = good "<<endl;
				break;
			}
			if(final_grade>=50 && final_grade<65)
			{
				cout<<"grade = pass "<<endl;
				break;
			}
			if(final_grade>=0 && final_grade<50)
			{
				cout<<"grade = fail "<<endl;
				break;
			}
		}//end if
	}//end while
	file.close();
	if(flag==0)
	{
		cout<<"student not found "<<endl;
	}
}//end function
	
//-------------------------------------------------------------------------------------------------------------
int enterChoice()
{
   cout << "\n__________________________________________________________________________" << endl;
   cout<<"\n\t\t\t\tHamza Hamruni \n\t\t\t\t213010793"<<endl;
        cout<< "\n\t\t[1] - Display information" << endl
        << "\t\t[2] - Add " << endl
        <<"\t\t[3] - Search "<<endl									// System 
        << "\t\t[0] - End program " << endl;
   int menuChoice;
   cout << "\nEnter your choice: "; 
   cin >> menuChoice;
   return menuChoice;
}

//------------------------------------------------------------------------------------------------------------------
main(){
   char filename[30];
   cout << "\nEnter file name: "; 
   cin >> filename;
   long stdNo;
   int choice;
   while(choice=enterChoice())
	{
       switch (choice) {
          case 1: 
		  	  displayRec(filename); 
			  break;
          case 2: 
		  	  Add(filename); 
			  break;
		  case 3:
		  	cout<<"Enter Search stNo : ";
		  	cin>>stdNo;
		  	search(filename,stdNo);
		  	break;
          case 0: 
		  	   break;
          default: system("cls");
       }
   }
   cout <<endl;
}

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
enum y{Y,N};
struct student
{
	int number_of_student,many;					// Number Of Students & Many
	long id;									// Id Students 
	char name[50];								// Name Student
	y f;
	int number_of_courses;						// Number Of Courses
	char course[6];								// Course
	int credits;								// credits
	float grade;								// Grade
};
int main()
{
	student ST;
	ofstream file;
	file.open("StudentGrades.txt",ios::out | ios::app);
//-------------------------------------------------------------------------------------
	cout<<"Enter Number Students ? ";
	cin>>ST.number_of_student;
//-------------------------------------------------------------------------------
	cout<<"many ? ";
	cin>>ST.many;
//------------------------------------------------------------------------------
	file<<ST.number_of_student<<" "<<ST.many<<endl;
//-----------------------------------------------------------
	for(int i=0;i<ST.number_of_student;i++)
	{
		system("cls");
		cin.ignore();
		cout<<"Enter Id Number student : ";
		cin>>ST.id;
		cin.ignore();
//----------------------------------------------
		cout<<"Enter Name Student : ";	
		cin.getline(ST.name,49,'\n');
//---------------------------------------
		cout<<"many [Y/N] ? ";
		ST.f=Y;
//---------------------------------------
		cout<<"Enter Number Of Courses : ";
		cin>>ST.number_of_courses;
//-----------------------------------------
		file<<ST.id<<" "<<ST.name<<" "<<ST.f<<" "<<ST.number_of_courses<<endl;
//-----------------------------------------------------------------
		for(int j=0;j<ST.number_of_courses;j++)
		{
			
			cin.ignore();
			cout<<"Enter Course "<<j+1<<" : ";
			cin.getline(ST.course,6,'\n');
			cout<<"Enter Credits : ";
			cin>>ST.credits;
			cout<<"Enter Grade : ";
			cin>>ST.grade;
			file<<ST.course<<" "<<ST.credits<<" "<<ST.grade<<endl;
		}
//--------------------------------------

///------------------------------------------

//-----------------------------------------------
		

		
	}
	file.close();
	
}

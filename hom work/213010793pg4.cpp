//
//														Hamza Hamruni
//														  213010793
//														    PG_4
#include<iostream>
#include<fstream>
#include<string>
#include <iomanip>

using namespace std;
struct student
{
	int number_of_student,fee_value;						// Number Of Students & Fee Value
	long id;											 	// Students Id
	string first_name,middle_name,last_name;				// Student Name
	char status;											// Status [Y/N]
	int number_of_courses;									// Number Of Courses
	char course[6];											// Course
	int credits;											// credits
	float grade;											// Grade
};
//--------------------------------------------------------------------------------------------
int main()
{
	cout<<"\t\t\t\tHamza Hamruni\n\t\t\t\t  213010793\n\t\t\t\t    PG_4\n\n______________________________________________________________________\n";
	student ST;
	ifstream file;
	file.open("StudentGrades.txt",ios::in);
	if(!file)
	{
		cout<<"\t\t\t\tFile Is Not Found ";
		exit(1);
	}
//---------------------------------------------------------------------------------------------

	int Total_number_of_credits;
	float Semester_GPA;
	
//----------------------------------------------------------------------------------------------

	file>>ST.number_of_student>>ST.fee_value;
	 
//-----------------------------------------------------------
	for(int i=0;i<ST.number_of_student;i++)
	{
		Semester_GPA=0;
		Total_number_of_credits=0;
		
//-----------------------------------------------------------

		file>>ST.id>>ST.first_name>>ST.middle_name>>ST.last_name>>ST.status>>ST.number_of_courses;
	
//------------------------------------------------------------
		
		
			cout<<"\nStudent ID: "<<ST.id<<endl;
			cout<<"Student Name: "<<ST.first_name<<" "<<ST.middle_name<<" "<<ST.last_name<<endl;
			cout<<"Number of courses enrolled: "<<ST.number_of_courses<<endl;
			cout<<"Course     Credits     Grade"<<endl;
		for(int j=0;j<ST.number_of_courses;j++)
		{
//-------------------------------------------------------------

			file>>ST.course>>ST.credits>>ST.grade;
			
//-------------------------------------------------------------
			if(ST.status=='Y' || ST.status=='y')
			{
			
				cout<<ST.course<<setw(6)<<left<<"     "<<ST.credits<<setw(7)<<left<<"           "<<ST.grade<<endl;
			}
			if(ST.status=='n' || ST.status=='N')
			{
			
				cout<<ST.course<<setw(6)<<left<<"     "<<ST.credits<<setw(7)<<left<<"           "<<"*****"<<endl;
			}
			Total_number_of_credits+=ST.credits;
			Semester_GPA=Semester_GPA+(ST.grade*ST.credits);
		}
		Semester_GPA=Semester_GPA/Total_number_of_credits;
		if(ST.status=='Y' || ST.status=='y')
		{
		
			cout<<"\nTotal number of credits: "<<Total_number_of_credits<<endl;
			cout<<"Semester GPA: "<<Semester_GPA<<endl<<"______________________________________________________________________"<<endl;
		}
		if(ST.status=='n' || ST.status=='N')
		{
		
			cout<<"\nTotal number of credits: "<<Total_number_of_credits<<endl;
			cout<<"Sorry tuition not paid"<<endl<<"______________________________________________________________________"<<endl;
		}

		
	}
	file.close();
	
}

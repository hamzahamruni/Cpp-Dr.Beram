//
//                                                     Hamza Hamruni
//                                                      213010793
//                                                         PG3
#include<fstream>
#include <iostream>
#include <iomanip>
#include<stdlib.h>
#include<cstring>
using namespace std;
struct student
{
	long long id;
	char name[20];
	float examp1,examp2,final,final_grade;
};
student ST;
void cin_id()
{
	cout<<"Enter Id Number Of Student :  ";
	cin>>ST.id;
	while(ST.id<=0 || ST.id>9999999999)
	{
			cout<<"Plesa Agine Enter Id Number :  ";
	        cin>>ST.id;
	}
	cin.ignore();
}
void cin_name()
{
	cout<<"Enter Name Of Student :  ";
	cin>>ST.name;
	cin.ignore();
}
void cin_grade()
{
	cout<<"Enter Grade Examp 1 [0 - 100] : ";
	cin>>ST.examp1;
	while(ST.examp1<0 || ST.examp1>100)
	{
			cout<<"Plesa Agine Enter Grade Examp 1 [0 - 100] : ";
	        cin>>ST.examp1;
	}
	cout<<"Enter Grade Examp 2 [0 - 100] : ";
	cin>>ST.examp2;
	while(ST.examp2<0 || ST.examp2>100)
		{
			cout<<"Plesa Agine Enter Grade Examp 2 [0 - 100] : ";
	        cin>>ST.examp2;
	}
	cout<<"Enter Grade Final [0 - 100] : ";
	cin>>ST.final;
	while(ST.final<0 || ST.final>100)
	{
			cout<<"Plesa Agine Enter Grade Final [0 - 100] : ";
	        cin>>ST.final;
	}
	ST.final_grade=ST.examp1+ST.examp2+ST.final;
	cin.ignore();
}
void add()
{

	system("cls");
	ofstream file;
	file.open("student",ios::out | ios::app);
	cin_id();
	cin_name();
	cin_grade();
	file.write((char *)&ST,sizeof(student));
	file.close();
}
void statistcy()
{
	ifstream file;
	file.open("student",ios::in);
	if(!file)
	{
		cout<<"\tERORR\nFilr Is Not Found "<<endl;
		return;
	}
	int n=0;
	float max_examp1=0,min_examp1=100,avg_examp1=0;
    float max_examp2=0,min_examp2=100,avg_examp2=0;
	float max_final=0,min_final=100,avg_final=0;
	float max_final_grade=0,min_final_grade=300,avg_final_grade=0;
	while(file.read((char *)&ST,sizeof(student)))
	{
	
//----------------------------------------
		if(ST.examp1>max_examp1)
	    	  max_examp1=ST.examp1;
		if(ST.examp1<min_examp1)           // EXAMP 1 
	    	  min_examp1=ST.examp1;
		avg_examp1+=ST.examp1;
//----------------------------------------
		if(ST.examp2>max_examp2)
		      max_examp2=ST.examp2;
		if(ST.examp2<min_examp2)          // EXAMP 2 
	    	  min_examp2=ST.examp2;
		avg_examp2+=ST.examp2;
//------------------------------------------
		if(ST.final>max_final)
	    	  max_final=ST.final;
		if(ST.final<min_final)            // FINAL
	    	  min_final=ST.final;
		avg_final+=ST.final;
//--------------------------------------------
		if(ST.final_grade>max_final_grade)
	    	  max_final_grade=ST.final_grade;
		if(ST.final_grade<min_final_grade)    // FINAL GRADE 
	    	  min_final_grade=ST.final_grade;
		avg_final_grade+=ST.final_grade;
//---------------------------------------------
		n++;
    }
	system("cls");
	cout<<"\t Examp 1            Examp 2            Final           Final Grade"<<endl;
	cout<<"AVg       "<<setw(10)<<left<<avg_examp1/n<<"         "<<setw(10)<<left<<avg_examp2/n<<"         "<<setw(10)<<left<<avg_final/n<<"        "<<setw(10)<<left<<avg_final_grade/n<<endl;
	cout<<"Max       "<<setw(10)<<left<<max_examp1<<"         "<<setw(10)<<left<<max_examp2<<"         "<<setw(10)<<left<<max_final<<"        "<<setw(10)<<left<<max_final_grade<<endl;
	cout<<"Min       "<<setw(10)<<left<<min_examp1<<"         "<<setw(10)<<left<<min_examp2<<"         "<<setw(10)<<left<<min_final<<"        "<<setw(10)<<left<<min_final_grade<<endl;
}

void print()
{
	system("cls");
	ifstream file;
	file.open("student",ios::in);
	if(!file)
	{
		cout<<"\t ERORR"<<"\nFile Is Not Found ";
		return;
	}
	cout<<"Id Number      Name                    Exmp 1  Exmp 2  Final   Final Grade"<<endl<<"__________________________________________________________________________"<<endl;
	while(file.read((char *)&ST,sizeof(student)))
	{
		cout<<setw(10)<<left<<ST.id<<"     "
			<<setw(20)<<left<<ST.name<<"     "
			<<setw(3)<<left<<ST.examp1<<"     "
			<<setw(3)<<left<<ST.examp2<<"     "
			<<setw(3)<<left<<ST.final<<"     "
			<<setw(3)<<left<<ST.final_grade<<endl;
	}
	file.close();
}
int system(void)
{
	int x;
	cout<<"________________________________________________________________________";
	cout<<endl<<"                Nema          : HAMZA HAMRONI "<<endl<<"                Student Number: 213010793  "<<endl;
	cout<<"\n\n [1] - Add Student Information"<<"\n [2] - Display Student Information"<<"\n [3] - Print Of Id Number"<<"\n [4] - Statistcy"<<"\n [5] - End Program"<<endl<<endl<<endl;
		cout<<"Enter your choice ?"<<endl;
		cin>>x;
		return x;
		    
}
void print_of_id()
{
	system("cls");
	ifstream file;
	file.open("student",ios::in);
	if(!file)
	{
		cout<<"\tERORR \nFile Is Not Found";
		return;
	}
	int i=0,n=0;
	student sp[10],temp;
	while(file.read((char *)&sp[i],sizeof(student)))
	{
		i++;
		n++;
	}
	file.close();
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(sp[i].id>sp[j].id)
			{
				temp.id=sp[i].id;strcpy(temp.name,sp[i].name);temp.examp1=sp[i].examp1;temp.examp2=sp[i].examp2;temp.final=sp[i].final;temp.final_grade=sp[i].final_grade;
				sp[i].id=sp[j].id;strcpy(sp[i].name,sp[j].name);sp[i].examp1=sp[j].examp1;sp[i].examp2=sp[j].examp2;sp[i].final=sp[j].final;sp[i].final_grade=sp[j].final_grade;
				sp[j].id=temp.id;strcpy(sp[j].name,temp.name);sp[j].examp1=temp.examp1;sp[j].examp2=temp.examp2;sp[j].final=temp.final;sp[j].final_grade=temp.final_grade;
				
			}
		}
	}

	cout<<"Id Number      Name                    Exmp 1  Exmp 2  Final   Final Grade"<<endl<<"__________________________________________________________________________"<<endl;
	for(int i=0;i<n;i++)
	{
		
			cout<<setw(10)<<left<<sp[i].id<<"     "
			<<setw(20)<<left<<sp[i].name<<"     "
			<<setw(3)<<left<<sp[i].examp1<<"     "
			<<setw(3)<<left<<sp[i].examp2<<"     "
			<<setw(3)<<left<<sp[i].final<<"     "
			<<setw(3)<<left<<sp[i].final_grade<<endl;
	
	}
}
int main()
{
	int choice;
	while((choice=system()))
	{
		switch(choice)
		{
			case 1:
				add();
				break;
			case 2:
				print();
				break;
			case 3:
				print_of_id();
				break;
			case 4:
				statistcy();
				break;
			case 5:
			    cout<<endl<<"########################## END ########################"<<endl;
			    exit(1);
			default: system("cls");
		}
	}
}


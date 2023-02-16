//								Hamza Hamruni
//								 213010793
//									Q_3
#include<iostream>
#include<fstream>
using namespace std;
struct employee
{
	long idNo;
	char fName[10],mName[10],iName[15];
	float salary;
};
void binary2text()
{
	ifstream file1;
	file1.open("employee.bin");
	if(!file1)
	{
		cout<<"File Is Not Found "<<endl;
		exit(1);
	}
	employee st;
	ofstream file2;
	file2.open("employee.txt");
	while(file1.read((char *)&st,sizeof(st)))
	{
		if(st.salary>1000)
		{
			file2<<st.idNo<<" "<<st.fName<<" "<<st.mName<<st.iName<<" "<<st.salary<<endl;
		}
	}
	file1.close();
	file2.close();
}
int main()
{
}

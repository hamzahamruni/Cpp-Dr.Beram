//
//														Hamza Hamruni
//														  213010793
//														 Test_1 Q(3)
#include<iostream>
#include<fstream>
using namespace std;
struct chrfrg
{
	int chr,digit,others;
};
chrfrg charfreguende(const char filename[])
{
	ifstream file;
	file.open(filename,ios::in);
	if(!file)
	{
		cout<<"File Is Not Found ";
		exit(1);
	}
	int flag=0;
	char ch;
	chrfrg A={0,0,0};
	file>>ch;
	while(file.eof())
	{
		for(int i=0;i<58;i++)
		{
			if(ch=='a'+i)
			{
				A.chr=A.chr+1;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			for(int i=0;i<10;i++)
		   {
				if(ch=='0'+i)
				{
						A.digit=A.digit+1;
						flag=1;
					break;
				}
			}
		}	
		if(flag==0)
		{
				for(int i=0;i<32;i++)
				{
					if(ch==' '+i)
					{
						A.others=A.others+1;
						flag=1;
						break;
					}
				}
		}
		flag=0;
		file>>ch;
	}//end while
	return A;
}// end function
int main()
{
	char filename[30];
	cout<<"Enter File Name : ";
	cin>>filename;
	chrfrg a=charfreguende(filename);
	cout<<"chr = "<<a.chr<<"\ndigit = "<<a.digit<<"\tothers = "<<a.others<<endl;
	
}

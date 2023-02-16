//            
//                                         Name : Hamza Hamruni
//                                         Id Number : 213010793
//                                                 Pg1
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream file;
	char file_name[20];
	cout<<"Enter Name File : "<<endl;jh
	cin>>file_name;
	char ch,C;
	int k=0;
	file.open(file_name,ios::in);
	if(!file)
    {
    	cout<<"File is not found";
    	exit(1);
    }
    cout<<endl<<"                                 HAMZA HAMRUNI"<<endl<<"                                 213010793";
    cout<<endl<<"_______________________________________________________________________________"<<endl<<endl;
    file.get(ch);
    for(int i=0;i<=94;i++)
    {
    	

       while(!file.eof())
       {
    	 if(ch==(' '+i))
    	 {
    	 	k=k+1;
    	 }
        file.get(ch);
       }
      C=32;
      if(k>0)
         cout<<(C=C+i)<<" = "<<k<<endl;
      k=0;
      file.close();
      file.open(file_name,ios::in);
      file.get(ch);
   }
   cout<<endl<<"_______________________________________________________________________________"<<endl<<endl;
   file.close();
}

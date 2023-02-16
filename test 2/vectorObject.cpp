#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int>a(n);
	cout<<"a contains";
	for(int i=0;i<a.size();i++)
	cout<<a.at(i)<<" ";
	cout<<endl;
	for(int i=0;i<a.size();i++) //bug : <= should be <
	 a.at(i)=i+2;
	 cout<<"reprint the contents of the vector"<<endl;
	 cout<<"a contains";
	 for(int i=0;i<a.size();i++)
	 cout<<a.at(i)<<" ";
	 cout<<endl;
	 cout<<endl;
	 a.push_back(9);
	 a.push_back(30);
	 a.push_back(80);
	 a.push_back(100);
	 cout<<" size = "<<a.size()<<endl;
	 	 for(int i=0;i<a.size();i++)
	 cout<<a.at(i)<<" ";
	 cout<<endl;
	 a.pop_back();
	 a.pop_back();
	 	 cout<<" size = "<<a.size()<<endl;
	 	 for(int i=0;i<a.size();i++)
	 cout<<a.at(i)<<" ";
	 
	 system("pause");

}




#include<iostream>
using namespace std;
int main()
{
	int n,i,sum=0,rows,clos;
	long **a;
	cin>>rows;
	cin>>clos;
	a=new long *[rows];
	for(int i=0;i<rows;i++)
	     a[i]=new long[clos];
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<clos;j++)
		{
			cin>>*a[i]>>**a[j];
		}
	}
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<clos;j++)
		{
			cout<<**a[i]<<" "<<*a[j];
		}
	}
	
}

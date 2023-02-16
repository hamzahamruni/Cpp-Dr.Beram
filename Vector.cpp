#include<iostream>
#include<vector>
using namespace std;
void print(vector <int>v,int n)
{
	//v.push_back(10);
	cout<<"v Size = "<<v.size()<<" "<<"capacity = "<<v.capacity()<<endl;
	cout<<"\nArray : "<<endl;
	for(int i=0;i<v.size();i++)
	{
		cout<<v.at(i)<<" ";
	}
	cout<<endl;
}
int main()
{
	int i,n;
	cin>>n;
	vector<int>::iterator it;
	vector<int>x(n);
	for(i=0;i<n;i++)
	{
		x.push_back(2+i);
	}
	print(x,n);
	cout<<"x Size = "<<x.size()<<" "<<"capacity = "<<x.capacity()<<endl;
	x.push_back(-70);
	print(x,n);
	cout<<"x Size = "<<x .size()<<" "<<"capacity = "<<x.capacity()<<endl;
		x.push_back(90);
	cout<<"x Size = "<<x .size()<<" "<<"capacity = "<<x.capacity()<<endl;
	x.pop_back();
	
	cout<<"x Size = "<<x .size()<<" "<<"capacity = "<<x.capacity()<<endl;
}

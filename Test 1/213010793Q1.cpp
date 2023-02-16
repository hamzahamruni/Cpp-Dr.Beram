//
//														Hamza Hamruni
//														 213010793
//														Test_1 Q(1)
#include<fstream>
#include <iostream>
#include <iomanip>
#include<stdlib.h>
#include<cstring>
using namespace std;
template<tyapname T>;
T average(const T a[][cols],const T Rows,const T cols)
{
	int i,jsum=0;n=0;
	for(i=0;i<Rows;i++)
	{
		for(j=0;j<cols;j+++)
		{
			sum=sum+a[i][j];
			n++;
		}
	}
	return (sum/n);
}
int main()
{
	template<taypname T>;
	int a[2][4]={1,2,3,4,1,2,3,4},iavg;
	double b[][2]={1.1,2.2,3.3,4.4},favg;
	int aRows=2,aCols=4,bRows=2,bCols=2;
	iavg=average(a,aRows,aCols);
	favg=average(b,bRows,bCols);
	cout<<iavg<<" "<<favg<<endl;
	
}

#include<iostream>
using namespace std;
class Matrix
{
	int **a;
	int ROWS,COLS;
	public :
		Matrix(int r,int c)
		{
			ROWS=r;
			COLS=c;
		}
		bool isSymmetric()
		{
			int flag=0;
			for(int i=0;i<ROWS;i++)
			{
				for(int j=0;j<COLS;j++)
				{
					if(a[i][j]==a[j][i])
						flag++;
					else
						return (!true);
				}
			}
			return true;
		}
		bool isLowerTringle()
		{
			int flag=0;
			for(int i=0;i<ROWS;i++)
			{
				for(int j=i;j<COLS;j++)
				{
					if(a[i][j+1]==0)
						flag++;
					else
						return (!true);					
				}
			}
			return true;
			
		}
	
};
int main()
{
	
}

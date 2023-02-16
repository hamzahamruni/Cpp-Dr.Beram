#include<iostream>
using namespace std;
class Rectangle
{	
		int width,length;
	public:
		Rectangle(int x=1,int y=1)
		{
			width=x;
			length=y;
		}
		void setwl(int x,int y)
		{
			width=x;
			length=y;
		}
		int getwidth()
		{
			return width;
		}
		int getlength()
		{
			return length;
		}
		int area()
		{
			return width*length;
		}
};
class Box :private Rectangle
{
	int height;
	public:
		Box(int x=1,int y=1,int z=1)
		{
			setwl(x,y);
			height=z;
			
		}
		int getheight()
		{
			return height;
		}
		void showData()
		{
			cout<<getwidth()<<" "<<getlength()<<" "<<height<<endl;
		}
		int volume()
		{
			return area()*height;
		}
};
int main()
{
	Box b1,b2(2,3,4);
	b1.showData();
	cout<<"Volume box 1 = "<<b1.volume()<<endl;
	b2.showData();
	cout<<"Volume box 2 = "<<b2.volume()<<endl;
	system("pause");
}

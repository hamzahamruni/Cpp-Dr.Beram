//
//												Hamza Hamruni
//												 213010793
//												Test_1 Q(2)
#include<iostream>
using namespace std;

struct Vec 
{
	float x,y;
};

Vec operator+ (const Vec a,const Vec b)
{
	Vec z;
	z.x=a.x+b.x;
	z.y=a.y+b.y;
	return (z.x,z.y);
}

int main ()
{
	Vec p1,p2,p3;
	p3=p1+p2;
	cout<<"p3=("<<p3.x<<","<<p3.y<<")\n";
}

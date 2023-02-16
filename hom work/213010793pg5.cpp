//
//														Hamza Hamruni
//														  213010793
//														    PG_5
#include<iostream>
#include<fstream>
#include<string>
#include <iomanip>
#include <iomanip>
using namespace std;
class Time
{
	int hours;
	int minutes;
	public:
		Time(int h=0,int m=0):hours(h),minutes(m){}
		void SetTime(int h,int m){hours=h;minutes=m;}
		Time operator+(const Time t)
		{
			Time A;
			A.hours=hours+t.hours+((minutes+t.minutes)/60);
			A.minutes=(minutes+t.minutes)%60;
			return A;
		}
		Time operator-(const Time t)
		{
			Time A;
			A.hours=hours-t.hours;
			A.minutes=minutes-t.minutes;
			while(A.minutes<0)
			{
				A.hours=A.hours-1;
				A.minutes=A.minutes+60;
			}
			return A;
		}
		Time operator*(double D)
		{
	 		Time A;
	 		A.hours=hours*D;
	 		A.minutes=minutes*D;
	 		while(A.minutes<0)
	 		{
	 			A.hours=A.hours-1;
	 			A.minutes=A.minutes+60;
	 			
	 		}
			return A;
		}
		void show()
		{
			cout<<hours<<":"<<minutes<<" H/M"<<setw(14)<<right<<"\t\t";
		}
};
//--------------------------------------------------------------------------------------------
int main()//																				
{
	cout<<"\t\t\t\tHamza Hamruni\n\t\t\t\t  213010793\n\t\t\t\t    PG_5"
	<<"\n_______________________________________________________________________________\n";
	Time Departure_time,Flight_time,Access_time;
	
//-------------------------------------------------------------------------
	Departure_time.SetTime(2,30);Flight_time.SetTime(1,40);
	Access_time=Departure_time+Flight_time;
	cout<<"\nDeparture Time\t\t\tFlight Time\t\t\tAccess Time\n\n";
	Departure_time.show();
	Flight_time.show();
	Access_time.show();
//------------------------------------------------------------------------------
	
	Departure_time.SetTime(4,0);Flight_time.SetTime(2,15);
	Access_time=Departure_time+Flight_time;
	cout<<endl;
	Departure_time.show();
	Flight_time.show();
	Access_time.show();
//---------------------------------------------------------------------------------
	
	Departure_time.SetTime(12,45);Flight_time.SetTime(0,50);
	Access_time=Departure_time+Flight_time;
	cout<<endl;
	Departure_time.show();
	Flight_time.show();
	Access_time.show();
	
	
//___________________________________________________________________________________________________________________
//---------------------------------------------------------------------
	Departure_time.SetTime(3,30);Access_time.SetTime(5,10);
	Flight_time=Access_time-Departure_time;
	cout<<"\n_______________________________________________________________________________\n";
	cout<<"\nDeparture Time\t\t\tAccess Time\t\t\t\Flight Time\n\n";
	Departure_time.show();
	Access_time.show();
	Flight_time.show();
	
//-----------------------------------------------------------------------
	Departure_time.SetTime(4,0);Access_time.SetTime(4,50);
	Flight_time=Access_time-Departure_time;	
	cout<<endl;
	Departure_time.show();
	Access_time.show();
	Flight_time.show();
	
//-----------------------------------------------------------------------
	Departure_time.SetTime(12,15);Access_time.SetTime(13,40);
	Flight_time=Access_time-Departure_time;	
	cout<<endl;
	Departure_time.show();
	Access_time.show();
	Flight_time.show();
	cout<<endl;	

}

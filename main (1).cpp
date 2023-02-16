#include <iostream>
#include <iomanip>
//#include <math.h>
#include <stdlib.h>
using namespace std;
#include "point.h"
void printPoint(Point t){
     cout <<"(" << t.getX() << "," << t.getY() <<")\n" <<endl;
     system("pause");
}

double distanceB2P(){
     Point a, b;
     cout << "\nset the x and y coordinates for point a\n";
     a.setXY();
     cout << "\nset the x and y coordinates for point b\n";
     b.setXY();
     double d = a.distance(b);
     cout <<"\ndistance between two points = " << setprecision(2) << d << endl << endl;
     system("pause");
     return d;
}

double slopeO2P(){
     Point a, b;
     cout << "\nset the x and y coordinates for point a\n";
     a.setXY();
     cout << "\nset the x and y coordinates for point b\n";
     b.setXY();
     double s = a.slope(b);
     cout <<"\nslop = " << setprecision(2) << s <<endl << endl;
     system("pause");
     return s;
}

void midPointB2P(){
     Point a, b;
     cout << "\nset the x and y coordinates for point a\n";
     a.setXY();
     cout << "\nset the x and y coordinates for point b\n";
     b.setXY();
     Point mp;
     mp.midPoint(a, b);
     cout <<"\nmid point between points a & b is point(x,y) = mp";
     printPoint(mp);
}

void constructor(){
     cout << "\ncreat an instance p of class Point with initial values using constructor\n"
          << "\np(x,y) = p";
     Point p(5,6);
     printPoint(p);
}

void setVPoint(){
     Point q;
     cout << "\nset the x coordinate for point q\n";
     q.setX();
     cout << "\nset the y coordinate for point q\n";
     q.setY();
     cout << "\nq(x,y)= q";
     printPoint(q);
     Point r;
     cout << "\nset the x and y coordinates for point r\n";
     r.setXY();
     cout << "\nr(x,y)= r";
     printPoint(r);
}

int enterChoice(){
   int menuChoice;
   cout << endl << endl
        << "            Choice ................" << endl
        << "          1 - constructor" << endl
        << "          2 - set point " << endl
        << "          3 - distance to point" << endl
        << "          4 - mid point" << endl
        << "          5 - slope" << endl
        << "          6 -  " << endl
        << "          7 -  " << endl
        << "          0 - End program " << endl << endl
        << "            Enter your choice: "; cin >> menuChoice;
   return menuChoice;
}

int main(){
   Point a, b;
   int choice;
   do {
       choice = enterChoice();
       switch (choice){
          case 0: break;
          case 1: constructor(); break;
          case 2: setVPoint(); break;
          case 3: distanceB2P(); break;
          case 4: midPointB2P(); break;
          case 5: slopeO2P(); break;
          case 6: break;
          case 7: break;
          default: cout << "Enter valid choice ...\n";
       }
   } while(choice);
   return 0;
}

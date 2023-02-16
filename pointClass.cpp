#include <iostream>
#include <iomanip>
#include <math.h>
#include<stdlib.h>
using namespace std;


double input(char *prompt){
  double v;
  while(true){
      cout << prompt;
      if ((cin >> v)) break;
      cin.clear();
      cin.ignore(1000,'\n');
      cout << "\nBad input value ....\n\n";
  }
  return v;
}

class Point{
     double x,y;
   public:
     Point(){}
     Point(double, double);
     double getX(){return x;}
     double getY(){return y;}
     void setX();
     void setY();
     void setXY();
     Point midPoint(Point, Point);
     double distance(Point);
     double slope(Point);
};

Point::Point (double valueX, double valueY){
     x = valueX;
     y = valueY;
}

void Point::setX(){
     char prompt[] = "Enter X coordinate: ";
     x = input(prompt);
}

void Point::setY(){
     char prompt[] = "Enter Y coordinate: ";
     y = input(prompt);
}

void Point::setXY(){
     char prompt[] = "Enter coordinate (x, y): ";
     while(true){
        cout << prompt;
        if ((cin >> x >> y)) break;
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "\nBad input value ....\n\n";
     }
}

Point Point::midPoint(Point a, Point b){
     x = (a.x + b.x)/2.0;
     y = (a.y + b.y)/2.0;
}

double Point::distance(Point t){
     return(sqrt((x - t.x)*(x - t.x) + (y - t.y)*(y - t.y)));
}

double Point::slope(Point t){
     return((y - t.y)/(x - t.x));
}
// end of class Point

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

main(){
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
}



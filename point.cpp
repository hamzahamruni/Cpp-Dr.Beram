#include <iostream>
#include <math.h>
#include "point.h"

double input(char *prompt){
  double v;
  while(true){
      cout << prompt;
      if ((cin >> v)) break;
      cin.clear();
      cin.ignore(1000,'\n'); //cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout << "\nBad input value ....\n\n";
  }
  return v;
}

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

void Point::midPoint(Point a, Point b){
     x = (a.x + b.x)/2.0;
     y = (a.y + b.y)/2.0;
}

double Point::distance(Point t){
     return(sqrt((x - t.x)*(x - t.x) + (y - t.y)*(y - t.y)));
}

double Point::slope(Point t){
     return((y - t.y)/(x - t.x));
}

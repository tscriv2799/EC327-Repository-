#ifndef POINT2D_H                                                       
#define POINT2D_H                                                       //Define the following class
#include "Vector2D.h"

using namespace std;

class Point2D                                                           //Class header//
{ 
    public:                                                             //Public member variables//
    double x;
    double y;

    Point2D();                                                          //Default Constructor//
    Point2D(double in_x, double in_y);                                  //Defined Constructor//
};

ostream& operator<<(ostream&, const Point2D);                           //Non-member overloaded operator prototypes//
Point2D operator+(Point2D, Point2D);
Vector2D operator-(Point2D, Point2D);

double GetDistanceBetween(Point2D, Point2D);                            //Non-member function prototype//

#endif                                                                  //End class definition 
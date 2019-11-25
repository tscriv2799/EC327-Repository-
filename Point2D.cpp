#include <iostream>
#include <cmath>
#include "Point2D.h"
#include "Vector2D.h"

using namespace std;

Point2D::Point2D()                                                              //x and y set to 0//
{
    x = 0.00;
    y = 0.00; 
}

Point2D:: Point2D(double in_x, double in_y)                                     //Constructor that sets in_x and in_y to x and y//
{
    x = in_x;
    y = in_y;
}

ostream& operator<<(ostream& out, const Point2D val)                            //Overloading << operator//
{
    out << "(" << val.x << "," << val.y << ")";                                 //Returns the cartesian coordinate form//
    return out;
}

Point2D operator+(Point2D p1, Point2D p2)                                       //Overloading + operator//
{
    Point2D newval;                                                             //Define variable newval//

    newval.x = p1.x + p2.x;                                                     //Add x components//
    newval.y = p1.y + p2.y;                                                     //Add y components//

    return newval;                                                              //Return newval//
}

Vector2D operator-(Point2D p1, Point2D p2)                                      //Overloading - operator//
{
   Vector2D newval;                                                             //Define variable newval//

   newval.x = p1.x - p2.x;                                                      //Subtract x components//
   newval.y = p1.y - p2.y;                                                      //Subtract y components//

   return newval;                                                               //Return newval//
}

double GetDistanceBetween(Point2D p1, Point2D p2)                               //GetDistanceBetween Function//
{
    return fabs(sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)));                     //Return distance formula between two points//
}
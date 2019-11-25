#include <iostream>                                                 //Preprocessor Directives//
#include <cmath>
#include "Vector2D.h"                                               //Include class header file//

using namespace std;

Vector2D::Vector2D()                                                //Sets x and y to 0//
{ 
    x = 0;
    y = 0;
}

Vector2D::Vector2D(double in_x, double in_y)                       //Constructor that takes in_x and in_y and sets it to x and y//
{
    x = in_x;
    y = in_y;
}

ostream& operator<<(ostream& out, const Vector2D val)               //Overloading << operator//
{
    out << "<" << val.x << "," << val.y << ">";                     //Returns vector component form//
    return out; 
}

Vector2D operator*(Vector2D v1, double d)                           //Overloading * operator//
{
    Vector2D newval;                                                //Define variable newval//

    newval.x = v1.x * d;                                            //Multiply x by d//
    newval.y = v1.y * d;                                            //Multiply y by d//

    return newval;                                                  //Return newval//
}

Vector2D operator/(Vector2D v1, double d)                           //Overloading / operator//
{
    Vector2D newval;                                                //Define variable newval//

    newval.x = v1.x / d;                                            //Divide x by d//
    newval.y = v1.y / d;                                            //Divide y by d//

    return newval;                                                  //Return newval//
}

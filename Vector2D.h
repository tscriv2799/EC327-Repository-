#ifndef VECTOR2D_H                                                          
#define VECTOR2D_H                                                          //Define the following class//

using namespace std;

class Vector2D                                                              //Class header//
{
    public:                                                                 //Public member variables//
    double x;   
    double y;

    Vector2D();                                                             //Default constructor//
    Vector2D(double in_x, double in_y);                                     //Defined constructor//
};

ostream& operator<<(ostream&, const Vector2D);                              //Non-member overloaded operator prototypes//
Vector2D operator*(Vector2D, double);
Vector2D operator/(Vector2D, double);

#endif                                                                      //End class definition//
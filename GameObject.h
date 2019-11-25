#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H                                                    //Define GameObject.h//
#include "Point2D.h"                                                    //Include Point2D.h//

using namespace std;

class GameObject                                                        //Class definition//
{
    protected:                                                          //Protected Members//
    Point2D location;
    int id_num;
    char display_code;
    char state;

    public:                                                             //Public constructors//
    GameObject(char in_code);
    GameObject(Point2D in_loc, int in_id, char in_code);
    virtual ~GameObject();                                              //Public destructor//
    
    Point2D GetLocation();                                              //Public member functions//
    int GetId();
    char GetState();
    //void DrawSelf(char* ptr);
    virtual bool Update() = 0;
    virtual void ShowStatus();
    virtual bool ShouldBeVisible() = 0;
};

#endif                                                                  //End definition//
#include <iostream>
#include "GameObject.h"                                                 //Preprocessor Directives w/ include GameObject.h//

using namespace std;

GameObject::GameObject(char in_code)                                    //Default Constructor//
{
    display_code = in_code;                                             //display_code set to in_code//    
    id_num = 1;
    state = 0;
    cout << "GameObject constructed" << endl;                           //Cout GameObject constructed//
}

GameObject::GameObject(Point2D in_loc, int in_id, char in_code)         //Defined Constructor//
{
    display_code = in_code;                                             //display_code, id_num, and location set to arguments//    
    id_num = in_id;
    location = in_loc;
    state = 0;
    cout << "GameObject constructed" << endl;                           //Cout GameObject constructed//
}

GameObject::~GameObject()
{
    cout << "GameObject destructed" << endl;
}

Point2D GameObject::GetLocation()                                       //Function that returns the location//
{
    return location;
}

int GameObject::GetId()                                                 //Function that returns the ID #//
{
    return id_num;
}

char GameObject::GetState()                                             //Function that returns the state//
{
    return state;
}

void GameObject::ShowStatus()                                           //Function that returns status//
{
    cout << display_code << id_num << " at " << location;
}

//void GameObject::DrawSelf(char* ptr)                                    //Function that assigns object's display code to the first element of the array//   
//{
 //   ptr[0] = display_code;                                              //Second element gets assigned the id_num//
//    ptr[1] = id_num;
//}

#ifndef BUILDING_H                                              
#define BUILDING_H                                              //Define Building.h//
#include "GameObject.h"                                         //Include GameObject.h//

class Building : public GameObject                              //Class definition for building and it inherits GameObject//
{
    private:                                                    //Private member variable
    unsigned int pokemon_count;                     

    public:                                                     //Public constructor prototype//
    Building();
    Building(char in_code, int in_id, Point2D in_loc);
    
    void AddOnePokemon();                                       //Public member functions//
    void RemoveOnePokemon();
    void ShowStatus();
    bool ShouldBeVisible();
};

#endif                                                          //End definition//

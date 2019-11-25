#ifndef POKEMONCENTER_H
#define POKEMONCENTER_H                     //Define PokemonCenter//
#include "Building.h"                       //Include Building.h//
#include "GameObject.h"

enum PokemonCenterStates                    //Enumerated type//
{
    STAMINA_POINTS_AVAILABLE = 0,           //First enumerator//
    NO_STAMINA_POINTS_AVAILABLE = 1         //Second enumerator//
};

class PokemonCenter : public Building      //Class definition for PokemonCenter and it inherits Building//
{
    private:                                //Private members//
    unsigned int stamina_capacity;
    unsigned int num_stamina_points_remaining;
    double dollar_cost_per_stamina_point;

    public:
    PokemonCenter();                        //Default Constructor//
    PokemonCenter(int in_id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc);    //Constructor with 4 parameters//
    ~PokemonCenter();                       //Public destructor//

                                            //Public Member Functions//
    bool HasStaminaPoints();                
    unsigned int GetNumStaminaPointsRemaining();
    bool CanAffordStaminaPoints(unsigned int stamina_points, double budget);
    double GetDollarCost(unsigned int stamina_points);
    unsigned int DistributeStamina(unsigned int points_needed);
    bool Update();
    void ShowStatus();
};

#endif                                      //End definition//
#ifndef POKEMON_H
#define POKEMON_H                       //Define Pokemon class//
#include <string.h>                     //Include string library, math library, and random functions library//
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include "GameObject.h"                 //Include GameObject.h, PokemonCenter.h, PokemonGym.h, Point2D.h, and Vector2D.h//
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Point2D.h"
#include "Vector2D.h"

enum PokemonStates                      //Enumeration type for Pokemon object//
{
    STOPPED = 0,
    MOVING = 1,
    EXHAUSTED = 2,                      //States assigned to numerical values//
    IN_GYM = 3,
    IN_CENTER = 4,
    MOVING_TO_GYM = 5,
    MOVING_TO_CENTER = 6,
    TRAINING_IN_GYM = 7,
    RECOVERING_STAMINA = 8
};

class Pokemon : public GameObject           //Class definition for Pokemon which inherits GameObject//
{
    public:                                 //Public constructors//
    Pokemon();
    Pokemon(char in_code);
    Pokemon(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc);
    ~Pokemon();                             //Public destructor//

                                            //Public members//
    void StartMoving(Point2D dest);
    void StartMovingToCenter(PokemonCenter* center);
    void StartMovingToGym(PokemonGym* gym);
    void StartTraining(unsigned int num_training_units);
    void StartRecoveringStamina(unsigned int num_stamina_points);
    void Stop();
    bool isExhuasted();
    bool ShouldBeVisible();
    bool Update();
    void ShowStatus();  
    string GetName();
    
    protected:                              //Protected members// 
    bool UpdateLocation();
    void SetupDestination(Point2D dest);                                   
                                            //Private members//
    private:
    double speed;
    bool is_in_gym;
    bool is_in_center;
    unsigned int stamina;
    unsigned int experience_points;
    double pokemon_dollars;
    unsigned int training_units_to_buy;
    unsigned int stamina_points_to_buy;
    string name;
    PokemonCenter* current_center;
    PokemonGym* current_gym;
    Point2D destination;
    Vector2D delta;
};

static double GetRandomAmountOfPokemonDollars();

#endif                                      //End class definition//


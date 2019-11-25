#ifndef POKEMONGYM_H
#define POKEMONGYM_H                                        //Define PokemonGym//
#include "Building.h"                                       //Include Building.h and GameObject.h//
#include "GameObject.h"                                 

enum PokemonGymStates                                       //Enumerated type//
{
    NOT_BEATEN = 0,                                         //First enumerator//
    BEATEN = 1                                              //Second enumerator//
};

class PokemonGym : public Building                          //Class definition which inherits Building//
{
    private:                                                //Private members//
    unsigned int num_training_units_remaining;
    unsigned int max_number_of_training_units;
    unsigned int stamina_cost_per_training_unit;
    double dollar_cost_per_training_unit;
    unsigned int experience_points_per_training_unit;

    public:                                                 //Public constructors//
    PokemonGym();
    PokemonGym(unsigned int max_training_units, unsigned int stamina_cost, double dollar_cost, unsigned int exp_points_per_unit, int in_id, Point2D in_loc);
    ~PokemonGym();  //Public Destructor//

    double GetDollarCost(unsigned int unit_qty);            //Public member functions//
    unsigned int GetStaminaCost(unsigned int unit_qty);
    unsigned int GetNumTrainingUnitsRemaining();
    bool isAbleToTrain(unsigned int unit_qty, double budget, unsigned int stamina);
    unsigned int TrainPokemon(unsigned int training_units);
    bool Update();
    bool isBeaten();
    void ShowStatus();
};

#endif                                                      //End definition//
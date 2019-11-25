#include <iostream>                             //Preprocessor Directives and include PokemonGym.h//
#include "PokemonGym.h"

using namespace std;                            //Using namespace std;

PokemonGym::PokemonGym() : Building()           //Default Constructor//
{
    display_code = 'G';                             //Members initialized to original values//
    state = NOT_BEATEN;
    max_number_of_training_units = 10;
    num_training_units_remaining = max_number_of_training_units;
    stamina_cost_per_training_unit = 1;
    dollar_cost_per_training_unit = 1.0;
    experience_points_per_training_unit = 2;
    cout << "PokemonGym default constructed" << endl;       //Cout PokemonGym default constructed//
    id_num = 1;
}

PokemonGym::PokemonGym(unsigned int max_training_units, unsigned int stamina_cost, double dollar_cost, unsigned int exp_points_per_unit, int in_id, Point2D in_loc) : Building('G', in_id, in_loc) //Defined constructor//
{
    display_code = 'G';                                 //Certain values initialized based on instructions, rest set to original values//
    state = NOT_BEATEN;
    id_num = in_id;
    max_number_of_training_units = max_training_units;
    stamina_cost_per_training_unit = stamina_cost;
    experience_points_per_training_unit = exp_points_per_unit;
    dollar_cost_per_training_unit = dollar_cost;
    location = in_loc;
    num_training_units_remaining = max_number_of_training_units;
    cout << "PokemonGym constructed" << endl;           //Cout PokemonGym constructed//
}

PokemonGym::~PokemonGym()           //Destructor//
{
    cout << "Pokemon Gym destructed" << endl;
}

double PokemonGym::GetDollarCost(unsigned int unit_qty)     //Function that returns dollar cost for purchasing training units//
{
    return dollar_cost_per_training_unit * unit_qty;
}

unsigned int PokemonGym::GetStaminaCost(unsigned int unit_qty)  //Function that returns stamina cost for purchasing stamina points//
{
    return stamina_cost_per_training_unit * unit_qty;
}

unsigned int PokemonGym::GetNumTrainingUnitsRemaining()    //Function that returns the amount of traning units in the Gym//
{
    return num_training_units_remaining;
}

bool PokemonGym::isAbleToTrain(unsigned int unit_qty, double budget, unsigned int stamina)  //Function that returns true if the budget and stamina are greater that the cost of the unit_qty//
{
    if ((budget >= (dollar_cost_per_training_unit * unit_qty)) && (stamina >= (stamina_cost_per_training_unit * unit_qty)))
        return true;
    else 
        return false;               //Otherwise the function returns false//
}

unsigned int PokemonGym::TrainPokemon(unsigned int training_units)
{
    if (num_training_units_remaining >= training_units)     //If the number of training units at the Gym is greater than or equal to the requested training points//
    {
        num_training_units_remaining = num_training_units_remaining - training_units;   //The number of training points remaining is the points remaining - training units//
        return training_units * experience_points_per_training_unit;        //The experience points is the training_units multiplied by the cost per unit//
    }
    else if (num_training_units_remaining < training_units)   //Else if the number of training units remaining is less than the number requested//          
    {
        unsigned int experience_points = num_training_units_remaining * experience_points_per_training_unit;    //Temp variable with experience point calculation//
        num_training_units_remaining = 0;       //Training points remaining is 0 to represent beating the Gym//
        return experience_points;       //Return the temp variable experience_points//
    }
    else 
        return 0;
}

bool PokemonGym::Update()           //Update function//
{
    if (num_training_units_remaining == 0 && state == NOT_BEATEN)     //If the training units remaining is 0//
    {
        state = BEATEN;     //state is BEATEN//
        display_code = 'g'; //display_code = 'g'//
        cout << display_code << id_num << " has been beaten" << endl;   //Cout message//   
        return true;        //Return true//
    }
    else 
        return false;       //Otherwise return false 
}

bool PokemonGym::isBeaten()     //IsBeaten function//
{
    if (num_training_units_remaining == 0)      //If the training units remaining is 0//
        return true;            //Return true//
    else 
        return false;           //Otherwise return false//
}

void PokemonGym::ShowStatus()           //ShowStatus function//
{
    cout << "Pokemon Gym Status: ";         //Cout statements defined by instructions//   
    GameObject::ShowStatus();
    cout << endl;
    Building::ShowStatus();                         //Explicit call to Builder ShowStatus function//
    cout << "   Max number of training units: " << max_number_of_training_units << endl;
    cout << "   Stamina cost per training unit: " << stamina_cost_per_training_unit << endl;
    cout << "   Pokemon dollar per training unit: " << dollar_cost_per_training_unit << endl;
    cout << "   Experience points per training unit: " << experience_points_per_training_unit << endl;
    cout << "   " << num_training_units_remaining << " training unit(s) are remaining for this gym" << endl;
}
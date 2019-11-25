#include <iostream>                         //Preprocessor Directives//
#include "PokemonCenter.h"                  //Include PokemonCenter.h//

using namespace std;                        //Using namespace std//

PokemonCenter::PokemonCenter() : Building() //Default Constructor//
{
    display_code = 'C';                     //Set values for members//
    stamina_capacity = 100;
    num_stamina_points_remaining = stamina_capacity;    
    dollar_cost_per_stamina_point = 5;
    state = STAMINA_POINTS_AVAILABLE;           //State set to stamina points available//
    cout << "PokemonCenter default constructed" << endl;    //Cout PokemonCenter default constructed//
    id_num = 1;
}

PokemonCenter::PokemonCenter(int in_id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc) : Building('C', in_id, in_loc)   //Defined Constructor//
{
    display_code = 'C';                             //Set values for members//
    id_num = in_id;
    location = in_loc;
    dollar_cost_per_stamina_point = stamina_cost;
    stamina_capacity = stamina_cap;
    state = STAMINA_POINTS_AVAILABLE;           //State set to stamina points available//
    num_stamina_points_remaining = stamina_capacity;    
    cout << "PokemonCenter constructed" << endl;        //Cout PokemonCenter constructed//
}

PokemonCenter::~PokemonCenter()
{
    cout << "Pokemon Center destructed" << endl;       //Destructor//
}

bool PokemonCenter::HasStaminaPoints()
{
    if (num_stamina_points_remaining >= 1)      //If the amount of stamina is greater than 1, return true//
        return true;
    else 
        return false;                           //If no stamina remains, return 0//
}

unsigned int PokemonCenter::GetNumStaminaPointsRemaining()
{
    return num_stamina_points_remaining;        //Return the number of stamina points remaining//
}

bool PokemonCenter::CanAffordStaminaPoints(unsigned int stamina_points, double budget)
{
    if (budget >= (stamina_points * dollar_cost_per_stamina_point))     //If the budget is greater than or equal to the total dollar cost of the amount of stamina points//
        return true;
    else                                                                //Otherwise return false//
        return false; 
}

double PokemonCenter::GetDollarCost(unsigned int stamina_points)
{
    return stamina_points * dollar_cost_per_stamina_point;              //Retrun the dollar cost of the stamina points//
}

unsigned int PokemonCenter::DistributeStamina(unsigned int points_needed)
{
    if (num_stamina_points_remaining >= points_needed)                          //If num_stamina_points_remaining is greater than or equal to points_needed//
    {
        num_stamina_points_remaining = num_stamina_points_remaining - points_needed;    //Subtract num_stamina_points_remaining - points_needed//
        return points_needed;                                                           //Return points_needed//
    }
    else if (num_stamina_points_remaining < points_needed)                      //Else if num_stamina_points_remaining is less than points_needed//
    {
        num_stamina_points_remaining = 0;                                       //num_stamina_points_remaining = 0//
        return num_stamina_points_remaining;                                    //Return num_stamina_points_remaining//
    }
    else 
        return 0;
}

bool PokemonCenter::Update()                                                    //Update function
{
    if (num_stamina_points_remaining == 0 && state == STAMINA_POINTS_AVAILABLE) //If the stamina points are depleted and state is still STAMINA_POINTS_AVAILABLE//
    {
        state = NO_STAMINA_POINTS_AVAILABLE;                                    //State = NO_STAMINA_POINTS_AVAILABLE//
        display_code = 'c';      //display_code = 'c'//                                                
        cout << "Pokemon Center " << id_num << " has ran out of stamina points." << endl;
        return true;    
    }
    else 
        return false;
}

void PokemonCenter::ShowStatus()
{
    cout << "Pokemon Center Status: ";                                          //ShowStatus function//
    GameObject::ShowStatus();
    cout << endl;
    Building::ShowStatus();                                                     //Explicit call to Building class ShowStatus function//
    cout << "   Pokemon dollar per stamina point: " << dollar_cost_per_stamina_point << endl;
    cout << "   has " << num_stamina_points_remaining << " stamina point(s) remaining." << endl;
}
#include <iostream>
#include "Building.h"                                                       //Include Building header file//

using namespace std;

Building::Building() : GameObject('B')                                      //Default constructor//
{
    display_code = 'B';                                                     //Set display_code to 'B' and initialize all other members to original values//
    id_num = 1;
    state = 0;
    cout << "Building default constructed" << endl;                         //Cout default building constructed//
    pokemon_count = 0;
}

Building::Building(char in_code, int in_id, Point2D in_loc) : GameObject(in_loc, in_id, in_code)    //Defined Constructor//
{
    display_code = in_code;                                                    //Set display_code, in_id, and location to argument parameters//
    id_num = in_id;
    location = in_loc;
    state = 0;
    cout << "Building constructed" << endl;                                    //Cout building constructed//     
    pokemon_count = 0;
}  

void Building::AddOnePokemon()                                                  //Add one pokemon function//
{
    pokemon_count = pokemon_count + 1;
}

void Building::RemoveOnePokemon()                                               //Remove one pokemon function//
{
    pokemon_count = pokemon_count - 1;
}

void Building::ShowStatus()                                                     //ShowStatus function//
{   
    cout << "   " << pokemon_count;
    if (pokemon_count == 1)                                                     //If/Else Block to print how many pokemon are in building//
        cout << " pokemon is in this building" << endl;
    else 
        cout << " pokemon are in this building" << endl;
}

bool Building::ShouldBeVisible()                                                //ShouldBeVisible function that returns true//
{
    return true;
}
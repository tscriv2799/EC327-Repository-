#include <iostream>
#include "Model.h"

Model::Model()
{
    time = 0;       //Initialize time to 0//

    Point2D point1(5.0, 1.0);        //Defining Point2D points//
    Point2D point2(10.0, 1.0);
    Point2D point3(1.0, 20.0);
    Point2D point4(10.0, 20.0);
    Point2D point5(0.0, 0.0);
    Point2D point6(5.0, 5.0);

    object_ptrs[0] = pokemon_ptrs[0] = new Pokemon("Pikachu", 1, 'P', 2, point1);     //Using new to create objects and assigning them to object_ptrs array and respective object array//
    object_ptrs[1] = pokemon_ptrs[1] = new Pokemon("Bulbasaur", 2, 'P', 1, point2);
    object_ptrs[2] = center_ptrs[0] = new PokemonCenter(1, 1.0, 100, point3);
    object_ptrs[3] = center_ptrs[1] = new PokemonCenter(2, 2.0, 200, point4);
    object_ptrs[4] = gym_ptrs[0] = new PokemonGym(10, 1, 2.0, 3, 1, point5);
    object_ptrs[5] = gym_ptrs[1] =  new PokemonGym(20, 5, 7.5, 8, 2, point6);

    num_objects = 6;        //num_objects initialized to 6//
    num_pokemon = 2;        //num_pokemon initilaized to 2//
    num_centers = 2;        //num_centers initialized to 2//
    num_gyms = 2;           //num_gyms initialized to 2//
    cout << "Model default constructed" << endl;        //Cout default constructed//
}

Model::~Model()
{
    delete object_ptrs[0];     //Delete first pokemon object//
    delete object_ptrs[1];     //Delete second pokemon object//
    delete object_ptrs[2];     //Delete first pokemon center object// 
    delete object_ptrs[3];     //Delete second pokemon center object//
    delete object_ptrs[4];     //Delete first pokemon gym object//
    delete object_ptrs[5];     //Delete second pokemon gym object//
    cout << "Model destructed" << endl;     //Cout destructed message//
}

Pokemon* Model::GetPokemonPtr(int id)               //Get Pokemon Ptr//
{
    for (int i = 0; i < num_pokemon; i++)                         //If pokemon_ptrs id_num matches the requested id, return the pointer//
    {
        if (pokemon_ptrs[i]->GetId() == id)
            return pokemon_ptrs[i];
    }
    return 0;       //Else return 0//
}

PokemonCenter* Model::GetPokemonCenterPtr(int id)       //Get Pokemon Center Ptr//
{
    for (int i = 0; i < num_centers; i++)                         //If center_ptrs id_num matches the requested id, return the pointer//
    {
        if (center_ptrs[i]->GetId() == id)
            return center_ptrs[i];
    }       
    return 0;                                   //Else return 0;
}

PokemonGym* Model::GetPokemonGymPtr(int id)     //Get Pokemon Gym Ptr//
{
    for (int i = 0; i < num_gyms; i++)                     //If gym_ptrs id_num matches the requested id, return the pointer//
    {
        if (gym_ptrs[i]->GetId() == id)
            return gym_ptrs[i];
    }
    return 0;       //Else return 0//
}

bool Model::Update()
{
    time++;
    int true_id = false;                //Wil check if any of the Update() functions return true//   
    int gym_count = 0;                  //Counter for gyms that are beaten//
    int pokemon_count = 0;              //Counter for pokemon that are exhausted//
    static bool game_end = false;
    for (int i = 0; i < num_objects; i++)
    {
        if (object_ptrs[i]->Update() == true)    //Calls each object's Update function using GameObject. GameObject's Update function is pure virtual//
        {
            true_id = true;
        }
    }

    for (int i = 0; i < num_gyms; i++)                  //Loop that runs through gym_ptrs//
    {
        if (gym_ptrs[i]->isBeaten() == true)            //If the gym object has been beaten, increment gym_count//
        {
            gym_count += 1;
        }
    }

    for (int i = 0; i < num_pokemon; i++)               //Loop that runs through pokemon_ptrs//
    {
        if (pokemon_ptrs[i]->isExhuasted() == true)     //If the pokemon object is exhausted, increment the pokemon_count//
        {
            pokemon_count += 1;
        }
    }

    if (gym_count == num_gyms)          //If gym_count equals 2, print game over message and exit//
    {
        cout << "GAME OVER: You win! All Pokemon Gyms beaten!" << endl;
        exit (EXIT_SUCCESS);
    }
    if (pokemon_count == num_pokemon)   //If pokemon_count equals 2, print game over message and exit//
    {
        cout << "GAME OVER: You lose! All of your Pokemon are tired!" << endl;
        exit (EXIT_SUCCESS);
    }
    
    if (true_id == true)
       return true; 
    else
       return false;
   return false;
}

//void Model::Display(View& view)
//{

//}

void Model::ShowStatus()
{
    cout << "Time: " << time << endl;
    for (int i = 0; i < num_objects; i++)
    {
        object_ptrs[i]->ShowStatus();        //Calls each object's ShowStatus function using GameObject. GameObject's ShowStatus function is virtual//
    }
}
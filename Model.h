#ifndef MODEL_H
#define MODEL_H                     //Define model class//
#include "stdlib.h"
#include "GameObject.h"             //Include GameObject.h, Building.h, PokemonCenter.h, PokemonGym.h, and Pokemon.h//
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "Point2D.h"

class Model                         //Class definition//
{
    private:                        //Private member variables and copy constructor//
    int time;
    GameObject* object_ptrs[10];
    int num_objects;
    Pokemon* pokemon_ptrs[10];
    int num_pokemon;
    PokemonCenter* center_ptrs[10];
    int num_centers;
    PokemonGym* gym_ptrs[10];
    int num_gyms;
    Model(const Model&);            //Copy constructor private//

    public:                         //Public constructor and destructor//
    Model();
    ~Model();
    
    Pokemon* GetPokemonPtr(int id);                 //Public member functions//
    PokemonCenter* GetPokemonCenterPtr(int id);
    PokemonGym* GetPokemonGymPtr(int id);
    bool Update();
    //void Display(View& view);
    void ShowStatus();
};

#endif
    


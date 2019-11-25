#include <iostream>
#include "GameCommand.h"

void DoMoveCommand(Model& model, int pokemon_id, Point2D p1)
{
    Pokemon* idPtr = model.GetPokemonPtr(pokemon_id);      //If the pokemon's ID matches the requested ID//
    if (idPtr->GetId() == pokemon_id)
    {
        cout << "Moving " << idPtr->GetName() << " to " << p1 << endl;   //Cout moving statement//
        (*idPtr).StartMoving(p1);
    }
    else 
        cout << "Error: Please enter a valid command!" << endl;     //Else print error message//
}

void DoMoveToCenterCommand(Model& model, int pokemon_id, int center_id)    //If the pokemon's ID matches the requested pokemon ID//
{                                                                          //and the center's ID matches the requested center
    Pokemon* idPtr = model.GetPokemonPtr(pokemon_id);
    PokemonCenter* centerIdPtr = model.GetPokemonCenterPtr(center_id);
    if (idPtr->GetId() == pokemon_id && centerIdPtr->GetId() == center_id)
    {
        cout << "Moving " << idPtr->GetName() << " to center " << centerIdPtr->GetId() << endl;      //Cout moving to center message//
        (*idPtr).StartMovingToCenter(centerIdPtr);
    }
    else 
        cout << "Error: Please enter a valid command!" << endl;         //Else print error message//
}

void DoMoveToGymCommand(Model& model, int pokemon_id, int gym_id)       //If the pokemon's ID matches the requested pokemon ID//
{                                                                       //and the gym's ID matches the requested gym//
    Pokemon* idPtr = model.GetPokemonPtr(pokemon_id);
    PokemonGym* gymIdPtr = model.GetPokemonGymPtr(gym_id);
    if (idPtr->GetId() == pokemon_id && gymIdPtr->GetId() == gym_id)
    {
        cout << "Moving " << idPtr->GetName() << " to gym " << gymIdPtr->GetId() << endl;    //Cout moving to gym message//
        (*idPtr).StartMovingToGym(gymIdPtr);
    }
    else 
        cout << "Error: Please enter a valid command!" << endl;     //Else print error message//
}

void DoStopCommand(Model& model, int pokemon_id)
{
    Pokemon* idPtr = model.GetPokemonPtr(pokemon_id);              //If the pokemon's ID matches the requested ID//
    if (idPtr->GetId() == pokemon_id)
    {
            cout << "Stopping " << idPtr->GetName() << endl;                 //Cout stopping message//
            (*idPtr).Stop();
    }
    else 
        cout << "Error: Please enter a valid command!" << endl;     //Else print error message//
}

void DoTrainInGymCommand(Model& model, int pokemon_id, unsigned int training_units)  //If the pokemon's ID matches the requested ID//
{
    Pokemon* idPtr = model.GetPokemonPtr(pokemon_id);
    if (idPtr->GetId() == pokemon_id)
    {
        cout << "Training " << idPtr->GetName() << endl;     //Cout training message//
        (*idPtr).StartTraining(training_units);
    }
    else 
        cout << "Error: Please enter a valid command!" << endl;     //Else print error message//
}

void DoRecoverInCenterCommand(Model& model, int pokemon_id, unsigned int stamina_points)     //If the pokemon's ID matches the requested ID//
{
    Pokemon* idPtr = model.GetPokemonPtr(pokemon_id);
    if (idPtr->GetId() == pokemon_id)
    {
        cout << "Recovering " << idPtr->GetName() << "'s stamina" << endl;       //Cout recovering message//
        (*idPtr).StartRecoveringStamina(stamina_points);
    }
    else 
        cout << "Error: Please enter a valid command!" << endl;             //Else print error message//
}

void DoGoCommand(Model& model)
{
    cout << "Advancing one tick." << endl;          //Cout advancing one tick//
    model.Update();                                 //Calling Model's Update() function//
}

void DoRunCommand(Model& model)
{
    cout << "Advancing to next event." << endl;     //Cout advancing one tick//
    model.Update();                                 //Calling Model's Update() function//
}
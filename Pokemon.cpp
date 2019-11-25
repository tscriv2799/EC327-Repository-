#include <iostream>
#include <string.h>
#include "Pokemon.h"                                    //Preprocessor Directives and include "Pokemon.h"//

using namespace std;

Pokemon::Pokemon() : GameObject('P')                    //Default constructor//
{
    speed = 5;                                          //Initializes speed to 5//
    cout << "Pokemon default constructed" << endl;
    is_in_gym = false;
    is_in_center = false;
    stamina = 20;
    experience_points = 0;
    pokemon_dollars = 0;                                //Initialize private members in the constructor//
    training_units_to_buy = 0;
    stamina_points_to_buy = 0;
    current_center = NULL;
    current_gym = NULL;
    id_num = 1;
}

Pokemon::Pokemon(char in_code) : GameObject(in_code)    //Defined constructor//
{   
    speed = 5;
    state = STOPPED;                                    //Initializes speed, state, and display_code//
    display_code = in_code;
    cout << "Pokemon constructed" << endl;
    is_in_gym = false;
    is_in_center = false;
    stamina = 20;
    experience_points = 0;                              //Initialize private members in the constructor//
    pokemon_dollars = 0;
    training_units_to_buy = 0;
    stamina_points_to_buy = 0;
    current_center = NULL;
    current_gym = NULL;
    id_num = 1;
}

Pokemon::Pokemon(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc) : GameObject(in_loc, in_id, in_code)   //Defined constructor//
{
    speed = in_speed;                                   //Initializes speed and name to be the arguments//
    name = in_name;
    state = STOPPED;
    cout << "Pokemon constructed" << endl;
    is_in_gym = false;
    is_in_center = false;
    stamina = 20;
    experience_points = 0;                              //Initialize private members in the constructor//
    pokemon_dollars = 0;
    training_units_to_buy = 0;
    stamina_points_to_buy = 0;
    current_center = NULL;
    current_gym = NULL;
    location = in_loc;
}

Pokemon::~Pokemon()                                     //Destructor//
{
    cout << "Pokemon destructed" << endl;
}

void Pokemon::StartMoving(Point2D dest)                    //Start moving function//
{
    SetupDestination(dest);                                //Explicit call to SetupDestination function//
    if (dest.x == location.x && dest.y == location.y)      //If the location is the same as destination//
        cout << display_code << id_num << ": I'm already there. See?" << endl;  //Cout already there//
    else if (state == EXHAUSTED)                           //Else if exhausted, cout exhausted//
        cout << display_code << id_num << ": I am exhausted. I may move but you cannot see me." << endl;
    else 
    {
        cout << display_code << id_num << ": On my way." << endl;       //Else cout moving there//
        state = MOVING;
    }
}

void Pokemon::StartMovingToCenter(PokemonCenter* center)    //Moving to Pokemon Center function//
{
    current_center = center;                          //Set current_center to the requested center//                                                                                         
    SetupDestination(current_center->GetLocation());  //Call the SetupDestination function//
    if (current_center->GetLocation().x == location.x && current_center->GetLocation().y == location.y)        //If location is the same as destination of current_center, print already there message//
        cout << display_code << id_num << ": I am already at the Pokemon Center!" << endl;
    else if (state == EXHAUSTED)
        cout << display_code << id_num << ": I am exhausted so I can't move to recover stamina..." << endl; //If exhuasted, print exhausted message//
    else 
    {
        cout << display_code << id_num << ": On my way to center " << current_center->GetId() << endl;    //If moving, print on my way and chnage state to moving//
        state = MOVING_TO_CENTER;
    }
}

void Pokemon::StartMovingToGym(PokemonGym* gym)     //MovingToGym function//
{
    current_gym = gym;                              //Set current_gym to gym//
    SetupDestination(current_gym->GetLocation());   //Call the SetupDestination function//
    if (current_gym->GetLocation().x == location.x && current_center->GetLocation().y == location.y)        //If the pokemon is already at the gym, print already there message//
        cout << display_code << id_num << ": I am already at the Pokemon Gym!" << endl;
    else if (state == EXHAUSTED)
        cout << display_code << id_num << ": I am exhausted so I can't move to recover stamina.." << endl;  //If exhausted, print exhausted message//
    else 
    {
        cout << display_code << id_num << ": On my way to gym " << current_gym->GetId() << endl;    //Else print on my way to gym and set state to MOVING_TO_GYM//
        state = MOVING_TO_GYM;
    }
}

void Pokemon::StartTraining(unsigned int num_training_units)        //Start Training Function//
{
    if (state == EXHAUSTED)
        cout << display_code << id_num << ": I am exhausted so no more training for me..." << endl; //If Exhuasted//
    else if (state != IN_GYM)
        cout << display_code << id_num << ": I can only train in a Pokemon Gym!" << endl;   //If not in Gym//
    else if (current_gym->isAbleToTrain(num_training_units, pokemon_dollars, stamina) == false)
        cout << display_code << id_num << ": Not enough stamina and/or money for training" << endl; //If is not able to train//
    else if (current_gym->isBeaten() == true)
        cout << display_code << id_num << ": Cannot train! This Pokemon Gym is already beaten!" << endl;    //If gym is beaten//
    else 
    {
        state = TRAINING_IN_GYM;    //Change state to TRAINING_IN_GYM//
        if (num_training_units <= current_gym->GetNumTrainingUnitsRemaining())       //If/Else block that sets training_units to buy to the minimum of num_training_units and the training units in the current_gym//
        {
            training_units_to_buy = num_training_units;
            cout << display_code << id_num << ": Started to train at Pokemon Gym " << current_gym->GetId() << " with " << training_units_to_buy << " training units" << endl;    //If is able to train//
        }
        else 
        {
            training_units_to_buy = current_gym->GetNumTrainingUnitsRemaining();
            cout << display_code << id_num << ": Started to train at Pokemon Gym " << current_gym->GetId() << " with " << training_units_to_buy << " training units" << endl;    //If is able to train//
        }
    }
}

void Pokemon::StartRecoveringStamina(unsigned int num_stamina_points)
{
    if (current_center->CanAffordStaminaPoints(num_stamina_points, pokemon_dollars) == false)   //If the pokemon can't afford stamina, cout message//
        cout << display_code << id_num << ": Not enough money to recover stamina." << endl;
    else if (current_center->HasStaminaPoints() == false)   //If there are no stamina points, cout message//
        cout << display_code << id_num << ": Cannot recover! No stamina points remaining in this Pokemon Center" << endl;
    else if (state != IN_CENTER)    //If the pokemon is not in a center, cout message//
        cout << display_code << id_num << ": I can only recover stamina at a Pokemon Center!" << endl;
    else 
    {
        state = RECOVERING_STAMINA;     //State is RECOVERING_STAMINA//
        if (num_stamina_points <= current_center->GetNumStaminaPointsRemaining())   //If/Else block to set stamina_points_to_buy to the minimum number of num_stamina_points or the requested stamina//
        {
            stamina_points_to_buy = num_stamina_points; 
            cout << display_code << id_num << ": Started recovering " << stamina_points_to_buy << " at Pokemon Center " << current_center->GetId() << endl;
        }       
        else 
        {
            stamina_points_to_buy = current_center->GetNumStaminaPointsRemaining();
            cout << display_code << id_num << ": Stated recovering " << stamina_points_to_buy << ": at Pokemon Center " << current_center->GetId() << endl;
        }
    }
}

void Pokemon::Stop()        //Stop function that sets state to STOPPED and prints message//
{
    state = STOPPED;
    cout << endl << display_code << id_num << ": Stopping.." << endl;
}

bool Pokemon::isExhuasted() //Returns true is the pokemon is exhausted//
{
    if (stamina == 0)
        return true;
    else 
        return false;
}

bool Pokemon::ShouldBeVisible() //Returns true if the pokemon is not exhausted//
{
    if (stamina != 0)
        return true;
    else 
        return false;
}

bool Pokemon::Update()               //Update function//
{
    switch (state)                   //Switch statement for all different states//
    {
        case 0:                      //If object stops return false//
        {
            if (isExhuasted() == true)     //If the pokemon is exhausted//
                state = EXHAUSTED;
            return false;  
        } break;
        case 1:                      //If object is moving, call UpdateLocation() and if at location state is stopped and return true//
        {
            if (UpdateLocation() == true)
            {
                state = STOPPED;
                if (isExhuasted() == true)  //If the pokemon is exhausted//
                    state = EXHAUSTED;
                return true;
            }
            else    //Else state is still MOVING//
            {
                state = MOVING;
                if (is_in_center == true)                   //Remove pokemon//
                {
                    is_in_center = false;
                    current_center->RemoveOnePokemon();
                }
                else if (is_in_gym == true)                 //Remove pokemon//
                {   
                    is_in_gym = false;
                    current_gym->RemoveOnePokemon();
                }
                else if (isExhuasted() == true)  //If the pokemon is exhausted//
                    state = EXHAUSTED;
                return false;
            }
        } break;
        case 6:                         
        {
            if (UpdateLocation() == true)    //If the pokemon has arrived at the center//
            {
                state = IN_CENTER;      //State becomes IN_CENTER and function returns true//
                is_in_center = true;
                current_center->AddOnePokemon();    //Adding a pokemon//
                if (isExhuasted() == true)  //If the pokemon is exhausted//
                    state = EXHAUSTED;
                return true;
            }
            else 
            {
                state = MOVING_TO_CENTER;         //Otherwise State stays to moving and function returns false//
                if (is_in_center == true)         //Remvoing a pokemon//
                {
                    is_in_center = false;
                    current_center->RemoveOnePokemon();
                }
                if (isExhuasted() == true)        //If the pokemon is exhausted//
                    state = EXHAUSTED;
                return false;
            }
        } break;
        case 5:                                 
        {
            if(UpdateLocation() == true)        //If the pokemon has arrived at the gym//
            {
                state = IN_GYM;                 //State becomes IN_GYM//
                is_in_gym = true;
                current_gym->AddOnePokemon();   //Adding a pokemon//
                if (isExhuasted() == true)
                    state = EXHAUSTED;
                return true;
            }
            else 
            {
                state = MOVING_TO_GYM;      //Otherwise State stays to MOVING_TO_GYM//
                if (is_in_gym == true)      //Removing a pokemon//
                {
                    is_in_gym = false;
                    current_gym->RemoveOnePokemon();
                }
                else if (isExhuasted() == true)  //If the pokemon is exhausted//
                    state = EXHAUSTED;
                return false;
            }
        } break;
        case 4:                             //If IN_CENTER return false//
        {
            if (isExhuasted() == true)    //If the pokemon is exhausted//
                state = EXHAUSTED;
            return false;
        } break;
        case 3:                             //If IN_GYM return false//
        {
            if (isExhuasted() == true)
                state = EXHAUSTED;
            return false;
        } break;
        case 7:                             //If the Pokemon is TRAINING_IN_GYM//
        {
            stamina = stamina - current_gym->GetStaminaCost(training_units_to_buy);     //Calculate the decrease in stamina//
            pokemon_dollars = pokemon_dollars - current_gym->GetDollarCost(training_units_to_buy);  //Calculate the decrease in Pokemon dollars//
            experience_points = experience_points + current_gym->TrainPokemon(training_units_to_buy);   //Calculate the increase in experience points//
            cout << "** " << name << " completed " << training_units_to_buy << " training unit(s)! **" << endl;     //Cout messages//
            cout << "** " << name << " gained " << experience_points << " experience points(s) **" << endl;
            state = IN_GYM;     //State is now IN_GYM and reuturn true//
            if (isExhuasted() == true)  //If the pokemon is exhausted//
                    state = EXHAUSTED;
            return true;
        } break;
        case 8:                            //If the Pokemon is RECOVERING_STAMINA//
        {
            stamina = stamina + current_center->DistributeStamina(stamina_points_to_buy);   //Calculate the increase in stamina//
            pokemon_dollars = pokemon_dollars - current_center->GetDollarCost(stamina_points_to_buy);   //Calculate the decrease in Pokemon dollars//
            cout << "** " << name << " recovered " << stamina_points_to_buy << " stamina point(s) **" << endl;  //Cout message//
            state = IN_CENTER;              //State is now IN_CENTER//
            if (isExhuasted() == true)  //If the pokemon is exhausted//
                    state = EXHAUSTED;
            return true;
        } break;
        default:                            //Default case//
        {
            return false;
        } break;
    }
}

void Pokemon::ShowStatus()   //ShowStatus Function for Pokemon//
{
    cout << name << " status: ";
    GameObject::ShowStatus();           //Explicit call to GameObject's ShowStatus function//
    switch (state)
    {
        case 0: 
        {
            cout << " stopped" << endl;         //If the object is stopped, cout stopped
            cout << "   Stamina: " << stamina << endl;
            cout << "   Pokemon Dollars: " << setprecision(2) << fixed << pokemon_dollars << endl; //Stamina, pokemon dollars, and experience points statements//
            cout << "   Experience Points: " << experience_points << endl;
        } break;
        case 1:     //If the object is moving, cout moving statement//
        {
            cout << " moving at a speed of " << speed << " to destination <" << destination.x << "," << destination.y << "> at each step of " << delta << endl;
            cout << "   Stamina: " << stamina << endl;
            cout << "   Pokemon Dollars: " << setprecision(2) << fixed << pokemon_dollars << endl; //Stamina, pokemon dollars, and experience points statements//
            cout << "   Experience Points: " << experience_points << endl;
        } break;
        case 6:     //If the object is moving to a Center, display moving to center message//
        {
            cout << " heading to Pokemon Center " << current_center->GetId() << " at a speed of " << speed << " at each step " << delta << endl;
            cout << "   Stamina: " << stamina << endl;
            cout << "   Pokemon Dollars: " << setprecision(2) << fixed << pokemon_dollars << endl; //Stamina, pokemon dollars, and experience points statements//
            cout << "   Experience Points: " << experience_points << endl;
        } break;
        case 5:     //If the object is moving to a Gym, display moving to gym message//
        {
            cout << " heading to Pokemon Gym " << current_gym->GetId() << " at a speed of " << speed << " at each step " << delta << endl;
            cout << "   Stamina: " << stamina << endl;
            cout << "   Pokemon Dollars: " << setprecision(2) << fixed << pokemon_dollars << endl; //Stamina, pokemon dollars, and experience points statements//
            cout << "   Experience Points: " << experience_points << endl;
        } break;
        case 4:     //If the object is in a center, display the in center message//
        {
            cout << "inside Pokemon Center " << current_center->GetId() << endl;
            cout << "   Stamina: " << stamina << endl;
            cout << "   Pokemon Dollars: " << setprecision(2) << fixed << pokemon_dollars << endl; //Stamina, pokemon dollars, and experience points statements//
            cout << "   Experience Points: " << experience_points << endl;
        } break;
        case 3:     //If the object is in a gym, display the in gym message//
        {
            cout << " inside Pokemon Gym " << current_gym->GetId() << endl;
            cout << "   Stamina: " << stamina << endl;
            cout << "   Pokemon Dollars: " << setprecision(2) << fixed << pokemon_dollars << endl;
            cout << "   Experience Points: " << experience_points << endl; //Stamina, pokemon dollars, and experience points statements//
        } break;
        case 7:     //If the object is training, print training message//
        {
            cout << " training in Pokemon Gym " << current_gym->GetId() << endl;
            cout << "   Stamina: " << stamina << endl;
            cout << "   Pokemon Dollars: " << setprecision(2) << fixed << pokemon_dollars << endl;
            cout << "   Experience Points: " << experience_points << endl; //Stamina, pokemon dollars, and experience points statements//
        } break;
        case 8:     //If the object is recovering stamina, print recovering stamina message//
        {
            cout << " recovering stamina in Pokemon Center " << current_center->GetId() << endl;
            cout << "   Stamina: " << stamina << endl;
            cout << "   Pokemon Dollars: " << setprecision(2) << fixed << pokemon_dollars << endl; //Stamina, pokemon dollars, and experience points statements//
            cout << "   Experience Points: " << experience_points << endl;
        } break;
        default:     //Default case//
        {
        } break;
    }
}

bool Pokemon::UpdateLocation()      //UpdateLocation Function//
{
    if (fabs(destination.x - location.x) <= fabs(delta.x) && fabs(destination.y - location.y) <= fabs(delta.y)) //If the object is one step away according to the instructions...//
    {
        location = destination;     //Set location to the destination//
        cout << display_code << id_num << ": I'm there!" << endl;       //cout I'm there//
        
        return true;        //Return true//
    }
    else 
        location.x = location.x + delta.x;
        location.y = location.y + delta.y; 
        if (stamina > 0)
            stamina = stamina - 1;
        else if (stamina == 0)
            stamina = 0;
        pokemon_dollars = pokemon_dollars + GetRandomAmountOfPokemonDollars();
        cout << display_code << id_num << ": step..." << endl;  //Else indicate step needed//
        return false;
}

void Pokemon::SetupDestination(Point2D dest)    //SetupDestination function//
{
    destination = dest;
    delta = (destination - location) * (speed / GetDistanceBetween(destination, location));     //Calculate delta based on instructions//
}

string Pokemon::GetName()               //Getter function to return name//
{
    return name;
}

static double GetRandomAmountOfPokemonDollars()        //Function returns random amount of pokemon dollars between 0.0 and 2.0//
{
    static bool first = true;
    if (first)
    {
        srand(time(NULL));
        first = false;
    }
    double val = 0 + (double)rand() * (2-0) / (double)RAND_MAX;
    return val;
}
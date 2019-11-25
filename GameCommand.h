#ifndef GAMECOMMAND_H                           
#define GAMECOMMAND_H                                                               //Define GAMECOMMAND_H and include "Model.h"//
#include "Model.h"
#include "Pokemon.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"

void DoMoveCommand(Model& model, int pokemon_id, Point2D p1);                       //Function prototypes for GameCommand//
void DoMoveToCenterCommand(Model& model, int pokemon_id, int center_id);
void DoMoveToGymCommand(Model& model, int pokemon_id, int gym_id);
void DoStopCommand(Model& model, int pokemon_id);
void DoTrainInGymCommand(Model& model, int pokemon_id, unsigned int training_units);
void DoRecoverInCenterCommand(Model& model, int pokemon_id, unsigned int stamina_points);
void DoGoCommand(Model& model);
void DoRunCommand(Model& model);

#endif                                                                               //End definition//
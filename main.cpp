#include <iostream>                     //Preprocessor directives and include "Model.h," "Point2D.h," and "GameCommand.h"//
#include "Model.h"
#include "GameCommand.h"
#include "Point2D.h"

using namespace std;                    //Using namepsace std//

int main()
{
    char input;                         //Define variable input//
    Model model;                        //Create model object//
    model.ShowStatus();

    while(input != 'q')                 //While the user does not enter 'q'//
    {
        cout << "";                     //Cin user input//
            cin >> input;
        switch (input)                  //Switch statement//
        {
            case 'm':   //Move to destination//
            {
                int id, x, y;           //Cout/Cin arguments//
                cout << "";
                    cin >> id >> x >> y;
                Point2D point(x,y);         //Create Point2D object//
                DoMoveCommand(model, id, point);        //Move to destination function and echo statement//
            } break;
            case 'g':   //Move to Gym//
            {
                int id1, id2;           //Cout/Cin arguments//
                cout << "";
                    cin >> id1 >> id2;
                DoMoveToGymCommand(model, id1, id2);    //Move to gym and echo statement//
            } break;
            case 'c':   //Move to center//
            {
                int id1, id2;
                cout << "";
                    cin >> id1 >> id2;
                DoMoveToCenterCommand(model, id1, id2);     //Move to center function and echo statement//
            } break;
            case 's':   //Stop//
            {
                int id;             //Cout/Cin arguments//
                cout << "";
                    cin >> id;
                DoStopCommand(model, id);   //Stop function and echo statement//
            } break;
            case 'r':   //Recover stamina//
            {
                int id1;                        //Cout/Cin arguments//
                unsigned int stamina_units;
                cout << "";
                    cin >> id1 >> stamina_units;
                DoRecoverInCenterCommand(model, id1, stamina_units);        //Recover function and echo statement//
            } break;
            case 't':   //Train in gym//
            {
                int id1;                        //Cout/Cin arguments//
                unsigned int training_units;
                cout << "";
                    cin >> id1 >> training_units;
                DoTrainInGymCommand(model, id1, training_units);        //Train function and echo statement//
            } break;
            case 'v':   //Advance one tick and update//
            {
                DoGoCommand(model);     //DoGoCommand//
                model.ShowStatus();
            } break;
            case 'x':
            {
                int count = 0;
                while (count != 5 || model.Update() == true)
                {
                    count = count + 1;
                    DoRunCommand(model);       //Keep updating unless update returns true or count is greater than 5//
                    model.ShowStatus();
                } 
            } break;
            case 'q':   //Quit program//
            {
                return 0;       //End the program//
            } break;
        }
    }
}
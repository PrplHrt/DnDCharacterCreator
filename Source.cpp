#include <cmath>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <cctype>
#include "myHeader.h"

//Using the handbook in this link to create this program: https://online.anyflip.com/ofsj/cxmj/mobile/index.html

/*Things to do:
-Add race menu
  -Design menu interface
  -Add racial bonuses
  -Make info into text files OR NOT
  -Design subraces menu for each race with subraces
-Add class menu
  -Design menu interface
  -Add "Equipment"
-Add a Show() function that displays the character's info
*/

int main()
{
    //randomise based on time of system
    srand(time(NULL));
    Character player;

    Race(player);
    player.Display();
    return 0;
}



//CreateCharacter function that takes in character object and creates the Character
void CreateCharacter(Character& player)
{
    std::string name;

    //Setting the name of the Character
    std::cout << "First, please name your character:\n";
    std::cin >> name;
    player.SetName(name);

    //Clearing the Console
    system("CLS");

    //Race
    std::cout << "Second, let's decide on a race\n";
    Race(player);

    //Class

    //Stats
}

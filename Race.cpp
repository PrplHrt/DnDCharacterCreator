//Race decider function
void Race(Character& player)
{
    //pointer which will contain all the descriptions of each race
    std::string desc[9][5];

    //Create Text files with all this info and move the info to those, then replace the info here with directories which would then be called and displayed in the menu
    //For Races with subraces add an option in selection to decide on specific subrace
    //Race Names
    desc[0][0] = "Dwarf";       //Has Subraces
    desc[1][0] = "Elf";         //Has Subraces
    desc[2][0] = "Halfling";    //Has Subraces
    desc[3][0] = "Human";       //Has Variants
    desc[4][0] = "Dragonborn";  //Add Detail for Dragonborn race breaths
    desc[5][0] = "Gnome";       //Has Subraces
    desc[6][0] = "Half-Elf";
    desc[7][0] = "Half-Orc";
    desc[8][0] = "Tiefling";
    //Race descriptions
    desc[0][1] = "\tLifespan: ~350 years\n\tAdult at: 50 years\n\tSize: 4 to 5 ft tall, ~150 lbs, Medium\n\tAlignment Tendencies: Lawful Good\n\tSpeed: 25ft\n\tLanguages:\n\t\t>Common\n\t\t>Dwarvish";
    desc[1][1] = "\tLifespan: ~750 years\n\tAdult at: ~100 years\n\tSize: 5 to 6 ft tall, Slender, Medium\n\tAlignment Tendencies: Chaotic Good\n\tSpeed: 30ft\n\tLanguages:\n\t\t>Common\n\t\t>Elvish";
    desc[2][1] = "\tLifespan: ~150 years\n\tAdult at: 20 years\n\tSize: ~3 ft tall, ~40 lbs, Small\n\tAlignment Tendencies: Lawful Good\n\tSpeed: 25ft\n\tLanguages:\n\t\t>Common\n\t\t>Halfling";
    desc[3][1] = "\tLifespan: ~80 years\n\tAdult at: ~20 years\n\tSize: 5 to 6+ ft tall, Medium\n\tAlignment Tendencies: None\n\tSpeed: 30ft\n\tLanguages:\n\t\t>Common\n\t\t>Any Other Language"; //Should add a choice later on for human's additional language
    desc[4][1] = "\tLifespan: ~80 years\n\tAdult at: 15 years\n\tSize: 6+ ft tall, ~250 pounds, Medium\n\tAlignment Tendencies: Either Good or Bad\n\tSpeed: 30ft\n\tLanguages:\n\t\t>Common\n\t\t>Draconic";
    desc[5][1] = "\tLifespan: 350-500 years\n\tAdult at: 40 years\n\tSize: 3 to 4 ft tall, ~40 lbs, Small\n\tAlignment Tendencies: Good (Lawful or Chaotic based on profession)\n\tSpeed: 25ft\n\tLanguages:\n\t\t>Common\n\t\t>Gnomic";
    desc[6][1] = "\tLifespan: ~180 years\n\tAdult at: 20 years\n\tSize: 5 to 6 ft tall, Human-like, Medium \n\tAlignment Tendencies: Chaotic\n\tSpeed: 30ft\n\tLanguages: \n\t\t>Common\n\t\t>Elvish\n\t\t>One more language of choice";
    desc[7][1] = "\tLifespan: ~75 years\n\tAdult at: 14 years\n\tSize: 5 to 6+ ft tall, ~190 lbs, Medium\n\tAlignment Tendencies: Chaotic Evil\n\tSpeed: 30ft\n\tLanguages:\n\t\t>Common\n\t\t>Orc";
    desc[8][1] = "\tLifespan: ~80 years\n\tAdult at: ~20 years\n\tSize:  5 to 6+ ft tall, Human-like, Medium\n\tAlignment Tendencies: Chaotic\n\tSpeed: 30ft\n\tLanguages:\n\t\t>Common\n\t\t>Infernal";
    //Racial Bonuses
    desc[0][2] = "\tSTR: \n\tDEX: \n\tCON: +2\n\tINT: \n\tWIS: \n\tCHA: ";
    desc[1][2] = "\tSTR: \n\tDEX: +2\n\tCON: \n\tINT: \n\tWIS: \n\tCHA: ";
    desc[2][2] = "\tSTR: \n\tDEX: +2\n\tCON: \n\tINT: \n\tWIS: \n\tCHA: ";
    desc[3][2] = "\tSTR: +1\n\tDEX: +1\n\tCON: +1\n\tINT: +1\n\tWIS: +1\n\tCHA: +1";
    desc[4][2] = "\tSTR: +2\n\tDEX: \n\tCON: \n\tINT: \n\tWIS: \n\tCHA: +1";
    desc[5][2] = "\tSTR: \n\tDEX: \n\tCON: \n\tINT: +2\n\tWIS: \n\tCHA: ";
    desc[6][2] = "\tSTR: \n\tDEX: \n\tCON: \n\tINT: \n\tWIS: \n\tCHA: +2\n\tAnd +1 to any two other stats"; //Add option to select stat for additional bonus
    desc[7][2] = "\tSTR: +2\n\tDEX: \n\tCON: +1\n\tINT: \n\tWIS: \n\tCHA: ";
    desc[8][2] = "\tSTR: \n\tDEX: \n\tCON: \n\tINT: +1\n\tWIS: \n\tCHA: +2";
      //Array that contains values for Racial Bonuses:
      int bonus[9][6] = {{0,0,2,0,0,0},{0,2,0,0,0,0},{0,2,0,0,0,0},{1,1,1,1,1,1},{2,0,0,0,0,1},{0,0,0,2,0,0},{0,0,0,0,0,2},{2,0,1,0,0,0},{0,0,0,1,0,2}};
    //Subraces
    desc[0][3] = "Subraces:\n\t>Hill Dwarf\n\t>Mountain Dwarf";
    //Hill: WIS +1 & Hit Point Max +1 and +1/lvl | Mountain: STR +2 & proficiency with light and medium armor
    desc[1][3] = "Subraces:\n\t>High Elves\n\t>Wood Elves\n\t>Drow";
    /*High: INT +1 & Proficiency with longsword, shortsword, shortbow, and longbow & One Cantrip of choice from Wizard spell list w/ INT as spellcasting ability
    & Add one more language of choice| Wood:  WIS +1 & Proficiency with longsword, shortsword, shortbow, and longbow & Increased speed to 35ft & You can attempt
    to hide when lightly obscured with foilage and other natural phenomena|Drow have Chaotic Evil tendencies & CHA +1 & Darkvision with radius 120 ft &
    Disadvantage on attack rolls and perception checks that relly on sight when you or objective is in direct sunlight & You know Dancing lights cantrip lvl1, Faerie fire can be cast once
    per day at and beyond lvl3, @ lvl5 darkness spell can be cast once per day, CHA is spellcasting ability for all of these & Proficiency with rapiers, shortswords, and hand crossbows*/
    desc[2][3] = "Subraces:\n\t>Lightfoot\n\t>Stout";
    /*Lightfoot: CHA +1 & You can attempt to hide when you are obscured by a creature at least one size bigger than you |
     Stout: CON +1 & Advantage on saving throws against poison and resistance against poison damage*/
    desc[3][3] = "Subraces:\n\t>Normal\n\t>Variant";
    /*Variant's replace Human's stats with any 2 stats gaining a +1, a proficiency in any skill of choice, and gain one feat of choice*/
    desc[4][3] = "Subraces:\n\t>Black (Acid)\n\t>Blue (Lightning)\n\t>Brass (Fire)\n\t>Bronze (Lightning)\n\t>Copper (Acid)\n\t>Gold (Fire)\n\t>Green (Poison)\n\t>Red (Fire)\n\t>Silver (Cold)\n\t>White (Cold)";
    desc[5][3] = "Subraces:\n\t>Forest Gnomes\n\t>Rock Gnomes";
    /*Forest: DEX +1 & Minor Illusion cantrip is known and INT is spellcasting ability & Can communicate with small animals and beast with gestures
     and sounds | Rock: CON +1 & Add twice proficiency bonus to any History checks on magical and technological items & Tinker (ability to make a trinket
     with one of three functions should add more details */
    desc[6][3] = "Subraces: N/A";
    desc[7][3] = "Subraces: N/A";
    desc[8][3] = "Subraces: N/A";
    //Racial additions
    desc[0][4] = "-Speed not reduced by heavy armor.\n-Has \"DarkVision\" and can see upto 60ft in dim light as though it was bright and in darkness as if it was dim. You can\'t discern colors in darkness.\n-Advantage on saving throws against poison and resistance against poison damage.\n-Proficiency with battleaxe, handaxe, throwing hammer, and warhammer.\nProficiency in the tools of your choice:\n\t>smith\'s tools\n\t>brewer\'s supplies\n\t>mason\'s tools\n-Add double your proficiency bonus on history checks related to the origin of stonework.\n-Hard consonants and guttural sounds spill over to whatever language a Dwarf tries to speak.";
    desc[1][4] = "-Change names upon adulthood\n-Has \"DarkVision\" and can see upto 60ft in dim light as though it was bright and in darkness as if it was dim. You can\'t discern colors in darkness.\n-Proficiency in perception.\n-Advantage on saving throws against being charmed, and magic can't put you to sleep.\n-Does not sleep, instead can meditate for 4 hours and gains same benefit as 8 hours sleep.";
    desc[2][4] = "-When you roll a 1 on any roll, you can roll again and must take the new roll.\n-Advantage on saving throws from being frightened.\n-You can move through any space of a creature that's size is larger than yours.";
    desc[3][4] = "";
    desc[4][4] = "-Dragonborn posses a breath attack and resistances that vary based on the chosen type";
    desc[5][4] = "-Has \"DarkVision\" and can see upto 60ft in dim light as though it was bright and in darkness as if it was dim. You can\'t discern colors in darkness.\n-Advantage on all intelligence, charisma, and wisdom saving throws against magic";
    desc[6][4] = "-Has \"DarkVision\" and can see upto 60ft in dim light as though it was bright and in darkness as if it was dim. You can\'t discern colors in darkness.\n-Advantage on saving throws against being charmed, and magic can't put you to sleep.\n-Gain proficiency in n=any two skills of your choice.";
    desc[7][4] = "-Has \"DarkVision\" and can see upto 60ft in dim light as though it was bright and in darkness as if it was dim. You can\'t discern colors in darkness.\n-Gain proficiency in the intimidation skill.\n-When dropping to 0 hit points but not killed outright, you can instead go to 1 hit point (Once after every long rest).\n-When achieving a critical hit with a melee weapon, roll one of the weapon's damage dice and add that as damage to the critical hit.";
    desc[8][4] = "-Has \"DarkVision\" and can see upto 60ft in dim light as though it was bright and in darkness as if it was dim. You can\'t discern colors in darkness.\n-Resistance to fire damage.\n-Know the Thaumaturgy cantrip at lvl 1, Hellish Rebuke can be casted once per day as a 2nd level spell, at lvl 3, and the Darkness spell once per day at lvl 5 (all with CHA as the spellcasting ability).";

    //input for options at different stages
    char racemenu, subracemenu;
    /*
    N - next
    P - previous
    S - select
    */
    int i{0}, j{0};
    //Menu:
    std::cout << "The following will be a description of several available races in D&D.\n";
    system("pause");

    while(racemenu != 'S')
    {
      system("CLS");
      std::cout << "Name: " << desc[i][0] << std::endl;
      std::cout << "Basic Description:\n" << desc[i][1] <<std::endl;
      std::cout << "Racial Bonuses:\n" << desc[i][2] << std::endl;
      std::cout << desc[i][3] << std::endl;
      std::cout << "Additonal Info:\n" << desc[i][4] << std::endl << std::endl;
      std::cout << "Options:\n\t>N - next\n\t>P - previous\n\t>S - select\nInput: ";
      std::cin >> racemenu;

      //Allows for lowercase input of the prementioned options
      racemenu = toupper(racemenu);

      switch(racemenu)
      {
        case 'N':
          i++;
          break;
        case 'P':
          i--;
          break;
        case 'S':
          if(i == 4 || i >=6)
          {
            player.SetRace(desc[i][0]);
            player.AddStr(bonus[i][0]);
            player.AddDex(bonus[i][1]);
            player.AddCon(bonus[i][2]);
            player.AddInt(bonus[i][3]);
            player.AddWis(bonus[i][4]);
            player.AddCha(bonus[i][5]);
          }
          else
          {
            //Subraces go here
            switch(i)
            {
              case 0:
              //Dwarf
                while(subracemenu != 'S')
                {

                  //Handles user input
                  switch(subracemenu)
                  {
                    case 'N':
                      j++;
                      break;
                    case 'P':
                      j--;
                      break;
                    case 'S':
                      break;
                  }
                  //Allows for looping
                  if( i < 0 )
                  {
                    i = 1;
                  }
                  else if( i > 1 )
                  {
                    i = 0;
                  }
                }
                break;
              case 1:
              //Elf

                while(subracemenu != 'S')
                {
                  //Handles user input
                  switch(subracemenu)
                  {
                    case 'N':
                      j++;
                      break;
                    case 'P':
                      j--;
                      break;
                    case 'S':
                      break;
                  }
                  //Allows for looping
                  if( i < 0 )
                  {
                    i = 2;
                  }
                  else if( i > 2 )
                  {
                    i = 0;
                  }
                }
                break;
              case 2:
              //Halfling

                while(subracemenu != 'S')
                {
                  //Handles user input
                  switch(subracemenu)
                  {
                    case 'N':
                      j++;
                      break;
                    case 'P':
                      j--;
                      break;
                    case 'S':
                      break;
                  }
                  //Allows for looping
                  if( i < 0 )
                  {
                    i = 1;
                  }
                  else if( i > 1 )
                  {
                    i = 0;
                  }
                }
                break;
              case 3:
              //Human

                while(subracemenu != 'S')
                {
                  //Handles user input
                  switch(subracemenu)
                  {
                    case 'N':
                      j++;
                      break;
                    case 'P':
                      j--;
                      break;
                    case 'S':
                      break;
                  }
                  //Allows for looping
                  if( i < 0 )
                  {
                    i = 1;
                  }
                  else if( i > 1 )
                  {
                    i = 0;
                  }
                }
                break;
              case 5:
              //Gnome
                while(subracemenu != 'S')
                {
                  //Handles user input
                  switch(subracemenu)
                  {
                    case 'N':
                      j++;
                      break;
                    case 'P':
                      j--;
                      break;
                    case 'S':
                      break;
                  }
                  //Allows for looping
                  if( i < 0 )
                  {
                    i = 1;
                  }
                  else if( i > 1 )
                  {
                    i = 0;
                  }
                }
                break;
            }
          }
          break;
        default:
          std::cout << "\n\nInvalid Entry\n";
          system("pause");
          //Add error handling
      }

      //To make sure the menu loops back instead of going out of bounds
      if( i < 0 )
      {
        i = 8;
      }
      else if( i > 8 )
      {
        i = 0;
      }
    }

}

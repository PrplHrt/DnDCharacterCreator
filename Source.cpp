#include "cmath"
#include "iostream"
#include "ctime"
#include "stdlib.h"

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



class Character
{
private:
    //Basic aspects of a character
    std::string name;
    std::string Cclass;
    std::string race;
    //Stats & modifiers
    int strength, dexterity, constitution, intelligence, wisdom, charisma;
    int strMod, dexMod, conMod, intMod, wisMod, chaMod;

public:
    //Set & Get functions
    void SetName(std::string name) { this->name = name; }
    std::string GetName() { return name; }
    void SetClass(std::string Cclass) { this->Cclass = Cclass; }
    std::string GetClass() { return Cclass; }
    void SetRace(std::string race) { this->race = race; }
    std::string GetRace() { return race; }

    //Set functions for stats also set the modifiers
    void SetStr(int strength)
    {
        this->strength = strength;
        strMod = floor((strength - 10) / 2); //rounds down
    }
    void SetDex(int dexterity)
    {
        this->dexterity = dexterity;
        dexMod = floor((dexterity - 10) / 2);
    }
    void SetCon(int constitution)
    {
        this->constitution = constitution;
        conMod = floor((constitution - 10) / 2);
    }
    void SetInt(int intelligence)
    {
        this->intelligence = intelligence;
        intMod = floor((intelligence - 10) / 2);
    }
    void SetWis(int wisdom)
    {
        this->wisdom = wisdom;
        wisMod = floor((wisdom - 10) / 2);
    }
    void SetCha(int charisma)
    {
        this->charisma = charisma;
        chaMod = floor((charisma - 10) / 2);
    }
    //Add functions for stats to add racial bonuses
    void AddStr(int strength)
    {
        this->strength += strength;
        strMod = floor((this->strength - 10) / 2); //rounds down
    }
    void AddDex(int dexterity)
    {
        this->dexterity += dexterity;
        dexMod = floor((this->dexterity - 10) / 2);
    }
    void AddCon(int constitution)
    {
        this->constitution += constitution;
        conMod = floor((this->constitution - 10) / 2);
    }
    void AddInt(int intelligence)
    {
        this->intelligence += intelligence;
        intMod = floor((this->intelligence - 10) / 2);
    }
    void AddWis(int wisdom)
    {
        this->wisdom += wisdom;
        wisMod = floor((this->wisdom - 10) / 2);
    }
    void AddCha(int charisma)
    {
        this->charisma += charisma;
        chaMod = floor((this->charisma - 10) / 2);
    }
    //Get functions for stats
    int GetStr() { return strength; }
    int GetDex() { return dexterity; }
    int GetCon() { return constitution; }
    int GetInt() { return intelligence; }
    int GetWis() { return wisdom; }
    int GetCha() { return charisma; }
    //Get functions for modifiers
    int GetStrMod() { return strMod; }
    int GetDexMod() { return dexMod; }
    int GetConMod() { return conMod; }
    int GetIntMod() { return intMod; }
    int GetWisMod() { return wisMod; }
    int GetChaMod() { return chaMod; }

    //Function that creates Character Object
    Character(std::string name, std::string race, std::string Cclass, int str, int dex, int con, int intel, int wis, int cha)
    {
        this->name = name;
        this->race = race;
        this->Cclass = Cclass;
        SetStr(str);
        SetDex(dex);
        SetCon(con);
        SetInt(intel);
        SetWis(wis);
        SetCha(cha);
    }
    //In the case of no parameters (uses standard stats 15,14,13,12,10,8)
    Character()
    {
        name = "Torradh";
        race = "Tiefling";
        Cclass = "Warlock";
        SetStr(13);
        SetDex(10);
        SetCon(14);
        SetInt(12);
        SetWis(8);
        SetCha(15);
    }
};

//function prototypes
int Dice(int side);
void CreateCharacter(Character& player);
void Race(Character& player);

int main()
{
    //randomise based on time of system
    srand(time(NULL));

    Character player;
    Race(player);
    return 0;
}

//FUNCTIONS BELOW

//Dice function
int Dice(int side)
{
    //result variable to output the result
    int result{ 0 };
    //Limit function to only allow 4, 6, 8, 10, 12, 20, 100 sided die
    switch (side)
    {
    case 4:
    case 6:
    case 8:
    case 10:
    case 12:
    case 20:
    case 100:
        result = ((rand() % side) + 1); //Add 1 to result since '0' is not a possible role
        std::cout << "Rolled " << side << "-sided die, result: " << result << std::endl;
        return result;
    default:
        return 0;
    }
}

//CreateCharacter function that takes in character object and creates the Character
void CreateCharacter(Character& player)
{
    std::string input;

    //Setting the name of the Character
    std::cout << "First, please name your character:\n";
    std::cin >> input;
    player.SetName(input);

    //Clearing the Console
    system("CLS");

    //Race
    std::cout << "Second, let's decide on a race\n";
    Race(player);

    //Class

    //Stats
}

//Race decider function
void Race(Character& player)
{
    //pointer which will contain all the descriptions of each race
    std::string desc[9][5];

    //Create Text files with all this info and move the info to those, then replace the info here with directories which would then be called and displayed in the menu
    //For Races with subraces add an option in selection to decide on specific subrace
    //Race Names
    desc[0][0] = "Dwarf";    //Has Subraces
    desc[1][0] = "Elf";      //Has Subraces
    desc[2][0] = "Halfling"; //Has Subraces
    desc[3][0] = "Human";
    desc[4][0] = "Dragonborn";
    desc[5][0] = "Gnome";    //Has Subraces
    desc[6][0] = "Half-Elf";
    desc[7][0] = "Half-Orc";
    desc[8][0] = "Tiefling";
    //Race descriptions
    desc[0][1] = "Lifespan: ~350 years\nAdult at: 50 years\nSize: 4 to 5 ft tall, ~150 lbs, Medium\nAlignment Tendencies: Lawful Good\nSpeed: 25ft\nLanguages:\n\t>Common\n\t>Dwarvish";
    desc[1][1] = "Lifespan: ~750 years\nAdult at: ~100 years\nSize: 5 to 6 ft tall, Slender, Medium\nAlignment Tendencies: Chaotic Good\nSpeed: 30ft\nLanguages:\n\t>Common\n\t>Elvish";
    desc[2][1] = "Lifespan: \nAdult at: \nSize: \nAlignment Tendencies: \nSpeed: \nLanguages: \n";
    desc[3][1] = "Lifespan: \nAdult at: \nSize: \nAlignment Tendencies: \nSpeed: \nLanguages: \n";
    desc[4][1] = "Lifespan: \nAdult at: \nSize: \nAlignment Tendencies: \nSpeed: \nLanguages: \n";
    desc[5][1] = "Lifespan: \nAdult at: \nSize: \nAlignment Tendencies: \nSpeed: \nLanguages: \n";
    desc[6][1] = "Lifespan: \nAdult at: \nSize: \nAlignment Tendencies: \nSpeed: \nLanguages: \n";
    desc[7][1] = "Lifespan: \nAdult at: \nSize: \nAlignment Tendencies: \nSpeed: \nLanguages: \n";
    desc[8][1] = "Lifespan: \nAdult at: \nSize: \nAlignment Tendencies: \nSpeed: \nLanguages: \n";
    //Racial Bonuses
    desc[0][2] = "STR: \nDEX: \nCON: +2\nINT: \nWIS: \nCHA: \n";
    desc[1][2] = "STR: \nDEX: +2\nCON: \nINT: \nWIS: \nCHA: \n";
    desc[2][2] = "STR: \nDEX: \nCON: \nINT: \nWIS: \nCHA: \n";
    desc[3][2] = "STR: \nDEX: \nCON: \nINT: \nWIS: \nCHA: \n";
    desc[4][2] = "STR: \nDEX: \nCON: \nINT: \nWIS: \nCHA: \n";
    desc[5][2] = "STR: \nDEX: \nCON: \nINT: \nWIS: \nCHA: \n";
    desc[6][2] = "STR: \nDEX: \nCON: \nINT: \nWIS: \nCHA: \n";
    desc[7][2] = "STR: \nDEX: \nCON: \nINT: \nWIS: \nCHA: \n";
    desc[8][2] = "STR: \nDEX: \nCON: \nINT: \nWIS: \nCHA: \n";
    //Subraces
    desc[0][3] = "Subraces:\n\t>Hill Dwarf\n\t>Mountain Dwarf"; //Hill: WIS +1 & Hit Point Max +1 and +1/lvl | Mountain: STR +2 & proficiency with light and medium armor
    desc[1][3] = "Subraces:\n\t>High Elves\n\t>Wood Elves\n\t>Dark Elves/Drow"; //Drow have Chaotic Evil tendencies
    desc[2][3] = "Subraces:";
    desc[3][3] = "Subraces:";
    desc[4][3] = "Subraces:";
    desc[5][3] = "Subraces:";
    desc[6][3] = "Subraces:";
    desc[7][3] = "Subraces:";
    desc[8][3] = "Subraces:";
    //Racial additions
    desc[0][4] = "-Speed not reduced by heavy armor.\n-Has \"DarkVision\" and can see upto 60ft in dim light as though it was bright and in darkness as if it was dim. You can\'t discern colors in darkness.\n-Advantage on saving throws against poison and resistance against poison damage.\n-Proficiency with battleaxe, handaxe, throwing hammer, and warhammer.\nProficiency in the tools of your choice:\n\t>smith\'s tools\n\t>brewer\'s supplies\n\t>mason\'s tools\n-Add double your proficiency bonus on history checks related to the origin of stonework.\n-Hard consonants and guttural sounds spill over to whatever language a Dwarf tries to speak.\n";
    desc[1][4] = "-Change names upon adulthood\n-Has \"DarkVision\" and can see upto 60ft in dim light as though it was bright and in darkness as if it was dim. You can\'t discern colors in darkness.\n-Proficiency in perception.\n-Advantage on saving throws against being charmed, and magic can't put you to sleep.\n-Does not sleep, instead can meditate for 4 hours and gains same benefit as 8 hours sleep.\n";
    desc[2][4] = "";
    desc[3][4] = "";
    desc[4][4] = "";
    desc[5][4] = "";
    desc[6][4] = "";
    desc[7][4] = "";
    desc[8][4] = "";


    for (int i{ 0 }; i <= 4; i++)
    {
        std::cout << desc[0][i] << std::endl;
    }
}

#include <cmath>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <cctype>

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

    //A display functions
    void Display()
    {
      std::cout << "Player Info:\n"<< std::endl << name  << std::endl << race << std::endl << Cclass << std::endl << GetStr() << std::endl << GetDex() << std::endl << GetCon() << std::endl << GetInt() << std::endl << GetWis() << std::endl << GetCha() << std::endl;
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
    player.Display();
    return 0;
}

//FUNCTIONS BELOW



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

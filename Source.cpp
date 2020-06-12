#include "cmath"
#include "iostream"

/*Things to do:
-Add dice function
-Add race menu
  -Design menu interface
  -Add racial bonuses
-Add class menu
  -Design menu interface
  -Add "Equipment"
*/

class Character
{
private:
  //Basic aspects of a character
  std::string name;
  std::string class;
  std::string race;
  //Stats & modifiers
  int strength, dexterity, constitution, intelligence, wisdom, charisma;
  int strMod, dexMod, conMod, intMod, wisMod, chaMod;

public:
  //Set & Get functions
  void SetName(std::string name){this->name = name;}
  std::string GetName(){ return name; }
  void SetClass(std::string class){this->class = class;}
  std::string GetClass(){ return class; }
  void SetRace(std::string race){this->race = race;}
  std::string GetRace(){ return race; }

  //Set functions for stats also set the modifiers
  void SetStr(int strength)
  {
    this->strength = strength;
    strMod = floor((strength-10)/2); //rounds down
  }
  void SetDex(int dexterity)
  {
    this->dexterity = dexterity;
    dexMod = floor((dexterity-10)/2);
  }
  void SetCon(int constitution)
  {
    this->constitution = constitution;
    conMod = floor((constitution-10)/2);
  }
  void SetInt(int intelligence)
  {
    this->intelligence = intelligence;
    intMod = floor((intelligence-10)/2);
  }
  void SetWis(int wisdom)
  {
    this->wisdom = wisdom;
    wisMod = floor((wisdom-10)/2);
  }
  void SetCha(int charisma)
  {
    this->charisma = charisma;
    chaMod = floor((charisma-10)/2);
  }
  //Get functions for stats
  int GetStr(){return strength;}
  int GetDex(){return dexterity;}
  int GetCon(){return constitution;}
  int GetInt(){return intelligence;}
  int GetWis(){return wisdom;}
  int GetCha(){return charisma;}
  //Get functions for modifiers
  int GetStrMod(){return strMod;}
  int GetDexMod(){return dexMod;}
  int GetConMod(){return conMod;}
  int GetIntMod(){return intMod;}
  int GetWisMod(){return wisMod;}
  int GetChaMod(){return chaMod;}

//Function that creates Character Object
  Character(std::string name, std::string race, std::string class, int str, int dex, int con, int intel, int wis, int cha)
  {
    this->name = name;
    this->race = race;
    this->class = class;
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
    name = "Torradh"
    race = "Tiefling"
    class = "Warlock"
    SetStr(13);
    SetDex(10);
    SetCon(14);
    SetInt(12);
    SetWis(8);
    SetCha(15);
  }
}

int main()
{


  return 0;
}

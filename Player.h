#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player
{
private:
    std::string name;
    std::string race;
    std::string currentClass;
    int strength;
    int intelligence;
    int agility;
    int health;
    int hunger;
    int thirst;
public:
    Player();
    ~Player();
    void inputName();
    void inputRace();
    void inputCurrentClass();
    std::string getName();
    std::string getRace();
    std::string getCurrentClass();
    int getStrength();
    int getIntelligence();
    int getAgility();
    void setStrength(int strengthVal);
    void setIntelligence(int intelligenceVal);
    void setAgility(int agilityVal);
    void incrementStrength();
    void incrementIntelligence();
    void incrementAgility();
};

#endif // PLAYER_H

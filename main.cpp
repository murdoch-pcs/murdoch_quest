#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "./Player.h"

int main(){
    Player player1;

    do {
        std::cout << "Enter a character name: ";
        player1.inputName();
        system("CLS");

        if (player1.getName().length() > 10){
            std::cout << "ERROR! Max character limit is 10." << std::endl;
        } else if (player1.getName().length() == 0) {
            std::cout << "ERROR! Minimum character limit is 1." << std::endl;
        }

    } while (player1.getName().length() > 10 || player1.getName().length() == 0);

    do {
        std::cout << "Choose a class... [Warrior | Mage | Thief]: ";
        player1.inputCurrentClass();
        system("CLS");

        if (player1.getCurrentClass()!= "Warrior" && player1.getCurrentClass() != "Mage" && player1.getCurrentClass() != "Thief"){
            std::cout << "ERROR! Invalid choice." << std::endl;
        }

    } while (player1.getCurrentClass() != "Warrior" && player1.getCurrentClass() != "Mage" && player1.getCurrentClass() != "Thief");

    if (player1.getCurrentClass() == "Warrior"){
        player1.setStrength(12);
        player1.setIntelligence(4);
        player1.setAgility(8);
    } else if (player1.getCurrentClass() == "Mage"){
        player1.setStrength(4);
        player1.setIntelligence(12);
        player1.setAgility(8);
    } else {
        player1.setStrength(4);
        player1.setIntelligence(8);
        player1.setAgility(12);
    }

    std::cout << "Starting attributes... [Strength: " << player1.getStrength() << " | Intelligence: " << player1.getIntelligence();
    std::cout << " | Agility: " << player1.getAgility() << " ]" << std::endl;

    std::cout << std::endl << "Press ENTER to roll a D6...";
//    std::cin.ignore();
    std::cin.get();
    system("CLS");

    // dice roll loading screen
    std::string rollingSprites [] = {"Rolling.", "Rolling..", "Rolling..."};
    for (std::string s : rollingSprites){
        std::cout << s << std::endl;
        Sleep(1000);
        system("CLS");
    }

    std::string diceSprites [] = {" _______\n|      	|\n|   o 	|\n|      	|\n|_______|\n",
    " _______\n| o     |\n|       |\n|     o |\n|_______|\n", " _______\n| o     |\n|   o   |\n|     o |\n|_______|\n",
    " _______\n| o   o |\n|       |\n| o   o |\n|_______|\n", " _______\n| o   o |\n|   o   |\n| o   o |\n|_______|\n",
    " _______\n| o   o |\n| o   o |\n| o   o |\n|_______|\n"};

    // roll dice
    srand(time(0));
    int diceRoll {};
    diceRoll = 1 + (rand() % 6);

    std::cout << diceSprites[diceRoll - 1];

    std::cout << "You rolled a " << diceRoll << std::endl;

    std::cout << std::endl << "You have " << diceRoll << " points to assign to your attributes." << std::endl;

    std::cout << std::endl << "Press ENTER to continue...";
    std::cin.ignore();
    std::cin.get();
    system("CLS");

    std::string pointCount [6] = {"first", "second", "third", "fourth", "fifth", "sixth"};

    std::string attributeChoice {};

    for (int i = 1; i <= diceRoll; i++){
        do {
            std::cout << "Where would you like to assign your " << pointCount[i - 1]  << " point(s)? [Strength | Intelligence | Agility]: ";
            std::cin >> attributeChoice;
            system("CLS");

            if (attributeChoice != "Strength" && attributeChoice != "Intelligence" && attributeChoice != "Agility"){
                std::cout << "ERROR! Invalid choice." << std::endl;
            }

        } while (attributeChoice != "Strength" && attributeChoice != "Intelligence" && attributeChoice != "Agility");

        if (attributeChoice == "Strength"){
            player1.incrementStrength();
        } else if (attributeChoice == "Intelligence"){
            player1.incrementIntelligence();
        } else {
            player1.incrementAgility();
        }
    }

    std::cout << "Current attributes... [Strength: " << player1.getStrength() << " | Intelligence: " << player1.getIntelligence();
    std::cout << " | Agility: " << player1.getAgility() << " ]" << std::endl;

    return 0;
}

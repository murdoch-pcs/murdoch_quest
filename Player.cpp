#include <iostream>
#include "Player.h"
#include <string>

Player::Player()
{
}

Player::~Player()
{
}

void Player::inputName(){
    std::getline(std::cin, name);
}

void Player::inputCurrentClass(){
    std::getline(std::cin, currentClass);
}

std::string Player::getName(){
    return name;
}

std::string Player::getCurrentClass(){
    return currentClass;
}

int Player::getStrength(){
    return strength;
}

int Player::getIntelligence(){
    return intelligence;
}

int Player::getAgility(){
    return agility;
}

void Player::setStrength(int strengthValue){
    strength = strengthValue;
}

void Player::setIntelligence(int intelligenceValue){
    intelligence = intelligenceValue;
}

void Player::setAgility(int agilityValue){
    agility = agilityValue;
}

void Player::incrementStrength(){
    strength++;
}

void Player::incrementIntelligence(){
    intelligence++;
}

void Player::incrementAgility(){
    agility++;
}
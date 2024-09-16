#include "Hero.h"

Hero::Hero(){}

Hero::Hero(int lives){
    playerLives = lives;
    playerCoins = 0;
    playerPower = 0;
    playerKills = 0;
    arr = new int[2]; //array that represents mario's loc
}

Hero::~Hero(){
    delete arr;
}

int Hero::getCoins(){
    return playerCoins;
}

int Hero::getPower(){
    return playerPower;
}

void Hero::setLoc(int position1, int position2){
    pos1 = position1;
    pos2 = position2;
}

int* Hero::getLoc(){
    arr[0] = pos1;
    arr[1] = pos2;
    return arr;
}

void Hero::mushroom(){ //mario gets mushroom
    if(playerPower != 2){ //only lets mario level up if he doesnt have 2 power
        ++playerPower;
    }
}

void Hero::coin(){ //mario gets a coin
    ++playerCoins;
    if(playerCoins == 20){ //lives mario a life if he has enough coins and then resets his coin count
        playerCoins = 0;
        ++playerLives;
    }
}

bool Hero::goomba(){ //mario fights a goomba
    int winChance = rand() % 100;
    if(winChance <= 80){ //if mario withs the 80% chance
        return kill();
    }
    else{
        getHit();
        return false;
    }
}

bool Hero::kill(){ //mario gets a kill
    ++monsterKills; //counts number of monsters he has killed
    if(monsterKills == 7){ // if mario has killed 7, resets numOfKills nad adds a life
        monsterKills = 0;
        ++playerLives;
    }
    return true;
}

bool Hero::koopa(){ //mario fights koopa
    int winChance = rand() % 100;
    if(winChance <= 65){
        return kill();
    }
    else{
        getHit();
        return false;
    }
}

bool Hero::boss(){ //mario fights a boss
    int winChance;
    while(playerLives > 0){
        winChance = rand() % 100;
        if(winChance <= 50){
            return kill();
        }
        else{
            getHitBoss();
        }
    }
    return false;
}

void Hero::getHitBoss(){ //mario gets hit by a boss
    if(playerPower <= 1){ //if he doesn't have 2 power, he gets set to 0 power and loses life
        playerPower = 0; 
        --playerLives;
    }
    else{
        playerPower -= 2; //if he has 2 power, loses 2 power
    }
}

void Hero::getHit(){
    if(playerPower == 0){ //if he doesn't have power he loses a life
        --playerLives;
    }
    else{ //if he does he loses a power
        --playerPower;
    }
}

int Hero::getLives(){
    return playerLives;
}
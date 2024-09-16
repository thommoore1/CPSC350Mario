#ifndef HERO_H
#define HERO_H

#include <iostream>
using namespace std;

class Hero{
    public:
        Hero();
        Hero(int lives);
        ~Hero();

        bool fight(char type);
        bool goomba();
        bool koopa();
        bool boss();
        void setLoc(int position1, int position2);
        void mushroom();
        void coin();
        int* getLoc();
        int getLives();
        int getPower();
        int getCoins();
    private:
        int monsterKills;
        bool kill();
        void getHit();
        void getHitBoss();
        unsigned int playerCoins;
        unsigned int playerKills;
        int playerPower;
        int playerLives;
        int pos1;
        int pos2;
        int *arr;
};

#endif
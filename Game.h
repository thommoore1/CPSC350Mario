#ifndef GAME_H
#define GAME_H

#include <iostream>
using namespace std;

#include "FileOutputter.h"
#include "Level.h"
#include "Hero.h"

class Game{
    public:
        Game();
        Game(int level, int dimN, int lives, int coins, int nothing, int goomba, int koopa, int mushroom, string outputFileName);
        ~Game();
        void runGame();
    private:
        void wrapAround(int* marioMoveTry);
        void marioUpdate(int* marioMoveTry);
        void checkTiles(int* marioMoveTry);
        void directionVariable(int* marioMoveTry);

        FileOutputter* outputter;
        Level* levelGenerator;
        Hero* mario;
        char ***levels;

        bool warped;
        bool notOver;
        bool win;
        unsigned int numOfLev;
        unsigned int dimension;
        unsigned int initalLives;
        unsigned int turnCounter;
        unsigned int currLevel;
        int marioMove; //sometimes negative
};
#endif
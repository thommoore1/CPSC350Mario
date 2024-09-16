#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
using namespace std;

#include "Hero.h"
#include "FileOutputter.h"

class Level{
    public:
        Level();
        Level(int coins, int nothing, int goomba, int koopa, int mushroom, int dimensions, Hero* MarioPrt);
        ~Level();
        char** fillLevel(char** array3D, bool isFinal);
        int* moveMario(FileOutputter* fp);
        char** addMario(char** array3D);
    private:
        void fillRandomNumbers(char** levelArray);

        Hero* mario; //mario object
        int* marioNewLoc; //mario's new location
        int* marioLoc; //mario's location
        unsigned int coinsPer; //percentage of coins
        unsigned int nothingPer; //percentage of nothing tiles
        unsigned int goombaPer; //percentage of goombas
        unsigned int koopaPer; //oercentage of koopas
        unsigned int mushroomPer; //percentage of mushrooms
        unsigned int dims; //dimensions of levels
        int random_number; //random number
        int random_number2;
        
};

#endif
#ifndef FILEOUTPUTTER_H
#define FILEOUTPUTTER_H

#include <iostream>
#include <fstream>
using namespace std;


class FileOutputter{
    public:
        FileOutputter();
        ~FileOutputter();
        void printArray(char** levelArray, int arraySize);
        void level(int currLevel);
        void power(int power);
        void marioLoc(int* marioLoc);
        void coin();
        void mushroom();
        void goombaWin();
        void goombaLose();
        void koopaWin();
        void koopaLose();
        void bossWin();
        void bossLose();
        void empty();
        void warp();
        void livesAfter(int livesAfter);
        void coinsAfter(int coinsAfter);
        void marioNextMove(int marioMove);
        void win(int turnCounter);
        void lose(int turnCounter);
        void moves();
        void spawn();
        void initalLevelPrint(int i);
    private:
};

#endif
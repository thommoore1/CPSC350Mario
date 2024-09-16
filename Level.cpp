#include "Level.h"

Level::Level(){}

Level::~Level(){
    delete[] marioNewLoc;
    delete[] marioLoc;
}

Level::Level(int coins, int nothing, int goomba, int koopa, int mushroom, int dimensions, Hero* marioPtr){
    marioNewLoc = new int[2];
    marioLoc = new int[2];
    dims = dimensions;
    mario = marioPtr;
    coinsPer = (dimensions*dimensions)*(coins/100.0);
    nothingPer = (dimensions*dimensions)*(nothing/100.0);
    goombaPer = (dimensions*dimensions)*(goomba/100.0);
    koopaPer = (dimensions*dimensions)*(koopa/100.0);
    mushroomPer = (dimensions*dimensions)*(mushroom/100.0);
    random_number;
    random_number2;
    srand(time(nullptr)); //sets random seed for rand function
}

void Level::fillRandomNumbers(char** levelArray){ //used for randomly filling level
    random_number = rand() % dims;
    random_number2 = rand() % dims;
    while(levelArray[random_number][random_number2] != 'x'){ //if the tile it is replacing is not x, it re-does the random-ness until it is
        random_number = rand() % dims;
        random_number2 = rand() % dims;
    }
}

char** Level::fillLevel(char** levelArray, bool isFinal){
    for(int i = 0; i < dims; i++){ //fills array with blank tiles first
        for(int j = 0; j < dims; j++){
            levelArray[i][j] = 'x';
        }
    }
    //fills array with  tiles depending on what percentage they are supposed to be
    for(int k = 0; k < coinsPer; ++k){
        fillRandomNumbers(levelArray);
        levelArray[random_number][random_number2] = 'c'; 
    }
    for(int l = 0; l < goombaPer; ++l){
        fillRandomNumbers(levelArray);
        levelArray[random_number][random_number2] = 'g';
    }

    for(int l = 0; l < koopaPer; ++l){
        fillRandomNumbers(levelArray);
        levelArray[random_number][random_number2] = 'k';
    }

    for(int l = 0; l < mushroomPer; ++l){
        fillRandomNumbers(levelArray);
        levelArray[random_number][random_number2] = 'm';
    }

    fillRandomNumbers(levelArray);
    levelArray[random_number][random_number2] = 'b';

    if(!isFinal){
    fillRandomNumbers(levelArray);
    levelArray[random_number][random_number2] = 'w';
    }
    return levelArray;
}

char** Level::addMario(char** levelArray){
    fillRandomNumbers(levelArray);
    mario->setLoc(random_number, random_number2);
    levelArray[random_number][random_number2] = 'H';
}

int* Level::moveMario(FileOutputter* fp){ //randomly tryes to move mario up down left or right
    int marioMove = rand() % 4;
    marioLoc = mario->getLoc();
    if(marioMove == 0){ //move up
        marioNewLoc[1] = marioLoc[1] + 1;
        marioNewLoc[0] = marioLoc[0];
    }
    else if(marioMove == 1){ //move down
        marioNewLoc[1] = marioLoc[1] - 1;
        marioNewLoc[0] = marioLoc[0];
    }
    else if(marioMove == 2){ //move left
        marioNewLoc[0] = marioLoc[0] - 1;
        marioNewLoc[1] = marioLoc[1];
    }
    else{ //move right
        marioNewLoc[0] = marioLoc[0] + 1;
        marioNewLoc[1] = marioLoc[1];
    }

    return marioNewLoc;
}
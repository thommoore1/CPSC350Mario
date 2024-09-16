#include "FileOutputter.h"

FileOutputter::FileOutputter(){
    ofstream gameClear;
    gameClear.open("gameOutput.txt");
    gameClear << "";
    gameClear.close();
}

FileOutputter::~FileOutputter(){

}

void FileOutputter::printArray(char** levelArray, int arraySize){
    ofstream gameOutput;
    gameOutput.open("gameOutput.txt", ios::app);
    for(int i = 0; i < arraySize; ++i){
        for(int j = 0; j < arraySize; ++j){
            gameOutput << levelArray[i][j] << ' ';
        }
        gameOutput << endl;
    }
    gameOutput << endl;
    gameOutput.close();
}

void FileOutputter::spawn(){
    ofstream gameOutput;
    gameOutput.open("gameOutput.txt", ios::app);
    gameOutput << "Mario has spawned in" << endl;
    gameOutput.close();
}

void FileOutputter::initalLevelPrint(int i){
    ofstream gameOutput;
    gameOutput.open("gameOutput.txt", ios::app);
    gameOutput << "This is level: " << (i + 1) << endl;
    gameOutput.close();
}

void FileOutputter::level(int currLevel){
    ofstream gameOutput;
    gameOutput.open("gameOutput.txt", ios::app);
    gameOutput << "Current level is " << currLevel + 1 << endl;
    gameOutput.close();
}

void FileOutputter::power(int power){
    ofstream gameOutput;
    gameOutput.open("gameOutput.txt", ios::app);
    gameOutput << "Mario's power level before moving is " << power << endl;
    gameOutput.close();
}

void FileOutputter::marioLoc(int* marioLoc){
    ofstream gameOutput;
    gameOutput.open("gameOutput.txt", ios::app);
    gameOutput << "Mario's location is " << (marioLoc[1] + 1) << ", " << (marioLoc[0] + 1) << endl;
    gameOutput.close();
}

void FileOutputter::coin(){
    ofstream gameOutput;
    gameOutput.open("gameOutput.txt", ios::app);
    gameOutput << "Mario has got a coin" << endl;
    gameOutput.close();
}

void FileOutputter::mushroom(){
    ofstream gameOutput;
    gameOutput.open("gameOutput.txt", ios::app);
    gameOutput << "Mario got a mushroom" << endl;
    gameOutput.close();
}

void FileOutputter::goombaWin(){
    ofstream gameOutput;
    gameOutput.open("gameOutput.txt", ios::app);
    gameOutput << "Mario killed a goomba" << endl;
    gameOutput.close();
}

void FileOutputter::goombaLose(){
    ofstream gameOutput;
    gameOutput.open("gameOutput.txt", ios::app);
    gameOutput << "Mario lost to a goomba" << endl;
    gameOutput.close();
}
void FileOutputter::koopaWin(){
    ofstream gameOutput;
    gameOutput.open("gameOutput.txt", ios::app);
    gameOutput << "Mario killed a goomba" << endl;
    gameOutput.close();
}
void FileOutputter::koopaLose(){
    ofstream gameOutput;
    gameOutput.open("gameOutput.txt", ios::app);
    gameOutput << "Mario lost to a koopa" << endl;
    gameOutput.close();
}
void FileOutputter::bossWin(){
    ofstream gameOutput;
    gameOutput.open("gameOutput.txt", ios::app);
    gameOutput << "Mario killed a boss" << endl;
    gameOutput.close();
}

void FileOutputter::bossLose(){
    ofstream gameOutput;
    gameOutput.open("gameOutput.txt", ios::app);
    gameOutput << "Mario lost to a boss" << endl;
    gameOutput.close();
}
void FileOutputter::empty(){
    ofstream gameOutput;
    gameOutput.open("gameOutput.txt", ios::app);
    gameOutput << "Mario moved to a blank tile" << endl;
    gameOutput.close();
}
void FileOutputter::warp(){
    ofstream gameOutput;
    gameOutput.open("gameOutput.txt", ios::app);
    gameOutput << "Mario warped to the next level" << endl;
    gameOutput.close();
}

void FileOutputter::livesAfter(int marioLives){
    ofstream gameOutput;
    gameOutput.open("gameOutput.txt", ios::app);
    gameOutput << "Mario has " << marioLives << " lives" << endl;
    gameOutput.close();
}

void FileOutputter::coinsAfter(int marioCoins){
    ofstream gameOutput;
    gameOutput.open("gameOutput.txt", ios::app);
    gameOutput << "Mario has " << marioCoins << " coins" << endl;
    gameOutput.close();
}
void FileOutputter::marioNextMove(int marioMove){
    ofstream gameOutput;
    gameOutput.open("gameOutput.txt", ios::app);
    gameOutput << "Mario ";
    if(marioMove == 0){
        gameOutput << "moved down" << endl;
    }
    else if(marioMove == 1){
        gameOutput << "moved up" << endl;
    }
    else if(marioMove == 2){
        gameOutput << "moved right" << endl;
    }
    else if(marioMove == 3){
        gameOutput << "movedleft" << endl;
    }
    else{
        gameOutput << "moved to stay put" << endl;
    }
    gameOutput.close();
}

void FileOutputter::win(int turnCount){
    ofstream gameOutput;
    gameOutput.open("gameOutput.txt", ios::app);
    gameOutput << "Mario wins" << endl;
    gameOutput << "It took " << turnCount << " turns to get here";
    gameOutput.close();
}

void FileOutputter::lose(int turnCount){
    ofstream gameOutput;
    gameOutput.open("gameOutput.txt", ios::app);
    gameOutput << "Mario loses" << endl;
    gameOutput << "It took " << turnCount << " turns to get here";
    gameOutput.close();
}

void FileOutputter::moves(){
    ofstream gameOutput;
    gameOutput.open("gameOutput.txt", ios::app);
    gameOutput << "Mario loses" << endl;
    gameOutput.close();
}
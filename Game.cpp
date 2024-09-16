#include "Game.h"

Game::Game(){}

//TODO: Figure out if I need to check if all % add too 100

Game::~Game(){
    delete mario;

    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            delete[] levels[i][j];
        }
        delete[] levels[i];
    }
    delete outputter;
    delete[] levels;
    delete levelGenerator;
}

Game::Game(int level, int dimN, int lives, int coins, int nothing, int goomba, int koopa, int mushroom, string outputFileName){
    marioMove = 0; //represents the direction (or lack of) that mario is moving for the outputter to know what to pring
    currLevel = 0; //current level
    turnCounter = 0; //many turns have passed
    dimension = dimN; //dimensions of each level
    numOfLev = level; //total number of levels
    warped = false; //tracks if mario is moving to the next level
    notOver = true; //tracks if the game has finished
    win = true; //tracks if the game has been won

    outputter = new FileOutputter(); //main object for outputting to output file
    mario = new Hero(lives); //represents mario
    levelGenerator = new Level(coins, nothing, goomba, koopa, mushroom, dimN, mario); //main object for setting up and managing level

    levels = new char**[dimN]; //3d array and loop to set up size
    for (int i = 0; i < dimN; ++i) {
        levels[i] = new char*[dimN];
        for (int j = 0; j < dimN; ++j) {
            levels[i][j] = new char[numOfLev];
        }
    }

    bool finalCheck = false; //lets the levelGenerator know if its the final level so it doesnt add a warp pipe
    for(int h = 0; h < numOfLev; ++h){ //fills the levels
        if(h == numOfLev - 1){
            finalCheck = true;
        }
        levelGenerator->fillLevel(levels[h], finalCheck);
    }
    for(int i = 0; i < numOfLev; ++i){ //prints all the levels without mario
        outputter->initalLevelPrint(i);
        outputter->printArray(levels[i], dimension);
    }
}

void Game::runGame(){ //main game running function
    int* marioMoveAttempt = new int[2]; //mario's attempted move
    levelGenerator->addMario(levels[currLevel]); //adds mario to level1
    marioMoveAttempt = levelGenerator->moveMario(outputter); //fills array with move up, right, left, or down

    while(notOver){ //loops over and over to run the game until a win or loss
        outputter->level(currLevel); //outputs currentlevel
        checkTiles(marioMoveAttempt); //checks where mario is moving and does certain things depending on what is there
        marioMoveAttempt = levelGenerator->moveMario(outputter); //fills array with move up, right, left, or down
    }

    if(win){
        outputter->win(turnCounter); //outputs if mario wins
    }
    else{
        outputter->lose(turnCounter); //outputs if mario loses
    }

    delete[] marioMoveAttempt;
}

void Game::marioUpdate(int* marioMoveTry){//moves mario to new tile and replaces his old one with a blank tile and outputs some of his data
    levels[currLevel][mario->getLoc()[0]][mario->getLoc()[1]] = 'x'; 
    mario->setLoc(marioMoveTry[0], marioMoveTry[1]); //sets mario's internal location array
    levels[currLevel][mario->getLoc()[0]][mario->getLoc()[1]] = 'H';
    outputter->marioLoc(mario->getLoc()); //prints mario's loc
    outputter->power(mario->getPower()); //prints mario's power
}

void Game::directionVariable(int* marioMoveTry){ //sets marioMove variable to denote where he is going for output
    if(marioMoveTry[0] > mario->getLoc()[0]){
        marioMove = 0;
    }
    else if(marioMoveTry[0] < mario->getLoc()[0]){
        marioMove = 1;
    }
    else if(marioMoveTry[1] > mario->getLoc()[1]){
        marioMove = 2;
    }
    else if(marioMoveTry[1] < mario->getLoc()[1]){
        marioMove = 3;
    }
}

void Game::wrapAround(int* marioMoveTry){ //if mario tries to go over the array size, loops around
    if(marioMoveTry[0] == dimension){
        marioMoveTry[0] = 0;
    }

    if(marioMoveTry[0] == -1){
        marioMoveTry[0] = dimension - 1;
    }

    if(marioMoveTry[1] == dimension){
        marioMoveTry[1] = 0;
    }

    if(marioMoveTry[1] == -1){
        marioMoveTry[1] = dimension - 1;
    }
}

void Game::checkTiles(int* marioMoveTry){ //checks where mario is going and updates variables depending on that
    warped = false; //resets this variable incase its been changed

    directionVariable(marioMoveTry); //alters variable for what direction kario went
    wrapAround(marioMoveTry); //makes sure thers no index out of bounds

    if(turnCounter == 0){ //if its turn one mario does some things a little differently
        outputter->marioLoc(mario->getLoc()); //outputs mario's loc
        outputter->power(mario->getPower()); //outputs mario's power
        outputter->spawn(); //outputs mario's spawn message
    }
    else if(levels[currLevel][marioMoveTry[0]][marioMoveTry[1]] == 'x'){//if mario tries to move to a blank tile
        marioUpdate(marioMoveTry); //updates mario's loc
        outputter->empty(); //outputs nothing message
    }
    else if(levels[currLevel][marioMoveTry[0]][marioMoveTry[1]] == 'm'){ //if mario tries to move to a mushroom
        marioUpdate(marioMoveTry); //ipdates mario's loc
        mario->mushroom(); //gives mario a mushroom
        outputter->mushroom(); //gain mushroom message
    }
    else if(levels[currLevel][marioMoveTry[0]][marioMoveTry[1]] == 'c'){ //if mario tries to move to coin
        marioUpdate(marioMoveTry); //updates mario's loc
        mario->coin(); //gives mario coin
        outputter->coin(); //coin message
    }
    else if(levels[currLevel][marioMoveTry[0]][marioMoveTry[1]] == 'g'){ //if mario tries to move to goomba
        if(mario->goomba()){ //if he wins
            marioUpdate(marioMoveTry); //updates mario's loc
            outputter->goombaWin(); //outputs goomba win message
        }
        else{ //if he loses
            if(mario->getLives() == 0){ //if hes out of lives
                notOver = false; //ends while loop
                win = false; //lets outputter know mario is staying put
                outputter->goombaLose(); //goomba lose message
                marioMove = -1; //lets outputter know mario is staying put
            }
            else{ //if he has enough lives
                outputter->goombaLose(); //outputs goomba win message
                marioMove = -1; //lets outputter know mario is staying put
            }
        }
    }
    else if(levels[currLevel][marioMoveTry[0]][marioMoveTry[1]] == 'k'){ // if mario tries to move to koopa
        if(mario->koopa()){ //if he wins
            marioUpdate(marioMoveTry); //updates mario's location
            outputter->koopaWin(); //outputs koopa win message
        }
        else{ //if he loses
            if(mario->getLives() == 0){ //if hes out of lives
                notOver = false; //ends while loop
                marioMove = -1; //lets outputter know mario is staying put
                win = false; //lets outputter output that mario lost
                outputter->koopaLose(); //outputs koopa lose message
            }
            else{ //if he has enough lives
                outputter->koopaLose(); //outputs koopa lose message
                marioMove = -1; //lets outputter know mario is staying put
            }
        }
    }
    else if(levels[currLevel][marioMoveTry[0]][marioMoveTry[1]] == 'b'){ //if mario fights a boss
        if(mario->boss() == true){ //if mario wins
            marioUpdate(marioMoveTry); //updates mario's location
            if(currLevel != numOfLev - 1){ //if mario is not on last level
                ++currLevel; //moves to next level
                levelGenerator->addMario(levels[currLevel]); //adds mario to next level
                outputter->bossWin(); //outputs boss win message
            }
            else{ //if it is the last level
                notOver = false; //ends while loop
                outputter->bossWin();
            }
        }
        else{ //if mario loses
                outputter->bossLose(); //outputs boss loss message
                notOver = false; //ends while loop
                win = false; //lets outputter output that mario lost
        }
    }
    else if(levels[currLevel][marioMoveTry[0]][marioMoveTry[1]] == 'w'){ //if mario hits warp pipe
        marioUpdate(marioMoveTry); //moves mario
        ++currLevel; //moves up a level
        levelGenerator->addMario(levels[currLevel]); //adds mario to next level
        warped = true; //this is for a check that makes sure that outputter doesnt accidentally output the next array instead of the current one
        outputter->warp(); //outputs warp message
    }

    outputter->livesAfter(mario->getLives()); //prints mario's lives after everything
    outputter->coinsAfter(mario->getCoins()); //prints mario's coins after everything
    if(turnCounter != 0){ //if its not turn one, outputs mario's next move
        outputter->marioNextMove(marioMove);
    }

    if(warped){ //if mario warped, it moved the currLevel variable up earlier, so the program has to go back one to print the current level if mario did warp
        outputter->printArray(levels[currLevel - 1], dimension); //prints array
    }
    else{
        outputter->printArray(levels[currLevel], dimension); //prints array
    }

    int marioMove = -1; //resets variable
    ++turnCounter; //counts turn
}

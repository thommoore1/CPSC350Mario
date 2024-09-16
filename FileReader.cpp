#include "FileReader.h"

FileReader::FileReader(string fileName, string outputFileName){
    int* gameData = new int[8]; //array for holding data from the input file
    Game* gameObject; //object that sets up and runs game
    string line; //string for reading input file
    int count = -1; //int for indexing through gameData
    ifstream readFile(fileName);
    
    if(readFile.is_open()){//reading file and adding it to array
        while(getline(readFile,line)){
            gameData[++count] = stoi(line);
        }
    }

    if(gameData[3] + gameData[4] + gameData[5] + gameData[6] + gameData[7] != 100){//checking that input adds to 100%
        cerr << "Your inputs do not add up to 100" << endl;
    }

    gameObject = new Game(gameData[0], gameData[1], gameData[2], gameData[3], gameData[4], gameData[5], gameData[6], gameData[7], outputFileName);
    gameObject->runGame();

    delete gameObject;
    delete[] gameData;

}

FileReader::~FileReader(){
    
}
#ifndef FILEREADER_H
#define FILEREADER_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Game.h"

class FileReader{
    public:
        FileReader();
        ~FileReader();
        FileReader(string fileName, string outputFileName);
    private:

};


#endif


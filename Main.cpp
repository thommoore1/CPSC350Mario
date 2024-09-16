#include "fileReader.h"

int main(int argc, char** argv){
    FileReader* fr = new FileReader(argv[1], argv[2]);
    delete fr;
}
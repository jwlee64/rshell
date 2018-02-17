#ifndef RSHELL_H
#define RSHELL_H

#include "cmd.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <cstdlib>
#include <fcntl.h>

using namespace std; 

class rshell {
    protected: 
        vector<CMD*> commands;
    public:
        rshell() : commands(0){};
        void run(); 
        void tokenize(char inputLine[]);
};

#endif 

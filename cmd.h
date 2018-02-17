#ifndef __CMD_H__
#define __CMD_H__

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

class CMD{
    protected:
        string str;
        bool alreadyRun;
        
    public:
        CMD(): str(""), alreadyRun(false) {}
        virtual bool execute(bool& itr) = 0 ;
        virtual string type() = 0;
        string showString();
};

class Exec : public CMD {
        
    public:
        Exec(string name);
        bool execute(bool& itr);
        string type();
};

class Con : public CMD {
    public:
        Con(string name);
        bool execute(bool& itr);
        string type();
};

#endif

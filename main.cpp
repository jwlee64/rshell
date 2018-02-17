#include "cmd.h"
#include "cmd.cpp"
#include "rshell.h"
#include "rshell.cpp"

using namespace std;

int main()
{
    char in[] = "echo a && echo b || echo c && echo d && echo e; echo f";
    rshell shell;
    shell.run();
    return 0;
}


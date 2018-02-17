#include "cmd.h"

string CMD::showString(){
    return str;
}

Exec::Exec(string name){
    str=name;
    alreadyRun=false;
}

string Exec::type(){
    return "EXEC";
}

Con::Con(string name){
    str=name;
    alreadyRun=false;
}

string Con::type(){
    return "CON";
}

bool Exec::execute(bool & itr)
{
    if (!itr)
    {
        return false;
    }
    
    if (str == "exit") {    //secondary exit command in attempt to fix exit bug
        std::abort(); 
    }
    
    bool returner = true;
    char** commandAr = new char*[1000]; 
    string temp = str.substr(0,str.find(" "));
    char *execName = new char[str.length()];
    char *arg = new char[str.length()];
    strcpy(execName,temp.c_str());
    unsigned i = 1; 
    
    commandAr[0] = execName;
    
    while (str.find(" ") < 1000) {
        temp = str.substr(0, str.find(" ")); 
        strcpy(arg, temp.c_str());
        commandAr[i] = arg; 
        i++;
        str.erase(0,str.find(" ") + 1);
    }
    
    if(!str.empty())
    {
        temp = str;
        char *com = new char[str.length()];
        strcpy(com,temp.c_str());
        commandAr[i] = com;
    }
    
    
    commandAr[i+1] = NULL; 
    
    pid_t pid = fork(); 
    
    if (pid == -1)
    {
        perror("Fork failed");
        returner = false; 
    }
    else if (pid == 0 && execvp(execName, commandAr)) 
    {
        perror("Execute failed");
        returner = false; 
    }
    else if (pid > 0)
    {
        if (wait(0) == -1) 
        {
            perror("Wait failed"); 
            returner = false; 
        }
    }
    delete[] commandAr;
    delete[] execName;
    delete[] arg;
    
    return returner; 
}

bool Con::execute(bool & itr){
    if (str == "&&" && itr)
    {
        return true;
    }
    else if (str == "||" && !itr)
    {
        return true;
    }
    else if (str == ";")
    {
        return true;
    }
    return false;
}

#include "cmd.h"
#include "rshell.h"

void rshell::tokenize(char inputLine[])
{
    string command;
    char * pch = strtok(inputLine," ");
    while (pch)
    {
        string temp(pch);
        if (temp == "&&")
        {
            commands.push_back(new Exec(command));
            commands.push_back(new Con(temp));
            command = "";
        }
        else if (temp == "||")
        {
            commands.push_back(new Exec(command));
            commands.push_back(new Con(temp));
            command = "";
        }
        else if (temp.find(";") != string::npos)
        {
            command = command + " " + temp.substr(0, temp.size()-1);
            commands.push_back(new Exec(command));
            commands.push_back(new Con(temp));
            command = "";
        }
        else if (temp.find("#") != string::npos)
        {
            commands.push_back(new Exec(command));
            commands.push_back(new Exec("#"));
            commands.push_back(new Exec(temp.substr(1, temp.size())));
            command = "";
        }
        else 
        {
            if (command == "")
            {
                command = temp;
            }
            else 
            {
                command = command + " " + temp;
            }
        }
        pch = strtok(NULL, " ");
    }
    commands.push_back(new Exec(command));
}

void rshell::run() 
{
    string input;
    while(true)
    {
    	cout << "$";
    	getline(cin, input);
    	char ar[input.size()];
    	strcpy(ar, input.c_str()); 
        tokenize(ar);
        
    	bool ToRun = true; 
    	for (int a = 0; a < commands.size(); a++)
    	{
    		if(commands.at(a)->showString() == "#")
    			break;
    		if (commands.at(a)->showString() ==  "exit")
    			{ cout <<"exit rshell"; return ;}
    		ToRun = commands.at(a)->execute(ToRun);
        }
        commands.clear();
    }
}


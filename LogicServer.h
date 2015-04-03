//
//  LogicServer.h
//  Server
//
//  Created by Sergey Koldaev on 02/04/15.
//  Copyright (c) 2015 Sergey Koldaev. All rights reserved.
//

#ifndef __Server__LogicServer__
#define __Server__LogicServer__

#include <iostream>
#include <string>
#include <vector>

#include "SocketCommand.h"
#include "DiodSetRateCommand.h"
#include "DiodSetStateCommand.h"
#include "DiodSetColorCommand.h"

#include "DiodGetRateCommand.h"
#include "DiodGetStateCommand.h"
#include "DiodGetColorCommand.h"

using namespace std;

class LogicServer{
private:
    typedef struct {
        SocketCommand* cmd;
        string name;
        string id;
    } Command;
    
    vector<Command> commands;
    string responce_data;
public:
    LogicServer(){
        this->registerCommand("1212", "DiodGetRateCommand", new DiodGetRateCommand());
        this->registerCommand("1213", "DiodSetRateCommand", new DiodSetRateCommand());
        this->registerCommand("2212", "DiodGetStateCommand", new DiodGetStateCommand());
        this->registerCommand("1242", "DiodSetStateCommand", new DiodSetStateCommand());
        this->registerCommand("1112", "DiodGetColorCommand", new DiodGetColorCommand());
        this->registerCommand("3422", "DiodSetColorCommand", new DiodSetColorCommand());
    }
    
    ~LogicServer(){
        vector<Command>::iterator it;
        for (it = commands.end(); it != commands.begin(); it--){
            delete it->cmd;
            commands.pop_back();
        }
    }
    
    void registerCommand(string id, string name, SocketCommand* cmd);
    void request(string cmd, string data);
    string responce(){return responce_data;};
};


#endif /* defined(__Server__LogicServer__) */

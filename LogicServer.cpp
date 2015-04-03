//
//  LogicServer.cpp
//  Server
//
//  Created by Sergey Koldaev on 02/04/15.
//  Copyright (c) 2015 Sergey Koldaev. All rights reserved.
//

#include "LogicServer.h"

void LogicServer::registerCommand(string id, string name, SocketCommand* cmd){
    Command s = {
        .cmd = cmd,
        .name = name,
        .id = id
    };
    commands.push_back(s);
}

void LogicServer::request(string cmd, string data){
    vector<Command>::iterator it;
    try{
        for(it = commands.begin(); it != commands.end(); it++){
            if (cmd == it->id){
                it->cmd->request(data);
                this->responce_data = it->cmd->responce();
                return;
            }
        }
    }catch(exception* ex){
        cout << "Error in module " << it->name << "\n Exception: " << ex->what() << "\n" << endl;
    }
    
    cout<< "Command " << cmd << " doesn't exists!" << endl;
    
    this->responce_data = "STATUS FAILED\n";
}
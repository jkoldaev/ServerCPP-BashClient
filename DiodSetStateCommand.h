//
//  DiodSetStateCommand.h
//  Server
//
//  Created by Sergey Koldaev on 02/04/15.
//  Copyright (c) 2015 Sergey Koldaev. All rights reserved.
//

#ifndef Server_DiodSetStateCommand_h
#define Server_DiodSetStateCommand_h

#include "FakeDiodCApi.h"
#include "SocketCommand.h"

#include <algorithm>

class DiodSetStateCommand : public SocketCommand{

    virtual bool request(string data){
        this->responce_data = "STATUS ";
        string tmp = data;
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        tmp.erase(std::remove(tmp.begin(),tmp.end(),' '),tmp.end());
        tmp.erase(std::remove(tmp.begin(),tmp.end(),'\t'),tmp.end());
        tmp.erase(std::remove(tmp.begin(),tmp.end(),'\n'),tmp.end());
        tmp.erase(std::remove(tmp.begin(),tmp.end(),'\r'),tmp.end());

        char value = -1;
        if (tmp == "on"){
            value = 1;
        }else if (tmp == "off"){
            value = 0;
        }
        
        if (value < 0){
            this->responce_data += "FAILED\n";
            return false;
        }
        
        diod_setState(value);
        if (diod_getState() != value){
            this->responce_data += "FAILED\n";
            return false;
        }
        
        this->responce_data += "OK\n";
        return true;
    }
    
};

#endif

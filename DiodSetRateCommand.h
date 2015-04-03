//
//  DiodSetRateCommand.h
//  Server
//
//  Created by Sergey Koldaev on 02/04/15.
//  Copyright (c) 2015 Sergey Koldaev. All rights reserved.
//

#ifndef Server_DiodSetRateCommand_h
#define Server_DiodSetRateCommand_h

#include "FakeDiodCApi.h"
#include "SocketCommand.h"

class DiodSetRateCommand : public SocketCommand{

    virtual bool request(string data){
        this->responce_data = "STATUS ";
        string tmp = data;
        tmp.erase(std::remove(tmp.begin(),tmp.end(),' '),tmp.end());
        tmp.erase(std::remove(tmp.begin(),tmp.end(),'\t'),tmp.end());
        tmp.erase(std::remove(tmp.begin(),tmp.end(),'\n'),tmp.end());
        tmp.erase(std::remove(tmp.begin(),tmp.end(),'\r'),tmp.end());
        
        char value = atoi(&tmp.c_str()[0]);
        
        if (value < 0 || value > 5){
            this->responce_data += "FAILED\n";
            return false;
        }
        
        diod_setRate(value);
        if (diod_getRate() != value){
            this->responce_data += "FAILED\n";
            return false;
        }
        
        this->responce_data += "OK\n";
        return true;
    }
};

#endif

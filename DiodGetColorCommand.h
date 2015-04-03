//
//  DiodGetColorCommand.h
//  Server
//
//  Created by Sergey Koldaev on 02/04/15.
//  Copyright (c) 2015 Sergey Koldaev. All rights reserved.
//

#ifndef Server_DiodGetColorCommand_h
#define Server_DiodGetColorCommand_h

#include "FakeDiodCApi.h"
#include "SocketCommand.h"

class DiodGetColorCommand : public SocketCommand{
    
    virtual bool request(string data){
        this->responce_data = "STATUS ";
        int value = diod_getColor();
        if (value == RED){
            this->responce_data += "OK red\n";
        }else if (value == GREEN){
            this->responce_data += "OK green\n";
        }else if (value == BLUE){
            this->responce_data += "OK blue\n";
        }else{
            this->responce_data += "FAILED\n";
            return false;
        }
        
        return true;
    }
};

#endif

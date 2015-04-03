//
//  DiodGetStateCommand.h
//  Server
//
//  Created by Sergey Koldaev on 02/04/15.
//  Copyright (c) 2015 Sergey Koldaev. All rights reserved.
//

#ifndef Server_DiodGetStateCommand_h
#define Server_DiodGetStateCommand_h

#include "FakeDiodCApi.h"
#include "SocketCommand.h"

class DiodGetStateCommand : public SocketCommand{
    
    virtual bool request(string data){
        this->responce_data = "STATUS ";
        char value = diod_getState();
        if (value < 0 || value > 1){
            this->responce_data += "FAILED\n";
            return false;
        }
        
        if (value){
            this->responce_data += "OK on\n";
        }else{
            this->responce_data += "OK off\n";
        }
        
        return false;
    }
};

#endif

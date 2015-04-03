//
//  DiodGetRateCommand.h
//  Server
//
//  Created by Sergey Koldaev on 02/04/15.
//  Copyright (c) 2015 Sergey Koldaev. All rights reserved.
//

#ifndef Server_DiodGetRateCommand_h
#define Server_DiodGetRateCommand_h

#include "FakeDiodCApi.h"
#include "SocketCommand.h"

#include <iostream>
#include <sstream>

using namespace std;

class DiodGetRateCommand : public SocketCommand{

    virtual bool request(string data){
        this->responce_data = "STATUS ";
        const int value = (int)diod_getRate();
        if (value < 0 || value > 5){
            this->responce_data += "FAILED\n";
            return false;
        }

        ostringstream str;
        str << "OK " << value << "\n";
        this->responce_data += str.str();
        return true;
    }
};

#endif

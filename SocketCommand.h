//
//  SocketCommand.h
//  Server
//
//  Created by Sergey Koldaev on 02/04/15.
//  Copyright (c) 2015 Sergey Koldaev. All rights reserved.
//

#ifndef __Server__SocketCommand__
#define __Server__SocketCommand__

#include <iostream>
#include <string>

using namespace std;

class SocketCommand{
protected:
    string responce_data;
public:
    const string responce(){return this->responce_data;}
    virtual bool request(string data){return false;}
};

#endif /* defined(__Server__SocketCommand__) */

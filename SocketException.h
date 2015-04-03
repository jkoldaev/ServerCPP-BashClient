//
//  SocketException.h
//  Server
//
//  Created by Sergey Koldaev on 02/04/15.
//  Copyright (c) 2015 Sergey Koldaev. All rights reserved.
//

#ifndef Server_SocketException_h
#define Server_SocketException_h

#include <string>

class SocketException
{
public:
    SocketException ( std::string s ) : m_s ( s ) {};
    ~SocketException (){};
    
    std::string description() { return m_s; }
    
private:
    
    std::string m_s;
    
};

#endif

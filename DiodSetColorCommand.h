//
//  DiodSetColorCommand.h
//  Server
//
//  Created by Sergey Koldaev on 02/04/15.
//  Copyright (c) 2015 Sergey Koldaev. All rights reserved.
//

#ifndef Server_DiodSetColorCommand_h
#define Server_DiodSetColorCommand_h

#include "FakeDiodCApi.h"
#include "SocketCommand.h"

static long hashString(const char* s){
    const long hash = 5323;
    long value = hash;
    while (*s) {
        value += value * hash + *s++;
    }
    return value;
}

class DiodSetColorCommand : public SocketCommand{

public:
    long redHash;
    long greenHash;
    long blueHash;
    
    DiodSetColorCommand(){
        redHash = hashString("red");
        greenHash = hashString("green");
        blueHash = hashString("blue");
    }
    
    virtual bool request(string data){
        this->responce_data = "STATUS ";
        string tmp = data;
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        tmp.erase(std::remove(tmp.begin(),tmp.end(),' '),tmp.end());
        tmp.erase(std::remove(tmp.begin(),tmp.end(),'\t'),tmp.end());
        tmp.erase(std::remove(tmp.begin(),tmp.end(),'\n'),tmp.end());
        tmp.erase(std::remove(tmp.begin(),tmp.end(),'\r'),tmp.end());
        
        long command = hashString(tmp.c_str());
        if (tmp == "red"){
            diod_setColor(RED);
            if (diod_getColor() == RED){
                this->responce_data += "OK\n";
                return true;
            }
        }else if (command == greenHash){
            diod_setColor(GREEN);
            if (diod_getColor() == GREEN){
                this->responce_data += "OK\n";
                return true;
            }
        }else if (command == blueHash){
            diod_setColor(BLUE);
            if (diod_getColor() == BLUE){
                this->responce_data += "OK\n";
                return true;
            }
        }
        
        this->responce_data += "FAILED\n";
        
        return false;
    }
};



#endif

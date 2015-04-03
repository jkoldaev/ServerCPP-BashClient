//
//  main.cpp
//  Server
//
//  Created by Sergey Koldaev on 01/04/15.
//  Copyright (c) 2015 Sergey Koldaev. All rights reserved.
//

#include "Server.h"

//c++

using namespace std;

int main(int argc, const char * argv[]) {

    try
    {
        if (argc < 2){
            std::cout << "Enter sever port: server [port]" << endl;
            return -1;
        }
        
        boost::asio::io_service io_service;
        
         // For atoi.
        Server(io_service, atoi(argv[1]));
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    
    return 0;
}

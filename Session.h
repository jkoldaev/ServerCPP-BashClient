//
//  Session.h
//  Server
//
//  Created by Sergey Koldaev on 02/04/15.
//  Copyright (c) 2015 Sergey Koldaev. All rights reserved.
//

#ifndef Server_Session_h
#define Server_Session_h

#include "LogicServer.h"

#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>

typedef boost::shared_ptr<boost::asio::ip::tcp::socket> socket_ptr;

const int max_length = 1024;

static LogicServer logicServer;

void session(socket_ptr sock)
{
    try
    {
        for (;;)
        {
            char data[max_length];
            
            boost::system::error_code error;
            size_t length = sock->read_some(boost::asio::buffer(data), error);
            if (error == boost::asio::error::eof){
                break;
            }
            else if (error){
                throw boost::system::system_error(error);
            }
            
            string responce_string("STATUS FAILED\n");
            string tmp_str(data);
            if (length > 4){
                string cmd = tmp_str.substr(0, 4);
                tmp_str = tmp_str.substr(4, length - 4);
                logicServer.request(cmd, tmp_str);
                responce_string = logicServer.responce();
            }
            
            if (boost::asio::write(*sock, boost::asio::buffer(responce_string.c_str(), responce_string.length()))){
                break;
            }
        }
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception in thread: " << e.what() << "\n";
    }
}

#endif

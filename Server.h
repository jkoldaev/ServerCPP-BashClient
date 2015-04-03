//
//  Server.h
//  Server
//
//  Created by Sergey Koldaev on 02/04/15.
//  Copyright (c) 2015 Sergey Koldaev. All rights reserved.
//

#ifndef Server_Server_h
#define Server_Server_h

#include "Session.h"

void Server(boost::asio::io_service& io_service, short port)
{
    cout << "Server running..." << endl;
    boost::asio::ip::tcp::acceptor a(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port));
    for (;;)
    {
        socket_ptr sock(new boost::asio::ip::tcp::socket(io_service));
        a.accept(*sock);
        boost::thread t(boost::bind(session, sock));
    }
}

#endif

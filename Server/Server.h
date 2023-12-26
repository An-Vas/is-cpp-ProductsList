//
// Created by user on 26.12.2023.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <boost/asio.hpp>
#include <iostream>
#include <boost/beast.hpp>
#include <memory>
#include "Session.h"

namespace http = boost::beast::http;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;

class Server {
private:
    tcp::acceptor acceptor_;
    tcp::socket socket_;
public:
    Server(net::io_context& ioc, tcp::endpoint endpoint) ;

    void start_accept() ;

};

#endif //SERVER_SERVER_H

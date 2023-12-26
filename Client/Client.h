
#ifndef CLIENT_CLIENT_H
#define CLIENT_CLIENT_H

#include <iostream>
#include <boost/asio.hpp>
#include <boost/beast.hpp>


namespace http = boost::beast::http;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;

class Client {
private:
    tcp::resolver resolver;
    tcp::socket socket_;
    net::io_context& ioc;
    http::response<http::dynamic_body> response;

public:
    Client (net::io_context& ioc, tcp::endpoint endpoint );
    std::string accept();
    void send(std::string msg);
    void restart();
};


#endif //CLIENT_CLIENT_H

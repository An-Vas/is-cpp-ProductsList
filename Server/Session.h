#ifndef SERVER_SESSION_H
#define SERVER_SESSION_H


#include <boost/asio.hpp>
#include <iostream>
#include <boost/beast.hpp>
#include <memory>
#include "Storage.h"

namespace http = boost::beast::http;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session> {
private:
    tcp::socket socket_;
    boost::beast::flat_buffer buffer_;
    http::request<http::dynamic_body> request_;
    http::response<http::dynamic_body> response_;
    Storage storage;

public:
    Session(tcp::socket socket);
    void start();

private:
    void read_request() ;
    void process_request() ;
    void buffer_consume();

};

#endif //SERVER_SESSION_H

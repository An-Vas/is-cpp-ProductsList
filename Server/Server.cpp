#include "Server.h"
Server::Server(net::io_context& ioc, tcp::endpoint endpoint) : acceptor_(ioc), socket_(ioc) {
    boost::system::error_code ec;

    acceptor_.open(endpoint.protocol(), ec);
    if (ec) {
        throw std::runtime_error("open: " + ec.message());
    }

    acceptor_.set_option(net::socket_base::reuse_address(true), ec);
    if (ec) {
        throw std::runtime_error("set_option: " + ec.message());
    }

    acceptor_.bind(endpoint, ec);
    if (ec) {
        throw std::runtime_error("bind: " + ec.message());
    }

    acceptor_.listen(net::socket_base::max_listen_connections, ec);
    if (ec) {
        throw std::runtime_error("listen: " + ec.message());
    }
}

void Server::start_accept() {
    acceptor_.async_accept(socket_,[this](boost::system::error_code ec) {
        if (!ec) {
            std::make_shared<Session>(std::move(socket_))->start();
            std::cout<<"New user!"<<"\n";

        }
        start_accept();
    });
}

#include <iostream>
#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include "Client.h"

namespace http = boost::beast::http;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;


Client::Client (net::io_context& ioc, tcp::endpoint endpoint): resolver(ioc), socket_(ioc), ioc(ioc){
    auto const results = resolver.resolve("localhost", "8080");
    net::connect(socket_, results.begin(), results.end());
}

std::string Client::accept() {
    boost::beast::flat_buffer buffer;
    http::response<http::dynamic_body> response;
    boost::system::error_code error;


    http::read(socket_, buffer, response, error);

    if (error) {
        if (error == boost::asio::error::eof) {
            std::cout << "Connection closed by server." << std::endl;
        } else {
            std::cerr << "Error reading answer: " << error.message() << std::endl;
        }
    }

    return boost::beast::buffers_to_string(response.body().data());

}

void Client::send(std::string msg){
    http::request<http::string_body> request{http::verb::post, "/", 11};
    request.set(http::field::host, "localhost");
    request.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
    request.version(11);
    request.method(http::verb::post);
    request.target("/");
    request.set(http::field::user_agent, "Beast");
    request.set(http::field::content_type, "text/plain");

    request.body() = msg;
    request.prepare_payload();

    http::write(socket_, request);

}

void Client::restart(){
    socket_.shutdown(boost::asio::socket_base::shutdown_both);
    socket_.close();

    resolver = tcp::resolver(ioc);
    auto const results = resolver.resolve("localhost", "8080");
    net::connect(socket_, results.begin(), results.end());

}
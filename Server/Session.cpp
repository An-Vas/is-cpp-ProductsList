#include "Session.h"

Session::Session(tcp::socket socket) : socket_(std::move(socket)), storage ("") {

}


void Session::start() {
    buffer_consume();
    read_request();
}

void Session::read_request() {
    auto self = shared_from_this();
    buffer_.consume(buffer_.size());
    buffer_.clear();

    http::async_read(socket_, buffer_, request_,
                     [this, self](boost::system::error_code ec, std::size_t bytes_transferred) {
                         if (!ec) {
                             std::cout << "Reading request: \n";
                             storage.data = boost::beast::buffers_to_string(request_.body().data());
                             std::cout << boost::beast::buffers_to_string(request_.body().data()) << " \n";
                             process_request();
                         }
                     });
}

void Session::process_request() {

    std::cout << "Sending response:\n";
    response_.version(request_.version());
    response_.result(http::status::ok);
    response_.set(http::field::server, "Echo Server");
    response_.set(http::field::content_type, "text/plain");
    response_.keep_alive(request_.keep_alive());
    response_.body() = request_.body();
    response_.prepare_payload();

    buffer_.consume(buffer_.size());
    std::cout << boost::beast::buffers_to_string(response_.body().data()) << " \n";

    auto self = shared_from_this();
    http::async_write(socket_, response_,
                      [this, self](boost::system::error_code ec, std::size_t bytes_transferred) {
                          if (!ec) {
                              buffer_.consume(buffer_.size());
                              response_.clear();
                              request_.clear();
                              read_request();

                          }
                      });

    buffer_.consume(buffer_.size());


}

void Session::buffer_consume(){
    buffer_.consume(buffer_.size());
}
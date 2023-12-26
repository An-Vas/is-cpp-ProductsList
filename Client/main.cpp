#include <iostream>
#include <boost/asio.hpp>

#include "Client.h"
#include "WindowSetup.h"


namespace http = boost::beast::http;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;


int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Russian");


    net::io_context ioc;
    Client client(ioc, {tcp::v4(), 8080});
    UserActivityHandler handler(client);
    WindowSetup windowSetup(argc, argv, handler);
    windowSetup.start_setup();

}

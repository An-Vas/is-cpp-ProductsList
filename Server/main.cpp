#include <boost/asio.hpp>
#include <iostream>
#include <boost/beast.hpp>
#include "Server.h"

namespace http = boost::beast::http;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;


int main() {
    try {
        net::io_context ioc(1);
        Server server(ioc, { tcp::v4(), 8080 });
        server.start_accept();
        ioc.run();
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;

}

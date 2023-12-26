#ifndef CLIENT_USERACTIVITYHANDLER_H
#define CLIENT_USERACTIVITYHANDLER_H

#include "Client.h"


class UserActivityHandler {
private:

    Client& client;
public:
    UserActivityHandler(Client& client);

    std::string handle_add_product (std::string product, int count);
    std::string handle_clear_list ();
};


#endif //CLIENT_USERACTIVITYHANDLER_H

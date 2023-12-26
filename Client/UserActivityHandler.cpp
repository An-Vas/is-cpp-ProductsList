
#include "UserActivityHandler.h"

std::string UserActivityHandler::handle_add_product (std::string product, int count){
    std::string req = product + " " + std::to_string(count)+ "\n";
    client.send(req);
    std::string res = client.accept();
    return res;
};

std::string UserActivityHandler::handle_clear_list (){
    std::string req = "clearlist";
    client.send(req);
    std::string res = client.accept();
    client.restart();
    return res;
};

UserActivityHandler::UserActivityHandler(Client& client): client(client){

}


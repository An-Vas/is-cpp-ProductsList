//
// Created by user on 21.01.2024.
//

#ifndef CLIENT_REQUEST_H
#define CLIENT_REQUEST_H


#include <string>
#include <list>
#include "ProductListItem.h"

class Request {
public:
    std::string type;
    std::string userId;
    std::list<ProductListItem> list;

};


#endif //CLIENT_REQUEST_H

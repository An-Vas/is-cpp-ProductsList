#ifndef CLIENT_RESPONSEHANDLER_H
#define CLIENT_RESPONSEHANDLER_H
#include <iostream>
#include <list>
#include "ResponseHandler.h"


class ResponseHandler {
public:
    static std::list<std::string> handle(const std::string& str);
};


#endif //CLIENT_RESPONSEHANDLER_H

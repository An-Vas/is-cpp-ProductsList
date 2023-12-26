#include "ResponseHandler.h"

std::list<std::string> ResponseHandler::handle(const std::string& str){
    std::string next;
    std::list<std::string> result;

    std::string::const_iterator it;
    for (it = str.begin(); it != str.end(); it++) {
        if (*it == '\\') {
            it++;
            if (*it == 'n'){
                if (!next.empty()) {
                    result.push_back(next);
                    next.clear();
                }
            } else {
                it--;
                next += *it;
            }


        } else {
            next += *it;
        }
    }
    it--;

    if (!next.empty()){
        result.push_back(next);
    }

    if (str.back() != '\n'){
        result.clear();
        std::cout << " clear\n";
    }
    return result;
}

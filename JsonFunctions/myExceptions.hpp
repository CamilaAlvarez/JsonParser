//
// Created by Camila Alvarez on 13-06-16.
//

#ifndef STREET2SHOPPARSER_MYEXCEPTIONS_HPP
#define STREET2SHOPPARSER_MYEXCEPTIONS_HPP

#include <exception>

namespace json_handler {
    class MyKeyError : std::exception {
        inline virtual const char *what() const throw() {
            return "key Error";
        }
    };

     class MyIndexError : std::exception {
        inline virtual const char *what() const throw() {
            return "Array indexes must be integers";
        }
    };

    class InvalidJson: std::exception {
        inline virtual const char *what() const throw(){
            return "Invalid Json";
        }
    };

}
#endif //STREET2SHOPPARSER_MYEXCEPTIONS_HPP

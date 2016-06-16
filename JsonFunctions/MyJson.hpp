//
// Created by Camila Alvarez on 13-06-16.
//

#ifndef STREET2SHOPPARSER_JSON_HPP
#define STREET2SHOPPARSER_JSON_HPP

#include "JsonValue.hpp"
#include "myExceptions.hpp"
#include <iostream>

namespace json_handler{
    extern MyIndexError JsonIndexError;
    extern MyKeyError JsonKeyError;
    extern InvalidJson InvalidJsonError;
    class MyJson {
    public:
        virtual ~MyJson();
        //Must return reference, so it can be called as a r-value expression
        virtual JsonValue*& operator[](const std::string& key) = 0;
        virtual JsonValue*& operator[](int index) = 0;
    };
    inline MyJson::~MyJson(){};
}




#endif //STREET2SHOPPARSER_JSON_HPP

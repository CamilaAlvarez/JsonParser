//
// Created by Camila Alvarez on 13-06-16.
//

#ifndef STREET2SHOPPARSER_JSONARRAY_HPP
#define STREET2SHOPPARSER_JSONARRAY_HPP

#include "JsonValue.hpp"
#include "MyJson.hpp"
#include <vector>

namespace json_handler{
    class MyJsonArray : public MyJson, public JsonValue {
    public:
        std::string toString();
        inline MyJsonArray(const std::vector<JsonValue*>& values):values(values){};
        inline MyJsonArray(){};
        inline MyJsonArray(unsigned long min_size){
            this->values.reserve(min_size);
        };
        MyJsonArray(const MyJsonArray& jsonArray);
        ~MyJsonArray();
        JsonValue*& operator[](const std::string& key);
        JsonValue*& operator[](int index);
        JsonValue* generateCopy();
        typedef std::vector<JsonValue*>::iterator iterator;
        typedef std::vector<JsonValue*>::const_iterator const_iterator;
        inline iterator begin() { return values.begin(); };
        inline iterator end() { return values.end(); };
        inline const_iterator cbegin() const { return values.begin(); };
        inline const_iterator cend () const { return values.end(); };
        void addValue(JsonValue* value);

    private:
        std::vector<JsonValue*> values;
    };
}


#endif //STREET2SHOPPARSER_JSONARRAY_HPP

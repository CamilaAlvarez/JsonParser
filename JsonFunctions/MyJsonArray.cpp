//
// Created by Camila Alvarez on 13-06-16.
//

#include "MyJsonArray.hpp"

json_handler::MyJsonArray::MyJsonArray(const json_handler::MyJsonArray& jsonArray){
    for(MyJsonArray::const_iterator it = jsonArray.cbegin(); it!=jsonArray.cend(); ++it) {
        json_handler::JsonValue* value = (*it)->generateCopy();
        this->values.push_back(value);
    }
}

json_handler::MyJsonArray::~MyJsonArray() {
    for(MyJsonArray::iterator it = values.begin(); it!=this->end(); ++it){
        delete *it;
    }
}

json_handler::JsonValue* json_handler::MyJsonArray::generateCopy() {
    return new MyJsonArray(this->values);
}

std::string json_handler::MyJsonArray::toString() {
    std::stringstream ss;
    ss<<"[ ";
    for(MyJsonArray::iterator it = this->begin(); it!=this->end(); ++it){
        json_handler::JsonValue* val = *it;
        ss<<val->toString();
        if( it+1 != this->end() ){
            ss<<",";
        }
        ss<<" ";
    }
    ss<<"]";

    return ss.str();
}

json_handler::JsonValue*& json_handler::MyJsonArray::operator[](const std::string& key){
    throw JsonIndexError;
}
json_handler::JsonValue*& json_handler::MyJsonArray::operator[](int index){
    if(index >= values.size() && index >=values.capacity())
        throw JsonIndexError;
    return values[index];
}

void json_handler::MyJsonArray::addValue(json_handler::JsonValue* value){
    this->values.push_back(value);
}
//
// Created by Camila Alvarez on 15-06-16.
//

#include "JsonDictionary.hpp"
#include <sstream>

json_handler::JsonDictionary::JsonDictionary(const JsonDictionary &dictionary) {
    for(JsonDictionary::const_iterator it = dictionary.cbegin(); it!= dictionary.cend(); ++it){
        json_handler::JsonValue* value = (it->second)->generateCopy();
        this->jsonDictionary[it->first] = value;
    }
}

json_handler::JsonDictionary::~JsonDictionary() {
    for(JsonDictionary::iterator it = this->begin(); it!=this->end(); ++it){
        delete it->second;
    }
}


json_handler::JsonValue* json_handler::JsonDictionary::generateCopy() {
    return new JsonDictionary(this->jsonDictionary);
}

json_handler::JsonValue*& json_handler::JsonDictionary::operator[](int index){
    throw JsonKeyError;
}

json_handler::JsonValue*& json_handler::JsonDictionary::operator[](const std::string &key) {
    if(this->jsonDictionary.find(key) == this->jsonDictionary.end()){
        throw JsonKeyError;
    }
    return this->jsonDictionary[key];
}

std::string json_handler::JsonDictionary::toString() {
    std::stringstream ss;
    ss<<"{ ";
    for(JsonDictionary::iterator it = this->begin(); it!=this->end(); ++it){
        ss<<"\""<<it->first<<"\" : "<<it->second->toString();
        JsonDictionary::iterator aux = it;
        if(++aux != this->end()){
            ss<<",";
        }
        ss<<" ";
    }
    ss<<"}";
    return ss.str();
}

void json_handler::JsonDictionary::addPair(const std::string& key, JsonValue *value) {
    this->jsonDictionary[key] = value;
}

bool json_handler::JsonDictionary::hasKey(const std::string &key) {
    return jsonDictionary.find(key) != jsonDictionary.end();
}
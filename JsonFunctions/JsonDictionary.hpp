//
// Created by Camila Alvarez on 15-06-16.
//

#ifndef STREET2SHOP_JSONDICTIONARY_HPP
#define STREET2SHOP_JSONDICTIONARY_HPP

#include <unordered_map>
#include "MyJson.hpp"

namespace json_handler{
    class JsonDictionary : public MyJson, public JsonValue  {
    public:
        inline JsonDictionary(){};
        inline JsonDictionary(const std::unordered_map<std::string, JsonValue*>& dictionary): jsonDictionary(dictionary){};
        JsonDictionary(const JsonDictionary& jsonDictionary);
        ~JsonDictionary();
        std::string toString();
        JsonValue*& operator[](const std::string& key);
        JsonValue*& operator[](int index);
        typedef std::unordered_map<std::string, JsonValue*>::iterator iterator;
        typedef std::unordered_map<std::string, JsonValue*>::const_iterator const_iterator;
        inline iterator begin() { return jsonDictionary.begin(); };
        inline iterator end() { return jsonDictionary.end(); };
        inline const_iterator cbegin() const { return jsonDictionary.begin(); };
        inline const_iterator cend () const { return jsonDictionary.end(); };
        void addPair(const std::string& key, JsonValue* value);
        bool hasKey(const std::string& key);
    private:
        std::unordered_map<std::string, JsonValue*> jsonDictionary;
        JsonValue* generateCopy();
    };
}



#endif //STREET2SHOP_JSONDICTIONARY_HPP

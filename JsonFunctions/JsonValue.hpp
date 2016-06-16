//
// Created by Camila Alvarez on 13-06-16.
//

#ifndef STREET2SHOPPARSER_JSONVALUE_HPP
#define STREET2SHOPPARSER_JSONVALUE_HPP

#include <sstream>

namespace json_handler{
    class JsonValue {
        friend class MyJsonArray;
        friend class JsonDictionary;
    public:
        virtual ~JsonValue() = 0;
        virtual std::string toString() = 0;
    private:
        virtual JsonValue* generateCopy() = 0;
    };

    inline JsonValue::~JsonValue() { }

    template <class _Tp> class Value : public JsonValue{
    public:
        Value(_Tp value):value(value){}
        inline _Tp getValue(){ return value;}
        inline std::string toString(){
            std::stringstream ss;
            ss<<std::boolalpha<<value;
            return ss.str();
        };

    private:
        _Tp value;
        inline JsonValue* generateCopy(){
            return new Value<_Tp>(value);
        }
    };

}

#endif //STREET2SHOPPARSER_JSONVALUE_HPP

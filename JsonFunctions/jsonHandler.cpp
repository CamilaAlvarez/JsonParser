//
// Created by Camila Alvarez on 16-06-16.
//

#include "jsonHandler.hpp"

namespace json_handler{
    MyJson& string2Json(const std::string &json){
        std::stack<const char&> characterStack;

        const char& first_char = json.at(0);

        if(first_char=='{' || first_char=='['){
            characterStack.push(first_char);
        }
        else{
            throw InvalidJsonError;
        }

        std::string copyJson = json;
        copyJson.erase(0,1);
        const char* jsonCharArray = copyJson.c_str();
        while(*jsonCharArray!='\0'){

        }
        for(char& c : copyJson){
            switch(c){
                case ' ':
                    break;
                case '{':
                    characterStack.push(c);
                default:
                    break;
            }

            if(characterStack.empty()){

            }
            characterStack
        }
    }
}
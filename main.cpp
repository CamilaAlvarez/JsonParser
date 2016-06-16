#include "JsonFunctions/jsonValue.hpp"
#include "MyJsonArray.hpp"
#include <iostream>

using namespace std;

int main() {
    json_handler::Value<string> ejemplo("hola");
    cout << ejemplo.getValue() << endl;
    return 0;
}
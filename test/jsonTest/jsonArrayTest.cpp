//
// Created by Camila Alvarez on 14-06-16.
//

#include "gtest/gtest.h"
#include "MyJsonArray.hpp"
#include "JsonDictionary.hpp"


TEST(JsonArrayTest, JsonArraySimpleValuesTest){
    std::string s = "string";
    json_handler::JsonValue* stringValue = new json_handler::Value<std::string>(s);

    std::vector<json_handler::JsonValue*> values;
    values.push_back(stringValue);

    json_handler::MyJsonArray jsonArray(values);

    ASSERT_EQ("[ string ]",jsonArray.toString());
}

TEST(JsonArrayTest, JsonArrayVariousValuesTest){
    std::string s = "string";
    std::string s2 = "string2";
    std::string s3 = "string3";
    std::string s4 = "string4";
    json_handler::JsonValue* stringValue = new json_handler::Value<std::string>(s);
    json_handler::JsonValue* stringValue2 = new json_handler::Value<std::string>(s2);
    json_handler::JsonValue* stringValue3 = new json_handler::Value<std::string>(s3);
    json_handler::JsonValue* stringValue4 = new json_handler::Value<std::string>(s4);

    std::vector<json_handler::JsonValue*> values;
    values.push_back(stringValue);
    values.push_back(stringValue2);
    values.push_back(stringValue3);
    values.push_back(stringValue4);

    json_handler::MyJsonArray jsonArray(values);

    ASSERT_EQ("[ string, string2, string3, string4 ]",jsonArray.toString());

}

TEST(JsonArrayTest, JsonArrayVariousValuesDifferentType){
    std::string s = "string";
    int i = 1;
    double d = 1.1;
    bool b = true;
    json_handler::JsonValue* stringValue = new json_handler::Value<std::string>(s);
    json_handler::JsonValue* intValue = new json_handler::Value<int>(i);
    json_handler::JsonValue* doubleValue = new json_handler::Value<double>(d);
    json_handler::JsonValue* booleanValue = new json_handler::Value<bool>(b);

    std::vector<json_handler::JsonValue*> values;
    values.push_back(stringValue);
    values.push_back(intValue);
    values.push_back(doubleValue);
    values.push_back(booleanValue);

    json_handler::MyJsonArray jsonArray(values);

    ASSERT_EQ("[ string, 1, 1.1, true ]",jsonArray.toString());

}

TEST(JsonArrayTest, JsonArrayAddValueTest){
    json_handler::JsonValue* stringValue = new json_handler::Value<std::string>("string");
    json_handler::MyJsonArray jsonArray;
    jsonArray.addValue(stringValue);

    ASSERT_EQ("[ string ]", jsonArray.toString());
}

TEST(JsonArrayTest, JsonArrayOperatorIntIndexTest){
    json_handler::JsonValue* stringValue = new json_handler::Value<std::string>("string");
    json_handler::MyJsonArray jsonArray;
    jsonArray.addValue(stringValue);

    ASSERT_EQ("string", (jsonArray[0])->toString());
}

TEST(JsonArrayTest, JsonArrayOperatorKeyIndexTest){
    json_handler::JsonValue* stringValue = new json_handler::Value<std::string>("string");
    json_handler::MyJsonArray jsonArray;
    jsonArray.addValue(stringValue);

    ASSERT_THROW(jsonArray["key"], json_handler::MyIndexError);
}

TEST(JsonArrayTest, JsonArrayCopyConstructorTest){
    json_handler::JsonValue* stringValue = new json_handler::Value<std::string>("string");
    json_handler::MyJsonArray jsonArray;
    jsonArray.addValue(stringValue);

    json_handler::MyJsonArray newJsonArray(jsonArray);
    ASSERT_EQ("[ string ]", newJsonArray.toString());
}

TEST(JsonArrayTest, JsonArrayAssignementTest){
    json_handler::MyJsonArray jsonArray(1);
    json_handler::JsonValue* stringValue = new json_handler::Value<std::string>("string");

    jsonArray[0] = stringValue;
    ASSERT_EQ("string", (jsonArray[0])->toString());
}

TEST(JsonArrayTest, JsonArrayNoValuesTest){
    json_handler::MyJsonArray jsonArray;

    ASSERT_EQ("[ ]", jsonArray.toString());
}

TEST(JsonArrayTest, JsonArrayElementTest){
    json_handler::JsonValue* stringValue = new json_handler::Value<std::string>("string");
    json_handler::MyJsonArray* jsonArrayValue = new json_handler::MyJsonArray();
    jsonArrayValue->addValue(stringValue);
    json_handler::MyJsonArray jsonArray;
    jsonArray.addValue(jsonArrayValue);

    ASSERT_EQ("[ [ string ] ]", jsonArray.toString());
}

TEST(JsonArrayTest, JsonArrayJsonDictionaryElement){
    json_handler::JsonValue* stringValue = new json_handler::Value<std::string>("value");
    std::unordered_map<std::string, json_handler::JsonValue*> values;
    values["key"] = stringValue;

    json_handler::JsonDictionary *jsonDictionaryValue = new json_handler::JsonDictionary(values);
    json_handler::MyJsonArray jsonArray;
    jsonArray.addValue(jsonDictionaryValue);

    ASSERT_EQ("[ { \"key\" : value } ]", jsonArray.toString());
}

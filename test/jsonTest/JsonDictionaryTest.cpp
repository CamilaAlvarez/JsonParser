//
// Created by Camila Alvarez on 16-06-16.
//

#include "gtest/gtest.h"
#include "JsonDictionary.hpp"
#include "MyJsonArray.hpp"

TEST(JsonDictionaryTest, SimplePairTest){
    json_handler::JsonValue* stringValue = new json_handler::Value<std::string>("value");
    std::unordered_map<std::string, json_handler::JsonValue*> values;
    values["key"] = stringValue;
    json_handler::JsonDictionary jsonDictionary(values);

    ASSERT_EQ("{ \"key\" : value }", jsonDictionary.toString());
}

TEST(JsonDictionaryTest, VariousElementsTest){
    json_handler::JsonValue* stringValue = new json_handler::Value<std::string>("value");
    json_handler::JsonValue* stringValue2 = new json_handler::Value<std::string>("value2");
    std::unordered_map<std::string, json_handler::JsonValue*> values;
    values["key"] = stringValue;
    values["key2"] = stringValue2;
    json_handler::JsonDictionary jsonDictionary(values);

    ASSERT_EQ("{ \"key\" : value, \"key2\" : value2 }", jsonDictionary.toString());
}

TEST(JsonDictionaryTest, VariousTypesElementsTest){
    json_handler::JsonValue* stringValue = new json_handler::Value<std::string>("value");
    json_handler::JsonValue* intValue = new json_handler::Value<int>(1);
    json_handler::JsonValue* booleanValue = new json_handler::Value<bool>(true);
    json_handler::JsonValue* doubleValue = new json_handler::Value<double>(2.5);
    std::unordered_map<std::string, json_handler::JsonValue*> values;
    values["string"] = stringValue;
    values["int"] = intValue;
    values["bool"] = booleanValue;
    values["double"] = doubleValue;
    json_handler::JsonDictionary jsonDictionary(values);

    ASSERT_EQ("{ \"string\" : value, \"int\" : 1, \"bool\" : true, \"double\" : 2.5 }", jsonDictionary.toString());
}

TEST(JsonDictionaryTest, JsonArrayElementTest){
    json_handler::MyJsonArray* jsonArray = new json_handler::MyJsonArray();
    jsonArray->addValue(new json_handler::Value<std::string>("string"));
    std::unordered_map<std::string, json_handler::JsonValue*> values;
    values["array"] = jsonArray;

    json_handler::JsonDictionary jsonDictionary(values);

    ASSERT_EQ("{ \"array\" : [ string ] }", jsonDictionary.toString());
}

TEST(JsonDictionaryTest, JsonDictionaryElementTest){
    json_handler::JsonValue* stringValue = new json_handler::Value<std::string>("value");
    std::unordered_map<std::string, json_handler::JsonValue*> values;
    values["key"] = stringValue;
    json_handler::JsonDictionary* jsonDictionaryValue = new json_handler::JsonDictionary(values);

    std::unordered_map<std::string, json_handler::JsonValue*> dictionaryValues;
    dictionaryValues["dictionary"] = jsonDictionaryValue;

    json_handler::JsonDictionary jsonDictionary(dictionaryValues);

    ASSERT_EQ("{ \"dictionary\" : { \"key\" : value } }", jsonDictionary.toString());

}

TEST(JsonDictionaryTest, NoElementsTest){
    json_handler::JsonDictionary jsonDictionary;

    ASSERT_EQ("{ }", jsonDictionary.toString());
}

TEST(JsonDictionaryTest, AddPairTest){
    json_handler::JsonDictionary jsonDictionary;
    jsonDictionary.addPair("key", new json_handler::Value<std::string>("value"));

    ASSERT_EQ("{ \"key\" : value }", jsonDictionary.toString());
}

TEST(JsonDictionaryTest, HasKeyTest){
    json_handler::JsonDictionary jsonDictionary;
    jsonDictionary.addPair("key", new json_handler::Value<std::string>("value"));

    ASSERT_TRUE(jsonDictionary.hasKey("key"));
}

TEST(JsonDictionaryTest, IntIndexTest){
    json_handler::JsonDictionary jsonDictionary;

    ASSERT_THROW(jsonDictionary[0], json_handler::MyKeyError);
}

TEST(JsonDictionaryTest, WrongKeyTest){
    json_handler::JsonDictionary jsonDictionary;

    ASSERT_THROW(jsonDictionary["key"], json_handler::MyKeyError);
}

TEST(JsonDictionaryTest, CorrectAssignmentTest){
    json_handler::JsonValue* stringValue = new json_handler::Value<std::string>("value");
    std::unordered_map<std::string, json_handler::JsonValue*> values;
    values["key"] = stringValue;
    json_handler::JsonDictionary jsonDictionary(values);

    ASSERT_EQ("{ \"key\" : value }", jsonDictionary.toString());

    jsonDictionary["key"] = new json_handler::Value<int>(1);
    delete stringValue;

    ASSERT_EQ("{ \"key\" : 1 }", jsonDictionary.toString());
}

TEST(JsonDictionaryTest, CopyConstructorTest){
    json_handler::JsonValue* stringValue = new json_handler::Value<std::string>("value");
    std::unordered_map<std::string, json_handler::JsonValue*> values;
    values["key"] = stringValue;
    json_handler::JsonDictionary jsonDictionary(values);

    ASSERT_EQ("{ \"key\" : value }", jsonDictionary.toString());

    json_handler::JsonDictionary copyJsonDictionary(jsonDictionary);
    ASSERT_EQ("{ \"key\" : value }", jsonDictionary.toString());
}
//
// Created by Camila Alvarez on 15-06-16.
//

#include "gtest/gtest.h"
#include "JsonValue.hpp"

TEST(JsonValuesTest, JsonValueStringTest){
    std::string s = "string";
    json_handler::Value<std::string> stringValue(s);

    ASSERT_EQ("string", stringValue.getValue());
}

TEST(JsonValuesTest, JsonValuesIntTest){
    int value = 13;
    json_handler::Value<int> intValue(value);

    ASSERT_EQ(13, intValue.getValue());
}

TEST(JsonValuesTest, JsonValuesDoubleTest){
    double value = 12.34;
    json_handler::Value<double> doubleValue(value);

    ASSERT_EQ(12.34, doubleValue.getValue());
}

TEST(JsonValuesTest, JsonValuesBooleanTest){
    bool value = false;
    json_handler::Value<bool> booleanValue(value);

    ASSERT_FALSE(booleanValue.getValue());
}

TEST(JsonValuesTest, JsonValueToStringStringTest){
    std::string s = "string";
    json_handler::Value<std::string> stringValue(s);

    ASSERT_EQ("string", stringValue.toString());
}

TEST(JsonValuesTest, JsonValuesToStringIntTest){
    int value = 13;
    json_handler::Value<int> intValue(value);

    ASSERT_EQ("13", intValue.toString());
}

TEST(JsonValuesTest, JsonValuesToStringDoubleTest){
    double value = 12.34;
    json_handler::Value<double> doubleValue(value);

    ASSERT_EQ("12.34", doubleValue.toString());
}

TEST(JsonValuesTest, JsonValuesToStringBooleanTest){
    bool value = false;
    json_handler::Value<bool> booleanValue(value);

    ASSERT_EQ("false", booleanValue.toString());
}
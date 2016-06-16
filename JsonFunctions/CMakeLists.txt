file(GLOB_RECURSE SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(json_handler STATIC ${SRC} JsonDictionary.cpp JsonDictionary.hpp MyJson.cpp jsonHandler.cpp)
target_include_directories(json_handler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
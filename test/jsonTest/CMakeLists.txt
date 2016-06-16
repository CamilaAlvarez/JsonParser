file(GLOB SRC *.cpp)

add_executable(jsonTests ${SRC} JsonDictionaryTest.cpp)
target_link_libraries(jsonTests json_handler libgtest)

add_test(NAME jsonTests
        COMMAND jsonTests)
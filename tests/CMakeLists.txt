add_executable(lib_tests MathLib_Test.cpp InterpretLib_Test.cpp main.cpp)

find_package(GTest CONFIG REQUIRED)

include(GoogleTest)
target_link_libraries(lib_tests PUBLIC MathLib PRIVATE InterpretLib GTest::gtest)

add_test(NAME lib_tests COMMAND lib_tests)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeProject1 PROPERTY CXX_STANDARD 20)
endif()
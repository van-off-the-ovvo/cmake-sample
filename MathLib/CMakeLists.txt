add_library(MathLib STATIC "MathLib.cpp")


target_include_directories(MathLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeProject1 PROPERTY CXX_STANDARD 20)
endif()
project(cn_parser)

add_executable(cn_parser main.cpp)

install(TARGETS cn_parser RUNTIME DESTINATION bin)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
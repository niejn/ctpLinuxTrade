cmake_minimum_required(VERSION 3.7)
project(ctpLinuxTrade)

set(CMAKE_CXX_STANDARD 11)

add_library(thosttraderapi SHARED IMPORTED)
#/home/njn/CLionProjects/ctpLinux/ThostTraderApi/ThostFtdcMdApi.h
SET_PROPERTY(TARGET thosttraderapi PROPERTY IMPORTED_LOCATION /home/njn/CLionProjects/ctpLinux/ThostTraderApi/libthosttraderapi.so)

set(SOURCE_FILES main.cpp TraderSpi.h TraderSpi.cpp)
add_executable(ctpLinuxTrade ${SOURCE_FILES})
target_link_libraries(ctpLinuxTrade thosttraderapi)
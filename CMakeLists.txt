project(ASEsqlTest)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(ASEsqlTest_SRCS ASEsqlTest.cpp main.cpp)
qt4_automoc(${ASEsqlTest_SRCS})
add_executable(ASEsqlTest ${ASEsqlTest_SRCS})
target_link_libraries(ASEsqlTest ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})

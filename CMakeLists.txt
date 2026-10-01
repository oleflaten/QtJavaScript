cmake_minimum_required(VERSION 3.19)
project(QtSimpleConsole LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Qml)

qt_standard_project_setup()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(QtJavaScript LANGUAGES CXX)

set(SOURCES
    main.cpp
    TinyTest.h TinyTest.cpp
)

# show script files in editor
file(GLOB SCRIPT_FILES
    "*.js"
)

add_executable(QtJavaScript ${SOURCES} ${SCRIPT_FILES})

target_link_libraries(QtJavaScript
    PRIVATE
        Qt::Core
        Qt::Qml
)

include(GNUInstallDirs)
install(TARGETS QtJavaScript
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

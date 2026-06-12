cmake_minimum_required(VERSION 3.16)    # require modern-enough cmake
project(DBApp LANGUAGES CXX)  # CXX = C++
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)              # use C++17 features
set(CMAKE_CXX_STANDARD_REQUIRED ON)     # error if compiler is too old
set(CMAKE_AUTOMOC ON)                   # auto-run Qt's moc on Q_OBJECT classes

find_package(Qt6 6.2 COMPONENTS Core Widgets Network REQUIRED)
# ^ "find Qt6 (at least 6.2) and these modules; fail if missing"

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(DBApp          # name of the binary
    src/main.cpp
    src/MainWindow.h
    src/MainWindow.cpp
    src/ApiClient.h
    src/ApiClient.cpp
)

target_link_libraries(DBApp PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Network
)
# ^ "link the Qt libraries into my binary"

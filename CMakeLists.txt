cmake_minimum_required(VERSION 3.16)    # require modern-enough cmake
project(DBApp LANGUAGES CXX)  # CXX = C++
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)              # use C++17 features
set(CMAKE_CXX_STANDARD_REQUIRED ON)     # error if compiler is too old
set(CMAKE_AUTOMOC ON)                   # auto-run Qt's moc on Q_OBJECT classes

# --- Gentoo multilib workaround -------------------------------------------
# This box keeps 32-bit libs in /usr/lib (Steam's ABI_X86="64 32") next to the
# 64-bit ones in /usr/lib64. Without steering, the 64-bit build breaks twice:
#   1. find_library() picks the 32-bit /usr/lib/libGLX.so -> "file in wrong format".
#   2. ld's rpath-link fallback (/lib:/usr/lib) hits the 32-bit libglib while
#      resolving libproxy's backend (an indirect dep of Qt6::Network), giving
#      bogus "undefined reference to g_*" link errors.
# Pointing both at /usr/lib64 fixes it; harmless on non-multilib systems.
if(EXISTS "/usr/lib64")
    list(PREPEND CMAKE_LIBRARY_PATH /usr/lib64)   # (1) prefer 64-bit libs
    add_link_options(-Wl,-rpath-link,/usr/lib64)  # (2) resolve indirect deps
endif()

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

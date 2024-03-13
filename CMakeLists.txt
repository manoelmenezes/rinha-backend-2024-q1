cmake_minimum_required (VERSION 3.8)

project(RinhaBackend CXX)
set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "/usr/include/boost")
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "/usr/lib/x86_64-linux-gnu")

add_executable(RinhaBackend main.cpp)
target_link_libraries(RinhaBackend ${CONAN_LIBS})

add_subdirectory(deps/libpqxx build-pqxx)
add_subdirectory(deps/json build-json)
#add_subdirectory(deps/served build-served)
target_link_libraries(RinhaBackend PRIVATE pqxx)
target_link_libraries(RinhaBackend PRIVATE nlohmann_json::nlohmann_json)
#target_link_libraries(RinhaBackend PRIVATE served-static)

find_package(cpprestsdk REQUIRED)

target_link_libraries(RinhaBackend PRIVATE cpprestsdk::cpprest)


find_package(PkgConfig)
pkg_check_modules(Pistache REQUIRED IMPORTED_TARGET libpistache)

target_link_libraries(RinhaBackend PRIVATE PkgConfig::Pistache)


cmake_minimum_required(VERSION 3.5)

file(GLOB SOURCES "*.cpp")

project(ws_client)

find_package(cpprestsdk REQUIRED)

add_executable(ws_client ${SOURCES})
target_link_libraries(main PRIVATE cpprestsdk::cpprest)

install( TARGETS
   ws_client

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
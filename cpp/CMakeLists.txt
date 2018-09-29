cmake_minimum_required(VERSION 3.7)

file(GLOB SOURCES "*.cpp")

project(ws_client)


if(UNIX)
  find_library(CPPRESTSDK_LIB cpprest)
elseif(WIN32)
  find_package(cpprestsdk REQUIRED)
  set(CPPRESTSDK_LIB cpprestsdk::cpprest)
endif()



add_executable(ws_client ${SOURCES})
target_link_libraries(ws_client PRIVATE ${CPPRESTSDK_LIB})

install( TARGETS
   ws_client

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)

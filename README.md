# saturn-wsclient
A websocket client implementation(in c++) for saturn - a dpos blockchain.

## Getting Started

Install the cpprestsdk first

With [vcpkg](https://github.com/Microsoft/vcpkg) on Windows
```
PS> vcpkg install cpprestsdk cpprestsdk:x64-windows
```
With [apt-get](https://launchpad.net/ubuntu/+source/casablanca/2.8.0-2build2) on Debian/Ubuntu
```
$ sudo apt-get install libcpprest-dev
```
With [brew](https://github.com/Homebrew/homebrew-core/blob/master/Formula/cpprestsdk.rb) on OSX
```
$ brew install cpprestsdk
```
With [NuGet](https://www.nuget.org/packages/cpprestsdk.android/) on Windows for Android
```
PM> Install-Package cpprestsdk.android
```
For other platforms, install options, how to build from source, and more, take a look at our [Documentation](https://github.com/Microsoft/cpprestsdk/wiki).

Once you have the library, look at our [tutorial](https://github.com/Microsoft/cpprestsdk/wiki/Getting-Started-Tutorial) to use the http_client. It walks through how to setup a project to use the C++ Rest SDK and make a basic Http request.

To use from CMake:
```cmake
cmake_minimum_required(VERSION 3.7)
project(main)

find_package(cpprestsdk REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE cpprestsdk::cpprest)
```

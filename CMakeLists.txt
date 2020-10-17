cmake_minimum_required(VERSION 3.5)

project(cashTracker LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Core Quick REQUIRED)


set(SOURCE main.cpp appregister.cpp logger.cpp operation.cpp balancechange.cpp balance.cpp)
set(HEADERS appregister.h logger.h operation.h balancechange.h balance.h)
set(TESTING tests/unittests.h tests/operationTests.h tests/balanceChangeTests.h)

if(ANDROID)
    add_library(cashTracker SHARED
      ${SOURCE}
      ${HEADERS}
      ${TESTING}
      qml.qrc
    )
else()
    add_executable(cashTracker
      ${SOURCE}
      ${HEADERS}
      ${TESTING}
      qml.qrc
    )
endif()

target_compile_definitions(cashTracker
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(cashTracker
  PRIVATE Qt5::Core Qt5::Quick)

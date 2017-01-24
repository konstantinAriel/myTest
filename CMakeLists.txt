cmake_minimum_required(VERSION 2.6)
message(STATUS "Start running cmake...")

set(PROJECT_NAME myTest)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11")
if (MSVC)
    message ("MAKE_COMPILER_IS_MSVC")
elseif (CMAKE_COMPILER_IS_GNUCXX)

    message ("MAKE_COMPILER_IS_GNUCXX")
else ()
    message ("Unknown compiler")
endif ()

include_directories(../gnuplot-iostream)
set(HEADERS myLib/gnuplot-iostream/gnuplot-iostream.h myLib/simpleini-master/SimpleIni.h src/Mirror.cpp src/Mirror.h)
set(SOURCE armadiloTest.cpp)
project(${PROJECT_NAME})

FIND_PACKAGE(Boost COMPONENTS REQUIRED iostreams regex system filesystem)
if(Boost_FOUND)
    message(STATUS "BOOST FOUND")
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES} ")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
    set(Boost_USE_STATIC_LIBS ON)
    set(Boost_USE_MULRITHREADED ON)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

FIND_PACKAGE(Armadillo COMPONENTS REQUIRED larmadillo)
if(ARMADILLO_FOUND)
    message(STATUS "ARMADILLO FOUND")
    message(STATUS "Armadillo_INCLUDE_DIRS:  ${ARMADILLO_INCLUDE_DIRS}")
    message(STATUS "Armadillo_LIBRARIES:     ${ARMADILLO_LIBRARIES} ")
    message(STATUS "Armadillo_VERSION:       ${ARMADILLO_VERSION_STRING}")

    include_directories(${Armadillo_INCLUDE_DIRS})
endif()

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCE})
message(STATUS "OK_1")

if(Boost_FOUND)
message(STATUS "OK")
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${ARMADILLO_LIBRARIES})
endif ()

cmake_minimum_required(VERSION 3.16)
project(Library_Rental_System)

set (SRC
src/randomClass.cpp
)

set (TESTS
tests/randomClass-ut.cpp
)

set (COMPILING_FLAGS
-Wall
-Werror
-std=c++20
)

set (GMOCK_LIBRARIES
-lgtest
-lgmock
-lpthread
)

include_directories(headers)

#LIBRARIES / CLASS FILES
add_library(${PROJECT_NAME}-lib ${SRC})
add_library(${PROJECT_NAME}-libut ${TESTS})

#MAIN
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC ${PROJECT_NAME}-lib)
target_compile_options(${PROJECT_NAME} PUBLIC ${COMPILING_FLAGS})

#TEST
add_executable(${PROJECT_NAME}-ut tests/mainTest.cpp)
target_link_libraries(${PROJECT_NAME}-ut PRIVATE ${PROJECT_NAME}-lib ${PROJECT_NAME}-libut ${GMOCK_LIBRARIES}) 
target_compile_options(${PROJECT_NAME}-ut PRIVATE ${FLAGS})
add_test(NAME ${PROJECT_NAME}-tests COMMAND ${PROJECT_NAME}-ut)

enable_testing()


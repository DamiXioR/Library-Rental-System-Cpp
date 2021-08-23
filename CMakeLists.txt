cmake_minimum_required(VERSION 3.16)
project(Library_Rental_System)

set (SRC
src/randomClass.cpp
src/book.cpp
src/shelf.cpp
src/magicBox.cpp
)

set (TESTS
tests/randomClass-ut.cpp
tests/book-ut.cpp
tests/shelf-ut.cpp
tests/magicBox-ut.cpp
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

#MAIN
add_executable(${PROJECT_NAME} main.cpp ${SRC})
target_compile_options(${PROJECT_NAME} PUBLIC ${COMPILING_FLAGS})

#TEST
add_executable(${PROJECT_NAME}-ut tests/mainTest.cpp ${SRC} ${TESTS})
target_link_libraries(${PROJECT_NAME}-ut PUBLIC ${GMOCK_LIBRARIES}) 
target_compile_options(${PROJECT_NAME}-ut PUBLIC ${FLAGS})
add_test(NAME ${PROJECT_NAME}-tests COMMAND ${PROJECT_NAME}-ut)

enable_testing()


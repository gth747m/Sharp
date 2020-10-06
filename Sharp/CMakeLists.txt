# CMakeList.txt : CMake project for Sharp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	# Using Clang
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	# Using GCC
	set(GCC_COMPILE_FLAGS "-Wall -Wextra -Wpedantic")
	set (CMAKE_CXX_FLAGS ${GCC_COMPILE_FLAGS})
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	# Using MSVC
	set(MSVC_COMPILE_FLAGS "/W4 /EHsc")
	set (CMAKE_CXX_FLAGS ${MSVC_COMPILE_FLAGS})
endif()

# Add source to this project's executable.
add_executable (Sharp 
	"Sharp.cpp"  
	"Literal.cpp" 
	"Parser.cpp" 
	"ScanException.cpp" 
	"Scanner.cpp" 
	"Token.cpp")

add_subdirectory ("Expressions")
add_subdirectory ("Statements")

# TODO: Add tests and install targets if needed.

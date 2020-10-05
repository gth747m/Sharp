# CMakeList.txt : CMake project for Sharp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
target_sources(Sharp
	PUBLIC
		"${CMAKE_CURRENT_LIST_DIR}/Statement.hpp" 
	PRIVATE
		)

# TODO: Add tests and install targets if needed.

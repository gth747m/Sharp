# CMakeList.txt : CMake project for Sharp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
target_sources(Sharp
	PUBLIC
		"${CMAKE_CURRENT_LIST_DIR}/AssignmentExpression.hpp" 
		"${CMAKE_CURRENT_LIST_DIR}/BinaryExpression.hpp" 
		"${CMAKE_CURRENT_LIST_DIR}/CallExpression.hpp" 
		"${CMAKE_CURRENT_LIST_DIR}/Expression.hpp" 
		"${CMAKE_CURRENT_LIST_DIR}/GroupExpression.hpp"
		"${CMAKE_CURRENT_LIST_DIR}/LiteralExpression.hpp" 
		"${CMAKE_CURRENT_LIST_DIR}/LogicalExpression.hpp"
		"${CMAKE_CURRENT_LIST_DIR}/UnaryExpression.hpp" 
		"${CMAKE_CURRENT_LIST_DIR}/VariableExpression.hpp"
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/AssignmentExpression.cpp" 
		"${CMAKE_CURRENT_LIST_DIR}/BinaryExpression.cpp" 
		"${CMAKE_CURRENT_LIST_DIR}/CallExpression.cpp" 
		"${CMAKE_CURRENT_LIST_DIR}/GroupExpression.cpp"
		"${CMAKE_CURRENT_LIST_DIR}/LiteralExpression.cpp" 
		"${CMAKE_CURRENT_LIST_DIR}/LogicalExpression.cpp"
		"${CMAKE_CURRENT_LIST_DIR}/UnaryExpression.cpp" 
		"${CMAKE_CURRENT_LIST_DIR}/VariableExpression.cpp")

# TODO: Add tests and install targets if needed.

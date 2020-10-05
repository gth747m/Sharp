# CMakeList.txt : CMake project for Sharp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
target_sources(Sharp
	PUBLIC
		"${CMAKE_CURRENT_LIST_DIR}/BlockStatement.hpp" 
		"${CMAKE_CURRENT_LIST_DIR}/ExpressionStatement.hpp" 
		"${CMAKE_CURRENT_LIST_DIR}/FunctionStatement.hpp" 
		"${CMAKE_CURRENT_LIST_DIR}/IfStatement.hpp" 
		"${CMAKE_CURRENT_LIST_DIR}/Statement.hpp" 
		"${CMAKE_CURRENT_LIST_DIR}/VariableStatement.hpp" 
		"${CMAKE_CURRENT_LIST_DIR}/WhileStatement.hpp" 
	PRIVATE
		"${CMAKE_CURRENT_LIST_DIR}/BlockStatement.cpp" 
		"${CMAKE_CURRENT_LIST_DIR}/ExpressionStatement.cpp" 
		"${CMAKE_CURRENT_LIST_DIR}/FunctionStatement.cpp" 
		"${CMAKE_CURRENT_LIST_DIR}/IfStatement.cpp" 
		"${CMAKE_CURRENT_LIST_DIR}/VariableStatement.cpp" 
		"${CMAKE_CURRENT_LIST_DIR}/WhileStatement.cpp" 
		)

# TODO: Add tests and install targets if needed.

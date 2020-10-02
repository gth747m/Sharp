# CMakeList.txt : CMake project for Sharp, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Sharp "Sharp.cpp"  "Parser.cpp" "Parser.h" "Scanner.h" "Scanner.cpp" "Token.h" "TokenType.h" "Token.cpp" "ScanException.h" "ScanException.cpp")

# TODO: Add tests and install targets if needed.

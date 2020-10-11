#include <iostream>
#include <sstream>
#include <vector>

#include "ScanException.hpp"
#include "Scanner.hpp"
#include "Parser.hpp"

int main()
{
    std::stringstream ss;
    ss << "#include \"stdio.h\"" << std::endl
        << std::endl
        << "int main(void)" << std::endl
        << "{" << std::endl
        << "    printf(\"Hello World!\\n\");" << std::endl
        << "    return 0;" << std::endl
        << "}" << std::endl;
    try 
    {
        std::stringstream ss2(ss.str());
        for (auto& token : Scanner::GetTokens(ss))
        {
            std::cout << token << std::endl;
        }
        Parser parser = Parser(Scanner::GetTokens(ss2));
        std::cout << "Found " << parser.Parse().size() 
            << " statements" << std::endl;
    }
    catch (ScanException& ex)
    {
        std::cerr << ex.what() << std::endl;
        std::cerr << "At line " << ex.GetLine() << " column " << ex.GetColumn() << std::endl;
        return 1;
    }
    return 0;
}

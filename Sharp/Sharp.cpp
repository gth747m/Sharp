#include <iostream>
#include <sstream>
#include <vector>

#include "ScanException.h"
#include "Scanner.h"

int main()
{
    std::stringstream ss;
    ss << "#include <iostream>" << std::endl
        << std::endl
        << "int main(void)" << std::endl
        << "{" << std::endl
        << "    std::cout << \"Hello World!\" << std::endl;" << std::endl
        << "    return 0;" << std::endl
        << "}" << std::endl;
    try 
    {
        for (Token& token : Scanner::GetTokens(ss))
        {
            std::cout << token << std::endl;
        }
    }
    catch (ScanException& ex)
    {
        std::cerr << ex.what() << std::endl;
        std::cerr << "At line " << ex.GetLine() << " column " << ex.GetColumn() << std::endl;
        return 1;
    }
    return 0;
}

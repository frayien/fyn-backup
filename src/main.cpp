#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;
using namespace std::string_literals;

int main(int argc, char* argv[])
{
    fs::path path_in;
    fs::path path_out;

    for(int p = 1; p < argc; ++p)
    {
        if(argv[p] == "-o"s)
        {
            p++;
            if(!(p < argc))
            {
                std::cerr << "output invalid" << std::endl;
                return -1;
            }

            path_out = argv[p];
        }
        else if(argv[p] == "-i"s)
        {
            p++;
            if(!(p < argc))
            {
                std::cerr << "input invalid" << std::endl;
                return -1;
            }

            path_in = argv[p];
        }
        else
        {
            std::cerr << "argument inconnu : " << argv[p] << std::endl;
            return -1;
        }
    }

    if(!fs::exists(path_out))
    {
        std::cerr << "pas de sortie" << std::endl;
        return -1;
    }

    if(!fs::exists(path_in))
    {
        std::cerr << "pas d'entrée" << std::endl;
        return -1;
    }

    for(const auto & it : fs::recursive_directory_iterator(path_in))
    {
        std::cout << it << std::endl;
    }

    return 0;
}

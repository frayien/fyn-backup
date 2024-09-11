#include <iostream>
#include <filesystem>
#include <string>

#include <boost/program_options.hpp>

namespace po = boost::program_options;
namespace fs = std::filesystem;
using namespace std::string_literals;

int main(int argc, char* argv[])
{
    fs::path path_in;
    fs::path path_out;

    po::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message")
        ("input,i", po::value<fs::path>(), "input path")
        ("output,o", po::value<fs::path>(), "output path")
    ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);    

    if (vm.count("help"))
    {
        std::cout << desc << "\n";
        return 1;
    }

    if (vm.count("input"))
    {
        std::cout << "Compression level was set to " << vm["input"].as<fs::path>() << ".\n";
    }

    if (vm.count("output"))
    {
        std::cout << "Compression level was set to " << vm["output"].as<fs::path>() << ".\n";
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

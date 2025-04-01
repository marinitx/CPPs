#include <iostream>
#include <string>

int replaceStr(std::string filename, std::string s1, std::string s2)
{
    //open filename (check if its empty or chmod)
    //find s1
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        std::cerr << "Try this: <filename> <string to search> <string to replace>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    return replaceStr(filename, s1, s2);
}
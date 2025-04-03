#include <iostream>
#include <string>
#include <fstream>

int replaceStr(const std::string &filename, const std::string &s1, const std::string &s2)
{
	if (s1.empty())
	{
		std::cerr << "Error: the string to search cannot be empty" << std::endl;
		return 1;
	}

	if (s1 == s2)
    {
        std::cerr << "Error: the search string and replacement string are the same." << std::endl;
        return 1;
    }

	std::ifstream inFile(filename);
	if (!inFile)
	{
		std::cerr << "Error: could not open file " << filename << std::endl;
		return 1;
	}

	std::string newFilename = filename + ".replace";
	std::ofstream outFile(newFilename);

	if (!outFile)
	{
		std::cerr << "Error: could not create file " << newFilename << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(inFile, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		}
		outFile << line << '\n';
	}

	inFile.close();
	outFile.close();

	return 0;
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
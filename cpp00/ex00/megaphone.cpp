#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	int	i;
    int j;

    i = 1;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
    else if (argc > 1)
    {
        while (i < argc)
        {
            j = 0;
            while (argv[i][j])
            {
                if (isalpha(argv[i][j]))
                    std::cout << (char)toupper(argv[i][j]);
                else
                    std::cout << argv[i][j];
                j++;
            }
            std::cout << " ";
            i++;
        }
    }
    std::cout << std::endl;
	return (0);
}
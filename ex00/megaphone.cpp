#include <iostream>

int main(int argc, char **argv)
{
    int c = 1;

    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    while(argv[c])
    {
        for (int i = 0; argv[c][i]; i++)
          std::cout << (char)std::toupper(argv[c][i]);
        c++;
    }
    return(0);
}

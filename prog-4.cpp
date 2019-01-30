#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void print_cases(const std::string& name)
{
    char up[name.length() + 1];
    char lo[name.length() + 1];

    for(size_t i = 0; i < name.size(); i++)
    {
        up[i] = std::toupper(name[i]);
        lo[i] = std::tolower(name[i]);
    }

    up[name.length()] = lo[name.length()] = '\0';

    std::cout << lo << " " << up << std::endl;
}

int main()
{

    print_cases("Elizabeth");
    print_cases("John");
    print_cases("Frank");
    print_cases("Fred");

    return 0;
}


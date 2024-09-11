#include "easyfind.hpp"

int main(void)
{
    std::vector<int>    container;
    for (int i = 0; i < 10; ++i)
        container.push_back(i);
    try
    {
        easyfind(container, 0);
        easyfind(container, 5);
        easyfind(container, 17);
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return (0);
}
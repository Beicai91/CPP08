#include "Span.hpp"

int main(void)
{
    std::cout << "------TEST1------" << std::endl;
    Span    obj(50);
    obj.addNumber(6);
    obj.addNumber(3);
    obj.addNumber(17);
    obj.addNumber(9);
    obj.addNumber(11);

    std::cout << "Shortest span: " << obj.shortestSpan() << std::endl;
    std::cout << "Longest span: " << obj.longestSpan() << std::endl;

    std::cout << "------TEST2------" << std::endl;
    Span    obj2(1000);
    std::vector<int>    vec;
    vec.reserve(1000);
    for (int i = 0; i < 1000; ++i)
        vec.push_back(i);
    obj2.addNumber(vec.begin(), vec.end());
    std::cout << "Shortest span: " << obj2.shortestSpan() << std::endl;
    std::cout << "Longest span: " << obj2.longestSpan() << std::endl;

    std::cout << "------TEST3------" << std::endl;
    vec.clear();
    vec.reserve(50);
    for (int i = 0; i < 50; ++i)
        vec.push_back(i);
    try
    {
        obj.addNumber(vec.begin(), vec.end());
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return (0);
}
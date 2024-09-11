#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main(void)
{
    MutantStack<int>    mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;
    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(27);
    mstack.push(32);
    mstack.push(0);

    MutantStack<int>::it  itb = mstack.begin();
    MutantStack<int>::it  ite = mstack.end();

    ++itb;
    --itb;
    while (itb != ite)
    {
        std::cout << *itb << std::endl;
        ++itb;
    }
    std::stack<int> normalStack(mstack); //creating a stack object by copying the content of mstack. the iterators we implemented are sliced off.
    return (0);
}

/*
//std::list is a container that has iterator

int main(void)
{
    std::list<int>   lst;

    lst.push_back(5);
    lst.push_back(17);

    std::cout << lst.back() << std::endl;
    lst.pop_back();

    std::cout << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(27);
    lst.push_back(32);
    lst.push_back(0);

    std::list<int>::iterator  itb = lst.begin();
    std::list<int>::iterator  ite = lst.end();

    ++itb;
    --itb;
    while (itb != ite)
    {
        std::cout << *itb << std::endl;
        ++itb;
    }
    return (0);
}
*/

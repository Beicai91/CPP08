#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <vector>
#include <exception>
#include <iostream>

class NotFoundException: public std::exception
{
    public:
        const char  *what() const throw();
};

template <typename T>
void    easyfind(T &container, int ele);

#include "easyfind.tpp"

#endif
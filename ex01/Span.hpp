#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span
{
    private:
        std::vector<int>    _storage;
        unsigned int    _size;
    
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        ~Span();
        Span    &operator=(const Span &other);

        void    addNumber(int num);
        void    addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int     shortestSpan();
        int     longestSpan();

        class   FullStorageException: public std::exception
        {
            public:
                const char  *what() const throw();
        };

        class   NoSpanException: public std::exception
        {
            public:
                const char *what() const throw();
        };

};

#endif
#include "Span.hpp"

//constructors and destructor
Span::Span(): _size(0)
{}

Span::Span(unsigned int n): _size(n)
{
    this->_storage.reserve(n);
}

Span::Span(const Span &other): _size(other._size)
{
    //deep copy!
    this->_storage.reserve(this->_size);
    for (unsigned int i = 0; i < this->_size; ++i)
        this->_storage.push_back(other._storage[i]);
}

Span::~Span()
{}

//operators
Span    &Span::operator=(const Span &other)
{
    if (this == &other)
        return (*this);
    this->_storage.clear();
    this->_size = other._size;
    this->_storage.reserve(this->_size);
    for (unsigned int i = 0; i < this->_size; ++i)
        this->_storage.push_back(other._storage[i]);
    return (*this);
}

//nested exception class
const char  *Span::FullStorageException::what() const throw()
{
    return ("The storage is full");
}

const char  *Span::NoSpanException::what() const throw()
{
    return ("No span can be found");
}

//other public funcs
void    Span::addNumber(int num)
{
    std::size_t size = this->_storage.size();
    if (size < this->_size)
        this->_storage.push_back(num);
    else
        throw FullStorageException();
}

void    Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (this->_storage.size() + std::distance(begin, end) > this->_size)
        throw FullStorageException();
    this->_storage.insert(this->_storage.end(), begin, end);
}

int Span::shortestSpan()
{
    int res;

    if (this->_storage.size() < 2)
        throw NoSpanException();
    std::sort(this->_storage.begin(), this->_storage.end());
    std::vector<int>::iterator  it = this->_storage.begin();
    res = *(it + 1) - *it;
    while (it != this->_storage.end() - 1)
    {
        if ((*(it + 1) - *it) < res)
            res = (*(it + 1) - *it);
        it++;
    }
    return (res);
}

int Span::longestSpan()
{
    int res;

    if (this->_storage.size() < 2)
        throw NoSpanException();
    std::sort(this->_storage.begin(), this->_storage.end());
    res = *(this->_storage.end() - 1) - *(this->_storage.begin());
    return (res);
}
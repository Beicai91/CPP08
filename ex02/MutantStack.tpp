//constructors, destructor and copy assignment operator
template <typename T>
MutantStack<T>::MutantStack():std::stack<T>(){}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other):std::stack<T>(other){}

template <typename T>
MutantStack<T>::~MutantStack(){}

template <typename T>
MutantStack<T>  &MutantStack<T>::operator=(const MutantStack &other)
{
    if (this == &other)
        return (*this);
    std::stack<T>::operator=(other);
    return (*this);
}

//other funcs
/*
std::stack<T>::c is a protected member of std::stack that stores the underlying container.
std::stack does not natively expose iterators, but by accessing the protected member c, which is the underlying container, you can expose iterators via begin() and end().*/
template <typename T>
typename MutantStack<T>::it MutantStack<T>::begin()
{
    return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::it MutantStack<T>::end()
{
    return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::const_it   MutantStack<T>::begin() const
{
    return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::const_it   MutantStack<T>::end() const
{
    return (std::stack<T>::c.end());
}
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(const MutantStack &other);
        ~MutantStack();
        MutantStack &operator=(const MutantStack &other);
        typedef typename std::stack<T>::container_type::iterator    it;
        typedef typename std::stack<T>::container_type::const_iterator  const_it;
        it  begin();
        it  end();
        const_it    begin() const;
        const_it    end() const;
};

#include "MutantStack.tpp"

#endif

/*
Notes:
1.std::stack does not directly expose iterators because it's a container adaptor with a specific interface (LIFO — Last In, First Out). However, std::stack is built on top of an underlying container (std::deque by default, or std::vector, std::list, etc., if specified).
2. std::stack<T>::container_type refers to the type of the underlying container that std::stack is using to store its elements.
3. By default, std::stack<T>::container_type is std::deque<T>, but you can specify a different container when you instantiate std::stack.
4. To declare the iterator type for the MutantStack class, which is derived from std::stack, we need to access the underlying container's iterator type.
*/
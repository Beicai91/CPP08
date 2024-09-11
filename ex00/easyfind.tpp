template <typename T>
void    easyfind(T &container, int ele)
{
    typename T::iterator    res;
    res = std::find(container.begin(), container.end(), ele);
    if (res == container.end())
        throw NotFoundException();
    std::cout << "Found target element in container" << std::endl;
}
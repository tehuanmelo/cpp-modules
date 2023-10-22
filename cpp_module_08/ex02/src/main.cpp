
#include "../inc/MutantStack.hpp"

template <typename T>
class MutantStack : public std::stack<T>
{
private:
public:
    class iterator
    {
    private:
        typename MutantStack::container_type::iterator it;
    public:
        iterator() {}
        iterator(typename MutantStack::container_type::iterator it) : it(it) {}
        ~iterator() {}
        T &operator*()
        {
            return *it;
        }
        iterator &operator++()
        {
            ++(this->it);
            return *this;
        }
        iterator operator++(int)
        {
            iterator tmp = *this;
            ++(this->it);
            return tmp;
        }
        iterator &operator--()
        {
            --(this->it);
            return *this;
        }
        iterator operator--(int)
        {
            iterator tmp = *this;
            --(this->it);
            return tmp;
        }
        bool operator!=(iterator& other)
        {
            return this->it != other.it;
        }
        bool operator==(iterator& other)
        {
            return this->it == other.it;
        }
    };

    iterator begin()
    {
        return iterator(this->c.begin());
    }

    iterator end() 
    {
        return iterator(this->c.end());
    }
};

int main()
{

    MutantStack<int> a;
    a.push(3);
    a.push(5);
    a.push(6);

    MutantStack<int>::iterator it;
    it = a.begin();
    
    std::cout << *++it << std::endl;
    std::cout << *it++ << std::endl;
    std::cout << *it << std::endl;

    return 0;
}
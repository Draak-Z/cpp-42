#include "mutantstack.hpp"
#include <list>

int main(void)
{
    std::cout << "------ Subject main ----" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << std::endl;
    std::cout << "-------  Copy tests -------" << std::endl;
    std::cout << "Empty: " << s.empty() << std::endl;
    std::cout << "Size: " << s.size() << std::endl;
    s.push(5);
    s.push(6);
    s.pop();
    std::cout << "Top: " << s.top() << std::endl;
    while (!s.empty())
    {
      std::cout << s.top() << ' ';
      s.pop();
    }
    std::cout << std::endl << "Empty: " << s.empty() << std::endl;
    std::cout << std::endl;
    std::cout << "-------  List tests -------" << std::endl;
    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    std::cout << list.back() << std::endl;
    list.pop_back();
    std::cout << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);
    std::list<int>::iterator lit = list.begin();
    std::list<int>::iterator lite = list.end();
    ++lit;
    --lit;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }
    std::cout << std::endl;
    return (0);
}
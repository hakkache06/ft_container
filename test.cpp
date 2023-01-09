
#include <iostream>
#include "pair.hpp"
#include "map.hpp"
#include <map>
//#include <pair>

template <typename Iter1, typename Iter2>
bool compareMaps(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2)
{
    for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
        if (first1->first != first2->first || first1->second != first2->second)
            return false;
    return true;
}

int main()
{

        std::map<char, int> m;
        ft::map<char, int> ft_m;


        // first insert function version (single parameter):
        // m.insert(std::pair<char, int>('a', 100));
        // m.insert(std::pair<char, int>('z', 200));

        // ft_m.insert(ft::pair<char, int>('a', 100));
        // ft_m.insert(ft::pair<char, int>('z', 200));

        // std::cout << m.size() << std::endl;
        // std::cout << ft_m.size() << std::endl;


        // std::pair<std::map<char, int>::iterator, bool> ret;
        // ft::pair<ft::map<char, int>::iterator, bool> ft_ret;

        // ret = m.insert(std::pair<char, int>('z', 500));
        // ft_ret = ft_m.insert(ft::pair<char, int>('z', 500));

        // std::cout << ret.second << "d\n";


        std::map<char, int>::iterator it = m.begin();
        ft::map<char, int>::iterator ft_it = ft_m.begin();

        m.insert(it, std::pair<char, int>('b', 300));
        m.insert(it, std::pair<char, int>('c', 400));

        ft_m.insert(ft_it, ft::pair<char, int>('b', 300));
        ft_m.insert(ft_it, ft::pair<char, int>('c', 400));

        std::cout << m.size() << "d\n";
        std::cout << ft_m.size() << "d\n";
        std::cout << ft_m.empty() << "d\n";
        std::cout << m.empty() << "d\n";



        std::map<char, int> anothermap;
        ft::map<char, int> ft_anothermap;
        anothermap.insert(m.begin(), m.find('c'));
        ft_anothermap.insert(ft_m.begin(), ft_m.find('c'));

        std::cout << anothermap.size() << "d\n";
        std::cout << ft_anothermap.size() << "d\n";
        std::cout << anothermap.empty() << "d\n";
        std::cout << ft_anothermap.empty() << "d\n";

        std::cout<< compareMaps(ft_m.begin(), ft_m.end(), m.begin(), m.end()) <<"44\n";
        std::cout<< compareMaps(ft_anothermap.begin(), ft_anothermap.end(), anothermap.begin(), anothermap.end()) <<"44\n";

            

}
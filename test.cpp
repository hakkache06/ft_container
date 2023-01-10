
#include <iostream>
#include "pair.hpp"
#include "map.hpp"
#include <map>
//#include <pair>



int main()
{

        std::map<int, int> m;
        ft::map<int, int> ft_m;
        std::map<int, int>::iterator it;
        ft::map<int, int>::iterator ft_it;

        // insert some values:
        ft_m[1] = 10;
        ft_m[2] = 20;
        ft_m[3] = 30;
        ft_m[4] = 40;
        ft_m[5] = 50;
        ft_m[6] = 60;

        m[1] = 10;
        m[2] = 20;
        m[3] = 30;
        m[4] = 40;
        m[5] = 50;
        m[6] = 60;

        it = m.find(2);
        ft_it = ft_m.find(2);

        m.erase(it);       // erasing by iterator
        ft_m.erase(ft_it); // erasing by iterato

        int ret = m.erase(3);       // erasing by key
        int ft_ret = ft_m.erase(3); // erasing by key
        
        // std::cout << ret << "hello\n";
         //std::cout << ft_ret << "hello";
        ft::map<int, int>::iterator a = ft_m.begin();

        while(a != ft_m.end())
        {
            std::cout << a->first << std::endl;
            a++;
        }

             std::map<int, int>::iterator b = m.begin();

        std::cout << "=============================================="<<"\n";
        while(b != m.end())
        {
            std::cout << b->first << std::endl;
            b++;
        }



}
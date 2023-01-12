
#include <iostream>
#include "pair.hpp"
#include "map.hpp"
#include <map>
//#include <pair>



int main()
{
  
    std::map<int, std::string> m1;
        std::map<int, std::string> m2;
        ft::map<int, std::string> ft_m2;
        ft::map<int, std::string> ft_m1;
        for (int i = 0; i < 1e4; ++i)
        {
            m2.insert(std::make_pair(i, "string2"));
            ft_m2.insert(ft::make_pair(i, "string2"));
        }

        m1 = m2;
        ft_m1 = ft_m2;
        
        m2.begin()->second = "hello";
        ft_m2.begin()->second = "hello";


        int i = 0;
        i = (ft_m1.begin()->second != ft_m2.begin()->second);
        std::cout << i << std::endl;

        ///ft_m1.begin()->second != ft_m2.begin()->second

}
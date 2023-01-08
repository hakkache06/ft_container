
#include <iostream>
#include "pair.hpp"
#include "map.hpp"
int main()
{
    ft::map<char,char> ito;

    ito.insert(ft::make_pair('A','A')) ;
    ito.insert(ft::make_pair('B','B')) ;
    ito.insert(ft::make_pair('C','c')) ;
    ito.insert(ft::make_pair('D','s')) ;
    ito.insert(ft::make_pair('E','e')) ;
    ito.insert(ft::make_pair('F','s')) ;

    ft::map<char,char>::iterator it = ito.begin();
    ito.affiche2();
    it++;
    it++;
    std::cout<<it->first<<std::endl;



}
#include "map.hpp"
#include "pair.hpp"


int main()
{
    ft::map<int,int> it;

    it.insertmap(ft::make_pair(1,12)) ;
    it.insertmap(ft::make_pair(2,44)) ;
    it.insertmap(ft::make_pair(3,44)) ;

    it.affiche2();

}
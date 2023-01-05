#include "map.hpp"
#include "pair.hpp"


int main()
{
    ft::map<int,int> ito;

    // ft::pair<int,int> f1;
    // f1 = ft::make_pair(1,44);
    ito.insertmap(ft::make_pair(1,12)) ;
    ito.insertmap(ft::make_pair(2,44)) ;
    ito.insertmap(ft::make_pair(3,44)) ;
    ito.insertmap(ft::make_pair(4,44)) ;
    ito.insertmap(ft::make_pair(5,44)) ;
    ito.insertmap(ft::make_pair(0,44)) ;

    


     ft::map<int,int>::iterator it = ito.begin();

    cout << it->first << "\n" ;
    it++;
    // cout << it->first << "\n" ;


    // ito.affiche2();
    

}
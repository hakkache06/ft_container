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

    
    //ito.affiche2();

    
      for (ft::map<int,int>::iterator it=ito.begin(); it!=ito.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

    




    // itp = 11 ; if(itp->right != null)  itp = 19 ; while(itp->left)  it=itp<-left

}
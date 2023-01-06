
#include <iostream>
#include<map>
#include "pair.hpp"
#include "map.hpp"
int main()
{
    ft::map<int,int> ito;

    ito.insert(ft::make_pair(4,44)) ;
    ito.insert(ft::make_pair(5,44)) ;
    ito.inser(ft::make_pair(1,12)) ;

    ito.insertmap(ft::make_pair(0,44)) ;

    
    ito.affiche2();

    
    // ft::map<int,int>::iterator ita=ito.begin();
    // std::cout << ita->first << " => " << ita->second << '\n';
    //   ita--;
    // std::cout << ita->first << " p => " << ita->second << '\n';
    //   ita++;
    // std::cout << ita->first << " p => " << ita->second << '\n';
      
  

  // pair<iterator,bool> insert (const value_type& val);
    // mymap.insert ( std::pair<char,int>('a',100) );
  // first insert function version (single parameter):
    // mymap.insert ( std::pair<char,int>('z',200) );
    // std::pair<std::map<char,int>::iterator,bool> ret;
    // ret = mymap.insert ( std::pair<char,int>('o',500) );
    // if (ret.second==false)
    // {
    //   std::cout << "element 'z' already existed";
    //   std::cout << " with a value of " << ret.second << '\n';
    // }
    // else
    // {
    // std::cout << ret.second << '\n';
    // }
  /////////////////////////////////////////////////////
  // iterator insert (iterator position, const value_type& val);

  // std::map<int,int> mymap;
  // std::map<int ,int >::iterator it ;
  // mymap.insert(std::make_pair(3,20));
  // mymap.insert(std::make_pair(1,20));
  // mymap.insert(std::make_pair(2,20));

  // for (it = mymap.begin(); it!=mymap.end();++it)
  // {
  //     std::cout << it->first << " ====>"<< it->second << "\n";
  // }


  // std::map<int,int> othermap;
  // std::map<int,int>::iterator  ita;
  // othermap.insert(mymap.begin(),mymap.end());
  // for (ita = othermap.begin(); ita!=othermap.end();++ita)
  // {
  //     std::cout << ita->first << " ====>"<< ita->second << "\n";
  // }







    //mymap.affiche2();
    // mymap.insert(it,std::pair<char,int>('s',300));
    // mymap.insert(it,std::pair<char,int>('d',300));
    // mymap.insert(it,std::pair<char,int>('g',300));
    // mymap.insert(it,std::pair<char,int>('h',300));
    // mymap.insert(it,std::pair<char,int>('l',300));
    // mymap.insert(it,std::pair<char,int>('k',300));
    // std::cout << it->first <<  std::endl;
  /// kayd7ko 3lina lah yhdihom
}
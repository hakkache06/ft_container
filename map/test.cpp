



#include "map.hpp"       // your Map path.
#include "../vector/vector.hpp" // your Vector path.
#include "pair.hpp" 

int main()
{
    ft::map<int,int> map;

    map.insert(ft::make_pair(15,5));
    map.insert(ft::make_pair(16,5));
    map.insert(ft::make_pair(4,5));
    map.insert(ft::make_pair(1,5));
    map.insert(ft::make_pair(2,5));
    map.insert(ft::make_pair(3,5));
    map.insert(ft::make_pair(0,5));
    map.insert(ft::make_pair(12,5));
    map.insert(ft::make_pair(36,5));
    map.insert(ft::make_pair(56,5));

    ft::map<int,int>::iterator it;
    it = map.begin();

    map.erase(it,map.end());


        while(true);


}
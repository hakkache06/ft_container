

#include "pair.hpp"
#include "Avl.hpp"
#include "nodda.hpp"

int main()
{
  
    ft::pair<int,int> f1;
    f1.first = 2;
    f1.second =45;

    ft::pair<int,int> f2;
    f2.first = 3;
    f2.second =5;


    ft::pair<int,int> f3;
    f3.first = 4;
    f3.second =78;

    ft::pair<int,int> f4;
    f4.first = 5;
    f4.second =23;

  

    AVL<ft::pair<int,int> > avl_tree;


    nodaaa <ft::pair<int,int> > *first_node;


   first_node = avl_tree.insert(first_node , f1);
//   first_node = avl_tree.insert(first_node , f2);
//   first_node = avl_tree.insert(first_node , f3);
//   first_node = avl_tree.insert(first_node , f4);

        //cout << first_node->pair.first << endl;
        //cout << first_node->pair.second << endl;



   

}
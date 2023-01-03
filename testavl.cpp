

#include "pair.hpp"
#include "Avl.hpp"
#include "nodda.hpp"

int main()
{

 AVL<ft::pair<int,int> > avl_tree;
 nodaaa <ft::pair<int,int> > *second_node;
  
    ft::pair<int,int> f1;
    f1.second = 40;
    f1.first = 1;  
  

   ft::pair<int,int> f4;
   f4.second = 45;
   f4.first = 2;  

     ft::pair<int,int> f5;
   f5.second = 17;
   f5.first = 3; 


       ft::pair<int,int> f6;
   f6.second = 20;
   f6.first = 4; 

   ft::pair<int,int> f8;
   f8.second = 78;
   f8.first = 5; 


 

   //       ft::pair<int,int> f5;
   //  f5.second = 10;
   //  f5.first = 5;  

         second_node = avl_tree.insert(second_node , f1);
         second_node = avl_tree.insert(second_node , f4);
         second_node = avl_tree.insert(second_node , f5);
         second_node = avl_tree.insert(second_node , f6);
         second_node = avl_tree.insert(second_node , f8);




      //avl_tree.printTree(second_node,"",true);
 
      //avl_tree.affiche(second_node);
      
      cout << avl_tree.min_node(second_node)->pair.first << "]";
       cout << avl_tree.max_node(second_node)->pair.first << "]";


   

}

#pragma once


# include <algorithm>
# include <functional>
# include <iostream>
#include "pair.hpp"
#include "vector.hpp"
#include "tree_iterator.hpp"
//#include "reverse_iterator.hpp"
#include "nodda.hpp"
#include "Avl.hpp"
//#include "map_ite.hpp"
namespace ft
{
  
  	template <
		class Key, /*Type de données de clé à stocker dans le map.*/
        class T, /*Type de données d'élément à stocker dans le map.*/
        class Compare = std::less<Key>, /*   */
        class Alloc = std::allocator<ft::pair<const Key,T> > /*   */
        >
    class map
    {

        
        public:

        typedef Key key_type;
        typedef T   mapped_type;
        typedef typename ft::pair<const key_type,mapped_type>  value_type;
        typedef Alloc   allocator_type;
        typedef size_t  size_type;
        typedef Compare key_compare;
        typedef ptrdiff_t difference_type;
        typedef typename Alloc::reference reference;
        typedef typename Alloc::const_reference const_reference;
        typedef typename Alloc::pointer pointer;
        typedef typename Alloc::const_pointer const_pointer; 
        //typedef	nodaaa<value_type,Alloc> _node;
        //// iterator 
        //typedef ft::tree_iterator<const value_type, Alloc, AVL<value_type,Alloc> > const_iterator;
        typedef  ft::tree_iterator<Key,T,value_type, Alloc,AVL<Key,T,value_type,Alloc> > iterator;

        // fin iterator


       
    public:
     
      Alloc _alloc;
      Compare _key_compare;
      size_type _size;
      
    // size_t _capacity;
 
        // class value compare
        // class value_compare: public std::binary_function<value_type,value_type,bool> 
        // {
        //     friend class map;
        // protected:
        //     Compare comp;
        //     value_compare(Compare c) : comp(c) {}
        // public:
        //     bool operator()(const value_type& x, const value_type& y) const
        //      {
        //         return comp(x.first, y.first);
        //     }
        // };

        public :

        // Construct empty
        explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
        {
            
        }

        // ~map()
        // {
        //     avl_tree.dellocate_node(_node); 
		// };
        // iterator 
    	
	   map (const map& x)
	   {
	        (*this) = x;
	   }  

        void    affiche2()
        {
            this->avl_tree.affiche(avl_tree._head);
        }

        iterator  begin()
        {
           return iterator(avl_tree.min_noode(avl_tree._head),avl_tree);
        }

        iterator  end()
        {
           return iterator(nullptr,avl_tree);
        }
        bool empty() const 
        {
            if (avl_tree.treesize()==0)
                return  (true);
            else    
                return (false);       
        }
        size_t size() const
        {
            return (avl_tree.tree_size());
        }

        size_t  max_size() const
        {
            return (avl_tree.alloc_noode.max_size());
        }
        // pair<iterator,bool> insert (const value_type& val)
        // {   
        //        nodaaa<value_type,Alloc> *temp = avl_tree.find_key(avl_tree._head,val.first);
        //        if(temp)
        //         {   
        //             avl_tree.insert(avl_tree._head,val.first);
        //             return (pair<iterator,false>) ft;
        //         } 
        //     return (pair<iterator,bool>)

        // }    
        iterator insert(iterator position ,const value_type &x)
        {
            (void)position;
            nodaaa <Key,T,value_type,Alloc> * temp =  avl_tree.find_key(avl_tree._head,x.first);

            if (temp == NULL )
            {
                avl_tree._head = avl_tree.insert(avl_tree._head,x);
                return (iterator(avl_tree._head,avl_tree));
            }   
            return iterator(temp,avl_tree);
        }

        // void insertp(const value_type &x)
        // {
        //     nodaaa <Key,T,value_type,Alloc> * temp =  avl_tree.find_key(avl_tree._head,x.first);

        //     if (temp == NULL )
        //         avl_tree._head = avl_tree.insert(avl_tree._head,x);

        // }
        ///If k matches the key of an element in the container, the function returns a reference to its mapped value
        mapped_type& operator[] (const key_type& k)
        {
            return (*((this->insertp(ft::make_pair(k,mapped_type()))).first)).second;
        }
        // template <class InputIterator> 
        // void insert (InputIterator first, InputIterator last)
        // {
             
        // };



    private:
    
  		AVL<Key,T,value_type,Alloc> avl_tree;    

    };

}
        // void    testparentnode(const value_type &x)
        // {

        //     avl_tree._parent = avl_tree.parent_noode(avl_tree._head,x.first);
        //     cout << avl_tree._parent->pair->first << "";
        // }


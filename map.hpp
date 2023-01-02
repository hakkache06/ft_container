
#pragma once


# include <algorithm>
# include <functional>
# include <iostream>
#include "pair.hpp"
#include "vector.hpp"
#include "bidirectional_iterator.hpp"
#include "reverse_iterator.hpp"
#include "nodda.hpp"
#include "Avl.hpp"
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
        typedef	nodaaa<value_type> _node;

        //// iterator 
        typedef typename	ft::bidirectional_iterator<_node, value_type>		iterator;
		typedef typename	ft::bidirectional_iterator<_node, const value_type>	const_iterator;

        //typedef typename ft::reverse_iterator < iterator > reverse_iterator;
        //typedef typename ft::reverse_iterator < const_iterator > const_reverse_iterator;
        //fin iterator


       
    public:
      nodaaa<T> *_head;
      nodaaa<T> *_last_node;
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
            avl_tree._alloc = alloc;
            avl_tree._last_node = avl_tree._alloc.allocate(1);
            avl_tree._alloc.construct(avl_tree._last_node,nodaaa<value_type>());
        }

        // ~map()
        // {
        //     avl_tree.dellocate_node(_node); 
		// };
        // iterator 
        // pair<iterator, bool> insert(const value_type& x)
        // {
            
        // }
      

    private:
		typedef typename allocator_type::template rebind<_node>::other		_avl_allocator;
		AVL<value_type> avl_tree;    

    };

}


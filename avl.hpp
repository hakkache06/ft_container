
#pragma once


# include <algorithm>
# include <functional>
# include <iostream>
# include "pair.hpp"

namespace ft
{
  
  	template <
		class Key, /*Type de données de clé à stocker dans le map.*/
        class T, /*Type de données d'élément à stocker dans le map.*/
        class Compare = std::less<Key>, /*   */
        class Alloc = std::allocator<ft::pair<const Key,T> > /*   */
        >
    class Avl
    {
        // Member types
        public:

        typedef Key key_type;
        typedef T   mapped_type;
        typedef typename ft::pair<const key_type,mapped_type>  value_type;
        typedef Alloc   allocator_type;
        typedef size_t  size_type;

    struct node
    {
        typedef key_type    key_type;
        node    *parent;
        node    *left;
        node    *right;
        size_type           heghit;
        value_type          *value;

        void    node_init()
        {
            this->parent = NULL;
            this->left = NULL;
            this->right = NULL;
            this->value = NULL;
            this->heghit = 0;
        }

        node(mapped_type data)
        {
            this->parent = NULL;
            this->left = NULL;
            this->right = NULL;
            this->value = data;
            this->heghit = 1;
        }

    };

        public :

       		AVL(void)
			{
				this->root = this->_alloc_node.allocate(1);
				this->root = init();
				this->root  = this->root;
				this->root = NULL;
			}

			~AVL()
			{
			}

    
        public :

            node													*root;
		private:
			allocator_type											_alloc;
			typename allocator_type::template rebind<node>::other	_alloc_node;
			Compare	


    };

}
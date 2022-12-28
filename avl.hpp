
#pragma once


# include <algorithm>
# include <functional>
# include <iostream>
# include "pair.hpp"




namespace ft
{

    // struct node
    // {
    //     typedef key_type    key_type;
    //     node    *parent;
    //     node    *left;
    //     node    *right;
    //     size_type           heghit;
    //     value_type          *value;

    //     void    node_init()
    //     {
    //         this->parent = NULL;
    //         this->left = NULL;
    //         this->right = NULL;
    //         this->value = NULL;
    //         this->heghit = 0;
    //     }

    //     node(mapped_type data)
    //     {
    //         this->parent = NULL;
    //         this->left = NULL;
    //         this->right = NULL;
    //         this->value = data;
    //         this->heghit = 1;
    //     }

    // };
  
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
            node    *parent;
            node    *left;
            node    *right;

            size_type           heghit;
            value_type          *value;
            Compare             _compare;

            void    node_init(void)
            {
                this->left = NULL;
                this->right = NULL;
                this->parent = NULL;
                this->heghit = 0;
                this->value = NULL;
            }
        };
        
         node													*root;


        public :


            //default constructor
       		avl(void)
			{
				this->root = this->_alloc_node.allocate(1);
				this->root = node_init();
                this->root->left = NULL;
			}

			~avl()
			{
			}

            node    *new_node_create( value_type const val)
            {
                node *new_node;

                new_node = this->_alloc_node.allocate(1);
                new_node->node_init();
                new_node->value = this->_alloc.allocate(1);
                this->_alloc.construct(new_node->value,val);
                new_node->heghit = 1;
                new_node->parent = NULL;
                return (new_node);
            }
            // blance_factor

            int     node_is_blanced(node *root)
            {
                int is_balanced = 0

                is_balanced = (root->left) ? (root->left->heghit) : 0;
                is_balanced -= (root->right) ? (root->right->heghit) : 0;
            }
                //if (|std::abs(node_is_blanced(root)) != 0 || 1 not balanced


		private:
			allocator_type											_alloc;
			typename allocator_type::template rebind<node>::other	_alloc_node;
			Compare	                                                _compare;

    };

}
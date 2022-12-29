
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
    //     node    *root;
    //     node    *left;
    //     node    *right;
    //     size_type           heghit;
    //     value_type          *value;

    //     void    node_init()
    //     {
    //         this->root = NULL;
    //         this->left = NULL;
    //         this->right = NULL;
    //         this->value = NULL;
    //         this->heghit = 0;
    //     }

    //     node(mapped_type data)
    //     {
    //         this->root = NULL;
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
    class map
    {

        private :
            struct node
            {
                node    *root;
                node    *left;
                node    *right;
                node    *parent;

                size_type           heghit;
                value_type          *value;

                // void    node_init(void)
                // {
                //     this->left = NULL;
                //     this->right = NULL;
                //     this->root = NULL;
                //     this->heghit = 0;
                //     this->value = NULL;
                // }
            };

        // Member types
        public:

        typedef Key key_type;
        typedef T   mapped_type;
        typedef typename ft::pair<const key_type,mapped_type>  value_type;
        typedef Alloc   allocator_type;
        typedef size_t  size_type;
        typedef ptrdiff_t difference_type;
        typedef typename Alloc::reference reference;
        typedef typename Alloc::const_reference const_reference;
        typedef typename Alloc::pointer pointer;
        typedef typename Alloc::const_pointer const_pointer;
        typedef typename ft::reverse_iterator < iterator > reverse_iterator;
        typedef typename ft::reverse_iterator < const_iterator > const_reverse_iterator;
        //typedef typename ft::bidirectional_iterator<node, key_compare> iterator;

        public :

        // Construct 

        


        private :



            node *allocate_tree_node()
            {
                node *root;

                root = this->_alloc_node.allocate(1);
                root->right = NULL;
                root->left = NULL;
                root->parent = NULL;
                std::memset(&root->val, 0, sizeof(root->val));
                return node;
            }

            node *deallocate_node(node *root)
			{
				this->_alloc.destroy(root->value);
				this->_alloc.deallocate(root->value, 1);
				this->_alloc_node.destroy(root);
				this->_alloc_node.deallocate(root, 1);
				root = NULL;

				return (root);
			}
            // blance_factor
            // balanced factor = hegit(subtreeleft) - heghit(subtreeright) = 0,1 balanced
            int     node_is_blanced(node *root)
            {
                int is_balanced = 0

                is_balanced = (root->left) ? (root->left->heghit) : 0;
                is_balanced -= (root->right) ? (root->right->heghit): 0;
            }
                //if (|std::abs(node_is_blanced(root)) != (0 || 1) not balanced
            node *max_node(node *root)
				{
					if (root && root->right)
						return (root->right->max_node());
					return (root);
				}


        //heghit Tree

    // int calcule_height(Node *parent)
    // {
    //    if(parent->left && parent->right)
    //    {
    //         if (parent->left->height < parent->right->height)
    //             return parent->right->height + 1;
    //         else return  parent->left->height + 1;
    //     }
    //     else if(parent->left && parent->right == NULL)
    //     {
    //        return parent->left->height + 1;
    //     }
    //     else if(parent->left == NULL && parent->right)
    //     {
    //         return parent->right->height + 1;
    //      }
    //      return 0;
    // }

            // DD GG Rotation simple
            // DG GD Rotation double

            // node    *RG(node *root)
            // {
            //     node *temp = root->left;
            // }

        private :

            int heghit_node(node *noda)
            {
                if(noda==NULL)
                    return 0;
                return (noda->heghit);    
            }
            int max_two_val(int a,int b)
            {
                return(a>b) ? a : b;
            }

            node    *new_node_create(const value_type &val , node *parent = NULL)
            {
                node *new_node;

                new_node = _alloc_node.allocate(1);
                _alloc.construct(new_node->value,val);
                new_node->right = NULL;
                new_node->left  = NULL;
                new_node->heghit = 1;
                new_node->parent = parent ;
                return (new_node);
            }

            int     get_balance(node *noda)
            {
                    if(noda==NULL)
                        return 0;
                    return(heghit_node(noda->left) - heghit_node(noda->right));
            }

      
            node *min_node(node *temp)
            {
                if (temp)
                {
                    while (temp->left)
                        temp= temp->left;
                }
                return (temp);
            }

            mode *max_node(node *temp)
            {
                if (temp)
                {
                    while (temp->right)
                        temp = temp->right;
                }
                return (temp);
            }

            node  *LR(node *noda)
            {
                node *y = noda->right; // B
                node *t2 = y->left;    // C
                y->left = noda;
                x->right = t2; 

                x->height = max_two_val(heghit_node(x->left),heghit_node(x->right)) + 1;
                y->height = max_two_val(heghit_node(y->left),heghit_node(y->right)) + 1;

                return (y);
            }


            node  *LRI(node *y)
            {
                node *x = y->left; // B
                node *t2 = x->right;    // C
                x->right = y; 
                y->left = t2;

                y->height = max_two_val(heghit_node(y->left),heghit_node(y->right)) + 1;
                x->height = max_two_val(heghit_node(x->left),heghit_node(x->right)) + 1;

                return (x);
            }
    
            node *insert_node(node *node, const value_type &val,node *parent = NULL)
            {
                int balance;
                // find correct position
                if (node == NULL)
                    return (new_node_create(val,parent));
                if (val.first < node->val.first)
                        node->left = insert_node(node->left,val,node);
                else if (val->first > node->val.first)
                        node->right = insert_node(node->right,val,node);
                else
                    return node; 
                //

                // balance Tree
                    node->height = 1 + max_two_val(heghit_node(node->left,node->right));

                    balance = get_balance(node);

                    if(balance > 1 && val.first < node->left->val.first)
                        return (LRI(node)); // single Right Rotation
                    if(balance < -1 && val.first > node->right.val.first)
                        return (LR(node));// single left rotation
                    if (balance < -1 && val.first < node->right.val.first)
                    {
                        node->right = LRI(node->right); // RL
                        return LR(node);
                    }
                    if (balance > 1 && val.first > node->left.val.fisrt)
                    {
                        node->left = LR(node->left);
                        return LRI(node);
                    }      
                    return node ;
                ///
            }


            node * balanced_node(node *root)
            {
                      // balanced node
                if (root == NULL)
                    return root;
                root->height = 1 + max(height(root->left), height(root->right));
                int balance = getBalance(root);

                if (balance > 1 && getBalance(root->left) >= 0)
                    return LRI(root);

                if (balance > 1 && getBalance(root->left) < 0)
                {
                    root->left = leftRotate(root->left);
                    return LRI(root);
                }
                if (balance < -1 &&
                    getBalance(root->right) <= 0)
                    return LR(root);
                if (balance < -1 &&
                    getBalance(root->right) > 0)
                {
                    root->right = rightRotate(root->right);
                    return LR(root);
                }
                return root;
            } 

        node *deleteNode(node *root, const key_type &key)
        {
        
        // Position node 
            if (root == NULL)
                return root;

            if (key < root->val.first)) 
                root->left = deleteNode(root->left, key);

            else if (root->val.first > key))
                root->right = deleteNode(root->right, key);
        ///
            else
            {
            // if have child    
                if ((root->left == NULL) ||(root->right == NULL))
                {
                    node *temp = root->left ? root->left : root->right;

                    if (temp == NULL)
                    {
                        temp = root;
                        root = NULL;
                    }
                    else // have child one
                    {
                        temp->parent = root->parent;
                        *root = *temp;
                    } 
                    _alloc_node.destroy(temp);
                    _alloc_node.deallocate(temp, 1);
                }
                else // node to be deleted have 2 child
                {
                    node *temp = min_node(root->right);
                    root->val = temp->val;
                    root->right = deleteNode(root->right,temp->val.first);
                }
            }

            return balanced_node(root);
        }

		private:
            node    *_root;
            node    _last_node;
			allocator_type											_alloc;
			typename allocator_type::template rebind<node>::other	_alloc_node;
			Compare	                                                _compare;

    };

}
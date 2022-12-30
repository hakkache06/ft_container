
 # pragma once

#include "pair.hpp"  	
#include <algorithm>
# include <functional>
# include <iostream>
      template <
		class Key, /*Type de données de clé à stocker dans le map.*/
        class T, /*Type de données d'élément à stocker dans le map.*/
        class Compare = std::less<Key>, /*   */
        class Alloc = std::allocator<ft::pair<const Key,T> > /*   */
        >
class AVL
{
        // membre Type
        public : 
		    typedef Key												key_type;
		    typedef T												mapped_type;
		    typedef typename ft::pair<const key_type, mapped_type>	value_type;
		    typedef size_t											size_type;
		    typedef Alloc											allocator_type;

    public :

        AVL()
        {
            allocate_tree_node();
        }

        ~AVL()
		{

		}

    public :

       
        int getBalance(node *N)
        {
            if (N == NULL)
                return 0;
            return height(N->left) - height(N->right);
        }

        node *allocate_tree_node()
        {
            node *node;

            node = this->_alloc_node.allocate(1);
            node->right = NULL;
            node->left = NULL;
            node->parent = NULL;
            std::memset(&node->val, 0, sizeof(node->val));
            return node;
        }

        int max(int a, int b)
        {
            return (a > b) ? a : b;
        }

        int height(node *N)
        {
            if (N == NULL)
                return 0;
            return N->height;
        }

        node *Createnewnode(const value_type &val, node *parent = NULL)
        {
            node *node;
            node = _alloc_node.allocate(1);
            _allocator_type.construct(&node->val, val);
            node->right = NULL;
            node->left = NULL;
            node->parent = parent;
            node->height = 1;
            return (node);
        }

        node *rightRotate(node *y)
        {
            node *x = y->left;
            node *T2 = x->right;

            x->right = y;
            y->left = T2;

            x->parent = y->parent;
            y->parent = x;
            if (T2)
                T2->parent = y;

            y->height = max(height(y->left),height(y->right)) +1;
            x->height = max(height(x->left),height(x->right)) + 1;
            return x;
        }

        node *leftRotate(node *x)
        {
            node *y = x->right;
            node *T2 = y->left;

            y->left = x;
            x->right = T2;

            y->parent = x->parent;
            x->parent = y;
            if (T2)
                T2->parent = x;

            x->height = max(height(x->left),height(x->right)) + 1;
            y->height = max(height(y->left),height(y->right)) + 1;
            return y;
        }


        node *insert_node(node *node, const value_type &val, node *parent = NULL)
        {
            if (node == NULL)
                return (Createnewnode(val, parent)); 
            if (_comp(val.first, node->val.first))
            {
                node->left = insert_node(node->left, val, node);
            }
            else if (_comp(node->val.first, val.first))
            {
                node->right = insert_node(node->right, val, node); 
            }
            else 
                return node;

            node->height =  max(height(node->left),height(node->right)) + 1;
            int balance = getBalance(node);

            // Left Left Case
            if (balance > 1 && _comp(val.first, node->left->val.first)) //val.first < node->left->val.first
                return rightRotate(node);
            // Right Right Case
            if (balance < -1 && _comp(node->right->val.first, val.first)) // val.first > node->right->val.first
                return leftRotate(node);
            // Left Right Case
            if (balance > 1 && _comp(node->left->val.first, val.first)) // val.first > node->left->val.first
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
            // Right Left Case
            if (balance < -1 && _comp(val.first, node->right->val.first)) // val.first < node->right->val.first
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
            return node;
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

        node *min_node(node *node)
        {
            if (node)
            {
                while (node->left)
                    node = node->left;
            }
            return (node);
        }

        node *max_node(node *node)
        {
            if (node)
            {
                while (node->right)
                    node = node->right;
            }
            return (node);
        }

        size_type tree_size(node *node) const
        {
            if (node == NULL || node->right == _last_node)
                return 0;
            return (tree_size(node->left) + 1 + tree_size(node->right));
        }

     int calcule_height(Node *parent)

    {
       if(parent->left && parent->right)
       {
            if (parent->left->height < parent->right->height)
                return parent->right->height + 1;
            else return  parent->left->height + 1;
        }
        else if(parent->left && parent->right == NULL)
        {
           return parent->left->height + 1;
        }
        else if(parent->left == NULL && parent->right)
        {
            return parent->right->height + 1;
         }
         return 0;
    }

        int     node_is_blanced(node *root)
    {
        int is_balanced = 
        is_balanced = (root->left) ? (root->left->heghit) : 0;
        is_balanced -= (root->right) ? (root->right->heghit): 0;
    }


    public:
    node        *root;
    node        *last_node_root_parent;

	private:
			allocator_type											_alloc;
			typename allocator_type::template rebind<node>::other	_alloc_node;
			Compare	                                                _compare;
};




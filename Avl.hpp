
 # pragma once

#include "pair.hpp"  	
#include <algorithm>
# include <functional>
# include <iostream>
# include "nodaaa.hpp"

/// AVL Tree implementation using C | AVL Tree Code | rotations in AVL Tree | LL RR LR RL rotation // https://www.youtube.com/watch?v=L0cDtyphZRc

//AVL Tree
template <class T, class Compare ,class Alloc = std::allocator<nodaaa<T> > >
class AVL{
    public:
        typedef typename T::first_type ftype;
        typedef typename Alloc::template rebind<T>::other _node_alloc; // alloc node
        typedef Alloc											allocator_type;
        typedef size_t                                          size_type;

    AVL()
    {
        _head = NULL;
        _size = 0;
    }

    AVL(const AVL &ref)
    {
        *this = ref;
    }

    AVL &operator=(const AVL &ref)
    {
        _head = ref._head;
        _last_node = ref._last_node;
        _alloc = ref._alloc;
        _key_compare = ref._key_compare;
        _size = ref._size;
    }
    
    int height(nodaaa<T> *n)
    {
        if (n == NULL)
            return 0;
        return n->height;
    }

    nodaaa<T> *min_node(nodaaa<T> *node) 
    {
        if (node)
        {
            while (node->left)
                node = node->left;
        }
        return (node);
    }

    nodaaa<T> *max_node(nodaaa<T> *node)
    {
        if (node)
        {
            while (node->right)
                node = node->right;
        }
        return (node);
    }

    int getBalance(nodaaa<T> *n)
    {
        if (n == NULL)
            return 0;
        return height(n->left) - height(n->right);
    }

   int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    bool key_comp(nodaaa<T> *n1, nodaaa<T> *n2){
        return (n1->_pair.first > n2->_pair.first);
    }

    nodaaa<T> *allocate_new_node(T _pair)
    {
        nodaaa<T> *node = _alloc.allocate(1);
        _alloc.construct(node,nodaaa<T>(_pair));
        return node;
    }

        nodaaa<T> *rightRotate(nodaaa <T>*y)
        {
            nodaaa<T> *x = y->left;
            nodaaa<T> *T2 = x->right;

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

        nodaaa<T> *leftRotate(nodaaa<T> *x)
        {
            nodaaa<T>*y = x->right;
            nodaaa<T> *T2 = y->left;

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
        
        nodaaa<T> *insert (nodaaa <T> *node, T pair){
        if (node == NULL){
            _size++;
             return (newnode(pair));
        }
        if (_key_compare(pair.first, node->_pair.first)){
            nodaaa<T> *leftchild = insert(node->left, pair);
            node->left = leftchild;
            leftchild->parent  = node;
        }
        else if (_key_compare(node->_pair.first, pair.first)){
            nodaaa<T> *rightchild = insert(node->right, pair);
            node->right = rightchild;
            rightchild->parent  = node;
        }
        else 
            return (node);
        node->_height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        if (balance > 1 && _key_compare(pair.first, node->pair.first))
            return (rightRotate(node));
        if (balance < -1 && _key_compare(node->pair.first, pair.first))
            return (leftRotate(node));
        if (balance > 1 && _key_compare(node->pair.first, pair.first)){
            node->_eft = leftRotate(node->_left);
            return (rightRotate(node));
        }
        if (balance < -1 && _key_compare(pair.first, node->pair.first)){
            node->right = rightRotate(node->right);
            return (leftRotate(node));
        }
        return (node);
    }

    size_type   treesize()
    {
        return _size;
    }

    int     node_is_blanced(nodaaa <T>*root)
    {
        int is_balanced = 
        is_balanced = (root->left) ? (root->left->heghit) : 0;
        is_balanced -= (root->right) ? (root->right->heghit): 0;
    }

    nodaaa<T> *deletenode(nodaaa<T> *node, ftype first){
        if (node == NULL)
            return (node);
        if (_key_compare(first, node->_pair.first)){
            node->_left = deletenode(node->_left, first);
        }
        else if (_key_compare(node->_pair.first, first)){
            node->_right = deletenode(node->_right, first);
        }
        else {
            if ((node->_left == NULL) || (node->_right == NULL)){
                nodaaa<T> *temp = node->_left ? node->_left : node->_right;

                if (temp){
                    temp = node;
                    node = NULL;
                }
                else{
                    temp->_parent = node->_parent;
                    if (node->_parent && node->_parent->_left == node){
                        temp->_parent->_left = temp;
                    }
                    else if (node->_parent && node->_parent->_right == node){
                        temp->_parent->_right = temp;
                    }
                    _alloc.destroy(node);
                    _alloc.deallocate(node,1);
                    --_size;
                    return (temp);
                }
                --_size;
                _alloc.destroy(temp);
                _alloc.deallocate(temp,1);
            }

            else {
                _node_alloc().destroy(&node->_pair);
                _node_alloc().construct(&node->_pair, minValnode(node->_right)->_pair);
                node->_right = deletenode(node->_right, node->_pair.first);
            }
        }
        if (node == NULL)
            return (node);
        node->_height = 1 + max(height(node->_left), height(node->_right));
        int balance = getBalance(node);
        if (balance > 1 && getBalance(node->_left) >= 0)
            return (rightRotate(node));
        if (balance > 1 && getBalance(node->_left) < 0){
            node->_left = leftRotate(node->_left);
            return (rightRotate(node));
        }
        if (balance < -1 && getBalance(node->_right) <= 0)
            return (leftRotate(node));
        if (balance < -1 && getBalance(node->_right) > 0){
            node->_right = rightRotate(node->_right);
            return (leftRotate(node));
        }
        return (node);
    }


    void dellocate_node(nodaaa<T> *node){
        if (node){
            dellocate_node(node->_left);
            dellocate_node(node->_right);
            _alloc.destroy(node);
            _alloc.deallocate(node,1);
        }
    }

        nodaaa<T> *find_key(nodaaa<T> *node, ftype first) {
        if (node == NULL)
            return (NULL);
        if (node->_pair.first == first)
            return (node);
        nodaaa<T> *n1 = find(node->_left, first);
        if (n1)
            return (n1);
        nodaaa<T> *n2 = find(node->_right, first);
        return (n2);
    }

       
    public:
      nodaaa<T> *_head;
      nodaaa<T> *_last_node;
      Alloc _alloc;
      Compare _key_compare;
      size_type _size;
    // size_t _capacity;
};


 



    //     int height(node *n)
    //     {
    //         if (n == NULL)
    //             return 0;
    //         return n->height;
    //     }

    //     node *Createnewnode(const value_type &val, node *parent = NULL)
    //     {
    //         node *node;
    //         node = _alloc_node.allocate(1);
    //         _allocator_type.construct(&node->val, val);
    //         node->right = NULL;
    //         node->left = NULL;
    //         node->parent = parent;
    //         node->height = 1;
    //         return (node);
    //     }



    //     node *insert_node(node *node, const value_type &val, node *parent = NULL)
    //     {
    //         if (node == NULL)
    //             return (Createnewnode(val, parent)); 
    //         if (_comp(val.first, node->val.first))
    //         {
    //             node->left = insert_node(node->left, val, node);
    //         }
    //         else if (_comp(node->val.first, val.first))
    //         {
    //             node->right = insert_node(node->right, val, node); 
    //         }
    //         else 
    //             return node;

    //         node->height =  max(height(node->left),height(node->right)) + 1;
    //         int balance = getBalance(node);

    //         // Left Left Case
    //         if (balance > 1 && _comp(val.first, node->left->val.first)) //val.first < node->left->val.first
    //             return rightRotate(node);
    //         // Right Right Case
    //         if (balance < -1 && _comp(node->right->val.first, val.first)) // val.first > node->right->val.first
    //             return leftRotate(node);
    //         // Left Right Case
    //         if (balance > 1 && _comp(node->left->val.first, val.first)) // val.first > node->left->val.first
    //         {
    //             node->left = leftRotate(node->left);
    //             return rightRotate(node);
    //         }
    //         // Right Left Case
    //         if (balance < -1 && _comp(val.first, node->right->val.first)) // val.first < node->right->val.first
    //         {
    //             node->right = rightRotate(node->right);
    //             return leftRotate(node);
    //         }
    //         return node;
    //     }

    //     node *deletenode(node *root, const key_type &key)
    //     {
        
    //     // Position node 
    //         if (root == NULL)
    //             return root;

    //         if (key < root->val.first)) 
    //             root->left = deletenode(root->left, key);

    //         else if (root->val.first > key))
    //             root->right = deletenode(root->right, key);
    //     ///
    //         else
    //         {
    //         // if have child    
    //             if ((root->left == NULL) ||(root->right == NULL))
    //             {
    //                 node *temp = root->left ? root->left : root->right;

    //                 if (temp == NULL)
    //                 {
    //                     temp = root;
    //                     root = NULL;
    //                 }
    //                 else // have child one
    //                 {
    //                     temp->parent = root->parent;
    //                     *root = *temp;
    //                 } 
    //                 _alloc_node.destroy(temp);
    //                 _alloc_node.deallocate(temp, 1);
    //             }
    //             else // node to be deleted have 2 child
    //             {
    //                 node *temp = min_node(root->right);
    //                 root->val = temp->val;
    //                 root->right = deletenode(root->right,temp->val.first);
    //             }
    //         }

    //                                   // balanced node
    //             if (root == NULL)
    //                 return root;
    //             root->height = 1 + max(height(root->left), height(root->right));
    //             int balance = getBalance(root);

    //             if (balance > 1 && getBalance(root->left) >= 0)
    //                 return LRI(root);

    //             if (balance > 1 && getBalance(root->left) < 0)
    //             {
    //                 root->left = leftRotate(root->left);
    //                 return LRI(root);
    //             }
    //             if (balance < -1 &&
    //                 getBalance(root->right) <= 0)
    //                 return LR(root);
    //             if (balance < -1 &&
    //                 getBalance(root->right) > 0)
    //             {
    //                 root->right = rightRotate(root->right);
    //                 return LR(root);
    //             }
    //             return root;

    //     }

    //     node *min_node(node *node)
    //     {
    //         if (node)
    //         {
    //             while (node->left)
    //                 node = node->left;
    //         }
    //         return (node);
    //     }

    //     node *max_node(node *node)
    //     {
    //         if (node)
    //         {
    //             while (node->right)
    //                 node = node->right;
    //         }
    //         return (node);
    //     }

    //     size_type tree_size(node *node) const
    //     {
    //         if (node == NULL || node->right == _last_node)
    //             return 0;
    //         return (tree_size(node->left) + 1 + tree_size(node->right));
    //     }

    //  int calcule_height(node *parent)

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

    //     int     node_is_blanced(node *root)
    // {
    //     int is_balanced = 
    //     is_balanced = (root->left) ? (root->left->heghit) : 0;
    //     is_balanced -= (root->right) ? (root->right->heghit): 0;
    // }


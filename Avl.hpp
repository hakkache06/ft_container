
 # pragma once

#include "pair.hpp"  	
#include <algorithm>
# include <functional>
# include <iostream>
#include "nodda.hpp"
using namespace std;

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++**/
/// AVL Tree implementation using C | AVL Tree Code | rotations in AVL Tree | LL RR LR RL rotation // https://www.youtube.com/watch?v=L0cDtyphZRc

// class pairue_compare
//           : public binary_function<pairue_type,pairue_type,bool> {
//         friend class AVL;
//         protected:
//           Compare comp;
//           pairue_compare(Compare c) : comp(c) {}
//         public:
//           bool operator()(const pairue_type& x, const pairue_type& y) const {
//             return comp(x.first, y.first);
// } };

//AVL Tree

template <class T ,class Alloc = std::allocator<nodaaa<T> > >
class AVL{
    public:
        typedef typename T::first_type   pair_first_pair;
        typedef typename Alloc::template rebind<nodaaa <T> >::other _node_alloc; // alloc node
        typedef Alloc											allocator_type;
        typedef size_t                                          size_type;

    public:
        nodaaa<T> *_head;
        nodaaa<T> *_last_node;
        Alloc _alloc;
        size_type _size;


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
       // _key_compare = ref._key_compare;
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

    // bool key_comp(nodaaa<T> *n1, nodaaa<T> *n2){
    //     return (n1->_pair.first > n2->_pair.first);
    // }

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
        
        ////////////////////// insert //////////////////////////
        nodaaa<T> *insert (nodaaa <T> *node, T pair){
        if (node == NULL){
            _size++;
             return (allocate_new_node(pair));
        }
        if (pair.first < node->pair.first){
            node->left = insert(node->left, pair);
        }
        else if (pair.first > node->pair.first ){
            node->right =  insert(node->right, pair);;
        }
        else 
            return (node);

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        /// second cases
        if (balance > 1 && pair.first < node->left->pair.first)
            return (rightRotate(node));
       
        if (balance > 1 &&  pair.first > node->left->pair.first ){
            node->left = leftRotate(node->left);
            return (rightRotate(node));
        }

        /// First cases
        if (balance < -1 &&  pair.first > node->right->pair.first )
            return (leftRotate(node));

        if (balance < -1 && pair.first < node->right->pair.first){
            node->right = rightRotate(node->right);
            return (leftRotate(node));
        }
        return (node);
    }
            ////////////////////// insert //////////////////////////


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

  
        node<T> *deletenode(node<T> *root, pair_first_pair key)
        {
        
        // Position node 
            if (root == NULL)
                return root;

            if (key < root->pair.first)) 
                root->left = deletenode(root->left, key);

            else if (root->pair.first > key))
                root->right = deletenode(root->right, key);
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
                    root->pair = temp->pair;
                    root->right = deletenode(root->right,temp->pair.first);
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

    //     }


        if (node == NULL)
            return (node);

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);
        if (balance > 1 && getBalance(node->left) >= 0)
            return (rightRotate(node));


        if (balance > 1 && getBalance(node->left) < 0){
            node->left = leftRotate(node->left);
            return (rightRotate(node));
        }

        if (balance < -1 && getBalance(node->right) <= 0)
            return (leftRotate(node));
        if (balance < -1 && getBalance(node->right) > 0){
            node->right = rightRotate(node->right);
            return (leftRotate(node));
        }
        return (node);
    }


    void dellocate_node(nodaaa<T> *node){
        if (node){
            dellocate_node(node->left);
            dellocate_node(node->right);
            _alloc.destroy(node);
            _alloc.deallocate(node,1);
        }
    }

        nodaaa<T> *find_key(nodaaa<T> *node,  pair_first_pair first) {
        if (node == NULL)
            return (NULL);
        if (node->pair.first == first)
            return(node);
        nodaaa<T> *n1 = find(node->left, first);
        if (n1)
            return (n1);
        nodaaa<T> *n2 = find(node->right, first);
        return (n2);
    }

    void printTree(nodaaa<T> *root, string indent, bool last)
     {
        if (root != nullptr) 
        {
            cout << indent;
            if (last) {
            cout << "R----";
            indent += "   ";
            } else {
            cout << "L----";
            indent += "|  ";
            }
            cout << root->pair.second<< endl;
            printTree(root->left, indent, false);
            printTree(root->right, indent, true);
        }
    }

        void printTreechekinsert(nodaaa<T> *root) {
        
        if(root!=NULL)
        {
            printTreechekinsert(root->left);
           printTreechekinsert(root->right);
            cout << root->pair.first << "  ";
        }
    }
    
    void print2DUtil(nodaaa<T>* root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += 10;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    cout << endl;
    for (int i = 10; i < space; i++)
        cout << " ";
    cout << root->pair.first << "\n";
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void affiche(nodaaa<T>* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}




};


 



    //     int height(node *n)
    //     {
    //         if (n == NULL)
    //             return 0;
    //         return n->height;
    //     }

    //     node *Createnewnode(const pairue_type &pair, node *parent = NULL)
    //     {
    //         node *node;
    //         node = _alloc_node.allocate(1);
    //         _allocator_type.construct(&node->pair, pair);
    //         node->right = NULL;
    //         node->left = NULL;
    //         node->parent = parent;
    //         node->height = 1;
    //         return (node);
    //     }



    //     node *insert_node(node *node, const pairue_type &pair, node *parent = NULL)
    //     {
    //         if (node == NULL)
    //             return (Createnewnode(pair, parent)); 
    //         if (_comp(pair.first, node->pair.first))
    //         {
    //             node->left = insert_node(node->left, pair, node);
    //         }
    //         else if (_comp(node->pair.first, pair.first))
    //         {
    //             node->right = insert_node(node->right, pair, node); 
    //         }
    //         else 
    //             return node;

    //         node->height =  max(height(node->left),height(node->right)) + 1;
    //         int balance = getBalance(node);

    //         // Left Left Case
    //         if (balance > 1 && _comp(pair.first, node->left->pair.first)) //pair.first < node->left->pair.first
    //             return rightRotate(node);
    //         // Right Right Case
    //         if (balance < -1 && _comp(node->right->pair.first, pair.first)) // pair.first > node->right->pair.first
    //             return leftRotate(node);
    //         // Left Right Case
    //         if (balance > 1 && _comp(node->left->pair.first, pair.first)) // pair.first > node->left->pair.first
    //         {
    //             node->left = leftRotate(node->left);
    //             return rightRotate(node);
    //         }
    //         // Right Left Case
    //         if (balance < -1 && _comp(pair.first, node->right->pair.first)) // pair.first < node->right->pair.first
    //         {
    //             node->right = rightRotate(node->right);
    //             return leftRotate(node);
    //         }
    //         return node;
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


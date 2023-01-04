
 # pragma once

//#include "pair.hpp"  	
#include <algorithm>
# include <functional>
# include <iostream>
#include "nodda.hpp"
using namespace std;

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++**/
/// AVL Tree implementation using C | AVL Tree Code | rotations in AVL Tree | LL RR LR RL rotation // https://www.youtube.com/watch?v=L0cDtyphZRc

// class value_compare
//           : public binary_function<value_type,value_type,bool> {
//         friend class AVL;
//         protected:
//           Compare comp;
//           value_compare(Compare c) : comp(c) {}
//         public:
//           bool operator()(const value_type& x, const value_type& y) const {
//             return comp(x.first, y.first);
// } };

//AVL Tree

template <class T , class alloc >
class AVL{
    public:
        typedef typename T::first_type   pair_first_pair;
      
        typedef typename alloc::template rebind<nodaaa<T,alloc> >::other _node_alloc; // alloc node
        typedef alloc											allocator_type;
        typedef size_t                                          size_type;

    public:
        nodaaa<T,alloc> *_head;
        _node_alloc  alloc_node;
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
        alloc_node = ref._alloc;
       // _key_compare = ref._key_compare;
        _size = ref._size;
    }
    
    int height(nodaaa<T,alloc> *n)
    {
        if (n == NULL)
            return 0;
        return n->height;
    }

    nodaaa<T,alloc> *min_node(nodaaa<T,alloc> *node) 
    {
        if (node)
        {
            while (node->left)
                node = node->left;
        }
        return (node);
    }

    nodaaa<T,alloc> *max_node(nodaaa<T,alloc> *node)
    {
        if (node)
        {
            while (node->right)
                node = node->right;
        }
        return (node);
    }

    int getBalance(nodaaa<T,alloc> *n)
    {
        if (n == NULL)
            return 0;
        return height(n->left) - height(n->right);
    }

   int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    // bool key_comp(nodaaa<T,alloc> *n1, nodaaa<T,alloc> *n2){
    //     return (n1->_pair.first > n2->_pair.first);
    // }

    nodaaa<T,alloc> *allocate_new_node(T _pair)
    {
        nodaaa<T,alloc> *node = alloc_node.allocate(1);
        alloc_node.construct(node,nodaaa<T,alloc>(_pair));
        return node;
    }


        nodaaa<T,alloc> *rightRotate(nodaaa<T,alloc>*y)
        {
            nodaaa<T,alloc> *x = y->left;
            nodaaa<T,alloc> *T2 = x->right;

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

        nodaaa<T,alloc> *leftRotate(nodaaa<T,alloc> *x)
        {
            nodaaa<T,alloc>*y = x->right;
            nodaaa<T,alloc> *T2 = y->left;

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
        nodaaa<T,alloc> *insert (nodaaa<T,alloc> *node, T pair){
        if (node == NULL){
            _size++;
             return (allocate_new_node(pair));
        }
        if (pair.first < node->pair->first){
            node->left = insert(node->left, pair);
        }
        else if (pair.first > node->pair->first ){
            node->right =  insert(node->right, pair);;
        }
        else 
            return (node);

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        /// second cases
        if (balance > 1 && pair.first < node->left->pair->first)
            return (rightRotate(node));
       
        if (balance > 1 &&  pair.first > node->left->pair->first ){
            node->left = leftRotate(node->left);
            return (rightRotate(node));
        }

        /// First cases
        if (balance < -1 &&  pair.first > node->right->pair->first )
            return (leftRotate(node));

        if (balance < -1 && pair.first < node->right->pair->first){
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

    int     node_is_blanced(nodaaa<T,alloc>*root)
    {
        int is_balanced = 
        is_balanced = (root->left) ? (root->left->heghit) : 0;
        is_balanced -= (root->right) ? (root->right->heghit): 0;
    }

    nodaaa<T,alloc> *deletenode(nodaaa<T,alloc> *node,  pair_first_pair first){

        if (node == NULL)
            return (node);

        if (first < node->pair->first){
            node->left = deletenode(node->left, first);
        }
        else if (first > node->pair->first){
            node->right = deletenode(node->right, first);

        }
        else {
            if ((node->left == NULL) || (node->right == NULL)){
                nodaaa<T,alloc> *temp = node->left ? node->left : node->right;

                if (temp == NULL){
                    temp = node;
                    node = NULL;
                }
                else{
                    *node = *temp;
                }
                     --_size;
                    alloc_node.destroy(temp);
                    alloc_node.deallocate(temp,1);
    
            }else
            {
                nodaaa<T,alloc> *temp  = min_node(node->right);
                node->pair = temp->pair;
                node->right = deletenode(node->right,temp->pair.first);

            }
        }
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


    void dellocate_node(nodaaa<T,alloc> *node){
        if (node){
            dellocate_node(node->left);
            dellocate_node(node->right);
            alloc_node.destroy(node);
            alloc_node.deallocate(node,1);
        }
    }

        nodaaa<T,alloc> *find_key(nodaaa<T,alloc> *node,  pair_first_pair first) {
        if (node == NULL)
            return (NULL);
        if (node->pair->first == first)
            return(node);
        nodaaa<T,alloc> *n1 = find(node->left, first);
        if (n1)
            return (n1);
        nodaaa<T,alloc> *n2 = find(node->right, first);
        return (n2);
    }

    void printTree(nodaaa<T,alloc> *root, string indent, bool last)
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

     void printTreechekinsert(nodaaa<T,alloc> *root) {
        
        if(root!=NULL)
        {
            printTreechekinsert(root->left);
           printTreechekinsert(root->right);
            cout << root->pair->first << "  ";
        }
    }
    
    void print2DUtil(nodaaa<T,alloc>* root, int space)
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
    cout << root->pair->first << "\n";
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void affiche(nodaaa<T,alloc>* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

    nodaaa<T,Alloc> parent_node(nodaaa<T,Alloc> root, pair_first_pair k)
    {

        if(root == ull || node->pair.first = k)
            return null;
        
        if((root->left != null && node->left->pair.first == k) || )

    }


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



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
      
        typedef typename alloc::template rebind<nodaaa<T,alloc> >::other _noode_alloc; // alloc noode
        typedef alloc											allocator_type;
        typedef size_t                                          size_type;

    public:
        nodaaa<T,alloc> *_head;
        _noode_alloc  alloc_noode;
        size_type _size;
        nodaaa<T,alloc> *_parent;


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
        alloc_noode = ref.alloc_noode;
       // _key_compare = ref._key_compare;
        _size = ref._size;
    }
    
    int height(nodaaa<T,alloc> *n)
    {
        if (n == NULL)
            return 0;
        return n->height;
    }

    nodaaa<T,alloc> *min_noode(nodaaa<T,alloc> *noode) 
    {
        if (noode)
        {
            while (noode->left)
                noode = noode->left;
        }
        return (noode);
    }

    nodaaa<T,alloc> *max_noode(nodaaa<T,alloc> *noode)
    {
        if (noode)
        {
            while (noode->right)
                noode = noode->right;
        }
        return (noode);
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

    nodaaa<T,alloc> *allocate_new_noode(T _pair)
    {
        nodaaa<T,alloc> *noode = alloc_noode.allocate(1);
        alloc_noode.construct(noode,nodaaa<T,alloc>(_pair));
        return noode;
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
        nodaaa<T,alloc> *insert (nodaaa<T,alloc> *noode, T pair){
        if (noode == NULL){
            _size++;
             return (allocate_new_noode(pair));
        }
        if (pair.first < noode->pair->first){
            noode->left = insert(noode->left, pair);
        }
        else if (pair.first > noode->pair->first ){
            noode->right =  insert(noode->right, pair);;
        }
        else 
            return (noode);

        noode->height = 1 + max(height(noode->left), height(noode->right));

        int balance = getBalance(noode);

        /// second cases
        if (balance > 1 && pair.first < noode->left->pair->first)
            return (rightRotate(noode));
       
        if (balance > 1 &&  pair.first > noode->left->pair->first ){
            noode->left = leftRotate(noode->left);
            return (rightRotate(noode));
        }

        /// First cases
        if (balance < -1 &&  pair.first > noode->right->pair->first )
            return (leftRotate(noode));

        if (balance < -1 && pair.first < noode->right->pair->first){
            noode->right = rightRotate(noode->right);
            return (leftRotate(noode));
        }
        return (noode);
    }
            ////////////////////// insert //////////////////////////



    size_type   treesize()
    {
        return _size;
    }

    int     noode_is_blanced(nodaaa<T,alloc>*root)
    {
        int is_balanced;
        is_balanced = (root->left) ? (root->left->heghit) : 0;
        is_balanced -= (root->right) ? (root->right->heghit): 0;
    }

    nodaaa<T,alloc> *deletenoode(nodaaa<T,alloc> *noode,  pair_first_pair first){

        if (noode == NULL)
            return (noode);

        if (first < noode->pair->first){
            noode->left = deletenoode(noode->left, first);
        }
        else if (first > noode->pair->first){
            noode->right = deletenoode(noode->right, first);

        }
        else {
            if ((noode->left == NULL) || (noode->right == NULL)){
                nodaaa<T,alloc> *temp = noode->left ? noode->left : noode->right;

                if (temp == NULL){
                    temp = noode;
                    noode = NULL;
                }
                else{
                    *noode = *temp;
                }
                     --_size;
                    alloc_noode.destroy(temp);
                    alloc_noode.deallocate(temp,1);
    
            }else
            {
                nodaaa<T,alloc> *temp  = min_noode(noode->right);
                noode->pair = temp->pair;
                noode->right = deletenoode(noode->right,temp->pair.first);

            }
        }
        if (noode == NULL)
            return (noode);

        noode->height = 1 + max(height(noode->left), height(noode->right));
        int balance = getBalance(noode);
        if (balance > 1 && getBalance(noode->left) >= 0)
            return (rightRotate(noode));


        if (balance > 1 && getBalance(noode->left) < 0){
            noode->left = leftRotate(noode->left);
            return (rightRotate(noode));
        }

        if (balance < -1 && getBalance(noode->right) <= 0)
            return (leftRotate(noode));
        if (balance < -1 && getBalance(noode->right) > 0){
            noode->right = rightRotate(noode->right);
            return (leftRotate(noode));
        }
        return (noode);
    }


    void dellocate_noode(nodaaa<T,alloc> *noode){
        if (noode){
            dellocate_noode(noode->left);
            dellocate_noode(noode->right);
            alloc_noode.destroy(noode);
            alloc_noode.deallocate(noode,1);
        }
    }

        nodaaa<T,alloc> *find_key(nodaaa<T,alloc> *noode,  pair_first_pair first) {
        if (noode == NULL)
            return (NULL);
        if (noode->pair->first == first)
            return(noode);
        nodaaa<T,alloc> *n1 = find(noode->left, first);
        if (n1)
            return (n1);
        nodaaa<T,alloc> *n2 = find(noode->right, first);
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
 
    // Print current noode after space
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

nodaaa<T,alloc> *parent_noode(nodaaa<T,alloc> *root, pair_first_pair k)
{

        if(root == NULL || root->pair->first == k)
            return NULL;
            
        if ((root->left != NULL && root->left->pair->first == k) || (root->right != NULL && root->right->pair->first == k))
                return root;
        nodaaa<T,alloc> *noode  = parent_noode(root->left,k);
        if (noode != NULL)
         return noode;
        noode = parent_noode(root->right,k);
    return noode;            

}



};


 



    //     int height(noode *n)
    //     {
    //         if (n == NULL)
    //             return 0;
    //         return n->height;
    //     }

    //     noode *Createnewnoode(const value_type &val, noode *parent = NULL)
    //     {
    //         noode *noode;
    //         noode = _alloc_noode.allocate(1);
    //         _allocator_type.construct(&noode->val, val);
    //         noode->right = NULL;
    //         noode->left = NULL;
    //         noode->parent = parent;
    //         noode->height = 1;
    //         return (noode);
    //     }



    //     noode *insert_noode(noode *noode, const value_type &val, noode *parent = NULL)
    //     {
    //         if (noode == NULL)
    //             return (Createnewnoode(val, parent)); 
    //         if (_comp(val.first, noode->val.first))
    //         {
    //             noode->left = insert_noode(noode->left, val, noode);
    //         }
    //         else if (_comp(noode->val.first, val.first))
    //         {
    //             noode->right = insert_noode(noode->right, val, noode); 
    //         }
    //         else 
    //             return noode;

    //         noode->height =  max(height(noode->left),height(noode->right)) + 1;
    //         int balance = getBalance(noode);

    //         // Left Left Case
    //         if (balance > 1 && _comp(val.first, noode->left->val.first)) //val.first < noode->left->val.first
    //             return rightRotate(noode);
    //         // Right Right Case
    //         if (balance < -1 && _comp(noode->right->val.first, val.first)) // val.first > noode->right->val.first
    //             return leftRotate(noode);
    //         // Left Right Case
    //         if (balance > 1 && _comp(noode->left->val.first, val.first)) // val.first > noode->left->val.first
    //         {
    //             noode->left = leftRotate(noode->left);
    //             return rightRotate(noode);
    //         }
    //         // Right Left Case
    //         if (balance < -1 && _comp(val.first, noode->right->val.first)) // val.first < noode->right->val.first
    //         {
    //             noode->right = rightRotate(noode->right);
    //             return leftRotate(noode);
    //         }
    //         return noode;
    //     }

    
    //     noode *min_noode(noode *noode)
    //     {
    //         if (noode)
    //         {
    //             while (noode->left)
    //                 noode = noode->left;
    //         }
    //         return (noode);
    //     }

    //     noode *max_noode(noode *noode)
    //     {
    //         if (noode)
    //         {
    //             while (noode->right)
    //                 noode = noode->right;
    //         }
    //         return (noode);
    //     }

    //     size_type tree_size(noode *noode) const
    //     {
    //         if (noode == NULL || noode->right == _last_noode)
    //             return 0;
    //         return (tree_size(noode->left) + 1 + tree_size(noode->right));
    //     }

    //  int calcule_height(noode *parent)

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

    //     int     noode_is_blanced(noode *root)
    // {
    //     int is_balanced = 
    //     is_balanced = (root->left) ? (root->left->heghit) : 0;
    //     is_balanced -= (root->right) ? (root->right->heghit): 0;
    // }



# pragma once
//#include "pair.hpp"  	
#include <algorithm>

  #include <functional>
  #include <iostream>
  #include "nodda.hpp"
  #include "pair.hpp"

  #include "tree_iterator.hpp"

  using namespace std;

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++**/
/// AVL Tree implementation using C | AVL Tree Code | rotations in AVL Tree | LL RR LR RL rotation // https://www.youtube.com/watch?v=L0cDtyphZRc

//AVL Treeå
template < class Key, class Type, class T, class alloc, class Compare >
  class AVL {
    public: typedef typename T::first_type pair_first_pair;

    typedef typename alloc::template rebind < nodaaa < Key,
    Type,
    T,
    alloc > > ::other _noode_alloc; // alloc noode
    typedef alloc allocator_type;
    typedef size_t size_type;
    typedef Compare ft_compare;

    public: nodaaa < Key,
    Type,
    T,
    alloc > * _head;
    _noode_alloc alloc_noode;
    size_type _size;
    //nodaaa<Key,Type,T,alloc> *_root;
    ft_compare _comp;
    alloc alloc_pr;

    AVL() {
      _head = NULL;
      _size = 0;
    }

    void swap(AVL & x) {
      AVL tmp;

      tmp._head = this -> _head;
      tmp.alloc_noode = this -> alloc_noode;

      this -> _head = x._head;
      this -> alloc_noode = x.alloc_noode;

      x._head = tmp._head;
      x.alloc_noode = tmp.alloc_noode;
    }

    AVL(const AVL & ref) {
      * this = ref;
    }

    AVL & operator = (const AVL & ref) {
      _head = ref._head;
      alloc_noode = ref.alloc_noode;
      // _key_compare = ref._key_compare;
      _size = ref._size;
      return ( * this);
    }

    int height(nodaaa < Key, Type, T, alloc > * n) {
      if (n == NULL)
        return 0;
      return n -> height;
    }

    nodaaa < Key,
    Type,
    T,
    alloc > * min_noode(nodaaa < Key, Type, T, alloc > * noode) const {
      if (noode) {
        while (noode -> left)
          noode = noode -> left;
      }
      return (noode);
    }

    nodaaa < Key,
    Type,
    T,
    alloc > * max_noode(nodaaa < Key, Type, T, alloc > * noode) {
      if (noode) {
        while (noode -> right)
          noode = noode -> right;
      }
      return (noode);
    }

    int getBalance(nodaaa < Key, Type, T, alloc > * n) {
      if (n == NULL)
        return 0;
      return height(n -> left) - height(n -> right);
    }

    int max(int a, int b) {
      return (a > b) ? a : b;
    }

    // bool key_comp(nodaaa<Key,Type,T,alloc> *n1, nodaaa<Key,Type,T,alloc> *n2){
    //     return (n1->_pair.first > n2->_pair.first);
    // }

    nodaaa < Key,
    Type,
    T,
    alloc > * allocate_new_noode(T _pair) {
      nodaaa < Key, Type, T, alloc > * noode = alloc_noode.allocate(1);
      alloc_noode.construct(noode, nodaaa < Key, Type, T, alloc > (_pair)); 
      return noode;
    }
    nodaaa < Key,
  
    Type,
    T,
    alloc > * rightRotate(nodaaa < Key, Type, T, alloc > * y) {
      nodaaa < Key, Type, T, alloc > * x = y -> left;
      nodaaa < Key, Type, T, alloc > * T2 = x -> right;

      x -> right = y;
      y -> left = T2;

      x -> parent = y -> parent;
      y -> parent = x;
      if (T2)
        T2 -> parent = y;

      y -> height = max(height(y -> left), height(y -> right)) + 1;
      x -> height = max(height(x -> left), height(x -> right)) + 1;
      return x;
    }

    nodaaa < Key,
    Type,
    T,
    alloc > * leftRotate(nodaaa < Key, Type, T, alloc > * x) {
      nodaaa < Key, Type, T, alloc > * y = x -> right;
      nodaaa < Key, Type, T, alloc > * T2 = y -> left;

      y -> left = x;
      x -> right = T2;

      y -> parent = x -> parent;
      x -> parent = y;
      if (T2)
        T2 -> parent = x;

      x -> height = max(height(x -> left), height(x -> right)) + 1;
      y -> height = max(height(y -> left), height(y -> right)) + 1;
      return y;
    }

    ////////////////////// insert //////////////////////////
    nodaaa < Key,
    Type,
    T,
    alloc > * insert(nodaaa < Key, Type, T, alloc > * noode, T pair) {
      if (noode == NULL) {
        _size++;
        return (allocate_new_noode(pair));
      }

      if (_comp(pair.first, noode -> pair -> first)) {
        noode -> left = insert(noode -> left, pair);
      } else if (_comp(noode -> pair -> first, pair.first)) {
        noode -> right = insert(noode -> right, pair);
      } else
        return (noode);

      noode -> height = 1 + max(height(noode -> left), height(noode -> right));

      int balance = getBalance(noode);

      /// second cases
      if (balance > 1 && _comp(pair.first, noode -> pair -> first))
        return (rightRotate(noode));

      if (balance > 1 && _comp(noode -> pair -> first, pair.first)) {
        noode -> left = leftRotate(noode -> left);
        return (rightRotate(noode));
      }

      /// First cases
      if (balance < -1 && _comp(noode -> right -> pair -> first, pair.first))
        return (leftRotate(noode));

      if (balance < -1 && _comp(pair.first, noode -> right -> pair -> first)) {
        noode -> right = rightRotate(noode -> right);
        return (leftRotate(noode));
      }
      return (noode);
    }
    ////////////////////// insert //////////////////////////

    size_type treesize() {
      return _size;
    }

    int noode_is_blanced(nodaaa < Key, Type, T, alloc > * root) {
      int is_balanced;
      is_balanced = (root -> left) ? (root -> left -> heghit) : 0;
      is_balanced -= (root -> right) ? (root -> right -> heghit) : 0;
    }

    nodaaa < Key,
    Type,
    T,
    alloc > * dele(nodaaa < Key, Type, T, alloc > * node,
      const pair_first_pair key) {

      if (node == NULL)
        return NULL;
      else if (key < node->pair->first)
          node->left = dele(node->left,key);
      else if (key > node->pair->first)
            node->right = dele(node->right,key);
      else
      {
           nodaaa < Key, Type, T, alloc > * temp;
          if(node->left == NULL) // node with only right child or not
          {
           temp = node->right;
            alloc_pr.destroy(node->pair);
            alloc_noode.destroy(node);
            alloc_pr.deallocate(node->pair, 1);
            alloc_noode.deallocate(node, 1);

            return temp;
          } 
          else if (node->right == NULL)
          {
            temp = node->left;
           alloc_pr.destroy(node->pair);
           alloc_noode.destroy(node);
           alloc_pr.deallocate(node->pair, 1);
           alloc_noode.deallocate(node, 1);
            return temp;
          }
          else
          {
            temp = min_noode(node->right);
            alloc_pr.destroy(node->pair);
            alloc_pr.construct(node->pair, ft::make_pair(temp->pair->first, temp->pair->second));
            node->right = dele(node->right,temp->pair->first);
          }

      }

        //  alloc_pr.destroy(a->pair);
        //   alloc_pr.deallocate(a->pair, 1);
        //   alloc_noode.destroy(a);
        //   alloc_noode.deallocate(a, 1);
         
      if (node == NULL) {
        return NULL;
      }
      node -> height = 1 + max(height(node -> left), height(node -> right));

      int balance = getBalance(node);

      if (balance > 1) {
        if (getBalance(node -> left) >= 0) {
          node = rightRotate(node);
        } else {
          node -> left = leftRotate(node -> left);
          node = rightRotate(node);
        }
      } else if (balance < -1) {
        if (getBalance(node -> right) <= 0) {
          node = leftRotate(node);
        } else {
          node -> right = rightRotate(node -> right);
          node = leftRotate(node);
        }
      }
      return node;
    }

    // nodaaa<Key,Type,T,alloc> *delet(pair_first_pair first)
    // {
    //     return deletenoode(_head,first);
    // }

    // nodaaa<key,Type,alloc> *insertfisrt(pair_first_pair first)
    // {
    //     insert(this._head,first);
    // }

    void dellocate_noode(nodaaa < Key, Type, T, alloc > * noode) {
      if (noode) {
        dellocate_noode(noode -> left);
        dellocate_noode(noode -> right); 
        alloc_pr.destroy(noode->pair);
        alloc_pr.deallocate(noode->pair, 1);   
        alloc_noode.destroy(noode);
        alloc_noode.deallocate(noode, 1);
      }
    }

    nodaaa < Key,
    Type,
    T,
    alloc > * find_key(nodaaa < Key, Type, T, alloc > * noode, pair_first_pair first) const {
      if (noode == NULL)
        return (NULL);
      if (noode -> pair -> first == first)
        return (noode);
      else if (_comp(first, noode -> pair -> first)) {
        nodaaa < Key, Type, T, alloc > * n1 = find_key(noode -> left, first);
        return (n1);
      } else if (_comp(noode -> pair -> first, first)) {
        nodaaa < Key, Type, T, alloc > * n2 = find_key(noode -> right, first);
        return (n2);
      }
      return noode;
    }

    void printTree(nodaaa < Key, Type, T, alloc > * root, string indent, bool last) {
      if (root != nullptr) {
        cout << indent;
        if (last) {
          cout << "R----";
          indent += "   ";
        } else {
          cout << "L----";
          indent += "|  ";
        }
        cout << root -> pair.second << endl;
        printTree(root -> left, indent, false);
        printTree(root -> right, indent, true);
      }
    }

    void printTreechekinsert(nodaaa < Key, Type, T, alloc > * root) {

      if (root != NULL) {
        printTreechekinsert(root -> left);
        printTreechekinsert(root -> right);
        cout << root -> pair -> first << "  ";
      }
    }

    void print2DUtil(nodaaa < Key, Type, T, alloc > * root, int space) {
      // Base case
      if (root == NULL)
        return;

      // Increase distance between levels
      space += 10;

      // Process right child first
      print2DUtil(root -> right, space);

      // Print current noode after space
      // count
      cout << endl;
      for (int i = 10; i < space; i++)
        cout << " ";
      cout << root -> pair -> first << "(" << root -> pair -> second << ")" << "\n";

      // Process left child
      print2DUtil(root -> left, space);
    }

    // Wrapper over print2DUtil()
    void affiche(nodaaa < Key, Type, T, alloc > * root) {
      // Pass initial space count as 0
      print2DUtil(root, 0);
    }

       nodaaa < Key, Type, T, alloc > *parent_noode(nodaaa < Key, Type, T, alloc > *root, pair_first_pair k)
    {
       nodaaa < Key, Type, T, alloc > *noode;
        if(root == NULL || root->pair->first == k)
            return NULL;
            
        if ((root->left != NULL && root->left->pair->first == k) || (root->right != NULL && root->right->pair->first == k))
                return root;
        else if(root->pair->first > k)
        {

            noode  = parent_noode(root->left,k);
            if (noode != NULL)
            return noode;

        }
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

/*
 
 void swap (AVL& x)
			{
				AVL tmp;

				tmp.root = this->root;
				tmp._alloc = this->_alloc;
				tmp._alloc_node = this->_alloc_node;
				tmp._compare = this->_compare;
				
				this->root = x.root;
				this->_alloc = x._alloc;
				this->_alloc_node = x._alloc_node;
				this->_compare = x._compare;
				
				x.root = tmp.root;
				x.root_parent = tmp.root_parent;
				x._alloc = tmp._alloc;
				x._alloc_node = tmp._alloc_node;
				x._compare = tmp._compare;
			}
 
 */
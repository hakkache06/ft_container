
#pragma once


# include <algorithm>
# include <functional>
# include <iostream>
#include "pair.hpp"
#include "vector.hpp"
#include "iterator.hpp"
# include "bidirectional_iterator.hpp"
#include "nodaaa.hpp"
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

        //// iterator 
        //typedef typename	ft::bidirectional_iterator<_node, value_type>		iterator;
		//typedef typename	ft::bidirectional_iterator<_node, const value_type>	const_iterator;

        typedef typename ft::reverse_iterator < iterator > reverse_iterator;
        typedef typename ft::reverse_iterator < const_iterator > const_reverse_iterator;
        //fin iterator


        public : // frined class AVL and node 
            
        struct  nodaaa 
        {

            public: 
            value_type _pair;
            nodaaa * parent;
            nodaaa * left;
            nodaaa * right;
            size_t height;
            public:

                // default construct nodaaa 
                nodaaa() {
                parent = NULL;
                left = NULL;
                right = NULL;
                height= 0;
                };

            nodaaa(value_type pair): _pair(pair) {
                parent = NULL;
                left = NULL;
                right = NULL;
                height = 1;
            };

            nodaaa & operator = (const nodaaa  & ref) {
                parent = ref.parent;
                left = ref.left;
                right = ref.right;
                height = ref.height;
                return ( * this);
            };

            nodaaa(const nodaaa& ref): _pair(ref._pair) {
                *this = ref;
            }
            ~nodaaa() {};

        };

        //class avl frined

    template<typename T>
    class AVL{
    public:
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
 

        // class value compare
        class value_compare: public std::binary_function<value_type,value_type,bool> 
        {
            friend class map;
        protected:
            Compare comp;
            value_compare(Compare c) : comp(c) {}
        public:
            bool operator()(const value_type& x, const value_type& y) const
             {
                return comp(x.first, y.first);
            }
        };

        public :

        // Construct empty
        explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
        {
            avl_tree._alloc = alloc;
            avl_tree._key_compare = comp;
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
		typedef	nodaaa<value_type> _node;
		typedef typename allocator_type::template rebind<_node>::other		_avl_allocator;
		AVL<value_type, key_compare> avl_tree;    

    };

}

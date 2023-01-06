#pragma once

#include "nodda.hpp"
#include "Avl.hpp"
namespace ft
{
        template <class T, class Alloc, class U>
    class tree_iterator{
    public:
        typedef T value_type;
        typedef std::ptrdiff_t difference_type; 
	    typedef	T*  pointer;
		typedef const T* const_pointer;
	    typedef T& reference;
        typedef const T& const_reference;
		typedef std::bidirectional_iterator_tag iterator_category;
        typedef typename T::first_type   pair_first_pair;

        U tree;
        tree_iterator(nodaaa<T,Alloc> *node, U _tree){
            nodas = node;
            tree = _tree;
         }

        // tree_iterator(const tree_iterator &ref):avl_tree_iter(ref.avl_tree_iter){
        // };

        // const tree_iterator &operator=(const tree_iterator &rhs){
        //     if (this == &rhs)
	    // 	    return (*this);
	    //     this->avl_tree_iter = rhs.avl_tree_iter;
        //     return (*this);
        // }
        ~tree_iterator(){
        }
        
    nodaaa<T,Alloc> *min_noode(nodaaa<T,Alloc> *noode) 
    {
        if (noode)
        {
            while (noode->left)
                noode = noode->left;
        }
        return (noode);
    }       

    nodaaa<T,Alloc> *parent_noode(nodaaa<T,Alloc> *root, pair_first_pair k)
    {

        if(root == NULL || root->pair->first == k)
            return NULL;
            
        if ((root->left != NULL && root->left->pair->first == k) || (root->right != NULL && root->right->pair->first == k))
                return root;
        nodaaa<T,Alloc> *noode  = parent_noode(root->left,k);
        if (noode != NULL)
         return noode;
        noode = parent_noode(root->right,k);
        return noode;            
    }

    const tree_iterator& operator--()
    {
        if(nodas ==  nullptr)
            return (*this);
        if(nodas->left == NULL && nodas->right == NULL)
            return (*this);

        if (nodas->left != nullptr)
        {
            nodas = min_noode(nodas->left);
        }else
        {
            nodaaa<T,Alloc> *parent = parent_noode(tree._head,nodas->pair->first);
            while (parent != nullptr && nodas == parent->left)
            {
                nodas = parent;
                parent = parent_noode(tree._head,parent->pair->first);
            }
            nodas = parent;
        }
        return (*this);
    }

    const tree_iterator& operator++()
    {
        if(nodas ==  nullptr)
            return (*this);
        if (nodas->right != nullptr)
        {
            nodas = min_noode(nodas->right);
        }else
        {
            nodaaa<T,Alloc> *parent = parent_noode(tree._head,nodas->pair->first);
            while (parent != nullptr && nodas == parent->right)
            {
                nodas = parent;
                parent = parent_noode(tree._head,parent->pair->first);
            }
            nodas = parent;
        }
        return (*this);
    }
	    tree_iterator operator++(int){
            tree_iterator tmp(*this);
            operator++();
            return (tmp);
        }
			
        // Dereference operator (*it).
        reference operator * () const {
            return * (this->nodas->pair);
        }
        // Pointer operator (it.operator->()).
        pointer operator -> () const {
            return & (operator * ());
      }
	    tree_iterator operator--(int)
        {
			tree_iterator tmp(*this);
            operator--();
            return (tmp);
		} 

        // const tree_iterator& operator--() {
        //     if (nodas->left) {
        //         nodas = nodas->left;
        //         while (nodas->right) {
        //             nodas = nodas->right;
        //         }
        //     } else {
        //         nodaaa<T,Alloc> *parent = parent_noode(tree._head,nodas->pair->first);
        //         while (parent && parent->left == nodas) {
        //             nodas = parent;
        //             parent = parent_noode(tree._head,parent->pair->first);;
        //         }
        //         nodas = parent;
        //     }
        //     return *this;
        // }


        bool operator==(const tree_iterator &it)const{
            return (nodas == it.nodas);
        };
        bool operator!=(const tree_iterator &it)const{
            return (nodas != it.nodas);
        };
        bool operator==(tree_iterator &x){
            return(this->nodas == x.nodas);
        }
        bool operator!=(tree_iterator &x){
            return(this->nodas != x.nodas);
        }
        public:
        nodaaa<T,Alloc> *nodas;
    }; 

}

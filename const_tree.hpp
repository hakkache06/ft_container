#pragma once

#include "nodda.hpp"
#include "Avl.hpp"
namespace ft
{
        template <class Key ,class Type,class T, class Alloc, class U>
    class const_tree{
    public:



    public: 
      typedef typename ft::iterator_traits < ft::iterator < std::bidirectional_iterator_tag,Type > > ::value_type value_type;
      typedef typename ft::iterator_traits < ft::iterator < std::bidirectional_iterator_tag,Type > > ::difference_type difference_type;
      typedef typename ft::iterator_traits < ft::iterator < std::bidirectional_iterator_tag,Type > > ::pointer pointer;
      typedef typename ft::iterator_traits < ft::iterator < std::bidirectional_iterator_tag,Type > > ::reference reference;
      typedef typename ft::iterator_traits < ft::iterator < std::bidirectional_iterator_tag,Type > > ::iterator_category iterator_category;

        // typedef T value_type;
        // typedef std::ptrdiff_t difference_type; 
	    // typedef	T*  pointer;
		// typedef const T* const_pointer;
	    // typedef T& reference;
        // typedef const T& const_reference;
		// typedef std::bidirectional_iterator_tag iterator_category;
        typedef typename T::first_type   pair_first_pair;

        U tree;

        const_tree():nodas(NULL),tree(){
        }
        const_tree( nodaaa<Key,Type,T,Alloc> *node, U _tree):nodas(node),tree(_tree){
 
         }
        const_tree(const const_tree &ref):nodas(ref.nodas),tree(ref.tree){
        };
        const_tree &operator=(const const_tree &rhs){
            if (this == &rhs)
	    	    return (*this);
	        this->nodas = rhs.nodas;
            this->tree = rhs.tree;
            return (*this);
        }
        ~const_tree(){
        }


    const_tree& operator--()
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
            nodaaa<Key,Type,T,Alloc> *parent = parent_noode(tree._head,nodas->pair->first);
            while (parent != nullptr && nodas == parent->left)
            {
                nodas = parent;
                parent = parent_noode(tree._head,parent->pair->first);
            }
            nodas = parent;
        }
        return (*this);
    }

    const_tree& operator++()
    {
        if(nodas ==  nullptr)
            return (*this);
        if (nodas->right != nullptr)
        {
            nodas = min_noode(nodas->right);
        }else
        {
            nodaaa<Key,Type,T,Alloc> *parent = parent_noode(tree._head,nodas->pair->first);
            while (parent != nullptr && nodas == parent->right)
            {
                nodas = parent;
                parent = parent_noode(tree._head,parent->pair->first);
            }
            nodas = parent;
        }
        return (*this);
    }
	    const_tree operator++(int){
            const_tree tmp(*this);
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
	    const_tree operator--(int)
        {
			const_tree tmp(*this);
            operator--();
            return (tmp);
		} 

        // const const_tree& operator--() {
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


        bool operator==(const const_tree &it)const{
            return (nodas == it.nodas);
        };
        bool operator!=(const const_tree &it)const{
            return (nodas != it.nodas);
        };
        bool operator==(const_tree &x){
            return(this->nodas == x.nodas);
        }
        bool operator!=(const_tree &x){
            return(this->nodas != x.nodas);
        }
        public:
        nodaaa<Key,Type,T,Alloc> *nodas;
    }; 

}

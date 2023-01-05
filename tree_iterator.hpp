
#pragma once

#include "nodda.hpp"
#include "Avl.hpp"
namespace ft
{
        template <class T, class Alloc>
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

        tree_iterator(nodaaa<T,Alloc> *node){
            this->_root = node;
         }

        // tree_iterator(const tree_iterator &ref):_root(ref._root){
        // };


        const tree_iterator &operator=(const tree_iterator &rhs){
            if (this == &rhs)
	    	    return (*this);
	        this->_root = rhs._root;
            return (*this);
        }

        ~tree_iterator(){
        }
        
        tree_iterator& operator++()
        {
            if(_root == nullptr)
                return (*this);

            if (_root->right != nullptr)
            {
                   _root = min_noode(_root->right);
                   return _root;
            }
            else
            {   
                 nodaaa<T,Alloc> *parent = parent_noode(_root,_root->pair->first);

                  if (_root->right == NULL && _root == parent->left)
                  {
                    _root = parent;
                    return (_root);
                  }  

                  else if (_root->right == NULL && _root == parent->right)  
                  {
                    while (parent != nullptr && _root == parent->right)
                    {
                        _root = parent;
                        parent = parent_noode(_root,parent->pair->first);
                    }
                        _root = parent;
                  }
            }
                return (*this);
        }

        pointer operator->()const{
            return (this->_root->pair);
        }
        reference operator*()const{
            return (this->_root->pair);
        }


    //    const tree_iterator& operator--()
    //     {
    //         if(_root == nullptr)
    //             return (*this);

    //         if (_root != nullptr)
    //         {
    //                _root = _root.min_node(_root->left);
    //         }else
    //         {
    //             nodaaa<T,Alloc> *parent = _root.parent_noode(_root);
    //             while (parent != nullptr && _root == parent->left)
    //             {
    //                 _root = parent;
    //                 parent = _root.parent_noode(parent);
    //             }   
    //             _root = parent;
    //                 return (*this);

    //         }
    //     }

	    const tree_iterator operator++(int){
            tree_iterator tmp(*this);
            operator++();
            return (tmp);
        }
			
	    // const tree_iterator operator--(int){
		// 	tree_iterator tmp(*this);
        //     operator--();
        //     return (tmp);
		// } 

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

    nodaaa<T,Alloc> *min_noode(nodaaa<T,Alloc> *noode) 
    {
        if (noode)
        {
            while (noode->left)
                noode = noode->left;
        }
        return (noode);
    }

        bool operator==(const tree_iterator &it)const{
            return (_root == it._root);
        };
        bool operator!=(const tree_iterator &it)const{
            return (_root != it._root);
        };
        bool operator==(tree_iterator &x){
            return(this->_root == x._root);
        }
        bool operator!=(tree_iterator &x){
            return(this->_root != x._root);
        }
        public:
        nodaaa<T,Alloc> _root;
    }; 

}



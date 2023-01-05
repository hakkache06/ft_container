
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


        tree_iterator(nodaaa<T,Alloc> *node){
            this->avl_tree_iter._head = node;
         }

        // tree_iterator(const tree_iterator &ref):avl_tree_iter(ref.avl_tree_iter){
        // };


        const tree_iterator &operator=(const tree_iterator &rhs){
            if (this == &rhs)
	    	    return (*this);
	        this->avl_tree_iter = rhs.avl_tree_iter;
            return (*this);
        }

        ~tree_iterator(){
        }
        
        tree_iterator& operator++()
        {
            if(avl_tree_iter._head == nullptr)
                return (*this);

            if (avl_tree_iter._head->right != nullptr)
            {
                   avl_tree_iter._head = avl_tree_iter.min_noode(avl_tree_iter._head->right);
                   return avl_tree_iter._head;
            }
            else
            {   
                 nodaaa<T,Alloc> *parent = avl_tree_iter.parent_noode(avl_tree_iter._head,avl_tree_iter._head->pair->first);

                  if (avl_tree_iter->right == NULL && avl_tree_iter._head == parent->left)
                  {
                    avl_tree_iter._head = parent;
                    return (avl_tree_iter._head);
                  }  

                  else if (avl_tree_iter->right == NULL && avl_tree_iter._head == parent->right)  
                  {
                    while (parent != nullptr && avl_tree_iter._head == parent->right)
                    {
                        avl_tree_iter._head = parent;
                        parent = avl_tree_iter.parent_noode(avl_tree_iter._head,parent->pair->first);
                    }
                        avl_tree_iter._head = parent;
                  }
            }
                return (*this);
        }

        pointer operator->()const{
            return (this->avl_tree_iter._head->pair);
        }
        reference operator*()const{
            return (this->avl_tree_iter._head->pair);
        }


    //    const tree_iterator& operator--()
    //     {
    //         if(avl_tree_iter._head == nullptr)
    //             return (*this);

    //         if (avl_tree_iter._head != nullptr)
    //         {
    //                avl_tree_iter = avl_tree_iter.min_node(avl_tree_iter->left);
    //         }else
    //         {
    //             nodaaa<T,Alloc> *parent = avl_tree_iter.parent_noode(avl_tree_iter._head);
    //             while (parent != nullptr && avl_tree_iter._head == parent->left)
    //             {
    //                 avl_tree_iter._head = parent;
    //                 parent = avl_tree_iter.parent_noode(parent);
    //             }   
    //             avl_tree_iter = parent;
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

        bool operator==(const tree_iterator &it)const{
            return (avl_tree_iter._head == it.avl_tree_iter._head);
        };
        bool operator!=(const tree_iterator &it)const{
            return (avl_tree_iter._head != it.avl_tree_iter._head);
        };
        bool operator==(tree_iterator &x){
            return(this->avl_tree_iter._head == x.avl_tree_iter._head);
        }
        bool operator!=(tree_iterator &x){
            return(this->avl_tree_iter._head != x.avl_tree_iter._head);
        }
        public:
        AVL<T, Alloc> avl_tree_iter;
    }; 

}



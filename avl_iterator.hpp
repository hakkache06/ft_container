
// #pragma once

//     template <class T, class Alloc>
//     class tree_iterator{
//     public:
//         typedef T value_type;
//         typedef std::ptrdiff_t difference_type; 
// 	    typedef	T*  pointer;
// 		typedef const T* const_pointer;
// 	    typedef T& reference;
//         typedef const T& const_reference;
// 		typedef std::bidirectional_iterator_tag iterator_category;

//         tree_iterator(){};

//         tree_iterator(const tree_iterator &ref):avl_tree(ref.avl_tree){
//         };

//         const tree_iterator &operator=(const tree_iterator &rhs){
//             if (this == &rhs)
// 	    	    return (*this);
// 	        this->avl_tree = rhs.avl_tree;
//             return (*this);
//         }
//         ~tree_iterator(){
//         }
        
//         bool operator==(const tree_iterator &it)const{
//             return (avl_tree._head == it.avl_tree._head);
//         };
//         bool operator!=(const tree_iterator &it)const{
//             return (avl_tree._head != it.avl_tree._head);
//         };

// 	    // const tree_iterator operator++(int){
//         //     tree_iterator tmp(*this);
//         //     operator++();
//         //     return (tmp);
//         // }
			
// 	    // const tree_iterator operator--(int){
// 		// 	tree_iterator tmp(*this);
//         //     operator--();
//         //     return (tmp);
// 		// } 

//         bool operator==(tree_iterator &x){
//             return(this->avl_tree._head == x.avl_tree._head);
//         }
//         bool operator!=(tree_iterator &x){
//             return(this->avl_tree._head != x.avl_tree._head);
//         }
//         protected:
//         AVL<T, Alloc> avl_tree;
//     }; 



// #pragma once
// #include "tree_iterator.hpp"
// //	typedef ft::iterator_map<value_type, value_compare> iterator;
// ///	typedef ft::const_iterator_map<value_type, value_compare> const_iterator;
// namespace ft{

// template <class T, class Alloc>
// class iterator_map : public tree_iterator<T, Alloc>{

// public:
//     typedef T* pointer;
//     typedef T& reference;
// 	typedef	typename tree_iterator<T, Alloc>::iterator_category		iterator_category;
// 	typedef	typename tree_iterator<T, Alloc>::value_type			value_type;

//     iterator_map(): tree_iterator<T, Alloc>(){};

//     ~iterator_map(){
//     }
//     iterator_map(const iterator_map &src){
//         *this = src;
//     };
//     iterator_map(nodaa<T,Alloc> *node){
//         this->avl_tree._head = node;
//     }
//     pointer operator->()const{
//         return&(this->avl_tree._head->_pair);
//     }
//     reference operator*()const{
//         return (this->avl_tree._head->_pair);
//     }
// 	iterator_map	&operator++() { tree_iterator<T, kc>::operator++(); return *this; };
// 	iterator_map	&operator--() { tree_iterator<T, kc>::operator--(); return *this; };
// 	iterator_map	operator++(int) {
// 		iterator_map tmp(*this);
// 		operator++();
// 		return tmp;
// 	};
// 	iterator_map	operator--(int)  {
// 		iterator_map tmp(*this);
// 		operator--();
// 		return tmp;
// 	};
    
    
// };

// }; 

// #pragma once
// #include "tree_iterator.hpp"

// namespace ft{

// template <class T, class Alloc>
// class const_iterator_map : public tree_iterator<T, Alloc>{

// public:
//     typedef const T* pointer;
//     typedef const T& reference;
//     typedef	typename tree_iterator<T, Alloc>::iterator_category		iterator_category;
// 	typedef	typename tree_iterator<T, Alloc>::value_type			value_type;

//     const_iterator_map(): tree_iterator<value_type, Alloc>(){
// 		};

//      ~const_iterator_map(){
//     }
//     const_iterator_map(const tree_iterator<value_type, Alloc> &src): tree_iterator<T, Alloc>(src){
//     };

//     const_iterator_map(node<T,Alloc> *node){
//         this->avl_tree._head = node;
//     }
//     pointer operator->()const{
//         return&(this->avl_tree._head->pair);
//     }
//     reference operator*()const{
//         return (this->avl_tree._head->pair);
//     }
// 		const_iterator_map	&operator++() { tree_iterator<T, Alloc>::operator++(); return *this; };
// 		const_iterator_map	&operator--() { tree_iterator<T, Alloc>::operator--(); return *this; };
// 		const_iterator_map	operator++(int) {
// 			const_iterator_map tmp(*this);
// 			operator++();
// 			return tmp;
// 		};
// 		const_iterator_map	operator--(int)  {
// 			const_iterator_map tmp(*this);
// 			operator--();
// 			return tmp;
// 		};
// };
// };


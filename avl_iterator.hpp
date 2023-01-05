
// #pragma once

// #pragma once
#include "tree_iterator.hpp"
//	typedef ft::iterator_map<value_type, value_compare> iterator;
///	typedef ft::const_iterator_map<value_type, value_compare> const_iterator;


namespace ft{
template <class T, class Alloc>
class iterator_map : public tree_iterator<T, Alloc>{

public:
    typedef T* pointer;
    typedef T& reference;
	typedef	typename tree_iterator<T, Alloc>::iterator_category		iterator_category;
	typedef	typename tree_iterator<T, Alloc>::value_type			value_type;

    iterator_map(): tree_iterator<T, Alloc>(){};

    ~iterator_map(){
    }
    iterator_map(const iterator_map &src){
        *this = src;
    };
    iterator_map(nodaa<T,Alloc> *node){
        this->avl_tree._head = node;
    }
    pointer operator->()const{
        return&(this->avl_tree._head->_pair);
    }
    reference operator*()const{
        return (this->avl_tree._head->_pair);
    }
	iterator_map	&operator++() { tree_iterator<T, kc>::operator++(); return *this; };
	iterator_map	&operator--() { tree_iterator<T, kc>::operator--(); return *this; };
	iterator_map	operator++(int) {
		iterator_map tmp(*this);
		operator++();
		return tmp;
	};
	iterator_map	operator--(int)  {
		iterator_map tmp(*this);
		operator--();
		return tmp;
	};
    
    
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


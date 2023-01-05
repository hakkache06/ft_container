#pragma once
#include "tree_iterator.hpp"

namespace ft{

template <class T, class Alloc>
class const_map_ite : public tree_iterator<T, Alloc>{

public:
    typedef const T* pointer;
    typedef const T& reference;
    typedef	typename tree_iterator<T, Alloc>::iterator_category		iterator_category;
	typedef	typename tree_iterator<T, Alloc>::value_type			value_type;

    const_map_ite(): tree_iterator<value_type, Alloc>(){
		};

     ~const_map_ite(){
    }
    const_map_ite(const tree_iterator<value_type, Alloc> &src): tree_iterator<T, Alloc>(src){
    };

    const_map_ite(node<T,Alloc> *node){
        this->avl_tree._head = node;
    }
    pointer operator->()const{
        return&(this->avl_tree._head->pair);
    }
    reference operator*()const{
        return (this->avl_tree._head->pair);
    }
		const_map_ite	&operator++() { tree_iterator<T, Alloc>::operator++(); return *this; };
		const_map_ite	&operator--() { tree_iterator<T, Alloc>::operator--(); return *this; };
		const_map_ite	operator++(int) {
			const_map_ite tmp(*this);
			operator++();
			return tmp;
		};
		const_map_ite	operator--(int)  {
			const_map_ite tmp(*this);
			operator--();
			return tmp;
		};
};
};


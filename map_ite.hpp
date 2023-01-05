
#pragma once
#include "tree_iterator.hpp"
//	typedef ft::map_ite<value_type, value_compare> iterator;
///	typedef ft::const_map_ite<value_type, value_compare> const_iterator;
namespace ft{

template <class T, class kc>
class map_ite : public tree_iterator<T, Alloc>{

public:
    typedef T* pointer;
    typedef T& reference;
	typedef	typename tree_iterator<T, Alloc>::iterator_category		iterator_category;
	typedef	typename tree_iterator<T, Alloc>::value_type			value_type;

    map_ite(): tree_iterator<T, Alloc>(){};

    ~map_ite(){
    }
    map_ite(const map_ite &src){
        *this = src;
    };
    map_ite(nodaa<T,Alloc> *node){
        this->_avlIt._head = node;
    }
    pointer operator->()const{
        return&(this->avl_tree._head->_pair);
    }
    reference operator*()const{
        return (this->avl_tree._head->_pair);
    }
	map_ite	&operator++() { tree_iterator<T, Alloc>::operator++(); return *this; };
	map_ite	&operator--() { tree_iterator<T, kc>::operator--(); return *this; };
	map_ite	operator++(int) {
		map_ite tmp(*this);
		operator++();
		return tmp;
	};
	map_ite	operator--(int)  {
		map_ite tmp(*this);
		operator--();
		return tmp;
	};
};

}; 

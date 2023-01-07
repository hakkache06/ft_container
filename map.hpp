
#pragma once


# include <algorithm>
# include <functional>
# include <iostream>
#include "pair.hpp"
#include "vector.hpp"
#include "tree_iterator.hpp"
//#include "reverse_iterator.hpp"
#include "nodda.hpp"
#include "Avl.hpp"
//#include "map_ite.hpp"
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
        //typedef	nodaaa<value_type,Alloc> _node;
        //// iterator 
        typedef ft::tree_iterator<Key,T,const value_type, Alloc, AVL<Key,T,value_type,Alloc> > const_iterator;
        typedef ft::tree_iterator<Key,T,value_type, Alloc,AVL<Key,T,value_type,Alloc> > iterator;
        typedef typename ft::reverse_iterator < iterator > reverse_iterator;
        typedef typename ft::reverse_iterator < const_iterator > const_reverse_iterator;

        // fin iterator


       
    public:
     
      Alloc _alloc;
      Compare _key_comp;
      size_type _size;
      
    // size_t _capacity;
 
        // class value compare
        // class value_compare: public std::binary_function<value_type,value_type,bool> 
        // {
        //     friend class map;
        // protected:
        //     Compare comp;
        //     value_compare(Compare c) : comp(c) {}
        // public:
        //     bool operator()(const value_type& x, const value_type& y) const
        //      {
        //         return comp(x.first, y.first);
        //     }
        // };

        public :

        // Construct empty
        explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
        {
            
        }

		template <class InputIterator> 
		 map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type())
		 {
			this->insert(first,last);
		 }

        //insert first -- last
        // ~map()
        // {
        //     avl_tree.dellocate_node(_node); 
		// };
        // iterator 
    	
	   map (const map& x)
	   {
	        (*this) = x;
	   }  

        void    affiche2()
        {
            this->avl_tree.affiche(avl_tree._head);
        }

        iterator begin()
		{
 			return iterator(avl_tree.min_noode(avl_tree._head),avl_tree);
 		}
        // const_iterator begin() const
		// {
 		// 	return const_iterator(avl_tree.min_noode(avl_tree._head),avl_tree);
 		// }

		iterator end()
		{
			return (iterator(nullptr,avl_tree));
		}
		// const_iterator end() const
		// {
		// 	return (const_iterator(nullptr,avl_tree));
		// }

		// reverse_iterator rbegin()
		// {
		// 	return (reverse_iterator(this->end()));
		// }

		// const_reverse_iterator rbegin() const
		// {
		// 	return (const_reverse_iterator(this->end()));
		// }
		// reverse_iterator rend()
		// {
		// 	return (reverse_iterator(this->begin()));
		// }

		// const_reverse_iterator rend() const
		// {
		// 	return (const_reverse_iterator(this->begin()));
		// }

		bool empty() const
		{
			return (this->_size == 0);
		}
		// size_type size() const
		// {
		// 	return (this->size);
		// }
		// size_type max_size() const
		// {
		// 	return (this->alloc_node.max_size());
		// }
		// mapped_type& operator[] (const key_type& k)
		// {
		// 	return ((*((this->insert(ft::make_pair(k, mapped_type()))).first)).second);
		// }

        pair<iterator,bool> insert (const value_type& val)
		{
			nodaaa<Key,T,value_type,Alloc>	*tmp;

			tmp = this->avl_tree.find_key(this->avl_tree._head,val.first);
			if (tmp)
				return (pair<iterator, bool>(iterator(tmp,avl_tree), false));
			++this->_size;
			avl_tree._head = avl_tree.insert(avl_tree._head,val);
			return (pair<iterator, bool>(iterator(this->avl_tree.find_key(this->avl_tree._head,val.first),avl_tree), true));
		}

        iterator insert (iterator position, const value_type& val)
 		{
 			(void) position;
			avl_tree._head = avl_tree.insert(avl_tree._head,val);
			return (iterator(this->avl_tree.find_key(avl_tree._head,val.first),avl_tree));
 		}
		// template <class InputIterator>
		// void insert (InputIterator first, InputIterator last)
		// {
		// 	while (first != last)
		// 		this->insert(avl_tree._head,*(first++));
		// }
        // void erase (iterator position)
		// {
		// 	if (this->avl_tree.find_key(avl_tree._head,(*position).first))
		// 	{
		// 		this->avl_tree.delete_node(avl_tree._head,(*position).first);
		// 		--this->size;
		// 	}
		// }
        // size_type erase (const key_type& k)
		// {
		// 	if (this->avl_tree.find_key(avl_tree._head,k)
		// 	{
		// 		this->avl_tree.delete_node(avl_tree._head,k);
		// 		--this->size;
		// 		return (1);
		// 	}
		// 	return (0);
		// }
        // void erase (iterator first, iterator last)
		// {
		// 	ft::Vector<key_type> tmp;
		// 	typename ft::Vector<key_type>::iterator it;

		// 	while (first != last)
		// 		tmp.push_back((first++)->first);
		// 	for (it = tmp.begin(); it != tmp.end(); it++)
		// 		this->erase(*it);
		// }
        // void swap (map& x)
     	// {
	    //     std::swap(this->_alloc, x._alloc);
 	    //     std::swap(this->_key_comp, x._key_comp);
 	    //     std::swap(this->_size, x._size);
 	    //     this->avl_tree.swap(x.avl_tree);
 	    // }
        // void clear()
 	    // {
 	    //     this->erase(this->begin(), avl_tree.max_noode());
 	    // }

        // iterator find (const key_type& k)
        // {
        //     nodaaa<Key,T,value_type> *pointer;

        //     pointer = this->find_key(avl_tree._head,k);
        //     return (pointer ? iterator(pointer) : this->end());
        // }

        // const_iterator find (const key_type& k) const
        // {
        //     nodaaa<Key,T,value_type> *pointer;

        //     pointer = this->find_key(avl_tree._head,k);
        //     return (pointer ? iterator(pointer) : this->end());
        // }

        // size_type count (const key_type& k) const
     	// {
     	//   return (avl_tree.find_key(avl_tree._head,k) != NULL);
        // }

        // iterator lower_bound (const key_type& k)
     	// {
 		// 	nodaaa<Key,T,value_type> *tmp;

 		// 	tmp = this->avl_tree._head.lower_bound(k);
 		// 	return (tmp ? iterator(tmp) : this->end());
 		// }
        
        // iterator upper_bound (const key_type& k)
        // {
        //     node *tmp;

        //     tmp = this->avl_tree._head->is_upper_boud(k);
        //     return (tmp ? iterator(tmp) : this->end());
        // }

        //pair<iterator,iterator> equal_range (const key_type& k)
// // 		{
// // 			return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
// // 		}
	
// // 		allocator_type get_allocator() const
// // 		{
// // 			return (this->_alloc);
// // 		}

// // 	public:
// // 	    friend bool operator==(const Map &lhs, const Map &rhs)
// // 		{
// // 			return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
// // 		}
// //         friend bool operator!=(const Map& lhs, const Map& rhs)
// // 		{
// // 			return !(lhs == rhs);
// // 		}

// //         friend bool operator<(const Map& lhs,const Map& rhs)
// // 		{
// // 			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
// // 		}

// //         friend bool operator<=(const Map& lhs,const Map& rhs)
// // 		{
// // 			return !(rhs < lhs);
// // 		}

// //         friend bool operator>(const Map& lhs, const Map& rhs )
// // 		{
// // 			return (rhs < lhs);
// // 		}

// //         friend bool operator>=(const Map& lhs,const Map& rhs )
// // 		{
// // 			return !(rhs > lhs);
// // 		}
// // };

// // template <class Key, class T, class Compare, class Alloc>
// // void swap (Map<Key,T,Compare,Alloc>& x, Map<Key,T,Compare,Alloc>& y)
// // {
// // 	x.swap(y);
// // }

    private:
    
  		AVL<Key,T,value_type,Alloc> avl_tree;    

    };

}
        // void    testparentnode(const value_type &x)
        // {

        //     avl_tree._parent = avl_tree.parent_noode(avl_tree._head,x.first);
        //     cout << avl_tree._parent->pair->first << "";
        // }



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
        typedef ft::tree_iterator<const value_type, Alloc, AVL<value_type,Alloc> > const_iterator;
        typedef  ft::tree_iterator<value_type, Alloc,AVL<value_type,Alloc> > iterator;

        // fin iterator


       
    public:
     
      Alloc _alloc;
      Compare _key_compare;
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

        iterator  begin()
        {
           return iterator(avl_tree.min_noode(avl_tree._head),avl_tree);
        }

        iterator  end()
        {
           return iterator(nullptr,avl_tree);
        }
        bool empty() const 
        {
            if (avl_tree.treesize()==0)
                return  (true);
            else    
                return (false);       
        }
        size_t size() const
        {
            return (avl_tree.tree_size());
        }

        size_t  max_size() const
        {
            return (avl_tree.alloc_noode.max_size());
        }
        // pair<iterator,bool> insert (const value_type& val)
        // {   
        //        nodaaa<value_type,Alloc> *temp = avl_tree.find_key(avl_tree._head,val.first);
        //        if(temp)
        //         {   
        //             avl_tree.insert(avl_tree._head,val.first);
        //             return (pair<iterator,false>) ft;
        //         } 
        //     return (pair<iterator,bool>)

        // }    
        iterator insert(iterator position ,const value_type &x)
        {
            (void)position;
            nodaaa <value_type,Alloc> * temp =  avl_tree.find_key(avl_tree._head,x.first);

            if (temp ==NULL )
            {
                avl_tree._head = avl_tree.insert(avl_tree._head,x);
                return (iterator(avl_tree._head,avl_tree));
            }   
            return iterator(temp,avl_tree);
        }

        // template <class InputIterator> 
        // void insert (InputIterator first, InputIterator last)
        // {
             
        // };



    private:
    
  		AVL<Key,Type,value_type,Alloc> avl_tree;    

    };

}





// 	public:

// 		template <class InputIterator>
// 		map (
// 			InputIterator first,
// 			InputIterator last,
// 			const key_compare& comp = key_compare(),
// 			const allocator_type& alloc = allocator_type()) : _key_comp(comp), _alloc(alloc), _size(0)
// 		{
// 			this->insert(first, last);
// 		}
// 		map (const map& x)
// 		{
// 			(*this) = x;
// 		}

// 		~map (void)
// 		{
// 			this->_tree.clear(true);
// 		}
		
// 	public:

// 		iterator begin()
// 		{
// 			return (iterator(this->_tree.root->minimum_node()));
// 		}

// 		const_iterator begin() const
// 		{
// 			return (const_iterator(this->_tree.root->minimum_node()));
// 		}

// 		iterator end()
// 		{
// 			return (iterator(nullptr));
// 		}
		
// 		const_iterator end() const
// 		{
// 			return (const_iterator(nullptr));
// 		}

// 		reverse_iterator rbegin()
// 		{
// 			return (reverse_iterator(this->end()));
// 		}

// 		const_reverse_iterator rbegin() const
// 		{
// 			return (const_reverse_iterator(this->end()));
// 		}
// 		reverse_iterator rend()
// 		{
// 			return (reverse_iterator(this->begin()));
// 		}

// 		const_reverse_iterator rend() const
// 		{
// 			return (const_reverse_iterator(this->begin()));
// 		}
// 		bool empty() const
// 		{
// 			return (this->_size == 0);
// 		}
// 		size_type size() const
// 		{
// 			return (this->_size);
// 		}
// 		size_type max_size() const
// 		{
// 			return (this->alloc_node.max_size());
// 		}
// 		Mapped_type& operator[] (const key_type& k)
// 		{
// 			return ((*((this->insert(ft::make_pair(k, Mapped_type()))).first)).second);
// 		}

// 		pair<iterator,bool> insert (const value_type& val)
// 		{
// 			node	*tmp;

// 			tmp = this->avl_tree.fin_node(val.first);
// 			this->avl_tree.insert(val);
// 			if (tmp)
// 				return (pair<iterator, bool>(tmp, false));
// 			++this->_size;
// 			return (pair<iterator, bool>(this->avl_tree.fin_node(val.first), true));
// 		}

// 		iterator insert (iterator position, const value_type& val)
// 		{
// 			(void) position;
// 			return (this->insert(val).first);
// 		}

// 		template <class InputIterator>
// 		void insert (InputIterator first, InputIterator last)
// 		{
// 			while (first != last)
// 				this->insert(*(first++));
// 		}

// 		void erase (iterator position)
// 		{
// 			if (this->avl_tree.fined((*position).first))
// 			{
// 				this->_tree.delete_node((*position).first);
// 				--this->_size;
// 			}
// 		}
// 		size_type erase (const key_type& k)
// 		{
// 			if (this->avl_tree.fined(avl_trea._head,k)
// 			{
// 				this->_tree.delete_node(avl_trea._head,k);
// 				--this->_size;
// 				return (1);
// 			}
// 			return (0);
// 		}
//     	// void erase (iterator first, iterator last)
// 		// {
// 		// 	ft::Vector<key_type> tmp;
// 		// 	typename ft::Vector<key_type>::iterator it;

// 		// 	while (first != last)
// 		// 		tmp.push_back((first++)->first);
// 		// 	for (it = tmp.begin(); it != tmp.end(); it++)
// 		// 		this->erase(*it);
// 		// }

// // 		void swap (Map& x)
// // 		{
// // 			std::swap(this->_alloc, x._alloc);
// // 			std::swap(this->_key_comp, x._key_comp);
// // 			std::swap(this->_size, x._size);
// // 			this->avl_tree.swap(x._tree);
// // 		}
// // 		// void clear()
// // 		// {
// // 		// 	this->erase(this->begin(), this->end());
// // 		// }
// // 		key_compare key_comp() const
// // 		{
// // 			return (this->_key_comp);
// // 		}

// // 		value_compare value_comp() const
// // 		{
// // 			return (value_compare(this->_key_comp));
// // 		}

// // 		iterator find (const key_type& k)
// // 		{
// // 			node *target;

// // 			target = this->_tree.fined_node(k);
// // 			return (target ? iterator(target) : this->end());
// // 		}
		
// // 		const_iterator find (const key_type& k) const
// // 		{
// // 			node *target;

// // 			target = this->avl_tree.fined_node(k);
// // 			return (target ? const_iterator(target) : this->end());
// // 		}

// // 		size_type count (const key_type& k) const
// // 		{
// // 			return (this->_tree.fined_node(k) != NULL);
// // 		}

// // 		iterator lower_bound (const key_type& k)
// // 		{
// // 			node *tmp;

// // 			tmp = this->avl_tree.lower_bound(k);
// // 			return (tmp ? iterator(tmp) : this->end());
// // 		}

// // 		const_iterator lower_bound (const key_type& k) const
// // 		{
// // 			node *tmp;

// // 			tmp = this->avl_tree.lower_bound(k);
// // 			return (tmp ? const_iterator(tmp) : this->end());
// // 		}

// // 		iterator upper_bound (const key_type& k)
// // 		{
// // 			node *tmp;

// // 			tmp = this->avl_tree.upper_bound(k);
// // 			return (tmp ? iterator(tmp) : this->end());
// // 		}
		
// // 		const_iterator upper_bound (const key_type& k) const
// // 		{
// // 			node *tmp;

// // 			tmp = this->_tree.upper_bound(k);
// // 			return (tmp ? const_iterator(tmp) : this->end());
// // 		}

// // 		pair<const_iterator,const_iterator> equal_range (const key_type& k) const
// // 		{
// // 			return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
// // 		}
		
// // 		pair<iterator,iterator> equal_range (const key_type& k)
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
// // };

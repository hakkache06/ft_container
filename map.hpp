
#pragma once


# include <algorithm>
# include <functional>
# include <iostream>
#include "pair.hpp"
#include "vector.hpp"
#include "tree_iterator.hpp"
#include "const_tree.hpp"
#include "nodda.hpp"
#include "Avl.hpp"
#include "sfinae.hpp"
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
        typedef nodaaa<Key,T,value_type,Alloc> Node;
        typedef size_t  size_type;
        typedef Compare key_compare;
        typedef ptrdiff_t difference_type;
        typedef typename Alloc::reference reference;
        typedef typename Alloc::const_reference const_reference;
        typedef typename Alloc::pointer pointer;
        typedef typename Alloc::const_pointer const_pointer;
        //typedef	nodaaa<value_type,Alloc> _node;
        //// iterator 
        typedef ft::tree_iterator<Key, const Node,const value_type, Alloc, AVL<Key,T,value_type,Alloc,Compare> > const_iterator;
        typedef ft::tree_iterator<Key, Node,value_type, Alloc,AVL<Key,T,value_type,Alloc,Compare> > iterator;

    	typedef typename ft::reverse_iterator < iterator > reverse_iterator;
        typedef typename ft::reverse_iterator < const_iterator > const_reverse_iterator;
		typedef typename value_type::first_type   pair_first_pair;
        // fin iterator


       
    public:
     
      Alloc _alloc;
      Compare _key_comp;
      size_type _size;
      
    // size_t _capacity;
 
        class value_compare: public std::binary_function<value_type,value_type,bool> 
        {
            friend class map;
        protected:
            Compare comp;
            value_compare(Compare c) : comp(c) {}
        public:
            bool operator()(const value_type& x, const value_type& y) const
             {
                return comp(x.first, y.first);
            }
        };

        public :

        // Construct empty
        explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()):_size(0)
        {
        }

		template <class InputIterator> 
		 map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type()):_size(0)
		 {
			this->insert(first,last);
		 }

		map<Key,T,Compare,Alloc> &operator= (const map<Key,T,Compare,Alloc>& x)
		{
			if(this == &x)
				return (*this);
			this->avl_tree = x.avl_tree;
			this->_alloc = x._alloc;
			this->_key_comp = x._key_comp;
			this->_size = x._size;
			return (*this);
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

        const_iterator begin() const
		{
 			return const_iterator(avl_tree.min_noode(avl_tree._head),avl_tree);
 		}

		iterator end()
		{
			return (iterator(nullptr,avl_tree));
		}

		const_iterator end() const
		{
			return (const_iterator(nullptr,avl_tree));
		}

		reverse_iterator rbegin()
		{
			return (reverse_iterator(this->end()));
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(this->begin()));
		}

		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(this->end()));
		}
		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(this->begin()));
		}

		bool empty() const
		{
			return (this->_size == 0);
		}
		size_type size() const
		{
			return (this->_size);
		}
		size_type max_size() const
		{
			return (this->alloc_node.max_size());
		}

        pair<iterator,bool> insert (const value_type& val)
		{
			Node	*tmp;		
			tmp = this->avl_tree.find_key(this->avl_tree._head,val.first);
			if (tmp)
				return (pair<iterator, bool>(iterator(tmp), false));
			++this->_size;			
			avl_tree._head = avl_tree.insert(avl_tree._head,val);
			return (pair<iterator, bool>(iterator(this->avl_tree.find_key(this->avl_tree._head,val.first)), true));
		}

        iterator insert (iterator, const value_type& val)
 		{
			avl_tree._head = avl_tree.insert(avl_tree._head,val);
			return (iterator(this->avl_tree.find_key(avl_tree._head,val.first),avl_tree));
 		}
		mapped_type& operator[] (const key_type& k)
		{
			return ((*((this->insert(ft::make_pair(k, mapped_type()))).first)).second);
		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
			while (first != last)
			{	
				avl_tree._head =  avl_tree.insert(avl_tree._head,(*(first++)));
				this->_size++;
			}
		}

        void erase (iterator position)
		{
			Node *pointer;
			pointer = this->avl_tree.find_key(avl_tree._head,(*position).first);
			if (pointer)
			{
				avl_tree._head = avl_tree.dele(avl_tree._head,(*position).first);
				this->_size--;
			}
		}

		void mese7(pair_first_pair val)
		{
			avl_tree._head =  avl_tree.deletenoode(avl_tree._head,val);
		}

        size_type erase (const key_type& k)
		{
			Node *pointer;
			pointer = this->avl_tree.find_key(avl_tree._head,k);

			if (pointer)
			{
				avl_tree._head = avl_tree.dele(avl_tree._head,k);
				this->_size--;
				return (1);
			}
			return (0);
		}

        void erase (iterator first, iterator last)
		{
			ft::Vector<key_type> tmp;
			typename ft::Vector<key_type>::iterator it;

			while (first != last)
				tmp.push_back((first++)->first);
			for (it = tmp.begin(); it != tmp.end(); it++)
			{
				avl_tree._head= this->avl_tree.dele(avl_tree._head,*it);
				this->_size--;
			}	
		}
        void swap (map& x)
     	{	
			//_alloc
			//_key_comp
			//_size
			// std::swap(_alloc,x._alloc);
			// std::swap(_key_comp,x._key_comp);
			// std::swap(_size,x._size);
	        std::swap(*this, x);

 	    }
		
        void clear()
 	    {	

 	        this->erase(this->begin(), this->end());
			avl_tree._head = NULL;
 	    }

        iterator find (const key_type& k)
        {
            Node *pointer;

            pointer = avl_tree.find_key(avl_tree._head,k);
            return (pointer ? iterator(pointer,avl_tree) : this->end());
        }

		iterator find (const key_type& k) const
        {
            Node *pointer;

            pointer = avl_tree.find_key(avl_tree._head,k);
            return (pointer ? iterator(pointer,avl_tree) : this->end());
        }

        size_type count (const key_type& k) 
     	{
			Node *pointer;
     	  	pointer = avl_tree.find_key(avl_tree._head,k);
			if(pointer)
		  	return (1);
		return(0);
        }

        iterator upper_bound (const key_type& k) const
     	{
			Node *temp;
			Node *parent;
			temp = avl_tree._head;

			while (temp != NULL)
			{
				if (temp->pair->first > k)
				{
					parent = temp;
					temp = temp->left;	
				}
				else
				{
					temp = temp->right;
				}
			}	
				 return iterator(temp,avl_tree);
 		}
		iterator lower_bound (const key_type& k) const
     	{	
			Node *pointer;
			iterator it = upper_bound(k);
     	  	pointer = avl_tree.find_key(avl_tree._head,k);
			if(pointer && it != end())
				return it;
			else
				return iterator(pointer,avl_tree);
 		}
		pair<iterator,iterator>	equal_range (const key_type& k) const
		{	
			return (ft::make_pair(lower_bound(k),upper_bound(k)));
		}
		key_compare key_comp() const
		{
			return (_key_comp);
		}
		value_compare	value_comp() const
		{
			return(value_compare(_key_comp));
		}
		allocator_type get_allocator() const
		{
			return (this->_alloc);
		}
    private:
    
  		AVL<Key,T,value_type,Alloc,Compare> avl_tree;    

	public:
	    friend bool operator==(const map &lhs, const map &rhs)
		{
			return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		}
        friend bool operator!=(const map& lhs, const map& rhs)
		{
			return !(lhs == rhs);
		}

        friend bool operator<(const map& lhs,const map& rhs)
		{

			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

        friend bool operator<=(const map& lhs,const map& rhs)
		{
			return !(rhs < lhs);
		}

        friend bool operator>(const map& lhs, const map& rhs )
		{
			return (rhs < lhs);
		}

        friend bool operator>=(const map& lhs,const map& rhs )
		{
			return !(rhs > lhs);
		}
};

template <class Key, class T, class Compare, class Alloc>
void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
{
	x.swap(y);
}


};


        // void    testparentnode(const value_type &x)
        // {

        //     avl_tree._parent = avl_tree.parent_noode(avl_tree._head,x.first);
        //     cout << avl_tree._parent->pair->first << "";
        // }



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

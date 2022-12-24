#pragma once

#include "iterator_traits.hpp"

namespace ft
{
    template <typename Iterator>
    class reverse_iterator
    {
        public:
            typedef Iterator iterator_type;
            typedef typename iterator_traits<Iterator>::value_type      value_type;
            typedef typename iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::pointer         pointer;
            typedef typename iterator_traits<Iterator>::reference       reference;
            typedef typename iterator_traits<Iterator>::iterator_category  iterator_category;

             reverse_iterator(): _pointer() {}
            explicit reverse_iterator(iterator_type it) : _pointer(it) {
            }
            template<class Iter>
            reverse_iterator(const reverse_iterator<Iter>& it) : _pointer(it.base()) {}

            iterator_type base() const 
            {
                return _pointer;
            }

            reference operator*() const
            {
                iterator_type tmp = _pointer;
                return *--tmp;
            }

            pointer operator->() const
            {
                iterator_type tmp(_pointer);
                --tmp;
                return tmp.operator->();
            }

            reverse_iterator& operator++()
            {
                --_pointer;
                return *this;
            }

            reverse_iterator operator++(int)
            {
                reverse_iterator tmp = *this;
                --_pointer;
                return tmp;
            }

            reverse_iterator& operator--()
            {
                ++_pointer;
                return *this;
            }

            reverse_iterator operator--(int)
            {
                reverse_iterator tmp = *this;
                ++_pointer;
                return tmp;
            }

            reverse_iterator	operator+(difference_type n) const
			{
				reverse_iterator	tmp(this->base());
				tmp._pointer -= n;
				return tmp; 
			}

            reverse_iterator& operator+=(difference_type n)
            {
                _pointer -= n;
                return *this;
            }

			reverse_iterator operator- (difference_type n) const
			{
				reverse_iterator	tmp(this->base());
				tmp._pointer += n;
				return (tmp);
			}

            reverse_iterator& operator-=(difference_type n)
            {
                _pointer += n;
                return *this;
            }

            reference operator[](difference_type n) const
            {
                return *(*this + n);
            }

            bool operator==(const reverse_iterator& it) const
            {
                return _pointer == it._pointer;
            }


            bool operator!=(const reverse_iterator& it) const
            {
                return _pointer != it._pointer;
            }

            bool operator<(const reverse_iterator& it) const
            {
                return _pointer > it._pointer;
            }

            bool operator>(const reverse_iterator& it) const
            {
                return _pointer < it._pointer;
            }

            bool operator<=(const reverse_iterator& it) const
            {
                return _pointer >= it._pointer;
            }

            bool operator>=(const reverse_iterator& it) const
            {
                return _pointer <= it._pointer;
            }

        private:
            iterator_type _pointer;
};

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& it)
	{
		return it + n;
	}

	template<class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return rhs.base() - lhs.base();
	}

	template<class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template<class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template<class Iterator>
	bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template<class Iterator>
	bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template<class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template<class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return lhs.base() <= rhs.base();
	}
   
}

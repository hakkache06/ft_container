#pragma once

#include "reverse_iterator.hpp"

#include "random_access_iterator.hpp"

#include <iostream>

#include <memory>

#include "sfinae.hpp"


namespace ft {
  template < class T, class Alloc = std::allocator < T > >
    class Vector {
      public:
        // Member types
        typedef T value_type;
      typedef Alloc allocator_type;
      typedef typename allocator_type::reference reference;
      typedef typename allocator_type::const_reference const_reference;
      typedef typename allocator_type::pointer pointer;
      typedef typename allocator_type::const_pointer const_pointer;
      typedef typename allocator_type::difference_type difference_type; // usually the same as ptrdiff_t

      typedef typename allocator_type::size_type size_type; //	an unsigned integral type that can represent any non-negative value of difference_type
      typedef typename ft::random_access_iterator < value_type > iterator;
      typedef typename ft::random_access_iterator <
      const value_type > const_iterator;
      typedef typename ft::reverse_iterator < iterator > reverse_iterator;
      typedef typename ft::reverse_iterator < const_iterator > const_reverse_iterator;

        //default constructor (1) empty container constructor (default constructor) Constructs an empty container, with no elements
      explicit Vector(): _size(0),
      _capacity(0),
      _alloc(allocator_type()),
      _buff(nullptr) {

      }

      explicit Vector(size_type n,
        const value_type & val = value_type(),
          const allocator_type & alloc = allocator_type())

      {
        this -> _alloc = alloc;
        this -> _buff = this -> _alloc.allocate(n);
        for (size_type i = 0; i < n; i++)
          this -> _alloc.construct( & this -> _buff[i], val);
        _size = n;
        _capacity = n;
      }

      // template <class InputIterator>
      // Vector (InputIterator first, InputIterator last, const allocator_type& _alloc = allocator_type()) : _alloc(_alloc)
      template < class InputIterator >
      Vector(InputIterator first, InputIterator last,
        const allocator_type & alloc = allocator_type(),
          typename ft::enable_if < !ft::is_integral < InputIterator > ::value, InputIterator > ::type = InputIterator()): _alloc(alloc) {
        size_t n = last - first;
        _buff = _alloc.allocate(n);
        for (size_t i = 0; i < n; i++)
          _alloc.construct( & _buff[i], first[i]);
        _size = n;
        _capacity = n;
      }

        Vector(const Vector& vecto): _capacity(0), _size(0), _alloc(vecto.get_allocator()){(*this) = vecto;}

        ~Vector(void)
		{
            for (size_type i = 0; i < this->size(); i++)
                this->_alloc.destroy(&this->_buff[i]);
			this->_alloc.deallocate(this->_buff, this->capacity());
		}

      Vector < value_type,
      std::allocator < T > > & operator = (const Vector < value_type, std::allocator < T > > & x) {
        if (this != & x) {
          _size = x._size;
          _capacity = x._capacity;
          _buff = _alloc.allocate(_capacity);
          for (size_t i = 0; i < _size; i++)
            _alloc.construct( & _buff[i], x._buff[i]);
        }
        return * this;
      }

      template < class InputIterator >
      void assign(InputIterator first, InputIterator last, typename std::enable_if < !std::is_integral < InputIterator > ::value, InputIterator > ::type = InputIterator()) {
        size_t n = last - first;
        if (n > _capacity) {
          for (size_t i = 0; i < _size; i++)
            _alloc.destroy( & _buff[i]);
          if (!_buff)
            _alloc.deallocate(_buff, _capacity);
          _buff = _alloc.allocate(n);
          _capacity = n;
        }
        for (size_t i = 0; i < n; i++)
          _alloc.construct( & _buff[i], first[i]);
        _size = n;
      }

      void assign(size_type n,
        const T & val) {
        for (size_t i = 0; i < _size; i++)
          _alloc.destroy( & _buff[i]);
        _size = n;
        if (n > _capacity) {
          if (!_buff)
            _alloc.deallocate(_buff, _capacity);
          _capacity = n;
          _buff = _alloc.allocate(_capacity);
        }
        for (size_t i = 0; i < _size; i++)
          _alloc.construct( & _buff[i], val);
        // for(size_t i = 0 ; i < _size ; i++)
        //   _alloc.construct(&_buff[i], val);
        // _alloc.deallocate(_buff);
        // _buff = _alloc.allocate(n);
        // for (size_t i = 0; i < n ; i++)
        //   _alloc.construct(&buff[i],val);
        // _size = n;
      }

      allocator_type get_allocator() const {
        return _alloc;
      }
      iterator begin() {
        return iterator(_buff);
      }
      const_iterator begin() const {
        return const_iterator(_buff);
      }
      iterator end() {
        return iterator(_buff + _size);
      }
      const_iterator end() const {
        return const_iterator(_buff + _size);
      }
      reverse_iterator rbegin() {
        reverse_iterator tmp(end());
        return tmp;
      }
      const_reverse_iterator rbegin() const {
        const_reverse_iterator tmp(end());
        return tmp;
      }
      reverse_iterator rend() {
        reverse_iterator tmp(begin());
        return tmp;
      }
      const_reverse_iterator rend() const {
        const_reverse_iterator tmp(begin());
        return tmp;
      }
      // capacity:
      size_type size() const {
        return _size;
      }
      size_type max_size() const {
        return _alloc.max_size();
      }
      void resize(size_type n, value_type val = value_type()) {
        if (n < _size) {
          for (size_type i = n; i < _size; i++)
            _alloc.destroy( & _buff[i]);

        }
        if (n > _size) {
          reserve(n);
          for (size_type i = _size; i < n; i++)
            _alloc.construct( & _buff[i], val);

        }
        _size = n;
      }

      size_type capacity() const {
        return _capacity;
      }
      bool empty() const {
        return _size == 0;
      }
      void reserve(size_type n) {
        if (n > _capacity) {
          pointer _tmp = _alloc.allocate(n);
          for (size_t i = 0; i < _size; i++) {
            _alloc.construct( & _tmp[i], _buff[i]);
            _alloc.destroy( & _buff[i]);
          }
          if (!_buff)
            _alloc.deallocate(_buff, _capacity);
          _buff = _tmp;
          _capacity = n;
        }
      }
      // element access:
      reference operator[](size_type n) {
        return _buff[n];
      }
      const_reference operator[](size_type n) const {
        return _buff[n];
      }
      const_reference at(size_type n) const {
        if (n < _size)
          return _buff[n];
        else
          throw std::out_of_range("out of range");

      }
      reference at(size_type n) {
        if (n < _size)
          return _buff[n];
        else
          throw std::out_of_range("out of range");
      }
      reference front() {
        return _buff[0];
      }
      const_reference front() const {
        return _buff[0];
      }
      reference back() {
        return _buff[_size - 1];
      }
      const_reference back() const {
        return _buff[_size - 1];
      }
      // modifiers:
      void push_back(const value_type & val) {
        if (_size == _capacity) {
          if (_capacity == 0)
            reserve(1);
          else
            reserve(_capacity * 2);
        }
        _alloc.construct( & _buff[_size], val);
        ++_size;
      }
      void pop_back() {
        _alloc.destroy( & _buff[_size--]);

      }
      iterator insert(iterator position,
        const value_type & x) {
        size_t len = 0;
        if (position.get_pointer())
          len = std::distance(begin(), position);

        if (_size >= _capacity) {
          if (_capacity == 0)
            reserve(1);
          else
            reserve(_capacity * 2);
        }
        for (size_t i = _size; i > len; i--) {
          _buff[i] = _buff[i - 1];
        }
        _buff[len] = x;
        ++_size;
        return & _buff[len];
      }
      void insert(iterator position, size_type n,
        const value_type & x) {
        size_type index = 0;
        if (position.get_pointer())
          index = std::distance(begin(), position);
        if (_size + n > _capacity) {
          if (n > _size)
            reserve(n + _size);
          else
            reserve(_capacity * 2);
        }
        for (size_type i = _size; i > index; i--) {
          _alloc.construct( & _buff[i + n - 1], _buff[i - 1]);
        }
        for (size_type i = index; i < index + n; i++)
          _alloc.construct( & _buff[i], x);
        _size += n;
      }
      template < class InputIterator >
      void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if < !ft::is_integral < InputIterator > ::value, InputIterator > ::type = InputIterator()) {
        size_type n = last - first;
        size_type index = 0;
        if (position.get_pointer())
          index = std::distance(begin(), position);
        if (_size + n > _capacity) {
          if (n > _size)
            reserve(n + _size);
          else
            reserve(_capacity * 2);
        }
        for (size_type i = _size; i > index; i--) {
          _buff[i + n - 1] = _buff[i - 1];
        }
        for (size_type i = index; i < index + n && first != last; i++, first++)
          _alloc.construct( & _buff[i], * first);
        _size += n;
      }

      iterator erase(iterator position) {
        size_t len = 0;
        if (position.get_pointer())
          len = std::distance(begin(), position);
        for (size_t i = len; i < _size - 1; i++) {
          _buff[i] = _buff[i + 1];
        }
        _alloc.destroy( & _buff[_size - 1]);
        --_size;
        return position;
      }
      iterator erase(iterator first, iterator last) {
        size_t len = std::distance(first, last);
        for (size_t i = 0; i < len; i++) {
          erase(first);
        }
        return first;

      }
	void swap (Vector& x)
	{
		value_type		*tmp_v;
		size_type		tmp_capacity;
		size_type		tmp_size;
		allocator_type	tmp_alloc;

		tmp_v = x._buff;
		tmp_capacity = x._capacity;
		tmp_size = x._size;
		tmp_alloc = x._alloc;
			x._buff = this->_buff;
		x._capacity = this->_capacity;
		x._size = this->_size;
		x._alloc = this->_alloc;
		this->_buff = tmp_v;
		this->_capacity = tmp_capacity;
		this->_size = tmp_size;
			this->_alloc = tmp_alloc;
	}

      void clear() {
        for (size_t i = 0; i < _size; i++)
          _alloc.destroy( & _buff[i]);
        _size = 0;
      }

      private: allocator_type _alloc;
      pointer _buff;
      size_type _size;
      size_type _capacity;
    };

template <class T, class Alloc>
void swap (Vector<T,Alloc>& x, Vector<T,Alloc>& y)
{
		x.swap(y);
}

// *** fin modifires

	//relational operators (Vector)
template <class T, class Alloc>
bool operator== (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}
template <class T, class Alloc>
bool operator!= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
{
	return !(lhs == rhs);
}

template <class T, class Alloc>
bool operator<  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
{
	return (ft::lexicographical_compare(
			lhs.begin(),lhs.end(),
			rhs.begin(), rhs.end()));
}

template <class T, class Alloc>
bool operator<= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
{
	return (!(rhs < lhs));
}

template <class T, class Alloc>
bool operator>  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
{
	return (rhs < lhs);
}

template <class T, class Alloc>
bool operator>= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
{
	return (!(rhs > lhs));
}

}
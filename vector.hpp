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
      buffer_v(nullptr) {

      }

      explicit Vector(size_type n,
        const value_type & val = value_type(),
          const allocator_type & alloc = allocator_type())

      {
        this -> _alloc = alloc;
        this -> buffer_v = this -> _alloc.allocate(n);
        for (size_type i = 0; i < n; i++)
          this -> _alloc.construct( & this -> buffer_v[i], val);
        _size = n;
        _capacity = n;
      }

      Vector(const Vector & vecto): _capacity(0),
      _size(0),
      _alloc(vecto.get_allocator()) {
        ( * this) = vecto;
      }

      template < class InputIterator >
      Vector(InputIterator first, InputIterator last,
        const allocator_type & alloc = allocator_type(),
          typename ft::enable_if < !ft::is_integral < InputIterator > ::value, InputIterator > ::type = InputIterator()): _alloc(alloc) {
          size_t n = last - first;
          buffer_v = _alloc.allocate(n);
          for (size_t i = 0; i < n; i++)
            _alloc.construct( & buffer_v[i], first[i]);
          _size = n;
          _capacity = n;
        }

        ~Vector(void) {
          for (size_type i = 0; i < this -> size(); i++)
            this -> _alloc.destroy( & this -> buffer_v[i]);
          this -> _alloc.deallocate(this -> buffer_v, this -> capacity());
        }

      Vector < value_type,
      std::allocator < T > > & operator = (const Vector < value_type, std::allocator < T > > & x) {
        if (this != & x) {
          _size = x._size;
          _capacity = x._capacity;
          buffer_v = _alloc.allocate(_capacity);
          for (size_t i = 0; i < _size; i++)
            _alloc.construct( & buffer_v[i], x.buffer_v[i]);
        }
        return * this;
      }

      template < class InputIterator >
      void assign(InputIterator first, InputIterator last, typename std::enable_if < !std::is_integral < InputIterator > ::value, InputIterator > ::type = InputIterator()) {
        size_t n = last - first;
        if (n > _capacity) {
          for (size_t i = 0; i < _size; i++)
            _alloc.destroy( & buffer_v[i]);
          if (!buffer_v)
            _alloc.deallocate(buffer_v, _capacity);
          buffer_v = _alloc.allocate(n);
          _capacity = n;
        }
        for (size_t i = 0; i < n; i++)
          _alloc.construct( & buffer_v[i], first[i]);
        _size = n;
      }

      // assign Efface un tableau et copie les éléments spécifiés dans le vecteur vide.

      // type 1 void assign (size_type n, const value_type& val);
      // n Nombre de copies d'un élément inséré dans le vecteur.
      // val Valeur de l'élément inséré dans le vecteur.

      void assign(size_type n,
        const T & val) {
        for (size_t i = 0; i < _size; i++)
          _alloc.destroy( & buffer_v[i]);
        _size = n;
        if (n > _capacity) {
          if (!buffer_v)
            _alloc.deallocate(buffer_v, _capacity);
          _capacity = n;
          buffer_v = _alloc.allocate(_capacity);
        }
        for (size_t i = 0; i < _size; i++)
          _alloc.construct( & buffer_v[i], val);

      }

      allocator_type get_allocator() const {
        return _alloc;
      }
      // *** iteraror X

      // ALL ITERATOR
      // return a reference to the first  element + random access iterator + not be dereferenced if conatiner empty
      iterator begin() {
        return (iterator(this -> buffer_v));
      }
      // return a reference to the first  element + random access iterator + not be dereferenced if conatiner empty
      const_iterator begin() const {
        return (const_iterator(this -> buffer_v));
      }
      //return iterator ma9bel la fin sequence
      iterator end() {
        return (iterator( & this -> buffer_v[this -> size()]));
      }
      //return iterator ma9bel la fin sequence
      const_iterator end() const {
        return (const_iterator( & this -> buffer_v[this -> size()]));
      }
      ///r eturn iterator pointing to the last
      reverse_iterator rbegin() {
        return (reverse_iterator(this -> end()));
      }
      //
      const_reverse_iterator rbegin() const {
        return (const_reverse_iterator(this -> end()));
      }
      //
      reverse_iterator rend() {
        return (reverse_iterator(this -> begin()));
      }
      //
      const_reverse_iterator rend() const {
        return (const_reverse_iterator(this -> begin()));
      }
      // *** fin iterator X
      // capacity:
      size_type size() const {
        return _size;
      }
      size_type max_size() const {
        return _alloc.max_size();
      }

      void resize(size_type n, value_type val = value_type()) // X
      {
        if (n > this -> capacity()) {
          this -> reserve_new_capacity(n);
          this -> fill_array(this -> size(), n, val);
        }
        if (n < this -> capacity()) {
          if (n < this -> size())
            for (size_type i = n; i < this -> size() - 1; i++)
              this -> _alloc.destroy( & this -> buffer_v[i]);
          else
            this -> fill_array(this -> size(), n, val);
        }
        this -> _size = n;
      }

      //  tbdel capacity  Réserve plus d'emplacements de mémoire
      void reserve(size_type n) // X
      {
        if (n <= this -> capacity())
          return;
        this -> reserve_new_capacity(n);
      }
      // helper function
      void reserve_new_capacity(std::size_t & n) {
        value_type * tmp;

        if (n == this -> capacity())
          return;

        if (n > _capacity) {
          pointer tmp = _alloc.allocate(n);
          for (size_t i = 0; i < _size; i++) {
            _alloc.construct( & tmp[i], buffer_v[i]);
            _alloc.destroy( & buffer_v[i]);
          }
          if (this -> capacity())
            this -> _alloc.deallocate(this -> buffer_v, this -> capacity());
          this -> buffer_v = tmp;
          this -> _capacity = n;
        }
      }

      void fill_array(std::size_t start, std::size_t end, value_type & val) {
        for (; start < end; start++)
          this -> _alloc.construct( & this -> buffer_v[start], val);
      }

      void destroy_array(std::size_t start, std::size_t end) {
        for (; start < end; start++)
          this -> _alloc.destroy( & this -> buffer_v[start]);
      }

      size_type capacity() const {
        return _capacity;
      }
      bool empty() const {
        return _size == 0;
      }

      // *** element access

      // return element be la position dyalo dayr b7al Vector::at ghi at ila mal9atch katred exception
      reference operator[](size_type n) {
        return (this -> buffer_v[n]);
      } // Retourne une référence à l'élément de vecteur à un emplacement spécifié.

      const_reference operator[](size_type n) const {
        return (this -> buffer_v[n]);
      }

      reference at(size_type n) {
        if (n > this -> size())
          throw std::out_of_range("out of range");
        return (this -> buffer_v[n]);
      }

      const_reference at(size_type n) const {
        if (n > this -> size())
          throw std::out_of_range("out of range");
        return (this -> buffer_v[n]);
      }

      reference front() {
        return ( * (this -> buffer_v));
      } // return direct refernce withit iteracleartor

      reference back() {
        return (this -> buffer_v[this -> size() - 1]);
      } // return direct refernce withot iterator

      const_reference front() const {
        return ( * (this -> buffer_v));
      }

      const_reference back() const {
        return (this -> buffer_v[this -> size() - 1]);
      }

      // *** fin element access

      // Vector::push_back  Ajoute un élément à la fin du vecteur.

      void push_back(const value_type & val) {
        if (this -> size() == this -> capacity()) {
          this -> reserve((this -> capacity() * 2) + (this -> capacity() == 0)); // maymkench reserveiw 0  donc capacity = 0 zid 1
        }
        this -> _alloc.construct( & this -> buffer_v[this -> _size++], val);
      }

      // fin push_back

      // Vector::pop_back Removes the last element in the Vector, 

      void pop_back() {
        if (!this -> size())
          return;
        this -> _alloc.destroy( & this -> buffer_v[--this -> _size]);
      }

      // insert Insère un élément, ou de nombreux éléments, ou une plage d’éléments dans le vecteur à une position spécifiée.
      // Position Position dans le vecteur où le premier élément est inséré.
      // Valeur de l'élément inséré dans le vecteur.
      // Nombre d'éléments insérés dans le vecteur.
      // Type 1

      void insert(iterator position, size_type n,
        const value_type & x) {
        size_type pos = 0;
        pos = std::distance(begin(), position);

        if (_size + n > _capacity) {
          if (n > _size)
            reserve(n + _size);
          else
            reserve(_capacity * 2);
        }
        for (size_type i = _size; i > pos; i--) {
          _alloc.construct( & buffer_v[i + n - 1], buffer_v[i - 1]);
        }
        for (size_type i = pos; i < pos + n; i++)
          _alloc.construct( & buffer_v[i], x);
        _size += n;
      }

      // iterator type 2

      iterator insert(iterator position,
        const value_type & x) {
        size_t pos = 0;
        pos = std::distance(begin(), position);

        if (_size >= _capacity) {
          if (_capacity == 0)
            reserve(1);
          else
            reserve(_capacity * 2);
        }
        for (size_t i = _size; i > pos; i--) {
          buffer_v[i] = buffer_v[i - 1];
        }
        buffer_v[pos] = x;
        ++_size;
        return & buffer_v[pos];
      }

      //type 3
      template < class InputIterator >
      void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if < !ft::is_integral < InputIterator > ::value, InputIterator > ::type = InputIterator()) {
        size_type n = last - first;
        size_type pos = 0;
        pos = std::distance(begin(), position);
        if (_size + n > _capacity) {
          if (n > _size)
            reserve(n + _size);
          else
            reserve(_capacity * 2);
        }
        for (size_type i = _size; i > pos; i--) {
          buffer_v[i + n - 1] = buffer_v[i - 1];
        }
        for (size_type i = pos; i < pos + n && first != last; i++, first++)
          _alloc.construct( & buffer_v[i], * first);
        _size += n;
      }

      void clear() {
        for (size_t i = 0; i < _size; i++)
          _alloc.destroy( & buffer_v[i]);
        _size = 0;
      }
      /// erase  Supprime un élément ou une plage d'éléments aux positions spécifiées dans le vecteur.
      // type 1

      iterator erase(iterator position) {
        size_type distance;
        size_type i;

        distance = std::distance(this -> begin(), position);
        this -> _alloc.destroy( & this -> buffer_v[distance]);
        i = distance;
        for (; i < this -> size() - 1; i++)
          this -> buffer_v[i] = this -> buffer_v[i + 1];
        this -> _alloc.destroy( & this -> buffer_v[i]);
        --this -> _size;
        return (iterator( & this -> buffer_v[distance]));
      }

      // type 2 range

      iterator erase(iterator first, iterator last) {
        size_t distance = std::distance(first, last);
        for (size_t i = 0; i < distance; i++) {
          erase(first);
        }
        return first;

      }
      void swap(Vector & x) {
        value_type * tmp_v;
        size_type tmp_capacity;
        size_type tmp_size;
        allocator_type tmp_alloc;

        tmp_v = x.buffer_v;
        tmp_capacity = x._capacity;
        tmp_size = x._size;
        tmp_alloc = x._alloc;
        x.buffer_v = this -> buffer_v;
        x._capacity = this -> _capacity;
        x._size = this -> _size;
        x._alloc = this -> _alloc;
        this -> buffer_v = tmp_v;
        this -> _capacity = tmp_capacity;
        this -> _size = tmp_size;
        this -> _alloc = tmp_alloc;
      }

      private: allocator_type _alloc;
      pointer buffer_v;
      size_type _size;
      size_type _capacity;
    };

  template < class T, class Alloc >
    void swap(Vector < T, Alloc > & x, Vector < T, Alloc > & y) {
      x.swap(y);
    }

  // *** fin modifires

  //relational operators (Vector)
  template < class T, class Alloc >
    bool operator == (const Vector < T, Alloc > & lhs,
      const Vector < T, Alloc > & rhs) {
      if (lhs.size() != rhs.size())
        return (false);
      return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }
  template < class T, class Alloc >
    bool operator != (const Vector < T, Alloc > & lhs,
      const Vector < T, Alloc > & rhs) {
      return !(lhs == rhs);
    }

  template < class T, class Alloc >
    bool operator < (const Vector < T, Alloc > & lhs,
      const Vector < T, Alloc > & rhs) {
      return (ft::lexicographical_compare(
        lhs.begin(), lhs.end(),
        rhs.begin(), rhs.end()));
    }

  template < class T, class Alloc >
    bool operator <= (const Vector < T, Alloc > & lhs,
      const Vector < T, Alloc > & rhs) {
      return (!(rhs < lhs));
    }

  template < class T, class Alloc >
    bool operator > (const Vector < T, Alloc > & lhs,
      const Vector < T, Alloc > & rhs) {
      return (rhs < lhs);
    }

  template < class T, class Alloc >
    bool operator >= (const Vector < T, Alloc > & lhs,
      const Vector < T, Alloc > & rhs) {
      return (!(rhs > lhs));
    }

}
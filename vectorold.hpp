# pragma once

#include <memory>
#include <stdexcept>
#include "iterator.hpp"    
#include "random_access_iterator.hpp" 
#include "reverse_iterator.hpp"    
#include "sfinae.hpp"

namespace ft
{

template < class T, class Alloc = std::allocator<T> >
class Vector
{

    public:
    // Member types
				typedef T											value_type;
		typedef Alloc													allocator_type;
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		typedef typename allocator_type::difference_type				difference_type; // usually the same as ptrdiff_t

		typedef typename allocator_type::size_type						size_type; //	an unsigned integral type that can represent any non-negative value of difference_type
		typedef typename ft::random_access_iterator<value_type>			iterator;
		typedef typename ft::random_access_iterator<const value_type>	const_iterator;
		typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
 
        // Part Allocation

	private:
    // les attrubites
        value_type		*buffer_v;
	    size_type		var_capacity;
	    size_type		var_size;
	    allocator_type	var_alloc;

    public:
		//Assign Vector content

        // Member functions
        //++++++++++++++++++++++++++++++++++++

        //construct/copy/destroy:
        //default constructor (1) empty container constructor (default constructor) Constructs an empty container, with no elements
        explicit Vector(const allocator_type& alloc = allocator_type()): buffer_v(NULL), var_capacity(0), var_size(0), var_alloc(alloc){}
        // constructor fill constructor Constructs a container with n elements. Each element is a copy of val.
        explicit Vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			this->var_alloc = alloc;
            this->buffer_v = this->var_alloc.allocate(n);
            for (size_type i = 0 ; i < n ; i++)
            	this->var_alloc.construct(&this->buffer_v /* pointer p*/, val); // Constructs an element object on the location pointed by p.
            var_size = n;
            var_capacity = n;
		}
		//Vector(const Vector<T,Allocator>& x); copy Construct
        Vector(const Vector& vecto): var_capacity(0), var_size(0), var_alloc(vecto.get_allocator()){(*this) = vecto;}

		// range constructor
		// Substitution Failure Is Not An Error
		
		 template <class InputIterator>
         	Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), 
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()): var_alloc(alloc)
              {
                size_t n = last - first;
                buffer_v = var_alloc.allocate(n); // returns a pointer to the first element.
                for (size_t i = 0 ; i < n ; i++)
                  var_alloc.construct(&buffer_v[i], first[i]); // Initialise la mémoire pointée par p avec une copie de l'objet auquel first
                  var_size = n;
                  var_capacity = n;
              }
		
        // destroy all conatainer
        ~Vector(void)
		{
            for (size_type i = 0; i < this->size(); i++)
                this->var_alloc.destroy(&this->buffer_v[i]);
			this->var_alloc.deallocate(this->buffer_v, this->capacity());
		}
        //+++++++++++++++++++++++++++++++++++++++++
// *** capacity 
        size_type size() const{return (this->var_size);} // X number element or object in Vector // Renvoie la taille actuelle
        size_type capacity() const{return (this->var_capacity);} //  X Renvoie la taille potentielle ou la capacité de stockage size allocation storage li kayen // 
        size_type max_size() const{return (this->var_alloc.max_size());} // X Renvoie la taille maximale  max element l y9do ykono fe container number machi dima kaysawi capacity katb9a chi 7aja mekhbya
        // change size dyal conatiner be n element ila kan n < me capacity kansghroh l n li b9a kaydestroya 
        //ila kan l3kess kanzido fe capacity
// resize(n, valeur) insère des éléments à la queue du vecteur
    
		allocator_type get_allocator() const
		{
			return (this->var_alloc);
		}

        void resize(size_type n, value_type val = value_type()) // X
		{
			if (n > this->capacity())
			{
				this->reserve_new_capacity();
				this->fill_array(this->size(), n, val);
			}
			if (n < this->capacity())
			{
				if (n < this->size())
					for (size_type i = n; i < this->size() - 1; i++)
						this->var_alloc.destroy(&this->buffer_v[i]);
				else
					this->fill_array(this->size(), n, val);
			}
			this->size = n;
		}
        
        //// check container wach empty
        bool empty() const // X
		{
			return (this->size() == 0);
		}
        //  tbdel capacity  Réserve plus d'emplacements de mémoire
        void reserve (size_type n) // X
		{
			if (n <= this->capacity())
			return ;
			this->reserve_new_capacity(n);
		}
		// helper function
		void	reserve_new_capacity(std::size_t &n)
		{
			value_type *tmp;

			if (n == this->capacity())
				return ;

			if (n > var_capacity)
            {
            	pointer tmp = var_alloc.allocate(n);
            	for ( size_t i = 0 ; i <var_size ; i++)
            	{
              	var_alloc.construct(&tmp[i],buffer_v[i]);
              	var_alloc.destroy(&buffer_v[i]);
            	}
            if (this->capacity())
				this->var_alloc.deallocate(this->buffer_v, this->capacity());
			this->buffer_v = tmp;
			this->var_capacity = n;
            }
		}

		void	fill_array(std::size_t start, std::size_t end, value_type &val)
		{
			for (; start < end; start++)
				this->var_alloc.construct(&this->buffer_v[start], val);
		}

		void	destroy_array(std::size_t start, std::size_t end)
		{
				for (; start < end; start++)
					this->var_alloc.destroy(&this->buffer_v[start]);
		}


// *** fin capacity


// *** iteraror X

        // ALL ITERATOR
        // return a reference to the first  element + random access iterator + not be dereferenced if conatiner empty
        iterator begin(){return (iterator(this->buffer_v));}
        // return a reference to the first  element + random access iterator + not be dereferenced if conatiner empty
        const_iterator begin() const{return (const_iterator(this->buffer_v));}
        //return iterator ma9bel la fin sequence
        iterator end(){return (iterator(&this->buffer_v[this->size()]));}
        //return iterator ma9bel la fin sequence
        const_iterator end() const{return (const_iterator(&this->buffer_v[this->size()]));}
        ///r eturn iterator pointing to the last
        reverse_iterator rbegin(){return (reverse_iterator(this->end()));}
        //
        const_reverse_iterator rbegin() const{return (const_reverse_iterator(this->end()));}
        //
        reverse_iterator rend(){return (reverse_iterator(this->begin()));}
        //
        const_reverse_iterator rend() const{return (const_reverse_iterator(this->begin()));}
// *** fin iterator X

// *** element access

    // return element be la position dyalo dayr b7al Vector::at ghi at ila mal9atch katred exception
    reference operator[] (size_type n){return (this->buffer_v[n]);} // Retourne une référence à l'élément de vecteur à un emplacement spécifié.

    const_reference operator[] (size_type n) const{return (this->buffer_v[n]);}

    reference at (size_type n)
	{ 
		if (n > this->size()) 
			throw std::out_of_range("out of range"); 
		return (this->buffer_v[n]);
	}

    const_reference at (size_type n) const
	{ 
		if (n > this->size())
		 throw std::out_of_range("out of range");
		return (this->buffer_v[n]);
	}

    reference front()
	{
		return (*(this->buffer_v));
	}// return direct refernce withit iteracleartor

    reference back()
	{
		return (this->buffer_v[this->size() - 1]);
	} // return direct refernce withot iterator

	const_reference front() const
	{
		return (*(this->buffer_v));
	}

    const_reference back() const
	{
		return (this->buffer_v[this->size() - 1]);
	}

// *** fin element access

// *** modifiers
	// assign Efface un tableau et copie les éléments spécifiés dans le vecteur vide.

		// type 1 void assign (size_type n, const value_type& val);
		// n Nombre de copies d'un élément inséré dans le vecteur.
		// val Valeur de l'élément inséré dans le vecteur.
		void assign (size_type n, const value_type& val)
		{
			
			for(size_t i = 0 ; i < var_size ; i++)
                var_alloc.destroy(&buffer_v[i]);
             var_size = n;

            if (n > var_capacity)
            {
                if (!buffer_v)
                    var_alloc.deallocate(buffer_v, var_capacity);
                var_capacity = n;
                buffer_v = var_alloc.allocate(var_capacity);
            }
            for (size_t i = 0 ; i < var_size ; i++)
                var_alloc.construct(&buffer_v[i], val);
		}
		// type 2 assign insère une plage d’éléments spécifiée du vecteur d’origine dans un vecteur, ou insère des copies d’un nouvel élément de valeur spécifié dans un vecteur.

		template <class InputIterator>
        void assign(InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
        {
            size_t n = last - first;
            if (n > var_capacity)
            {
                for (size_t i = 0 ; i < var_size ; i++)
                  var_alloc.destroy(&buffer_v[i]);
                if (!buffer_v)
                  var_alloc.deallocate(buffer_v, var_capacity);
                buffer_v = var_alloc.allocate(n);
                var_capacity = n;
              }
              for (size_t i = 0 ; i < n ; i++)
                var_alloc.construct(&buffer_v[i], first[i]);
            var_size = n;
            }

	// fin assign

	// Vector::push_back  Ajoute un élément à la fin du vecteur.

		void push_back (const value_type& val)
		{
			if (this->size() == this->capacity())
			{
				this->reserve((this->capacity() * 2) + (this->capacity() == 0)); // maymkench reserveiw 0  donc capacity = 0 zid 1
			}
			this->var_alloc.construct(&this->buffer_v[this->var_size++], val);
		}

	// fin push_back

   // Vector::pop_back Removes the last element in the Vector, 

		void pop_back()
		{
			if (!this->size())
				return ;
			this->var_alloc.destroy(&this->buffer_v[--this->var_size]);
		}

   //

   // insert Insère un élément, ou de nombreux éléments, ou une plage d’éléments dans le vecteur à une position spécifiée.
  // Position Position dans le vecteur où le premier élément est inséré.
  // Valeur de l'élément inséré dans le vecteur.
  // Nombre d'éléments insérés dans le vecteur.
  // Type 1

	void insert (iterator position, size_type n, const value_type& x)
    {
        size_type pos = 0;
        pos = std::distance(begin(), position);

        if (var_size + n > var_capacity)
        {
            if (n > var_size)
            reserve(n + var_size);
            else
            reserve(var_capacity * 2);
         }
        for (size_type i = var_size; i > index; i--){
            var_alloc.construct(&buffer_v[i + n - 1], buffer_v[i - 1]);
        }
        for (size_type i = index; i < index + n; i++)
            var_alloc.construct(&buffer_v[i], x);
        var_size += n;
    }

	// iterator type 2


	iterator insert(iterator position, const value_type& x)
    {
         size_t pos = 0;
        pos = std::distance(begin(),position);

        if (var_size >= var_capacity)
        {
        if (var_capacity == 0)
          reserve(1);
        else
            reserve (var_capacity * 2);            
        }
        for (size_t i = var_size ; i > pos ; i--)
        {
           buffer_v[i] = buffer_v[i - 1];
        }
        buffer_v[pos] = x;
        ++var_size;
        return &buffer_v[pos];
    }

		//type 3
	    template <class InputIterator>
     void insert(iterator position, InputIterator first, InputIterator last , typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
     {
         size_type n = last - first;
         size_type pos = 0;
           pos = std::distance(begin(), position);
         if (var_size + n > var_capacity)
         {
            if (n > var_size)
             reserve(n + var_size);
           else
             reserve(var_capacity * 2);
         }
         for (size_type i = var_size; i > pos; i--){
           buffer_v[i + n - 1] = buffer_v[i - 1];
         }
         for (size_type i = pos; i < pos + n && first != last; i++,first++)
          var_alloc.construct(&buffer_v[i],*first);
        var_size += n;
    }
  //
	// clear
	void clear()
    {
      for (size_t i = 0 ; i < var_size ; i++)
        var_alloc.destroy(&buffer_v[i]);
      	var_size = 0;
    }
	// swap  Échange les éléments de deux vecteurs.



	void swap (Vector& x)
	{
		value_type		*tmp_v;
		size_type		tmp_capacity;
		size_type		tmp_size;
		allocator_type	tmp_alloc;

		tmp_v = x.buffer_v;
		tmp_capacity = x.var_capacity;
		tmp_size = x.var_size;
		tmp_alloc = x.var_alloc;
			x.buffer_v = this->buffer_v;
		x.var_capacity = this->var_capacity;
		x.var_size = this->var_size;
		x.var_alloc = this->var_alloc;
		this->var_v = tmp_v;
		this->var_capacity = tmp_capacity;
		this->var_size = tmp_size;
			this->var_alloc = tmp_alloc;
	}

/// erase  Supprime un élément ou une plage d'éléments aux positions spécifiées dans le vecteur.
// type 1

	iterator erase (iterator position)
	{
		size_type distance;
		size_type i;

		distance = std::distance(this->begin(), position);
		this->var_alloc.destroy(&this->buffer_v[distance]);
		i = distance;
		for (; i < this->size() - 1; i++)
			this->buffer_v[i] = this->buffer_v[i + 1];
		this->var_alloc.destroy(&this->buffer_v[i]);
		--this->var_size;
		return (iterator(&this->buffer_v[distance]));
	}

// type 2 range

	iterator erase(iterator first, iterator last)
    {
        size_t distance = std::distance(first,last);
    	for (size_t i = 0 ; i < distance ; i++)
        {
        	erase(first);
        }
        return first;
              
    }
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

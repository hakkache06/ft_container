# pragma once

# include <memory>
# include <stdexcept>
# include <sfinae.hpp>

namespace ft
{

template < class T, class Alloc = std::allocator<T> >
class vector
{
    private:
    // les attrubites
        value_type		*buffer_v;
	    size_type		var_capacity;
	    size_type		var_size;
	    allocator_type	var_alloc;

		void	destroy_array(std::size_t start, std::size_t end)
		{
				for (; start < end; start++)
					this->alloc.destroy(&this->v[start]);
		}

    public:
    // Member types
		typedef typename ft::random_access_iterator<value_type>			iterator;
		typedef typename ft::random_access_iterator<const value_type>	const_iterator;
		typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
 
        // Part Allocation
		typedef T											value_type;
		typedef Alloc													allocator_type;
		typedef typename allocator_type::reference						reference;
		typedef typename allocator_type::const_reference				const_reference;
		typedef typename allocator_type::pointer						pointer;
		typedef typename allocator_type::const_pointer					const_pointer;
		typedef typename allocator_type::difference_type				difference_type; // usually the same as ptrdiff_t

		typedef typename allocator_type::size_type						size_type; //	an unsigned integral type that can represent any non-negative value of difference_type

    public:
		//Assign vector content

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
		//vector(const vector<T,Allocator>& x);
        Vector(const Vector& vecto): var_capacity(0), var_size(0), buffer_alloc(vecto.get_allocator()){(*this) = vecto;}

		// range constructor
		// Substitution Failure Is Not An Error
		
		 template <class InputIterator>
         	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), 
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()): var_alloc(alloc)
              {
                size_t n = last - first;
                buffer_v = var_alloc.allocate(n);
                for (size_t i = 0 ; i < n ; i++)
                  var_alloc.construct(&buffer_v[i], first[i]);
                  var_size = n;
                  var_capacity = n;
              }


		
        // destroy all conatainer
        ~Vector(void)
		{
            for (size_type i = 0; i < this->size(); i++)
                this->buffer_alloc.destroy(&this->v[i]);
			this->buffer_alloc.deallocate(this->v, this->capacity());
		}
        //+++++++++++++++++++++++++++++++++++++++++
// *** capacity
        size_type size() const{return (this->size);} // number element or object in vector
        size_type capacity() const{return (this->capacity);} // size allocation storage li kayen
        size_type max_size() const{return (this->alloc.max_size());} // max element l y9do ykono fe container number machi dima kaysawi capacity katb9a chi 7aja mekhbya
        // change size dyal conatiner be n element ila kan n < me capacity kansghroh l n li b9a kaydestroya 
        //ila kan l3kess kanzido fe capacity

        
        void resize(size_type n, value_type val = value_type())
		{
			if (n > this->capacity())
			{
				this->_realloc(n);
				this->_fill(this->size(), n, val);
			}
			if (n < this->capacity())
			{
				if (n < this->size())
					for (size_type i = n; i < this->size() - 1; i++)
						this->_alloc.destroy(&this->v[i]);
				else
					this->_fill(this->size(), n, val);
			}
			this->size = n;
		}
        
        //// check container wach empty
        bool empty() const
		{
			return (this->size() == 0);
		}
        //  tbdel capacity 
        void reserve (size_type n){if (n <= this->capacity())return ;this->_realloc(n);}



// *** fin capacity


// *** iteraror

        // ALL ITERATOR
        // return a reference to the first  element + random access iterator + not be dereferenced if conatiner empty
        iterator begin(){return (iterator(this->v));}
        // return a reference to the first  element + random access iterator + not be dereferenced if conatiner empty
        const_iterator begin() const{return (const_iterator(this->v));}
        //return iterator ma9bel la fin sequence
        iterator end(){return (iterator(&this->v[this->size()]));}
        //return iterator ma9bel la fin sequence
        const_iterator end() const{return (const_iterator(&this->v[this->size()]));}
        ///r eturn iterator pointing to the last
        reverse_iterator rbegin(){return (reverse_iterator(this->end()));}
        //
        const_reverse_iterator rbegin() const{return (const_reverse_iterator(this->end()));}
        //
        reverse_iterator rend(){return (reverse_iterator(this->begin()));}
        //
        const_reverse_iterator rend() const{return (const_reverse_iterator(this->begin()));}
// *** fin iterator

// *** element access

    // return element be la position dyalo dayr b7al Vector::at ghi at ila mal9atch katred exception
    reference operator[] (size_type n){return (this->v[n]);}
    const_reference operator[] (size_type n) const{return (this->v[n]);}
    reference at (size_type n){ if (n > this->size()) throw std::out_of_range("out of range"); return (this->v[n]);}
    const_reference at (size_type n){ if (n > this->size()) throw std::out_of_range("out of range"); return (this->v[n]);}
    reference front(){return (*(this->v))};// return direct refernce withit iterator
    reference back(){return (this->v[this->size() - 1]);} // return direct refernce withot iterator
	const_reference front() const{return (*(this->v));}
    const_reference back() const{return (this->v[this->size() - 1]);}

// *** fin element access

// *** modifiers


    // pop back Delete last elemnt remove lat element n9so size container be 1 
    void pop_back(){if (!this->size())return ;this->alloc.destroy(&this->v[--this->size]);}
    // push_back add new element at end of the vector
    void push_back (const value_type& val)
	{
		if (this->size() == this->capacity())
		{
			this->reserve((this->capacity() * 2) + (this->capacity() == 0));
		}
			this->alloc.construct(&this->_v[this->_size++], val);
	}

   // public member function insert 3 types
   // iterator insert (iterator position, const value_type& val); insert element before the element fe position mo7dada
   // incresing the container by size
    iterator insert (iterator position, const value_type& val)
	{
			size_type p;
			pos = this->_prepare_insert(position, 1);
			this->alloc.construct(&this->v[p], val);
			++this->_size;
			return (iterator(&this->v[p]));
	}
 
    //     void insert (iterator position, size_type n, const value_type& val);
    void insert (iterator position,size_type n, const value_type& val)
	{
			size_type pos;
			size_type i;

			pos = (this->_prepare_insert(position, n));
			i = n;
			while (i--)
				this->alloc.construct(&this->v[pos--], val);
			this->size += n;
	}
    // template <class InputIterator>    void insert (iterator position, InputIterator first, InputIterator last);
    template <class InputIterator>
	void insert (iterator position,InputIterator first,InputIterator last,typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type = InputIterator())
	{
		size_type pos;
		size_type distance;
		distance = std::distance(first, last);

	    pos = this->_prepare_insert(position, distance);
		while (first != last--)
			this->alloc.construct(&this->v[pos--], *(last));
		this->size += distance;
	}

	void assign (size_type n, const value_type& val)
	{
		if (n < this->size())
			this->destroy_array(n, this->size());
		if (n > this->capacity())
			this->reserve(n);
		this->destroy_array(0, this->size());
		this->size = n;
		for (size_type i = 0; i < n; i++)
			this->alloc.construct(&this->v[i], val);

	}

	allocator_type get_allocator() const
	{
			return (this->buffer_alloc);
	}
// *** fin modifires

};


}

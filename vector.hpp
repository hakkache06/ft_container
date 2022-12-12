# pragma once

# include <memory>
# include <stdexcept>

namespace ft
{

template < class T, class Alloc = std::allocator<T> >
class vector
{
    private:
    // les attrubites
        value_type		*v;
	    size_type		capacity;
	    size_type		size;
	    allocator_type	alloc;
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

        // Member functions
        //++++++++++++++++++++++++++++++++++++

        //construct/copy/destroy:
        //default constructor
        explicit Vector(const allocator_type& alloc = allocator_type()): v(nullptr), capacity(0), size(0), alloc(alloc){}
        // constructor 
        explicit Vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): capacity(n), size(0), alloc(alloc)
		{
			this->v = this->alloc.allocate(n);
			this->assign(n, val);
		}
        //vector(const vector<T,Allocator>& x);
        Vector(const Vector& vecto): capacity(0), size(0), alloc(vecto.get_allocator()){(*this) = vecto;}

        // destroy all conatainer
        ~Vector(void)
		{
            for (size_type i = 0; i < this->size(); i++)
                this->alloc.destroy(&this->v[i]);
			this->alloc.deallocate(this->v, this->capacity());
		}

        //+++++++++++++++++++++++++++++++++++++++++


// *** capacity


        size_type size() const{return (this->_size);} // number element or object in vector
        size_type capacity() const{return (this->_capacity);} // size allocation storage li kayen
        size_type max_size() const{return (this->_alloc.max_size());} // max element l y9do ykono fe container number machi dima kaysawi capacity katb9a chi 7aja mekhbya
        // change size dyal conatiner be n element ila kan n < me capacity kansghroh l n li b9a kaydestroya 
        //ila kan l3kess kanzido fe capacity

        /*
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
        */
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

    // Delete last elemnt remove lat element n9so size container be 1 
    void pop_back(){if (!this->size())return ;this->_alloc.destroy(&this->_v[--this->_size]);}



// *** fin modifires

};


}

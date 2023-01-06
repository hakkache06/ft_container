
#pragma once 

#include<iostream>
template <typename T , class alloc>
/// include compare

//typedef value_type										value_type;
//typedef key_type										key_type;
//typedef mapped_type										mapped_type;
//Compare													_compare;

class  nodaaa 
        {
            public: 
            alloc _alloc;
            T* pair;
            nodaaa * parent;
            nodaaa * left;
            nodaaa * right;
            size_t height;
            public:

                // default construct nodaaa 
                nodaaa() {
                pair = NULL;
                parent = NULL;
                left = NULL;
                right = NULL;
                height= 0;
                };

            nodaaa(T pairnode) {

                pair = _alloc.allocate(1);
                _alloc.construct(pair,pairnode);
                parent = NULL;
                left = NULL;
                right = NULL;
                height = 1;
            };

            nodaaa & operator = (const nodaaa  & ref) {
                parent = ref.parent;
                left = ref.left;
                right = ref.right;
                height = ref.height;
                return ( * this);
            };

            nodaaa(const nodaaa& ref): pair(ref.pair) {
                *this = ref;
            }
            ~nodaaa() {};
            
            // size_t     szie_heghit()
            // {
            //     return (height);
            // }
                
            //return the key of the current node
	    // key_type get_key() const
	    // {
	     // return (this->value->first);
	    // }
               //return return a reference to the value of the current node				
                // mapped_type &get_value()
                // {
	        // 	return (this->value->second);
                // }
                //return true if they are the same key, otherwise false.
		//bool is_equal(key_type k)
		//{
		//return (this->_compare(this->get_key(), k) == this->_compare(k, this->get_key()));
		//
        
      		/*
		// compare 2 keys and return if they met the condition bellow
		// @param k element key
		// @return true if they met the condition, otherwise false.
				
		bool is_lower_bound(key_type k)
		{
		return ((this->_compare(this->get_key(), k)) == false); uper bound true
		}
		*/
        
        

        };




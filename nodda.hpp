
#pragma once 

#include<iostream>
template <class Key,class Type, typename T , class alloc, class Compare std::less<key,Type>>

class  nodaaa 
{
            public: 
            alloc _alloc;
            T* pair;
            nodaaa * parent;
            nodaaa * left;
            nodaaa * right;
            size_t height;
            typedef Key key_type;
            typedef Type mapped_type;
            //////////////////////////////////////////////////////////////////////////\//
            typedef key_type										key_type;
            typedef mapped_type										mapped_type;
            Compare													_compare;
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
            
        //return the key of the current node
	        key_type get_key() const
	        {
	            return (this->pair>first);
	        }
            //return return a reference to the value of the current node				
            mapped_type &get_value()
            {
	        return (this->pair->second);
            }
            //return true if they are the same key, otherwise false.
		    bool is_equal(key_type k)
		    {
		        return (this->_compare(this->get_key(), k) == this->_compare(k, this->get_key()));
            }
        
		//return true if they met the condition, otherwise false.
				
		    bool is_lower_bound(key_type k)
		    {
		     return ((this->_compare(this->get_key(), k)) == false); 
		    }
        
            bool is_upper_boud(key_type k)
            {
                return ((this->_compare(this->get_key(), k)) == false); 
            }
        

};




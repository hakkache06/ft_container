
#pragma once 

#include<iostream>
template <typename T , class alloc>
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

        };




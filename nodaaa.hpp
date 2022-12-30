#pragma once


#include <string>
#include <iostream>
template < class T >


class nodaaa 
{

    public: 
      T _pair;
      nodaaa * parent;
      nodaaa * left;
      nodaaa * right;
      size_t height;
      public:

        // default construct nodaaa 
        nodaaa() {
          parent = NULL;
          left = NULL;
          right = NULL;
          height= 0;
        };

      nodaaa(T pair): _pair(pair) {
        parent = NULL;
        left = NULL;
        right = NULL;
        height = 1;
      };

      nodaaa(const nodaaa & ref): _pair(ref._pair) {
        * this = ref;
      }

      nodaaa & operator = (const nodaaa & ref) {
        parent = ref.parent;
        left = ref.left;
        right = ref._ight;
        height = ref.height;
        return ( * this);
      };

      ~nodaaa() {};

};

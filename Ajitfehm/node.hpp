
#pragma once

namespace ft 
{   
    template<class T>
    class node
    {
    public : 
    T _pair;
    node    *parent;
    node    *left;
    node    *right;
    size_t  hight;


    public:

        // default construct node 
        node()
        {
         parent = NULL;
         left = NULL;
         right = NULL;
         height = 0;
        };
        node(T pair):_pair(pair)
        {
            parent = NULL;
            left = NULL;
            right = NULL;
            height = 1;
        };

        node(const node &ref):_pair(ref._pair)
        {
            *this = ref;
        }

    node &operator=(const node &ref)
    {
        parent = ref.parent;
        left = ref.left;
        right = ref._ight;
        height = ref.height;
        return (*this);
    };

        ~node(){};
}
    
};


#pragram once

    template <class T, class Alloc>
    class tree_iterator{
    public:
        typedef T value_type;
        typedef std::ptrdiff_t difference_type; 
	    typedef	T*  pointer;
		typedef const T* const_pointer;
	    typedef T& reference;
        typedef const T& const_reference;
		typedef std::bidirectional_iterator_tag iterator_category;

        tree_iterator(){};

        tree_iterator(const tree_iterator &ref):avl_tree(ref.avl_tree){
        };


        const tree_iterator &operator=(const tree_iterator &rhs){
            if (this == &rhs)
	    	    return (*this);
	        this->avl_tree = rhs.avl_tree;
            return (*this);
        }

        ~tree_iterator(){
        }
        

        tree_iterator& operator++()
        {
            if(avl_tree._head == nullptr)
                return (*this);

            if (avl_tree._head != nullptr)
            {
                   avl_tree = avl_tree.min_node(avl_tree->right);
            }else
            {
                    
            }
        }








	    // const tree_iterator operator++(int){
        //     tree_iterator tmp(*this);
        //     operator++();
        //     return (tmp);
        // }
			
	    // const tree_iterator operator--(int){
		// 	tree_iterator tmp(*this);
        //     operator--();
        //     return (tmp);
		// } 


        bool operator==(const tree_iterator &it)const{
            return (avl_tree._head == it.avl_tree._head);
        };
        bool operator!=(const tree_iterator &it)const{
            return (avl_tree._head != it.avl_tree._head);
        };
        bool operator==(tree_iterator &x){
            return(this->avl_tree._head == x.avl_tree._head);
        }
        bool operator!=(tree_iterator &x){
            return(this->avl_tree._head != x.avl_tree._head);
        }
        protected:
        AVL<T, Alloc> avl_tree;
    }; 


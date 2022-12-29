#ifndef MAP_HPP
#define MAP_HPP

#include <utility>
#include <iomanip>
#include <math.h>

namespace ft
{
    template <class Key, class T, 
              class Compare = less<Key>,
              class Alloc = std::allocator<std::pair<Key, T> > >
    class map
    {

    private:
        struct TreeNode
        {
            std::pair<Key, T> val;
            TreeNode *left;
            TreeNode *right;
            TreeNode *parent;
            int height;
        };

    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef std::pair<key_type, mapped_type> value_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef typename Alloc::reference reference;
        typedef typename Alloc::const_reference const_reference;
        typedef typename Alloc::pointer pointer;
        typedef typename Alloc::const_pointer const_pointer;
        typedef typename ft::MapIterator<pointer, TreeNode, key_compare> iterator;
        typedef typename ft::MapIterator<const_pointer, TreeNode, key_compare> const_iterator;
        typedef typename ft::myReverseIterator<iterator> reverse_iterator;
        typedef typename ft::myReverseIterator<const_iterator> const_reverse_iterator;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;
        typedef typename Alloc::template rebind<TreeNode>::other node_allocator_type;

        class value_compare : public std::binary_function<value_type, value_type, bool>
        {
            friend class map;

        protected:
            Compare comp;
            value_compare(Compare c) : comp(c) {}

        public:
            bool
            operator()(const value_type &x, const value_type &y) const
            {
                return comp(x.first, y.first);
            }
        };

        /*================================ 4 CONSTRUCTORS: ================================*/

        /* EMPTY */
        explicit map(const key_compare &comp = key_compare(),
                     const allocator_type &alloc = allocator_type()) : _node(NULL), _comp(comp), _allocator_type(alloc)
        {
            this->_last_node = allocate_tree_node();
        }

        /*RANGE*/

        template <class InputIterator>
        map(InputIterator first, InputIterator last, typename ft::enable_if<!is_integral<InputIterator>::value> * = NULL,
            const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type()) : _node(NULL), _comp(comp), _allocator_type(alloc)
        {
            this->_last_node = allocate_tree_node();
            this->insert(first, last);
        }

        /*COPY*/
        map(const map &x) : _node(x._node), _comp(x._comp), _allocator_type(x._allocator_type)
        {
            this->_last_node = allocate_tree_node();
            _node = _alloc_node.allocate(1);
            *this = x;
        }

        /*================================ DESTRUCTOR: ================================*/

        virtual ~map()
        {
            clear();
            _alloc_node.deallocate(_last_node, 1);
        }

        /*================================ OPERATOR=: ================================*/

        map &operator=(const map &x)
        {
            if (&x != this)
            {
                clear();
                insert(x.begin(), x.end());
            }
            return (*this);
        }

        /*================================ ITERATORS: ================================*/

        iterator begin()
        {
            if (!_last_node->right) // in the last node I always update the min value after insertion
                return (iterator(_node));
            return (iterator(_last_node->right));
        }

        const_iterator begin() const
        {
            if (!_last_node->right)
                return (const_iterator(_node));
            return (const_iterator(_last_node->right));
        }

        iterator end()
        {
            return (iterator(_last_node));
        }

        const_iterator end() const
        {
            return (const_iterator(_last_node));
        }

        reverse_iterator rbegin()
        {
            return (reverse_iterator(end()));
        }

        const_reverse_iterator rbegin() const
        {
            return (const_reverse_iterator(end()));
        }

        reverse_iterator rend()
        {
            return (reverse_iterator(begin()));
        }

        const_reverse_iterator rend() const
        {
            return (const_reverse_iterator(begin()));
        }

        /*================================ CAPACITY: ================================*/

        bool empty() const
        {
            if (!_node)
                return true;
            else
                return false;
        }

        size_type size() const
        {
            if (!_node)
                return (0);
            return (tree_size(_node) + 1);
        }

        size_type max_size() const
        {
            return this->_alloc_node.max_size();
        }

        /*================================ ELEMENT ACCESS: ================================*/

        mapped_type &operator[](const key_type &k)
        {
            return (*((this->insert(std::make_pair(k, mapped_type()))).first)).second;
        }

        /*================================ MODIFIERS: ================================*/

        /* INSERT */

        /* The single element versions (1) return a pair,
        with its member pair::first set to an iterator pointing to either the newly inserted element
        or to the element with an equivalent key in the map. The pair::second element in the pair 
        is set to true if a new element was inserted or false if an equivalent key already existed. */

        void unlink_end()
        {
            if (_last_node->left)
                _last_node->left->right = NULL;
        }

        void link_end()
        {
            TreeNode *max = max_node(_node);

            _node->parent = NULL;
            max->right = _last_node;
            _last_node->left = max;
            _last_node->right = min_node(_node);
            _last_node->parent = max;
        }

        std::pair<iterator, bool>
        insert(const value_type &val)
        {
            if (_last_node->left)
                unlink_end();

            TreeNode *current = _node;
            TreeNode *tmp;

            while (current)
            {
                if (current->val.first == val.first)
                {
                    link_end();
                    return make_pair(iterator(current), false);
                }
                if (_comp(val.first, current->val.first)) // val.first < current->val.first
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            }
            _node = insert_node(_node, val);
            current = _node;
            while (current)
            {
                tmp = current;
                if (_comp(val.first, current->val.first)) // val.first < current->val.first
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            }
            link_end();
            return std::make_pair(iterator(tmp), true);
        }

        iterator
        insert(iterator position, const value_type &val)
        {
            TreeNode *current;
            TreeNode *tmp;

            (void)position;
            if (_last_node->left)
                unlink_end();
            _node = insert_node(_node, val);
            current = _node;
            while (current)
            {
                tmp = current;
                if (_comp(val.first, current->val.first)) // val.first < current->val.first
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            }
            link_end();
            return (iterator(tmp));
        }

        template <class InputIterator>
        void insert(InputIterator first, InputIterator last, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIterator = InputIterator())
        {
            (void)isIterator;
            while (first != last)
                insert(*(first++));
        }

        /* ERASE */

        void erase(iterator position)
        {
            erase((*position).first);
        }

        size_type erase(const key_type &k)
        {
            if (_last_node->right == _last_node->left)
            {
                unlink_end();
                _alloc_node.destroy(_node);
                _alloc_node.deallocate(_node, 1);
                _node = NULL;
                return 1;
            }
            unlink_end();
            _node = deleteNode(_node, k);
            link_end();
            return 1;
        }

        void erase(iterator first, iterator last)
        {
            if (first == this->begin() && last == this->end())
            {
                while (first != last && _node != NULL)
                    erase((*(first++)).first);
            }
            else
            {
                difference_type n = ft::distance(first, last);
                while (n--)
                    erase((*(first++)).first);
            }
        }

        /* SWAP */

        void swap(map &x)
        {
            if (this == &x)
                return;
            ft::swap(this->_node, x._node);
            ft::swap(this->_allocator_type, x._allocator_type);
            ft::swap(this->_alloc_node, x._alloc_node);
            ft::swap(this->_comp, x._comp);
            ft::swap(this->_last_node, x._last_node);
        }

        /* CLEAR */

        void clear()
        {
            erase(begin(), end());
        }

        /*================================ OBSERVERS: ================================*/

        key_compare key_comp() const
        {
            return key_compare();
        }

        value_compare value_comp() const
        {

            return value_compare(key_compare());
        }

        /*================================ OPERATIONS: ================================*/

        iterator find(const key_type &k)
        {

            TreeNode *current = _node;
            unlink_end();
            while (current)
            {
                if (current->val.first == k)
                {
                    link_end();
                    return (iterator(current));
                }
                if (_comp(k, current->val.first)) // k < current->val.first
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            }
            link_end();
            return end();
        }

        const_iterator find(const key_type &k) const
        {
            const_iterator(find(k));
        }

        size_type count(const key_type &k) const
        {
            TreeNode *current = _node;
            size_type count = 0;
            while (current)
            {
                if (current->val.first == k)
                {
                    count++;
                }
                if (_comp(k, current->val.first)) // k < current->val.first
                {
                    current = current->left;
                }
                else
                {
                    current = current->right;
                }
            }
            return count;
        }

        iterator lower_bound(const key_type &k)
        {
            iterator start = this->begin();
            iterator end = this->end();

            while (start != end)
            {
                if (_comp((*start).first, k) == false)
                    break;
                start++;
            }
            return (start);
        }

        const_iterator lower_bound(const key_type &k) const
        {
            return const_iterator(lower_bound(k));
        }

        iterator upper_bound(const key_type &k)
        {
            iterator start = this->begin();
            iterator end = this->end();

            while (start != end)
            {
                if (_comp(k, (*start).first))
                    break;
                start++;
            }
            return (start);
        }

        const_iterator upper_bound(const key_type &k) const
        {
            return const_iterator(upper_bound(k));
        }

        std::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
        {
            return std::make_pair(lower_bound(k), upper_bound(k));
        }

        std::pair<iterator, iterator> equal_range(const key_type &k)
        {
            return std::make_pair(lower_bound(k), upper_bound(k));
        }

        /*================================ HELPING FUNCTIONS : ================================*/
    private:
        TreeNode *allocate_tree_node()
        {
            TreeNode *node;

            node = this->_alloc_node.allocate(1);
            node->right = NULL;
            node->left = NULL;
            node->parent = NULL;
            std::memset(&node->val, 0, sizeof(node->val));
            return node;
        }

        // A utility function to get maximum
        // of two integers
        int max(int a, int b)
        {
            return (a > b) ? a : b;
        }

        int height(TreeNode *N)
        {
            if (N == NULL)
                return 0;
            return N->height;
        }

        /* Helper function that allocates a
   new node with the given key and
   NULL left and right pointers. */
        TreeNode *newNode(const value_type &val, TreeNode *parent = NULL)
        {
            TreeNode *node;
            node = _alloc_node.allocate(1);
            _allocator_type.construct(&node->val, val);
            node->right = NULL;
            node->left = NULL;
            node->parent = parent;
            node->height = 1; // new node is initially
                              // added at leaf

            return (node);
        }

        // A utility function to right
        // rotate subtree rooted with y
        // See the diagram given above.
        TreeNode *rightRotate(TreeNode *y)
        {
            TreeNode *x = y->left;
            TreeNode *T2 = x->right;

            // Perform rotation

            x->right = y;
            y->left = T2;

            // Update parent pointers
            x->parent = y->parent;
            y->parent = x;
            if (T2)
                T2->parent = y;

            // Update heights
            y->height = max(height(y->left),
                            height(y->right)) +
                        1;
            x->height = max(height(x->left),
                            height(x->right)) +
                        1;

            // Return new root
            return x;
        }

        // A utility function to left
        // rotate subtree rooted with x
        // See the diagram given above.
        TreeNode *leftRotate(TreeNode *x)
        {
            TreeNode *y = x->right;
            TreeNode *T2 = y->left;

            // Perform rotation
            y->left = x;
            x->right = T2;

            // Update parent pointers

            y->parent = x->parent;
            x->parent = y;
            if (T2)
                T2->parent = x;

            // Update heights
            x->height = max(height(x->left),
                            height(x->right)) +
                        1;
            y->height = max(height(y->left),
                            height(y->right)) +
                        1;

            // Return new root
            return y;
        }

        // Get Balance factor of node N
        int getBalance(TreeNode *N)
        {
            if (N == NULL)
                return 0;
            return height(N->left) - height(N->right);
        }

        // Recursive function to insert a key
        // in the subtree rooted with node and
        // returns the new root of the subtree.
        TreeNode *insert_node(TreeNode *node, const value_type &val, TreeNode *parent = NULL)
        {
            if (node == NULL)
                return (newNode(val, parent)); // initially parent is set to NULL

            /* 1. Perform the normal BST insertion */

            if (_comp(val.first, node->val.first)) // val.first < node->val.first
            {
                node->left = insert_node(node->left, val, node); // here we instead of NULL parent has the value
            }
            else if (_comp(node->val.first, val.first)) // val.first > node->val.first
            {
                node->right = insert_node(node->right, val, node); // here we instead of NULL parent has the value
            }
            else // Equal keys are not allowed in BST
                return node;

            /* 2. Update height of this ancestor node */
            node->height = 1 + max(height(node->left),
                                   height(node->right));

            /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
            int balance = getBalance(node);

            // If this node becomes unbalanced, then
            // there are 4 cases

            // Left Left Case
            if (balance > 1 && _comp(val.first, node->left->val.first)) //val.first < node->left->val.first
                return rightRotate(node);

            // Right Right Case
            if (balance < -1 && _comp(node->right->val.first, val.first)) // val.first > node->right->val.first
                return leftRotate(node);

            // Left Right Case
            if (balance > 1 && _comp(node->left->val.first, val.first)) // val.first > node->left->val.first
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }

            // Right Left Case
            if (balance < -1 && _comp(val.first, node->right->val.first)) // val.first < node->right->val.first
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
            /* return the (unchanged) node pointer */
            return node;
        }

        TreeNode *deleteNode(TreeNode *root, const key_type &key)
        {

            // STEP 1: PERFORM STANDARD BST DELETE
            if (root == NULL)
                return root;

            // If the key to be deleted is smaller
            // than the root's key, then it lies
            // in left subtree
            if (_comp(key, root->val.first)) // key < root->val.first
                root->left = deleteNode(root->left, key);

            // If the key to be deleted is greater
            // than the root's key, then it lies
            // in right subtree
            else if (_comp(root->val.first, key)) // key > root->val.first
                root->right = deleteNode(root->right, key);

            // if key is same as root's key, then
            // This is the node to be deleted
            else
            {
                // node with only one child or no child
                if ((root->left == NULL) ||
                    (root->right == NULL))
                {
                    TreeNode *temp = root->left ? root->left : root->right;

                    // No child case
                    if (temp == NULL)
                    {
                        temp = root;
                        root = NULL;
                    }
                    else
                    {
                        temp->parent = root->parent;
                        *root = *temp;
                    } // One child case
                      // Copy the contents of
                      // the non-empty child
                    _alloc_node.destroy(temp);
                    _alloc_node.deallocate(temp, 1);
                }
                else
                {
                    // node with two children: Get the inorder
                    // successor (smallest in the right subtree)
                    TreeNode *temp = min_node(root->right);

                    // Copy the inorder successor's
                    // data to this node
                    root->val = temp->val;

                    // Delete the inorder successor
                    root->right = deleteNode(root->right,
                                             temp->val.first);
                }
            }

            // If the tree had only one node
            // then return
            if (root == NULL)
                return root;

            // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
            root->height = 1 + max(height(root->left),
                                   height(root->right));

            // STEP 3: GET THE BALANCE FACTOR OF
            // THIS NODE (to check whether this
            // node became unbalanced)
            int balance = getBalance(root);

            // If this node becomes unbalanced,
            // then there are 4 cases

            // Left Left Case
            if (balance > 1 &&
                getBalance(root->left) >= 0)
                return rightRotate(root);

            // Left Right Case
            if (balance > 1 &&
                getBalance(root->left) < 0)
            {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }

            // Right Right Case
            if (balance < -1 &&
                getBalance(root->right) <= 0)
                return leftRotate(root);

            // Right Left Case
            if (balance < -1 &&
                getBalance(root->right) > 0)
            {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }

            return root;
        }

        TreeNode *min_node(TreeNode *node)
        {
            if (node)
            {
                while (node->left)
                    node = node->left;
            }
            return (node);
        }

        TreeNode *max_node(TreeNode *node)
        {
            if (node)
            {
                while (node->right)
                    node = node->right;
            }
            return (node);
        }

        size_type tree_size(TreeNode *node) const
        {
            if (node == NULL || node->right == _last_node)
                return 0;
            return (tree_size(node->left) + 1 + tree_size(node->right));
        }

        /*      ----PRINT TREE----      */
        /** These methods are not included in the 
  *** container map. They can be used to 
  *** check the balance of a tree.
  **
  */
        void treeprint()
        {
            int i = 0;
            while (i <= _height(_node) - 1)
            {
                printlv(i);
                i++;
                std::cout << std::endl;
            }
        }

        void printlv(int n)
        {
            TreeNode *temp = _node;
            int val = pow(2, _height(_node) - n + 1);
            std::cout << std::setw(val) << "";
            dispLV(temp, n, val);
        }

        void dispLV(TreeNode *p, int lv, int d)
        {
            int disp = 2 * d;
            if (lv == 0)
            {
                if (p == NULL)
                {

                    std::cout << " x ";
                    std::cout << std::setw(disp - 3) << "";
                    return;
                }
                else
                {
                    std::cout << " " << p->val.first << " ";
                    if (p->parent)
                        std::cout << "|" << p->parent->val.first;
                    std::cout << std::setw(disp - 3) << "";
                }
            }
            else
            {
                if (p == NULL && lv >= 1)
                {
                    dispLV(NULL, lv - 1, d);
                    dispLV(NULL, lv - 1, d);
                }
                else
                {
                    dispLV(p->left, lv - 1, d);
                    dispLV(p->right, lv - 1, d);
                }
            }
        }

    private:
        TreeNode *_node;
        TreeNode *_last_node;
        Compare _comp;
        allocator_type _allocator_type;
        node_allocator_type _alloc_node;
    };
}

#endif


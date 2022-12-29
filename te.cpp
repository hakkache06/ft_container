

        node *deleteNode(node *root, const key_type &key)
        {

            if (root == NULL)
                return root;

            if (_comp(key, root->val.first)) // key < root->val.first
                root->left = deleteNode(root->left, key);

            else if (_comp(root->val.first, key)) // key > root->val.first
                root->right = deleteNode(root->right, key);
            else
            {
                if ((root->left == NULL) ||(root->right == NULL))
                {
                    node *temp = root->left ? root->left : root->right;

                    if (temp == NULL)
                    {
                        temp = root;
                        root = NULL;
                    }
                    else
                    {
                        temp->parent = root->parent;
                        *root = *temp;
                    } 
                    _alloc_node.destroy(temp);
                    _alloc_node.deallocate(temp, 1);
                }
                else
                {
                    node *temp = min_node(root->right);
                    root->val = temp->val;
                    root->right = deleteNode(root->right,temp->val.first);
                }
            }

            if (root == NULL)
                return root;

            root->height = 1 + max(height(root->left), height(root->right));
            int balance = getBalance(root);

            if (balance > 1 && getBalance(root->left) >= 0)
                return LRI(root);

            if (balance > 1 && getBalance(root->left) < 0)
            {
                root->left = leftRotate(root->left);
                return LRI(root);
            }
            if (balance < -1 &&
                getBalance(root->right) <= 0)
                return LR(root);
            if (balance < -1 &&
                getBalance(root->right) > 0)
            {
                root->right = rightRotate(root->right);
                return LR(root);
            }

            return root;
        }



int main()
{


}
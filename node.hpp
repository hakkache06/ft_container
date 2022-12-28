

#pragma once
namespace ft 
{
    struct node
    {
        typedef key_type    key_type;
        node    *parent;
        node    *left;
        node    *right;
        size_type           heghit;
        value_type          *value;

        void    node_init()
        {
            this->parent = NULL;
            this->left = NULL;
            this->right = NULL;
            this->value = NULL;
            this->heghit = 0;
        }

}
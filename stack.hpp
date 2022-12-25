
#pragma one
#include "vector.hpp"
namespace ft {

template <class T, class Container = ft::Vector<T> >
class stack
{
    private :

        typedef T value_type; // Type qui représente le type d'objet stocké en tant qu'élément dans un objet stack.
        typedef Container container_type; // Type qui fournit le conteneur de base à adapter par un objet stack.
        typedef size_t size_type; // Type entier non signé qui peut représenter le nombre d'éléments dans un stack

    public :
        container_type _s;
        // Vector Container
        // Type de données des éléments à stocker dans la pile.
        // Type du conteneur sous-jacent utilisé pour implémenter la pile. La valeur par défaut est la classe deque<Type>.
        // Construit un objet stack qui est vide ou qui est une copie de l'objet conteneur de base.
        explicit stack (const container_type& _s = container_type()):_s(_s){}
        ~stack(void){};
        // Function 
        bool empty() const 
        {
            return (this->_s.empty());
        }

        size_type size()
        {
            return (this->_s.size());
        }

        value_type& top()
        {
            return (this->_s.back());
        }
        const value_type& top() const
        {
            return (this->_s.back());
        }
        void push(const value_type& val)
        {
            this->_s.push_back(val);
        }
        void    pop()
        {
            this->_s.pop_back();
        }
        void swap (stack& x)
        {
            this->_s.swap(x);
        }

    
        friend bool operator== (const Stack &lhs, const Stack &rhs)
        {
            return (lhs._s == rhs._s);
        }

        friend bool operator!= (const Stack &lhs, const Stack &rhs)
        {
            return (lhs._s != rhs._s);
        }

        friend bool operator<  (const Stack &lhs, const Stack &rhs)
        {
            return (lhs._s < rhs._s);
        }

        friend bool operator<= (const Stack &lhs, const Stack &rhs)
        {
            return (lhs._s <= rhs._s);
        }

        friend bool operator>  (const Stack &lhs, const Stack &rhs)
        {
            return (lhs._s > rhs._s);
        }

        friend bool operator>= (const Stack &lhs, const Stack &rhs)
        {
            return (lhs._s >= rhs._s);
        }
};
    	

}
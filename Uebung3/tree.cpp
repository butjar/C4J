#ifndef TREE_CPP
#define TREE_CPP

#include "tree.h"

using namespace mystl;

template <typename T, typename O>
Tree<T,O>::Tree(TreeNode<T,O> *root)
    :m_root(root){}

template <typename T, typename O>
TreeIterator<T,O> Tree<T,O>::insert(const T& value) {
    if(m_root == 0){
        m_root = new TreeNode<T,O>(value);
        return TreeIterator<T,O>(m_root);
    }else{
        if(m_root->find(value) != 0){

        } else if(m_root->find(value) == 0){
            TreeNode<T,O>* node = m_root;
            O Order;
            while(node != 0){
                if(Order(value,node->m_value)) {
                    if(node->m_left == 0){
                        node->m_left = new TreeNode<T,O>(value,node);
                        return node->m_left->getIterator();
                    }else{
                        node = node->m_left;
                    }
                } else if(Order(node->m_value,value)) {
                    if(node->m_right == 0){
                        node->m_right = new TreeNode<T,O>(value,node);
                        return node->m_right->getIterator();
                    }else{
                        node = node->m_right;
                    }
                }
            }
        }
    }
}

template <typename T, typename O>
void Tree<T,O>::clear() {
    m_root->m_left = 0;
    m_root->m_right = 0;
}

template <typename T, typename O>
TreeIterator<T,O> Tree<T,O>::begin() {
    return TreeIterator<T,O>(m_root, this);
}

template <typename T, typename O>
TreeIterator<T,O> Tree<T,O>::end() {
    return TreeIterator<T,O>(0, this);
}

template <typename T, typename O>
TreeIterator<T,O> Tree<T,O>::first() {
    return TreeIterator<T,O>(m_root->findFirst(), this);
}

template <typename T, typename O>
TreeIterator<T,O> Tree<T,O>::last() {
    return TreeIterator<T,O>(m_root->findLast(), this);
}

template <typename T, typename O>
TreeIterator<T,O> Tree<T,O>::find(const T& value){
    return m_root->find(value)->getIterator();
}

#endif

#include "AVLTree.h"

template<class T>
AVLTree<T>::AVLTree()
{
    this->root = NULL;
}

template<class T>
AVLTree<T>::AVLTree(AVLNode<T>* root)
{
    this->root = root;
}

template<class T>
int AVLTree<T>::height()
{
    return root->getHeight();
}

template<class T>
int AVLTree<T>::height(AVLNode<T> *node)
{   
    if (node == NULL) return 0;
    return node->getHeight();
}

template<class T>
int AVLTree<T>::calcHeight(AVLNode<T> *node)
{
    int h = 0;
    if(node != NULL)
    {
        h = 1 + max(calcHeight(node->getLeft()), node->getRight());
    }
    node->setHeight(h);
    return h;
}

template<class T>
AVLNode<T>* AVLTree<T>::rotateLL(AVLNode<T> *parent)
{
    AVLNode<T>* newRoot = parent->getLeft();
    parent->setLeft(newRoot.getRight());
    newRoot->setRight(parent);
    calcHeight(newRoot);
    return newRoot;
}   

template<class T>
AVLNode<T>* AVLTree<T>::rotateRR(AVLNode<T> *parent)
{
    AVLNode<T>* newRoot = parent.getRight();
    parent->setRight(newRoot.getLeft());
    newRoot->setLeft(parent);
    calcHeight(newRoot);
    return newRoot;
}

template<class T>
AVLNode<T>* AVLTree<T>::rotateLR(AVLNode<T> *parent)
{
    parent->setLeft(rotateRR(parent->getLeft()));
    return rotateLL(parent);
}

template<class T>
AVLNode<T>* AVLTree<T>::rotateRL(AVLNode<T> *parent)
{
    parent->setRight(rotateLL(parent->getRight()));
    return rotateRR(parent);
}

template<class T>
void AVLTree<T>::insert(T data)
{
    if(this->root == NULL)
    {
        this->root = AVLNode<T>(data);
        calcHeight(root);
        return;
    }
    else if(data < root->getData())
    {
        root->setLeft(insert(root->getLeft(), data));
    }
    else if(data >= root->getData())
    {
        root->setRight(insert(root->getRight(), data));
    }

}

template<class T>
AVLNode<T>* AVLTree<T>::insert(AVLNode<T> *node, T data)
{
    if(node == NULL)
    {
        node = AVLNode<T>(data);
        calcHeight(root);
        return node;
    }
    else if(data < node->getData())
    {
        node->setLeft(insert(node->getLeft(), data));
    }
    else if(data >= node->getData())
    {
        node->setRight(insert(node->getRight(), data));
    }
    int diff = height(node->getLeft()) - height(node->getRight());
    if (diff > 1)
    {
        if(height(node->getLeft()->getLeft()) - height(node->getLeft()->getRight()) > 0)
        {
            node = rotateLL(node);
        }
        else
        {
            node = rotateLR(node);
        }
    }
    else if(diff < -1)
    {
        if(height(node->getRight()->getLeft()) - height(node->getRight()->getRight()) > 0)
        {
            node = rotateRL(node);
        }
        else 
        {
            node = rotateRR(node);
        }
    }
    return node;
}

template<class T>
int AVLTree<T>::contains(T data)
{
    return 1;
}

template<class T>
int AVLTree<T>::validate()
{
    return 1;
}
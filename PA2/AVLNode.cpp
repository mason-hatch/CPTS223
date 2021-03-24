#include "AVLNode.h"

template<class T>
AVLNode<T>::AVLNode()
{
    this->data = NULL;
    this->left = NULL;
    this->right = NULL;
    this->height = 0;
}

template<class T>
AVLNode<T>::AVLNode(T data)
{
    this->data = data;
    this->left = NULL;
    this->right = NULL;
    this->height = 0;
}

template<class T>
AVLNode<T>::AVLNode(T data, AVLNode* left, AVLNode* right, int height)
{
    this->data = data;
    this->left = left;
    this->right = right;
    this->height = height;
}

template<class T>
T AVLNode<T>::getData()
{
    return this->data;
}

template<class T>
int AVLNode<T>::getHeight()
{
    return this->height;
}

template<class T>
void AVLNode<T>::setHeight(int height)
{
    this->height = height;
}

template<class T>
AVLNode<T>* AVLNode<T>::getLeft()
{
    return this->left;
}

template<class T>
AVLNode<T>* AVLNode<T>::getRight()
{
    return this->right;
}

template<class T>
void AVLNode<T>::setLeft(AVLNode* left)
{
    this->left = left;
}

template<class T>
void AVLNode<T>::setRight(AVLNode* right)
{
    this->right = right;
}
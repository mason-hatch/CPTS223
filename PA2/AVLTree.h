#ifndef AVLTREE_H
#define AVLTREE_H

#include <stdio.h>
#include <random>
#include <iterator>
#include <iostream>
#include <algorithm>
#include "AVLNode.h"

template <class T>
class AVLTree{
    AVLNode<T>* root;
public:
    AVLTree();
    AVLTree(AVLNode<T>* root);
    int height();
    int height(AVLNode<T> *node);
    int calcHeight(AVLNode<T> *parent);
    AVLNode<T>* rotateLL(AVLNode<T> *parent);
    AVLNode<T>* rotateRR(AVLNode<T> *parent);
    AVLNode<T>* rotateLR(AVLNode<T> *parent);
    AVLNode<T>* rotateRL(AVLNode<T> *parent);
    void insert(T data);
    AVLNode<T>* insert(AVLNode<T> *node, T data);
    int contains(T data);
    int validate();
};

#endif
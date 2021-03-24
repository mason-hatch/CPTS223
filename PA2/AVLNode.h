#ifndef AVLNODE_H
#define AVLNODE_H

#include <stdio.h>
#include <random>
#include <iterator>
#include <iostream>
#include <algorithm>

template <class T>
class AVLNode{
    T data;
    AVLNode<T>* left;
    AVLNode<T>* right;
    int height;
public:
    AVLNode();
    AVLNode(T data);
    AVLNode(T data, AVLNode<T>* left, AVLNode<T>* right, int height);
    T getData();
    int getHeight();
    void setHeight(int height);
    AVLNode<T>* getLeft();
    AVLNode<T>* getRight();
    void setLeft(AVLNode<T>* left);
    void setRight(AVLNode<T>* right);
};

#endif
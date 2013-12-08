//
//  Node.h
//  tree
//
//  Created by Nikita Galushko on 12.10.13.
//  Copyright (c) 2013 Nikita Galushko. All rights reserved.
//

#ifndef __tree__Node__
#define __tree__Node__

#include <iostream>

template<class VALUE>

class Node {
    
private:
    int key;
    VALUE data;
    Node<VALUE>* leftChild;
    Node<VALUE>* rightChild;
    
public:
    
    Node(int key, VALUE data, Node<VALUE>* left = 0, Node<VALUE>* right = 0);
    virtual int getKey();
    virtual VALUE getData();
    virtual Node<VALUE>* getLeft();
    virtual Node<VALUE>* getRight();
    virtual void setLeft(Node<VALUE>* left);
    virtual void setRight(Node<VALUE>* right);
    ~Node();
};

template<class VALUE>
Node<VALUE>::Node(int key, VALUE data, Node<VALUE>* left, Node<VALUE>* right) {
    
    this->key = key;
    this->data = data;
    this->leftChild = left;
    this->rightChild = right;
    
}

template<class VALUE>
int Node<VALUE>::getKey() {
    return this->key;
}

template<class VALUE>
VALUE Node<VALUE>::getData() {
    return this->data;
}

template<class VALUE>
Node<VALUE>* Node<VALUE>::getLeft() {
    return this->leftChild;
}

template<class VALUE>
Node<VALUE>* Node<VALUE>::getRight() {
    return this->rightChild;
}

template<class VALUE>
void Node<VALUE>::setLeft(Node<VALUE>* left) {
    this->leftChild = left;
}

template<class VALUE>
void Node<VALUE>::setRight(Node<VALUE>* right) {
    this->rightChild = right;
}

template<class VALUE>
Node<VALUE>::~Node() {
    std::cout<<"Node delete\n";
}
#endif /* defined(__tree__Node__) */

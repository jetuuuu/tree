//
//  Tree.h
//  tree
//
//  Created by Nikita Galushko on 12.10.13.
//  Copyright (c) 2013 Nikita Galushko. All rights reserved.
//

#ifndef __tree__Tree__
#define __tree__Tree__

#include <iostream>
#include "Node.h"
#include "CommonTree.h"

template<class VALUE>

class Tree : public CommonTree<VALUE> {
    
private:
    
    Node<VALUE>* root;
    
public:
    
    Tree(int key, VALUE data, Node<VALUE>* left = 0, Node<VALUE>* right = 0);
    Tree();
    Node<VALUE>* find(int key);
    void insert(int key, VALUE data);
    Node<VALUE>* getRoot();
    Node<VALUE>** getPointerRoot();
    friend std::ostream& operator<<(std::ostream& stream, const Tree<VALUE>& node);
};

template<class VALUE>
Tree<VALUE>::Tree() {
    this->root = 0;
};

template<class VALUE>
Tree<VALUE>::Tree(int key, VALUE data, Node<VALUE>* left, Node<VALUE>* right) {
    Node<VALUE>* root = new Node<VALUE>(key, data, left, right);
    this->root = root;
}

template <class VALUE>
std::ostream& operator<<(std::ostream& stream, Tree<VALUE>& tree) {
    stream<< tree.bracketPrint(tree.getRoot());
    return stream;
}

template<class VALUE>
void Tree<VALUE>::insert(int key, VALUE data) {
    
    Node<VALUE> *newNode = new Node<VALUE>(key, data);
    
    if (this->root == 0)
        root = newNode;
    else {
        Node<VALUE>* current = this->root;
        Node<VALUE>* parent;
        
        while (true) {
            parent = current;
            
            if (key < current->getKey()) {
                
                current = current->getLeft();
                if (current == 0) {
                    parent->setLeft(newNode);
                    return;
                }
                
            }
            else {
                current = current->getRight();
                if (current == 0) {
                    parent->setRight(newNode);
                    return;
                }
            }
        }
    }
    
}

template<class VALUE>
Node<VALUE>* Tree<VALUE>::find(int key) {
    
    Node<VALUE>* current = this->root;
    return CommonTree<VALUE>::find(key, current);
    
}

template<class VALUE>
Node<VALUE>** Tree<VALUE>::getPointerRoot() {
    return &root;
}

template<class VALUE>
Node<VALUE>* Tree<VALUE>::getRoot() {
    return this->root;
}
#endif /* defined(__tree__Tree__) */
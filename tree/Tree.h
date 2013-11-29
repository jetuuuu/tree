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
    Node<VALUE>* find(int key);
    void insert(int key, VALUE data);
    void deleteElements(int key);
    //void inorderTreeWalk(Node<VALUE>* node);
    Node<VALUE>* getRoot();
    //Node<VALUE>* min(Node<VALUE>* node);
    //Node<VALUE>* max(Node<VALUE>* node);
};


#endif /* defined(__tree__Tree__) */

template<class VALUE>
Tree<VALUE>::Tree(int key, VALUE data, Node<VALUE>* left, Node<VALUE>* right) {
    Node<VALUE>* root = new Node<VALUE>(key, data, left, right);
    this->root = root;
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
                
                current = &current->getLeft();
                if (current == 0) {
                    parent->setLeft(newNode);
                    return;
                }
                
            }
            else {
                current = &current->getRight();
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
    
    while (current->getKey() != key) {
        
        if (key < current->getKey()) {
            current = &current->getLeft();
        }
        else {
            current = &current->getRight();
        }
        
        if (current == 0)
            return 0;
    }
    
    return current;
    
}

template<class VALUE>
Node<VALUE>* Tree<VALUE>::getRoot() {
    return this->root;
}

/*template<class VALUE>
void Tree<VALUE>::inorderTreeWalk(Node<VALUE>* node) {
    
    if (node != 0) {
        this->inorderTreeWalk(&node->getLeft());
        std::cout<< node->getKey()<< "; ";
        this->inorderTreeWalk(&node->getRight());
    }
    
}

template<class VALUE>
Node<VALUE>* Tree<VALUE>::min(Node<VALUE>* node) {
    
    Node<VALUE>* last;
    Node<VALUE>* current = node;
    
    while (current != 0) {
        last = current;
        current = last->getLeft();
    }
    
    return last;
}

template<class VALUE>
Node<VALUE>* Tree<VALUE>::max(Node<VALUE>* node) {
    
    Node<VALUE>* last;
    Node<VALUE>* current = node;
    
    while (current != 0) {
        last = current;
        current = &last->getRight();
    }
    
    return last;
    
}*/
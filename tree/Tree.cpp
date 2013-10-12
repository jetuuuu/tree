//
//  Tree.cpp
//  tree
//
//  Created by Nikita Galushko on 12.10.13.
//  Copyright (c) 2013 Nikita Galushko. All rights reserved.
//

#include "Tree.h"
#include "Node.h"

Tree::Tree(int key, double data, Node* left, Node* right) {
    Node(key, data, left, right);
}

Node* Tree::find(int key) {
    
    Node* current = this->root;
    
    while (current->getKey() != key) {
        
        if (key < current->getKey()) {
            current = current->getLeft();
        }
        else {
            current = current->getRight();
        }
        
        if (current == 0)
            return 0;
    }
    
    return current;
    
}

void Tree::insert(int key, double data) {
    
    Node *newNode = new Node(key, data);
    
    if (this->root == 0)
        root = newNode;
    else {
        Node* current = this->root;
        Node* parent;
        
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
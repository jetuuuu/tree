//
//  Node.cpp
//  tree
//
//  Created by Nikita Galushko on 12.10.13.
//  Copyright (c) 2013 Nikita Galushko. All rights reserved.
//

#include "Node.h"

Node::Node(int key, double data, Node* left, Node* right) {
    
    this->key = key;
    this->data = data;
    this->leftChild = left;
    this->rightChild = right;
    
}

int Node::getKey() {
    return this->key;
}

double Node::getData() {
    return this->data;
}

Node* Node::getLeft() {
    return this->leftChild;
}

Node* Node::getRight() {
    return this->rightChild;
}

void Node::setLeft(Node* left) {
    this->leftChild = left;
}

void Node::setRight(Node *right) {
    this->rightChild = right;
}
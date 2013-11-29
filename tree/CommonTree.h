//
//  CommonTree.h
//  tree
//
//  Created by Nikita Galushko on 29.11.13.
//  Copyright (c) 2013 Nikita Galushko. All rights reserved.
//

#ifndef tree_CommonTree_h
#define tree_CommonTree_h

#include "Node.h"

template <class VALUE>

class CommonTree {
public:
    void inorderTreeWalk(Node<VALUE>* node);
    Node<VALUE>* max(Node<VALUE>* node);
    Node<VALUE>* min(Node<VALUE>* node);
};

template<class VALUE>
void CommonTree<VALUE>::inorderTreeWalk(Node<VALUE>* node) {
    
    if (node != 0) {
        this->inorderTreeWalk(&node->getLeft());
        std::cout<< node->getKey()<< "; ";
        this->inorderTreeWalk(&node->getRight());
    }
    
}

template<class VALUE>
Node<VALUE>* CommonTree<VALUE>::min(Node<VALUE>* node) {
    
    Node<VALUE>* last;
    Node<VALUE>* current = node;
    
    while (current != 0) {
        last = current;
        current = last->getLeft();
    }
    
    return last;
}

template<class VALUE>
Node<VALUE>* CommonTree<VALUE>::max(Node<VALUE>* node) {
    
    Node<VALUE>* last;
    Node<VALUE>* current = node;
    
    while (current != 0) {
        last = current;
        current = &last->getRight();
    }
    
    return last;
    
}
#endif

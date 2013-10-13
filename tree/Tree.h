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

class Tree {
    
private:
    
    Node* root;
    
    
public:
    
    Tree(int key, double data, Node* left = 0, Node* right = 0);
    Node* find(int key);
    void insert(int key, double data);
    void deleteElements(int key);
    void inorderTreeWalk(Node* node);
    Node* getRoot();
};


#endif /* defined(__tree__Tree__) */

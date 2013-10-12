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

class Node {
    
private:
    int key;
    double data;
    Node* leftChild;
    Node* rightChild;
    
    
public:
    
    Node(int key, double data, Node* left = 0, Node* right = 0);
    int getKey();
    double getData();
    
};

#endif /* defined(__tree__Node__) */

//
//  BTS.h
//  tree
//
//  Created by Nikita Galushko on 16.12.13.
//  Copyright (c) 2013 Nikita Galushko. All rights reserved.
//

#ifndef __tree__BTS__
#define __tree__BTS__

#include <iostream>
#include <vector>

#include "Tree.h"
#include "Node.h"

//template <class VALUE>

class BTS {
private:
    Tree<std::string>* tree;
    size_t numberOfVariables;
    size_t numberOfArray;
    size_t solve;
    size_t index;
    Node<std::string>* array;
    void setTree(size_t n, Node<std::string>** p);
    void initNodes();
public:
    BTS(size_t numberOfVariables);
    ~BTS();
    Tree<std::string>* getTree();
    size_t decision(int* arr);
};
#endif /* defined(__tree__BTS__) */

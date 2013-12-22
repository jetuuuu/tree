//
//  BTS.h
//  tree
//
//  Created by Nikita Galushko on 16.12.13.
//  Copyright (c) 2013 Nikita Galushko. All rights reserved.
//

#ifndef tree_BTS_h
#define tree_BTS_h

#include "Tree.h"
#include "Node.h"

template <class VALUE>

class BTS {
private:
    Tree<VALUE>* tree;
    size_t numbetOfVariables;
public:
    BTS(size_t numbetOfVariables);
    Tree<VALUE>* getTree();
    size_t solve();
};

template <class VALUE>
BTS<VALUE>::BTS(size_t numbetOfVariables) {
    this->numbetOfVariables = numbetOfVariables;
}

#endif

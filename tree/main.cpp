//
//  main.cpp
//  tree
//
//  Created by Nikita Galushko on 12.10.13.
//  Copyright (c) 2013 Nikita Galushko. All rights reserved.
//

#include <iostream>
#include "Node.h"
#include "Tree.h"

int main(int argc, const char * argv[])
{

    // insert code here...
    
    Tree* theTree = new Tree(50, 1.5);
    
    theTree->insert(25, 1.7);
    theTree->insert(15, 2);
    theTree->insert(46, 4);
    
    Node* node = theTree->find(25);
    std::cout<< "Left adress: "<< node->getLeft()<< std::endl;
    
    std::cout<< node->getInfo()<<std::endl;
 
    return 0;
    
}


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
    theTree->insert(60, 6);
    theTree->insert(54, 5.4);
    theTree->insert(71, 7);
    
    
    Node* node = theTree->find(25);
    std::cout<< "Left adress: "<< node->getKey()<< std::endl;
    
    theTree->inorderTreeWalk(theTree->getRoot());
 
    return 0;
    
}


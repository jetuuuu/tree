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
    
    Tree<double>* theTree = new Tree<double>(50, 1.5);
    
    theTree->insert(25, 1.7);
    theTree->insert(15, 2.0);
    theTree->insert(46, 4.0);
    theTree->insert(60, 6.0);
    theTree->insert(54, 5.4);
    theTree->insert(71, 7.0);
    theTree->insert(1, 0.0);
    
    Node<double>* node = theTree->find(25);
    std::cout<< "Left adress: "<< node->getData()<< std::endl;
    
    theTree->inorderTreeWalk(theTree->getRoot());
 
    Node<double>* min = theTree->max(theTree->getRoot());
    
    std::cout<< std::endl<<"Key: "<<min->getKey()<< std::endl;
    
    return 0;
    
}


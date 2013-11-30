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
#include "RBTree.h"
#include "RBNode.h"

int main(int argc, const char * argv[])
{

    // insert code here...
    
    RBTree<double>* theTree = new RBTree<double>(13, 1.5);
    
    theTree->insert(8, 1.7);
    theTree->insert(17, 2.0);
    theTree->insert(1, 4.0);
    theTree->insert(11, 6.0);
    theTree->insert(6, 5.4);
    theTree->insert(15, 7.0);
    theTree->insert(25, 0.0);
    theTree->insert(22, 0.0);
    //theTree->insert(27, 0.0);
    /*RBNode<double>* node = theTree->find(25);
    std::cout<< "Left adress: "<< node->getData()<< std::endl;*/
    
    theTree->inorderTreeWalk(theTree->getRoot());

    RBNode<double>* node = theTree->getRoot();
    
    //RBNode<double>* min = theTree->max(theTree->getRoot());
    
    std::cout<< std::endl<<"Key: "<<theTree->getRoot()->getRight()->getLeft()->getKey()<< std::endl;
    
    return 0;
    
}


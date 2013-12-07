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
    
    RBTree<double>* theTree = new RBTree<double>(50, 1.5);
    
    theTree->insert(25, 1.9);
    theTree->insert(75, 12);
    theTree->insert(12, 0.54);
    theTree->insert(37, 6.0);
    theTree->insert(31, 5.4);
    theTree->insert(43, 7.0);
    theTree->insert(28, 4.31);
    //theTree->insert(22, 18.45);

    //RBNode<double>* node = theTree->find(13);
    //std::cout<< "Left adress: "<< node->getData()<< std::endl;
    
    theTree->inorderTreeWalk((theTree->getRoot()));
    std::cout<< std::endl;
    std::cout<< std::endl;
    theTree->LSZ_Right(theTree->getRoot(), 0);
    
    //RBNode<double>* node = theTree->getRoot();
    //RBNode<double>* min = theTree->max(theTree->getRoot());
    std::cout<< std::endl;
    std::cout<< std::endl;
    std::cout<< std::endl<<"Key: "<<theTree->getRoot()->getRight()->getKey()<< std::endl;
    //std::cout<< std::endl<< "Find: " << node->getData() << std::endl;
    return 0;
    
}


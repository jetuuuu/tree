//
//  main.cpp
//  tree
//
//  Created by Nikita Galushko on 12.10.13.
//  Copyright (c) 2013 Nikita Galushko. All rights reserved.
//

#include <iostream>
#include <typeinfo>
#include <string>

#include "Node.h"
#include "Tree.h"
#include "RBTree.h"
#include "RBNode.h"

template <class VALUE>
void setTree(int n, Node<VALUE>* p, Node<VALUE>* array) {
    //static int len = 0;
    //if (p == 0)
        //return;
    int nl,nr;

    if (n == 0)
        p = NULL;
    else
    {
        nl = n/2;
        nr = n - nl - 1;
        p->setLeft(&array[nl]);
        VALUE temp;
        std::cout<<"Введите: " << std::endl;
        std::cin>>temp;
        array[nl].setData(temp);
        //length--;
        setTree<VALUE>(nl,p->getLeft(), array);
        p->setRight(&array[nr]);
        //setTree<VALUE>(nr,p->getRight(), array);
    }
    
}

int main(int argc, const char * argv[])
{

    // insert code here...
    
    RBTree<double>* theTree = new RBTree<double>(50, 1.5);
    
    theTree->insert(25, 1.9);
    theTree->insert(75, 12);
    theTree->insert(12, 0.54);
    theTree->insert(37, 6.0);
    theTree->insert(6, 5.4);
    theTree->insert(18, 7.0);
    theTree->insert(3, 4.31);
    //theTree->insert(90, 18.45);
    
    std::cout<< std::endl<<"Key: "<<theTree->getRoot()->getRight()->getKey()<< std::endl;
    //theTree->inorderTreeWalk((theTree->getRoot()));
    std::cout<< std::endl;
    std::cout<< std::endl;
    theTree->printTree((Node<double>*)theTree->getRoot());
    //std::cout<< theTree->bracketPrint((Node<double>*)theTree->getRoot()) <<std::endl;
    std::cout<< *theTree <<std::endl;
    std::cout<< "--------------------------" <<std::endl;
    std::cout<< std::endl;
    std::cout<< std::endl;
    
    Tree<std::string>* tree = new Tree<std::string>(50, "x1");//insert root x (x1)
    
    int numX = 5;
    int numArr = 1;
    for (int i = 0 ; i < numX - 1; i++) {
        numArr = (numArr * 2) + 1;
    }
    
    --numArr;
    
    Node<std::string>* array = new Node<std::string>[numArr];
    
    for (int i = 0; i < numArr; i++) {
        if (i == 0 || i == 1)
            array[i] = *new Node<std::string>(i, "x2");
        else if (i != numArr - 1 || i != numArr - 2)
            array[i] = *new Node<std::string>(i, "x3");
    }
    
    //setTree<std::string>(7, tree->getRoot(), array);
    
    //tree->getRoot()->setLeft();
    tree->insert(25, "x1");
    tree->insert(75, "x2");
    tree->insert(24, "x2");
    tree->insert(76, "x2");
    
    tree->printTree(tree->getRoot());
    std::cout<< *tree <<std::endl;
    return 0;
    
}


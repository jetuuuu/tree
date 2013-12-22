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
#include "BTS.h"

int main(int argc, const char * argv[])
{

    // insert code here...
    
    /*RBTree<double>* theTree = new RBTree<double>(50, 1.5);
    
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
    theTree->printTree((Node<double>*)theTree->getRoot(), true);
    //std::cout<< theTree->bracketPrint((Node<double>*)theTree->getRoot()) <<std::endl;
    std::cout<< *theTree <<std::endl;
    std::cout<< "--------------------------" <<std::endl;
    std::cout<< std::endl;
    std::cout<< std::endl;*/
    
    BTS *bts = new BTS(7);
    int* arr = new int[3];
    int x;
    std::cout<< "Если соперник находится выше по турнирной таблицы, то введите 1, иначе 0\n";
    std::cin>> x;
    arr[0] = x;
    std::cout<< "Если ваша любимая команда играет у себя дома, то введите 1, иначе 0\n";
    std::cin>> x;
    arr[1] = x;
    std::cout<< "Если в день матча будет идти дождь, то введите 1, иначе 0\n";
    std::cin>> x;
    arr[2] = x;
    size_t s = bts->decision(arr);
    if (s == 1)
        std::cout<< "С большой долей вероятности, ваша команда выйграет\n";
    else
        std::cout<< "Я бы на вашем месте не стал бы делать ставки на этот матч. Ваша команда с большой долей вероятности проиграет\n";
    Tree<std::string>* tree1 = bts->getTree();
    //tree1->printTree(tree1->getRoot(), false);
    
    return 0;
    
}


//
//  BTS.cpp
//  tree
//
//  Created by Nikita Galushko on 16.12.13.
//  Copyright (c) 2013 Nikita Galushko. All rights reserved.
//

#include "BTS.h"
#include <sstream>
#include <iostream>

BTS::BTS(size_t numberOfVariables) {
    this->numberOfVariables = numberOfVariables;
    this->index = 0;
    this->tree = new Tree<std::string>();
    
    this->array = new Node<std::string>[this->numberOfVariables];
}

Tree<std::string>* BTS::getTree() {
    return tree;
}

void BTS::initNodes() {
    for (int i = 0; i < this->numberOfVariables; i++) {
        if (i == 0)
            this->array[i] = *new Node<std::string>(i, "rival");
        else if (i > 1 && i < 3)
            this->array[i] = *new Node<std::string>(i, "place");
        else
            this->array[i] = *new Node<std::string>(i, " rain");
    }
}

size_t BTS::decision(int* arr) {
    this->setTree(this->numberOfVariables, tree->getPointerRoot());
    Node<std::string>* node = this->tree->getRoot();
    
    Node<std::string>* _solve = new Node<std::string>(30, "  no ");
    Node<std::string>* __solve = new Node<std::string>(40, " yes ");
    
    this->tree->getRoot()->getLeft()->getLeft()->setLeft(_solve);
    this->tree->getRoot()->getLeft()->getLeft()->setRight(_solve);
    
    this->tree->getRoot()->getLeft()->getRight()->setLeft(__solve);
    this->tree->getRoot()->getLeft()->getRight()->setRight(__solve);
    
    node->getRight()->getLeft()->setLeft(_solve);
    node->getRight()->getLeft()->setRight(_solve);
    
    node->getRight()->getRight()->setRight(_solve);
    node->getRight()->getRight()->setLeft(__solve);
    
    //this->tree->getRoot()->getLeft()->getLeft()->getLeft()->setData("  no ");
    
    for (int i = 0; i < 3; i++) {
        if (arr[i] == 0) {
            node = node->getLeft();
            this->solve = 0;
        }
        else if (arr[i] == 1) {
            node = node->getRight();
            this->solve = 1;
        }
    }
    
    if (node->getData() == " yes ")
        this->solve = 1;
    else
        this->solve = 0;
    
    return solve;
}

void BTS::setTree(size_t n, Node<std::string> **p) {
    size_t nl,nr;
    Node<std::string>* now;
    
    if (n == 0)
        p = NULL;
    else
    {
        nl = n/2;
        nr = n - nl - 1;
        //std::cin>> x;
        ++this->index;
        std::string str = "";
        if (this->index == 1)
            str = "rival";
        else if (this->index == 2 || this->index == 5)
            str = "place";
        else
            str = " rain";
        now = new Node<std::string>(this->index, str);
        setTree(nl, now->getPointerLeft());
        setTree(nr, now->getPointerRight());
        *p = now;
    }
}

BTS::~BTS() {
    delete tree;
    delete[] array;
}
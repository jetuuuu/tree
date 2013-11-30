//
//  RBTree.h
//  tree
//
//  Created by Nikita Galushko on 29.11.13.
//  Copyright (c) 2013 Nikita Galushko. All rights reserved.
//

#ifndef tree_RBTree_h
#define tree_RBTree_h

#include "RBNode.h"
#include "CommonTree.h"

template <class VALUE>
class RBTree {
private:
    RBNode<VALUE>* root;
    void rotateLeft(RBNode<VALUE>* node);
    void rotateRight(RBNode<VALUE>* node);
    void fixInsert(RBNode<VALUE>* node);
    bool externalSon(RBNode<VALUE>* node);
    bool internalSon(RBNode<VALUE>* node);
public:
    void insert(int key, VALUE data);
    RBTree(int key, VALUE data, RBNode<VALUE>* left = 0, RBNode<VALUE>* right = 0);
    RBNode<VALUE>* getRoot();
    void inorderTreeWalk(RBNode<VALUE>* node);
    void setRoot(RBNode<VALUE>* rot);
};

template<class VALUE>
RBTree<VALUE>::RBTree(int key, VALUE data, RBNode<VALUE>* left, RBNode<VALUE>* right) {
    RBNode<VALUE>* root = new RBNode<VALUE>(key, data, left, right, 0, BLACK);
    this->root = root;
}

template <class VALUE>
RBNode<VALUE>* RBTree<VALUE>::getRoot() {
    return this->root;
}

template <class VALUE>
void RBTree<VALUE>::setRoot(RBNode<VALUE>* rot) {
    this->root = rot;
}

template <class VALUE>
void RBTree<VALUE>::rotateLeft(RBNode<VALUE>* node) {
    
    RBNode<VALUE>* temp = node->getRight();
    //(RBNode<VALUE>)*node->getRight() = (RBNode<VALUE>)temp->getLeft();
    node->setRight(temp->getLeft());
    
    if (temp->getLeft()) {
        temp->getLeft()->setParent(node);
    }
    
    if (temp != 0) {
        temp->setParent(node->getParent());
    }
    
    if (node->getParent() != 0) {
        if (node == node->getParent()->getLeft()) {
            node->getParent()->setLeft(temp);
        }
        else {
            node->getParent()->setRight(temp);
        }
    }
    else {
        this->setRoot(temp);
    }
    
    temp->setLeft(node);
    
    if (node != 0) {
        node->setParent(temp);
    }
            std::cout<< "ROTATE LEFT" << std::endl;
}

template <class VALUE>
void RBTree<VALUE>::rotateRight(RBNode<VALUE>* node) {
    
    RBNode<VALUE>* temp = node->getLeft();
    node->setLeft(temp->getRight());

    if (temp->getRight() != 0) {
        temp->getRight()->setParent(node);
    }

    if (temp != 0) {
        temp->setParent(node->getParent());
    }
    
    if (node->getParent() != 0) {
        if (node == node->getParent()->getRight()) {
            node->getParent()->setRight(temp);
        }
        else {
            node->getParent()->setLeft(temp);
        }
    } else {
         this->setRoot(temp);
    }
    
    temp->setRight(node);
    
    if (node != 0) {
        node->setParent(temp);
    }
    
        std::cout<< "ROTATE RIGHT" << std::endl;
}

template <class VALUE>
bool RBTree<VALUE>::externalSon(RBNode<VALUE> *node) {
    if ((node->getParent()->getLeft() != 0) && (node->getParent()->getParent()->getLeft() != 0)) {
        return ((node->getKey() == node->getParent()->getLeft()->getKey()) && (node->getParent()->getKey() == node->getParent()->getParent()->getLeft()->getKey()));
            //return true;
    }
    else if ((node->getParent()->getRight() != 0) && node->getParent()->getParent()->getRight() != 0) {
        return ((node->getKey() == node->getParent()->getRight()->getKey()) && (node->getParent()->getKey() == node->getParent()->getParent()->getRight()->getKey()));
        //return true;
    }
    else
        return false;
}

template <class VALUE>
bool RBTree<VALUE>::internalSon(RBNode<VALUE>* node) {
    if (node->getParent()->getRight() != 0 && node->getParent()->getParent()->getLeft() != 0)
        return ((node->getKey() == node->getParent()->getRight()->getKey()) && (node->getParent()->getParent()->getLeft()->getKey() == node->getParent()->getKey())); //{
        //return true;
    //}
    else if ((node->getParent()->getLeft() != 0) && (node->getParent()->getParent()->getRight() != 0))
    return ((node->getKey() == node->getParent()->getLeft()->getKey()) && (node->getParent()->getParent()->getRight()->getKey() == node->getParent()->getKey()));
        //return true;
    else
        return false;
}

template <class VALUE>
void RBTree<VALUE>::insert(int key, VALUE data) {
    
    RBNode<VALUE> *newNode = new RBNode<VALUE>(key, data);
    
    if (this->root == 0)
        this->root = newNode;
    else {
        RBNode<VALUE>* current = this->root;
        RBNode<VALUE>* parent;
        
        while (true) {
            parent = current;
            newNode->setParent(parent);
            if (key < current->getKey()) {
                
                current = (current->getLeft());
                if (current == 0) {
                    parent->setLeft(newNode);
                    break;
                }
                else if (current->getParent()->getRight() != 0) {
                    if ((current->getColor() == RED) && (current->getParent()->getRight()->getColor() == RED)) {
                        current->changeColor();
                        current->getParent()->getRight()->changeColor();
                        if (current->getParent()->getKey() != this->getRoot()->getKey())
                            current->getParent()->changeColor();
                    }
                }
                
            }
            else {
                current = (current->getRight());
                if (current == 0) {
                    parent->setRight(newNode);
                    break;
                }
                else if (current->getParent()->getLeft() != 0) {
                    if ((current->getColor() == RED) && (current->getParent()->getLeft()->getColor() == RED)) {
                        current->changeColor();
                        current->getParent()->getLeft()->changeColor();
                        if (current->getParent()->getKey() != this->getRoot()->getKey())
                            current->getParent()->changeColor();
                    }
                }
            }
        }
    }
    this->fixInsert(newNode);
}

template <class VALUE>

void RBTree<VALUE>::fixInsert(RBNode<VALUE> *node) {
    //perent is black
    //std::cout<<"insert\n";
    if (node->getParent()->getColor() == BLACK) {
        return;
    }
    else if ((node->getParent()->getColor() == RED) && (this->externalSon(node))){
        node->getParent()->getParent()->changeColor();
        node->getParent()->changeColor();
        if (node->getParent()->getKey() == node->getParent()->getParent()->getLeft()->getKey()) {
                rotateRight(node->getParent()->getParent());
            //std::cout<<"This1: " << node->getKey()<<std::endl;
        }
        else {
            rotateLeft(node->getParent()->getParent());
                        //std::cout<<"This2: " << node->getKey()<<std::endl;
        }
    }
    else if ((node->getParent()->getColor() == RED) && (this->internalSon(node))) {
        node->getParent()->getParent()->changeColor();
        node->changeColor();
                    std::cout<<"OR This: " << node->getKey()<<std::endl;
        if ((node->getParent()->getRight() != 0) && (node->getKey() == node->getParent()->getRight()->getKey()))
            rotateLeft(node->getParent());
        else
            rotateRight(node->getParent());
        if (node->getKey() == node->getParent()->getLeft()->getKey())
            rotateRight(node->getParent());
        else
            rotateLeft(node->getParent());
    }
}

template<class VALUE>
void RBTree<VALUE>::inorderTreeWalk(RBNode<VALUE>* node) {
    
    if (node != 0) {
        this->inorderTreeWalk((node->getLeft()));
        if (node->getColor() == RED)
            std::cout<< node->getKey()<< "(RED)" <<"; ";
        else
            std::cout<< node->getKey()<< "(BLACK)" <<"; ";
        this->inorderTreeWalk((node->getRight()));
    }
    
}
#endif

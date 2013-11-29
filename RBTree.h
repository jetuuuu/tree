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
public:
    void insert(int key, VALUE data);
    RBTree(int key, VALUE data, RBNode<VALUE>* left = 0, RBNode<VALUE>* right = 0);
    RBNode<VALUE>* getRoot();
    void inorderTreeWalk(RBNode<VALUE>* node);
};

template<class VALUE>
RBTree<VALUE>::RBTree(int key, VALUE data, RBNode<VALUE>* left, RBNode<VALUE>* right) {
    RBNode<VALUE>* root = new RBNode<VALUE>(key, data, left, right);
    this->root = root;
}

template <class VALUE>
RBNode<VALUE>* RBTree<VALUE>::getRoot() {
    return this->root;
}

template <class VALUE>
void RBTree<VALUE>::rotateLeft(RBNode<VALUE>* node) {
    
    RBNode<VALUE>* temp = &(RBNode<VALUE>&)node->getRight();
    (RBNode<VALUE>)node->getRight() = (RBNode<VALUE>)temp->getLeft();
    
    if (temp->getLeft()) {
        (RBNode<VALUE>)temp->getLeft()->getParent() = node;
    }
    
    if (temp != 0) {
        (RBTree<VALUE>)temp->getParent() = (RBTree<VALUE>)node->getParent();
    }
    
    if (node->getParent() != 0) {
        if (node == node->getParent()->getLeft()) {
            node->getParent()->getLeft() = temp;
        }
        else {
            node->getParent()->getRight() = temp;
        }
    }
    else {
        this->getRoot() = temp;
    }
    
    temp->getLeft() = node;
    
    if (node != 0) {
        node->getParent() = temp;
    }
            std::cout<< "ROTATE LEFT" << std::endl;
}

template <class VALUE>
void RBTree<VALUE>::rotateRight(RBNode<VALUE>* node) {
    
    RBNode<VALUE>* temp = (RBNode<VALUE>)node->getLeft();
    (RBNode<VALUE>)node->getLeft() = (RBNode<VALUE>)temp->getRight();

    if (temp->getRight() != 0) {
        (RBNode<VALUE>)temp->getRight()->getParent() = node;
    }

    if (temp != 0) {
        temp->getParent() = node->getParent();
    }
    
    if (node->getParent() != 0) {
        if (node == node->getParent()->getRight()) {
            node->getParent()->getRight() = temp;
        }
        else {
            node->getPparent()->getLeft() = temp;
        }
    } else {
         this->getRoot() = temp;
    }
    
    temp->getRight() = node;
    
    if (node != 0) {
        node->getParent() = temp;
    }
    
        std::cout<< "ROTATE RIGHT" << std::endl;
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
                
                current = &static_cast<RBNode<VALUE>&>(current->getLeft());
                if (current == 0) {
                    parent->setLeft(newNode);
                    return;
                }
                
            }
            else {
                current = &static_cast<RBNode<VALUE>&>(current->getRight());
                if (current == 0) {
                    parent->setRight(newNode);
                    return;
                }
            }
        }
    }
    fixInsert(newNode);
}

template <class VALUE>

void RBTree<VALUE>::fixInsert(RBNode<VALUE> *node) {
    
    /*************************************
     *  maintain Red-Black tree balance  *
     *  after inserting node x           *
     *************************************/
    
    /* check Red-Black properties */
    while (node != this->root && node->getParent().getColor() == RED) {
        /* we have a violation */
        if (node->getParent().getKey() == node->getParent().getParent().getLeft().getKey()) {
            RBNode<VALUE> *y = &node->getParent().getParent().getRight();
            if (y->getColor() == RED) {
                
                /* uncle is RED */
                node->getParent().setColor(BLACK);
                y->setColor(BLACK);
                node->getParent().getParent().setColor(RED);
                node = &node->getParent().getParent();
            } else {
                
                /* uncle is BLACK */
                if (node->getKey() == node->getParent().getRight().getKey()) {
                    /* make x a left child */
                    node = &node->getParent();
                    rotateLeft(node);
                }
                
                /* recolor and rotate */
                node->getParent().setColor(BLACK);
                node->getParent().getParent().setColor(RED);
                rotateRight(&node->getParent().getParent());
            }
        } else {
            
            /* mirror image of above code */
            RBNode<VALUE> *y = &node->getParent().getParent().getLeft();
            if (y->getColor() == RED) {
                
                /* uncle is RED */
                node->getParent().setColor(BLACK);
                y->setColor(BLACK);
                node->getParent().getParent().setColor(RED);
                node = &node->getParent().getParent();
            } else {
                
                /* uncle is BLACK */
                if (node->getKey() == node->getParent().getLeft().getKey()) {
                    node = &node->getParent();
                    rotateRight(node);
                }
                node->getParent().setColor(BLACK);
                node->getParent().getParent().setColor(RED);
                rotateLeft(&node->getParent().getParent());
            }
        }
    }
    root->setColor(BLACK);
    std::cout<< "FIX INSERT" << std::endl;
}

template<class VALUE>
void RBTree<VALUE>::inorderTreeWalk(RBNode<VALUE>* node) {
    
    if (node != 0) {
        this->inorderTreeWalk(&static_cast<RBNode<VALUE>&>(node->getLeft()));
        std::cout<< node->getKey()<< " ("<< node->getColor()<< ")" <<"; ";
        this->inorderTreeWalk(&static_cast<RBNode<VALUE>&>(node->getRight()));
    }
    
}
#endif

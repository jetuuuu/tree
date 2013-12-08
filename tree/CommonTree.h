//
//  CommonTree.h
//  tree
//
//  Created by Nikita Galushko on 29.11.13.
//  Copyright (c) 2013 Nikita Galushko. All rights reserved.
//

#ifndef tree_CommonTree_h
#define tree_CommonTree_h

#include <string>
#include <sstream>

#include "Node.h"

template <class VALUE>

class CommonTree {
public:
    virtual void inorderTreeWalk(Node<VALUE>* node);
    virtual Node<VALUE>* max(Node<VALUE>* node);
    virtual Node<VALUE>* min(Node<VALUE>* node);
    void printTree(Node<VALUE>* tree);
    std::string bracketPrint(Node<VALUE>* node);
private:
    std::string tree;
    void traversal(Node<VALUE>* node);
    int _print_t(Node<VALUE>* tree, int is_left, int offset, int depth, char s[20][255]);
protected:
    virtual Node<VALUE>* find(int key, Node<VALUE>* node);
};

template <class VALUE>
int CommonTree<VALUE>::_print_t(Node<VALUE>* tree, int is_left, int offset, int depth, char s[20][255])
{
    char b[20];
    int width = 5;
    
    if (!tree) return 0;
    
    sprintf(b, "(%03d)", tree->getKey());
    
    int left  = _print_t(tree->getLeft(),  1, offset, depth + 1, s);
    int right = _print_t(tree->getRight(), 0, offset + left + width, depth + 1, s);
    
    for (int i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];
    
    if (depth && is_left) {
        
        for (int i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width/2 + i] = '-';
        
        s[depth - 1][offset + left + width/2] = '.';
        
    } else if (depth && !is_left) {
        
        for (int i = 0; i < left + width; i++)
            s[depth - 1][offset - width/2 + i] = '-';
        
        s[depth - 1][offset + left + width/2] = '.';
    }
    
    return left + width + right;
}

template <class VALUE>
void CommonTree<VALUE>::printTree(Node<VALUE>* tree)
{
    char s[20][255];
    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");
    
    _print_t(tree, 0, 0, 0, s);
    
    for (int i = 0; i < 10; i++)
        printf("%s\n", s[i]);
}

template<class VALUE>
void CommonTree<VALUE>::inorderTreeWalk(Node<VALUE>* node) {
    if (node != 0) {
        this->inorderTreeWalk(node->getLeft());
        std::cout<< node->getKey()<< "; ";
        this->inorderTreeWalk(node->getRight());
    }
    
}

template<class VALUE>
Node<VALUE>* CommonTree<VALUE>::min(Node<VALUE>* node) {
    
    Node<VALUE>* last;
    Node<VALUE>* current = node;
    
    while (current != 0) {
        last = current;
        current = last->getLeft();
    }
    
    return last;
}

template<class VALUE>
Node<VALUE>* CommonTree<VALUE>::max(Node<VALUE>* node) {
    
    Node<VALUE>* last;
    Node<VALUE>* current = node;
    
    while (current != 0) {
        last = current;
        current = last->getRight();
    }
    
    return last;
    
}

template <class VALUE>
void CommonTree<VALUE>::traversal(Node<VALUE> *node) {
    
    std::stringstream ss;
    ss<<node->getKey();
    std::string temp = "";
    ss>>temp;
    this->tree += "(";
    this->tree += temp;
    
    if (node->getLeft() != 0)
        this->traversal(node->getLeft());
    if (node->getRight() != 0)
        this->traversal(node->getRight());

    this->tree += ')';
}

template <class VALUE>
std::string CommonTree<VALUE>::bracketPrint(Node<VALUE>* node) {
    this->traversal(node);
    return tree;
}

template <class VALUE>
Node<VALUE>* CommonTree<VALUE>::find(int key, Node<VALUE> *current) {
    
    while (current->getKey() != key) {
        
        if (key < current->getKey())
            current = current->getLeft();
        else
            current = current->getRight();
        
        if (current == 0)
            return 0;
    }
    
    return current;
}
#endif
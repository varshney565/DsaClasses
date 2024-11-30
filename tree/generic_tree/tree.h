#pragma once
#include"node.h"
class Tree {
    public : 
    Node* root;

    virtual void insertNode(int data) = 0;

    virtual bool searchNode(int data) = 0;

    virtual void deleteNode(int data) = 0;

    virtual int height() = 0;
};
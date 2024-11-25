#pragma once
#include"node.h"
class Tree {
    public : 
    Node* root;

    virtual void insertNode(int data) = 0;

    virtual bool searchNode(Node* root, int data) = 0;

    virtual Node* deleteNode(Node* root,int data) = 0;

    virtual int height() = 0;
};
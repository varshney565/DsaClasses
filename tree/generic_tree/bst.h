#pragma once
#include"node.h"
#include"tree.h"
class BST : public Tree {

    private : 
    Node* insertHelper(Node* root,int data) {
        //base case
        if(root == nullptr) {
            Node* newNode = new Node(data);
            return newNode;
        }

        if(data >= root->data) {
            root->right = insertHelper(root->right,data);
        }else {
            root->left = insertHelper(root->left,data);
        }

        return root;
    }

    public:
    void insertNode(int data) override {
        this->root = insertHelper(this->root,data);
    }

    bool searchNode(Node* root,int data) override {

    }

    Node* deleteNode(Node* root,int data) override {

    }

    int height() {

    }

    void inorder(Node* root) {
        if(root == nullptr) {
            return;
        }
        
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};
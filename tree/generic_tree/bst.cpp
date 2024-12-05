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

    bool searchNode(Node* root,int data) {
        if(root == nullptr) {
            return false;
        }
        if(root->data == data) {
            return true;
        }
        if(data > root->data) return searchNode(root->right,data);
        else return searchNode(root->left,data);
    }

    Node* getSuccesor(Node* root) {
        Node* T = root->right;
        while(T != nullptr && T->left != nullptr) {
            T = T->left;
        }
        return T;
    }

    Node* deleteNode(Node* root,int data) {
        if(root == nullptr) return nullptr;

        if(root->data == data) {
            //first case root is a leaf node
            if(root->left == nullptr && root->right == nullptr) {
                delete(root);
                return nullptr;
            }else if(root->left == nullptr) {
                Node* temp = root->right;
                root->right = nullptr;
                delete(root);
                return temp;
            }else if(root->right == nullptr) {
                Node* temp = root->left;
                root->left = nullptr;
                delete(root);
                return temp;
            }else {
                Node* temp = getSuccesor(root);
                root->data = temp->data;
                root->right = deleteNode(root->right,root->data);
                return root;
            }
        }
        if(root->data > data) root->left = deleteNode(root->left,data);
        else root->right = deleteNode(root->right,data);
        return root;
    }

    int height(Node* root) {
        if(root == nullptr) return 0;
        int ans1 = height(root->left);
        int ans2 = height(root->right);
        if(ans1 > ans2) {
            return ans1 + 1;
        }else {
            return ans2 + 1;
        }
    }
    public:
    void insertNode(int data) override {
        this->root = insertHelper(this->root,data);
    }

    bool searchNode(int data) override {
        return searchNode(root,data);
    }

    void deleteNode(int data) override {
        root = deleteNode(root,data);
    }

    int height() {
        return height(root);
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
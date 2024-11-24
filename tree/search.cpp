#include<bits/stdc++.h>
#include"Node.h"
using namespace std;
bool search(int data,Node* root) {
    //base case
    if(root == nullptr) {
        return false;
    }
    
    bool leftAns = search(data,root->left);
    bool rightAns = search(data,root->right);
    if(leftAns == true || rightAns == true) return true;
    if(root->data == data) return true;
    return false;
}

bool search_bst(int data,Node* root) {
    //base case
    if(root == nullptr) {
        return false;
    }
    if(root->data == data) return true;
    if(root->data < data) return search(data,root->left);
    else return search(data,root->right);
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->right->left = new Node(4);
    root->right->left->left = new Node(5);
    root->left->left = new Node(10);
    root->right->right = new Node(6);

    bool status = search(11,root);
    cout<<status<<"\n";
}
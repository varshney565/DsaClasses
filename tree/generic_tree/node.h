#pragma once
class Node {
    public :
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
    }

    ~Node() {
        delete this;
    }
};
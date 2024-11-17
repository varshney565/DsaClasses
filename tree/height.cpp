#include<iostream>
using namespace std;

class Node {
    public : 
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }

    ~Node() {
        delete this->left;
        delete this->right;
    }
};

int height(Node *root) {
    //Edge Case
    if(root == nullptr) {
        return 0;
    }
    //Base Case
    if(root->right == nullptr && root->left == nullptr) {
        return 1;
    }

    //Recursive call
    int leftH = height(root->left);
    int rightH = height(root->right);

    //Root handle
    return 1 + max(leftH,rightH);
}

int sumBT(Node* root) {
    //base case
    if(root == nullptr) {
        return 0;
    }
    
    //recursive call
    int rightSum = sumBT(root->right);
    int leftSum = sumBT(root->left);
    
    int ans = rightSum + leftSum + root->data;
    return ans;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->right->left = new Node(4);
    root->right->left->left = new Node(5);
    int ans = height(root);
    cout<<"Height : "<<ans<<"\n";
}
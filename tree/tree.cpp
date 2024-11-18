#include<iostream>
#include<math.h>
using namespace std;
#include"Node.h"
#include"levelorder.h"

int height(Node*);

bool balanced(Node* root) {
    //Base Case
    if(root == nullptr) {
        return true;
    }

    bool leftAns = balanced(root->left);
    bool rightAns = balanced(root->right);

    //root calculations
    if(leftAns == false || rightAns == false) {
        return false;
    }

    int lh = height(root->left);
    int rh = height(root->right);
    return abs(lh-rh) <= 1;
}


pair<bool,int> balanced_improved(Node* root) {
    //Base Case
    if(root == nullptr) {
        return {true,0};
    }

    pair<bool,int> leftAns = balanced_improved(root->left);
    pair<bool,int> rightAns = balanced_improved(root->right);

    //root calculations
    if(leftAns.first == false || rightAns.first == false) {
        return {false,1 + max(leftAns.second,rightAns.second)};
    }


    int lh = leftAns.second;
    int rh = rightAns.second;
    bool status = abs(lh-rh) <= 1;
    int height = 1 + max(lh,rh);
    return {status,height};
}


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
    root->left->left = new Node(10);
    root->right->right = new Node(6);
    // int ans = height(root);
    // cout<<"Height : "<<ans<<"\n";
    pair<bool,int> ans = balanced_improved(root);
    cout<<"Height : "<<ans.second<<endl;
    cout<<"Status : "<<ans.first<<endl;
    levelOrder(root);

}
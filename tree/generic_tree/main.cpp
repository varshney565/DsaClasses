#include<bits/stdc++.h>
using namespace std;

#include"bst.h"

int main() {
    BST *tree1 = new BST();
    tree1->insertNode(15);

    tree1->insertNode(7);

    tree1->insertNode(2);

    tree1->insertNode(10);
    tree1->insertNode(20);
    tree1->insertNode(19);
    tree1->insertNode(16);
    tree1->insertNode(18);
    
    tree1->inorder(tree1->root);
    tree1->deleteNode(19);
    cout<<"\nTree After Deleting 19\n";
    tree1->inorder(tree1->root);
}
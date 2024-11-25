#include<bits/stdc++.h>
using namespace std;

#include"bst.h"

int main() {
    BST *tree1 = new BST();
    tree1->insertNode(2);

    tree1->insertNode(15);

    tree1->insertNode(10);

    tree1->insertNode(5);
    tree1->insertNode(9);
    
    tree1->inorder(tree1->root);

}
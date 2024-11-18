#include<queue>
void levelOrder(Node* root) {
    if(root == nullptr) return;
    queue<Node*> currentLevel,nextLevel;
    currentLevel.push(root);
    int level = 0;
    while(true) {
        while(currentLevel.empty() == false) {
            Node* frontNode = currentLevel.front();
            currentLevel.pop();
            cout<<frontNode->data<<" ";
            if(frontNode->left != nullptr) {
                nextLevel.push(frontNode->left);
            }
            if(frontNode->right != nullptr) {
                nextLevel.push(frontNode->right);
            }
        }
        //
        cout<<"\n";
        if(nextLevel.empty() == true) {
            break;
        }
        swap(currentLevel,nextLevel);
        level++;
    }
}
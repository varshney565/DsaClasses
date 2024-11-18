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
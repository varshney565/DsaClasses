class Node {
    public : 
        int data;
        Node* next;

    Node(int data) {
        this->data = data;
    }

    ~Node() {
        delete this->next;
    }
};
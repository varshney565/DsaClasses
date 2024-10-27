class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
    ~Node() {
        delete this->next;
    }
};

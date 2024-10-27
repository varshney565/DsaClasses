class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int length;

    void removeInternal(Node* node) {
        if (node == head) {
            head = head->next;
            if (head) head->prev = nullptr;
        } else if (node == tail) {
            tail = tail->prev;
            if (tail) tail->next = nullptr;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        node->next = nullptr;
        node->prev = nullptr;
        delete node;
        length--;
    }

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr), length(0) {}

    // Copy Constructor
    DoublyLinkedList(const DoublyLinkedList& other) : head(nullptr), tail(nullptr), length(0) {
        Node* current = other.head;
        while (current) {
            insert(current->data);
            current = current->next;
        }
    }

    // Move Constructor
    DoublyLinkedList(DoublyLinkedList&& other) noexcept : head(other.head), tail(other.tail), length(other.length) {
        other.head = nullptr;
        other.tail = nullptr;
        other.length = 0;
    }

    // Copy Assignment Operator
    DoublyLinkedList& operator=(const DoublyLinkedList& other) {
        if (this == &other) return *this;
        clear();
        Node* current = other.head;
        while (current) {
            insert(current->data);
            current = current->next;
        }
        return *this;
    }

    // Move Assignment Operator
    DoublyLinkedList& operator=(DoublyLinkedList&& other) noexcept {
        if (this == &other) return *this;
        clear();
        head = other.head;
        tail = other.tail;
        length = other.length;
        other.head = nullptr;
        other.tail = nullptr;
        other.length = 0;
        return *this;
    }

    // Destructor
    ~DoublyLinkedList() {
        clear();
    }

    // Insert in sorted order
    bool insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else if (value <= head->data) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else if (value >= tail->data) {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        } else {
            Node* current = head;
            while (current && current->data < value) {
                current = current->next;
            }
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
        }
        length++;
        return true;
    }

    // Remove a node by value
    bool remove(int value) {
        Node* current = head;
        while (current && current->data != value) {
            current = current->next;
        }
        if (!current) return false;
        removeInternal(current);
        return true;
    }

    // Access elements by index (0-based)
    int operator[](int index) const {
        if (index < 0 || index >= length) return -1;
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    // Stream operator to print list contents
    friend ostream& operator<<(ostream& os, const DoublyLinkedList& list) {
        Node* current = list.head;
        while (current) {
            os << current->data << " ";
            current = current->next;
        }
        return os;
    }

    // Get size of the list
    int size() const {
        return length;
    }

    // Check if the list is empty
    bool empty() const {
        return length == 0;
    }

    // Clear the list
    void clear() {
        delete head;
        head = tail = nullptr;
        length = 0;
    }

    // Comparison operators
    bool operator==(const DoublyLinkedList& other) const {
        if (length != other.length) return false;
        Node* current = head;
        Node* otherCurrent = other.head;
        while (current && otherCurrent) {
            if (current->data != otherCurrent->data) return false;
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
        return true;
    }

    bool operator!=(const DoublyLinkedList& other) const {
        return !(*this == other);
    }

    // Merge two sorted lists
    DoublyLinkedList operator+(const DoublyLinkedList& other) const {
        DoublyLinkedList result;
        Node* thisCurrent = head;
        Node* otherCurrent = other.head;

        while (thisCurrent && otherCurrent) {
            if (thisCurrent->data <= otherCurrent->data) {
                result.insert(thisCurrent->data);
                thisCurrent = thisCurrent->next;
            } else {
                result.insert(otherCurrent->data);
                otherCurrent = otherCurrent->next;
            }
        }

        while (thisCurrent) {
            result.insert(thisCurrent->data);
            thisCurrent = thisCurrent->next;
        }

        while (otherCurrent) {
            result.insert(otherCurrent->data);
            otherCurrent = otherCurrent->next;
        }

        return result;
    }
};
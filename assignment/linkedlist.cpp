#include"Ilist.cpp"
#include<bits/stdc++.h>
using namespace std;
class Node {
    public : 
    int data;
    Node* next;

    Node(int data ) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList : public IList { 
    public:
    Node* head;
    int length;

    LinkedList() {
        head = NULL;
        length = 0;
    }

    int getCurrentSize() const {
        return this->length;
    }

    bool isEmpty() const {
        return this->length == 0;
    }

    bool add(int newEntry) {
        if(head == NULL) {
            head = new Node(newEntry);
            length++;
            return true;
        }
        Node* curr = head;
        while(curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = new Node(newEntry);
        length++;
        return true;
    }


    bool remove(int anEntry) {
        if(head == nullptr) return false;
        Node* curr = head;
        Node* prev = nullptr;
        while(curr != nullptr && curr->data != anEntry) {
            prev = curr;
            curr = curr->next;
        }
        if(curr == nullptr) {
            return false;   
        }
        //curr is not null
        if(prev == nullptr) {
            Node* temp = head;
            head = curr->next;
            temp->next = nullptr;
            delete temp;
            length--;
            return true;
        }

        Node* temp = curr->next;
        prev->next = temp;
        curr->next = nullptr;
        delete curr;
        length--;
        return true;
    }

    void clear() {
        delete head;
        head = nullptr;
        length = 0;
    }

    bool contains(int anEntry) {
        int cnt = 0;
        Node* curr = head;
        while(curr->data != anEntry) {
            curr = curr->next;
            cnt++;
        }
        if(curr != nullptr) {
            traverseCount = cnt;
            return true;
        } 
        return false;
    }

    int getTraverseCount() const override { return traverseCount; }

    void resetTraverseCount() override { traverseCount = 0; }

    ~LinkedList() {
        clear();
    }

    void print() {
        Node* curr = head;
        while(curr != nullptr) {
            cout<<curr->data<<" --> ";
            curr = curr->next;
        }
    }    
};


// int main() {
//     LinkedList *list = new LinkedList();
//     int value;
//     while(cin >> value) {
//         list->add(value);
//     }

//     list->print();
//     list->remove(1);
//     cout<<"\n";
//     list->print();
//     // list->clear();
//     bool ans = list->contains(4);
//     if(ans) {
//         cout<<"\n4 is present !";
//         cout<<list->getTraverseCount()<<"\n";
//     }else {
//         cout<<"4 is not present !";
//     }
//     // list->print();
// }
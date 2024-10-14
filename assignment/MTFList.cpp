#include<bits/stdc++.h>
using namespace std;
#include"linkedlist.cpp"


class MTFList : public LinkedList {
    private : 
        void moveToFront(Node* prev, Node* curr) {
            if(prev != nullptr) {
                prev->next = curr->next;
                curr->next = head;
                head = curr;
            }
        }
    public : 
        MTFList() {
            head = nullptr;
            length = 0;
            traverseCount = 0;
        }

        bool contains(int anEntry) override {
            Node* curr = head;
            Node* prev = nullptr;
            int cnt = 0;
            while(curr != nullptr && curr->data != anEntry) {
                prev = curr;
                curr = curr->next;
                cnt++;
            }
            if(curr == nullptr) {
                return false;
            }
            moveToFront(prev,curr);
            traverseCount = cnt;
            return true;
        }

        ~MTFList() {
            clear();
        }
};

int main() {
    // 1 2 3 4 5
    MTFList* list = new MTFList();
    int value;
    while(cin>>value) {
        list->add(value);
    }
    cout<<"Length of the list : "<<list->getCurrentSize()<<"\n";
    list->print();
    bool res = list->contains(6);
    if(res == true) {
        cout<<"6 is present in the list\n";
    }else {
        cout<<"6 is not present in the list\n";
    }
    list->print();
}
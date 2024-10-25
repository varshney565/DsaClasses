#include<bits/stdc++.h>
using namespace std;

class Node {
    public : 
        int data;
        Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    ~Node() {
        delete this->next;
    }
};

void print(Node* head) {
    Node* curr = head;

    while(curr != NULL) {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
}


Node* addAtKth(Node* head,int position,int target) {
    //Edge Case
    if(head == nullptr && position > 1) {
        return nullptr;
    }
    //step 1
    if(position == 1) { 
        Node* newNode = new Node(target);
        newNode->next = head;
        return newNode;
    }
    //step 2
    Node* curr = addAtKth(head->next,position-1,target);
    //step 3
    head->next = curr;
    return head;
}

int main() {
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    Node* sixth = new Node(6);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = nullptr;

    int pos = 8;
    int target = 100;
    cout<<"Before\n";
    print(head);
    cout<<"\n";
    head = addAtKth(head,pos,target);
    cout<<"After\n";
    print(head);
}
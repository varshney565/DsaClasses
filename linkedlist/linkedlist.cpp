#include"Node.cpp"
#include<bits/stdc++.h>
using namespace std;

void print(Node* head) {
    Node* curr = head;

    /**
     * check
     * 
     * return;
     */

    while(curr != NULL) {
        cout<<curr->data<<"->";
        curr = curr->next;
    }
    // here i need the head of the linked list
}

int length(Node* head) {
    Node* curr = head;
    int cnt = 0;
    while(curr != NULL) {
        curr = curr -> next;
        cnt++;
    }
    return cnt;
}

Node* addAtEnd(int data,Node* head) {
    //TODO
}


Node* addAtKthNode(int data,Node* head,int k) {
    //TODO
}

Node* addAtBeginning(int data,Node* head) {
    Node* newNode = new Node(data);
    newNode->next = head;
    return newNode;
}

int main() {
    Node *head = new Node(1);
    Node *second = new Node(3);
    Node* third = new Node(5);
    Node* fourth = new Node(6);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    print(head);
    int l = length(head);
    cout<<"\nLength of the linked list : "<<l<<"\n";

    head = addAtBeginning(-1,head);
    print(head);
    int l2 = length(head);
    cout<<"\nLength of the linked list : "<<l2<<"\n";
}
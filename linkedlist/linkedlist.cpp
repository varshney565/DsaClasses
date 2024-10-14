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
        cout<<curr->data<<" ";
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
    if(head == NULL) {
        Node* temp = new Node(data);
        return temp;
    }
    Node* curr = head;
    while(curr->next != nullptr) {
        curr = curr->next;
    }
    Node* temp = new Node(data);
    curr->next = temp;
    return head;
}


Node* addAtKthPos(int data,Node* head,int k) {
    //TODO
    if(k < 0) {
        return head;
    }

    if(k == 0) {
        Node* curr = new Node(data);
        curr->next = head;
        return curr;
    }

    Node* curr = head;
    int position = 0;
    while(curr != nullptr && position < k-1) {
        position++;
        curr = curr->next;
    }

    Node* temp = new Node(data);
    if(curr != nullptr) {
        temp->next = curr->next;
        curr->next = temp;
    }
    return head;
}


Node* removeFromHead(Node* head) {
    Node* curr = head;
    curr = curr->next;
    head->next = nullptr;
    delete head;
    return curr;
}

Node* removeFromTail(Node* head) {
    //TODO
}

Node* removeFromKthPos(Node* head,int k) {
    //TODO
}


Node* findMid(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(/**check**/ fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node* addAtBeginning(int data,Node* head) {
    Node* newNode = new Node(data);
    newNode->next = head;
    return newNode;
}

bool isCycle(Node* head) {
    if(head == nullptr) {
        return false;
    }
    Node* fast = head,*slow = head;
    do {
        fast = fast->next;
        if(fast == nullptr) {
            return false;
        }
        fast = fast->next;
        slow = slow->next;
    }while(fast != nullptr && fast->next != nullptr && fast != slow);
    //logic for checking cycle or not
    if(fast == slow) {
        return true;
    }
    return false;
}

Node* reverse(Node* head) {
    Node* curr = head,*prev = nullptr,*next = nullptr;
    while(curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        //update
        prev = curr;
        curr = next;
    }
    //linked list is reversed
    return prev;
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
    cout<<"Before reverse\n";
    print(head);
    cout<<"After Reverse\n";
    head = reverse(head);
    print(head);

    // bool res = isCycle(head);
    // if(res) {
    //     cout<<"Cycle is there\n";
    // }else {
    //     cout<<"No cycle !\n";
    // }
    // print(head);
    // int l = length(head);
    // cout<<"\nLength of the linked list : "<<l<<"\n";

    // head = addAtBeginning(-1,head);
    // print(head);
    // cout<<"\n";
    // head = addAtEnd(8,head);
    // print(head);
    // cout<<"\n";
    // head = addAtKthPos(100,head,4);
    // head = removeFromHead(head);
    // print(head);

    // cout<<"\n";
    // Node* midNode = findMid(head);
    // cout<<"MidNode Data : "<<midNode->data<<"\n";
    // int l2 = length(head);
    // cout<<"\nLength of the linked list : "<<l2<<"\n";
}
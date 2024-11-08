class LinkedList {
    public : 
    Node* head;
    int len;

    add() {

    }
}


LinkedList operator-(LinkedList& list2) {
    vector<int> f(26,0);
    Node* temp = this->head;
    while(temp != nullptr) {
        f[temp->data-'a']++;
        temp = temp->next;
    }
    temp = list2->head;
    while(temp != nullptr) {
        f[temp->data-'a']--;
        temp = temp->next;
    }
    LinkedList newList;
    for(int i = 0 ; i < 26 ; i++) {
        for(int j = 0 ; j < f[i] ; j++) {
            newList.add(i+'a');
        }
    }
    return newList;
}
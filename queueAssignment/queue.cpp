template <typename QueueItem>
class Queue {
    public:
        bool dequeueBack();
        bool enqueue(QueueItem data);
    private:
        struct QueueNode {
            QueueItem item;
            QueueNode *next;
        };

        QueueNode *frontPtr;
        QueueNode *backPtr;
};

template <typename QueueItem>
bool Queue<QueueItem>::dequeueBack() {
    //when queue is empty
    if(frontPtr == nullptr) {
        return false;
    }

    //when only one element
    if(frontPtr == backPtr) {
        delete frontPtr;
        frontPtr = nullptr;
        backPtr = nullptr;
        return true;
    }

    QueueNode *curr = frontPtr;
    while(curr->next != backPtr) {
        curr = curr->next;
    }
    delete(backPtr);
    curr->next = nullptr;
    backPtr = curr;
    return true;
}

int main() {
    Queue<int> *queue = new Queue<int>();

}
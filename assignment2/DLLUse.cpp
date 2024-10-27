#include <bits/stdc++.h>
using namespace std;
#include "Node.h"
#include "DLL.h"
int main() {
    
    DoublyLinkedList list1;
    list1.insert(10);
    list1.insert(30);
    list1.insert(20);
    list1.insert(5);
    list1.insert(25);

    cout << "List1 : " << list1 << endl;

    cout << "Size of List1: " << list1.size() << endl;
    cout << "Is the List1 empty? " << (list1.empty() ? "Yes" : "No") << endl;

    list1.remove(10);
    list1.remove(25);

    cout << "List1 after removals: " << list1 << endl;

    cout<<"Copy constructor\n";
    DoublyLinkedList list2 = list1;

    cout << "List2: " << list2 << endl;

    // Test Copy Assignment
    cout<<"Copy Assignment\n";
    DoublyLinkedList list3;
    list3.insert(100);
    list3 = list1;

    cout << "List3: " << list3 << endl;

    // Test Move Constructor
    cout<<"Move Constructor\n";
    DoublyLinkedList list4 = move(list1);

    cout << "List4: " << list4 << endl;

    // Test Move Assignment
    cout<<"Move Assignment\n";
    DoublyLinkedList list5;
    list5.insert(50);
    list5 = move(list2);

    cout << "List5: " << list5 << endl;

    // Test Merge Operator (+)
    DoublyLinkedList list6;
    list6.insert(1);
    list6.insert(15);
    list6.insert(45);

    DoublyLinkedList mergedList = list4 + list6;

    cout << "Merged list: " << mergedList << endl;

    // Test Comparison operators
    cout << "Are list4 and list5 equal? " << (list4 == list5 ? "Yes" : "No") << endl;
    cout << "Are list4 and mergedList different? " << (list4 != mergedList ? "Yes" : "No") << endl;

    return 0;
}

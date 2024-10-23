#include<bits/stdc++.h>
using namespace  std;

class Integer {
    public :
    int val;

    Integer() {

    }

    Integer(int i) {
        this->val = i;
    }

    void print() {
        cout<<"Value of the Integer "<<this->val<<"\n";
    }

    //sum
    Integer add(const Integer &b) {
        Integer ans;
        ans.val = this->val + b.val;
        return ans;
    }

    Integer operator+(const Integer &b) {
        Integer ans;
        ans.val = this->val + b.val;
        return ans;
    }
};


int main() {
    Integer a(12),b(13),d(20);
    a.print();
    b.print();
    Integer c = a+b+d;
    c.print();
}




// class A {
//     public : 
//     int x;
//     A(int x) {
//         this->x = x;
//     }


//     void print() {
//         cout<<"X : "<<this->x<<"\n";
//     }
// };


// int main() {
//     A a(2),b(20);
//     a.print();
//     b.print();
// }
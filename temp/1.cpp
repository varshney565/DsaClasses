#include<iostream>
using namespace std;


class abc {
    public : 
    int i;
    abc(int i) {
        this->i = i;
    }
};

int main() {
    abc m(5);

    cout<<m.i<<"\n";
}
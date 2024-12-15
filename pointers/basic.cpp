#include<bits/stdc++.h>
using namespace std;

void do_something(int size,int *p) {
    p[1];

}


int main() {
    int i = 10;
    int *p = &i;
    cout<<p<<"\n";

    //size of
    int arr[12] = {3,4,5,6,7,8};
    do_something(12,arr);
    p = arr;

    cout<<sizeof(arr)<<"\n";
    cout<<sizeof(p)<<"\n";


    //initialization
    p = p + 1;
    // arr = arr + 1;

    //& operator
    cout<<arr<<"\n";
    cout<<&arr<<"\n";


    cout<<p<<"\n";
    cout<<&p<<"\n";
}
#include<bits/stdc++.h>
using namespace std;

int main() {
    // int i = 10;
    // int *p = &i;
    // int **a = &p;

    // cout<<i<<"\n"; //10
    // cout<<*p<<"\n";
    // cout<<**a<<"\n";

    // cout<<*a<<"\n";
    // cout<<&i<<"\n";


    int i = 10;
    int *a = &i;
    const int *b = &i;
    *a = 12;
    cout<<i<<"\n";
    cout<<*b<<"\n";
    // *b = 100;
    int j = 120;
    b = &j;

    int * const c = &i;
    c = &j;
}
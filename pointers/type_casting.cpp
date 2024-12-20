#include<bits/stdc++.h>
using namespace std;

int main() {
    /**
     * Typecasting
     * 
     * Implicit
     * Explicit
     */
    // int i = 100;
    // char k = i;
    // cout<<k<<"\n";


    // int *p = &i;
    // char *k2 = (char *)p;
    // cout<<*p<<"\n";
    // cout<<*k2<<"\n";


    /**
     * Reference variable
     */
    int i = 12;
    const int &j = i;
    cout<<i<<"\n";
    cout<<j<<"\n";
    i++;
    cout<<i<<"\n";
    cout<<j<<"\n";
    int k = 100;
    // j = k; error
    i = k;
    k++;
    cout<<j<<"\n";
    cout<<i<<"\n";
    cout<<k<<"\n";

    cout<<&i<<"\n";
    cout<<&j<<"\n";
    cout<<&k<<"\n";
}
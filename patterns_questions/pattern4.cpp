#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int m = 2*n-1;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j <= n-1+i ; j++) {
            if(j < n-1-i) {
                cout<<" ";
            }else {
                cout<<"*";
            }
        }
        cout<<"\n";
    }
}
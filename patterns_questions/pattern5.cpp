#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int m = n/2+1;
    int cnt = 0;
    int inc = 1;
    for(int i = 0 ; i < n ; i++) {
        if(i == m-1) {
            inc *= -1;
        }
        for(int j = 0 ; j < m ; j++) {
            if(j <= cnt) {
                cout<<"*";
            }else {
                cout<<" ";
            }
        }
        cnt += inc;
        cout<<"\n";
    }
}
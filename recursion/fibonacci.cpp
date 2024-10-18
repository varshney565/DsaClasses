#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
    //step 1
    if(n <= 1) return n;

    //step 2
    int o1 = fibonacci(n-1);
    int o2 = fibonacci(n-2);

    //step 3
    int ans = o1 + o2;
    return ans;
}

int main() {
    int n = 8;
    int ans = fibonacci(n);
    cout<<ans<<"\n";
}
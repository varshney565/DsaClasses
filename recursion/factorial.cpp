#include<bits/stdc++.h>
using namespace std;

int factorial(int n) {
    //step 1
    if(n == 0) {
        return 1;
    }

    //step 2
    int smallOutput = factorial(n-1);

    //step 3
    int ans = smallOutput*n;

    return ans;
}

int main() {
    int ans = factorial(4);
    cout<<ans<<"\n";
}
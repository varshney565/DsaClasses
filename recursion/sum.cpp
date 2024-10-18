#include<bits/stdc++.h>
using namespace std;

int sum(int n) {
    //step 1
    if(n == 0) return 0;

    //step 2
    int smallOutput = sum(n-1); //4
    //smallOutput = 10

    // step 3
    int ans = n + smallOutput;

    return ans;
}

int main() {
    int n = 5;
    cout<<sum(n)<<"\n";
    // 1 + 2 + 3 + 4 + 5 = 15
}
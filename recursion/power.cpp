#include<bits/stdc++.h>
using namespace std;

int power(int x,int n) {
    //step 1
    if(n == 0) return 1;
    //step 2
    int smallOut = power(x,n/2);
    //step 3
    if(n%2 == 0) {
        int answer = smallOut*smallOut;
        return answer;
    }else {
        int answer = x*smallOut*smallOut;
        return answer;
    }
}

int main() {
    int ans = power(2,8);
    cout<<ans<<"\n";
}
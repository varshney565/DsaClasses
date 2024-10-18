#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[],int n) {
    //step 1
    if(n <= 1) return true;

    //step 2
    int res = isSorted(arr,n-1);

    //step 3
    // if(res == true) {
    //     bool status = arr[n-1] > arr[n-2];
    //     return status;
    // }
    // return false;
    return res && arr[n-1] > arr[n-2];
}

int main() {
    int arr[10] = {1,2,3,4,5,16,7,8,9,10};
    bool res = isSorted(arr,10);
    cout<<res<<"\n";
}
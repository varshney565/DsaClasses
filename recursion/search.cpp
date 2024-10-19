#include<bits/stdc++.h>
using namespace std;

bool search(int arr[],int len,int target) {
    //step 1
    if(len == 0) return false;

    //step 2
    bool res = search(arr,len-1,target);

    //step 3
    if(res == true) return true;
    else {
        if(arr[len-1] == target) return true;
        else return false;
    }
}

int main() {
    int arr[10] = {1,2,3,4,11,23,3,3,2,1};
    bool res = search(arr,10,56);
    cout<<res<<"\n";
} 
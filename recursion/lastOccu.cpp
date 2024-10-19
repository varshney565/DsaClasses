#include<bits/stdc++.h>
using namespace std;

int search(int arr[],int len,int target) {
    //step1 
    if(len == 0) return -1;

    //step 2
    int res = search(arr,len-1,target); //assume

    //step 3
    if(arr[len-1] == target) return len-1;
    return res;
}

int main() {
    int arr[10] = {1,2,3,4,11,23,3,3,2,1};
    int res = search(arr,10,3);
    cout<<res<<"\n";
}
#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr,int si,int ei) {
    int pivot = arr[ei];
    int i = si-1;
    int j = si;
    while(j < ei) {
        if(arr[j] >= pivot) {
            j++;
            i++;
        }else {
            swap(arr[i],arr[j]);
            j++;
        }
    }
    i++;
    swap(arr[i],arr[ei]);
    return i;
}

void quickSort(vector<int>& arr,int si,int ei) {
    if(si >= ei) {
        return;
    }

    int ind = partition(arr,si,ei);
    quickSort(arr,si,ind-1);
    quickSort(arr,ind,ei);
}

int main() {
    vector<int> v = {4,2,9,8,3,5,7};
    // int ind = partition(v,0,6);
    // for(int i = 0 ; i < 7 ; i++) {
    //     cout<<v[i]<<" ";
    // }
    // cout<<"\n";
    // cout<<"index : "<<ind<<"\n";
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for(auto i = 0 ; i < v.size() ; i++) {
        cout<<v[i]<<" ";
    }

    for(auto it = v.begin() ; it != v.end() ; it++) {
        cout<<*it<<" ";
    }

    for(auto it1 = v.rbegin() ; it1 != v.rend() ; it1++) {
        cout<<*it1<<" ";
    }

    if(v.empty()) {
        cout<<"vector is empty\n";
    }else {
        cout<<"vector is not empty\n";
    }

    // reverse(v.begin(),v.end());

    for(auto i = 0 ; i < v.size() ; i++) {
        cout<<v[i]<<" ";
    }

    auto it = upper_bound(v.begin(),v.end(),2);    
    if(it != v.end()) {
        cout<<*it<<"\n";
    }else {
        cout<<"End";
    }

    auto res = binary_search(v.begin(),v.end(),12);
    if(res == true) {
        cout<<"ELement is present\n";
    }else {
        cout<<"Element is not present\n";
    }
}
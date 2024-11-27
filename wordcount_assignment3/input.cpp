#include<bits/stdc++.h>
using namespace std;

class Tree {
    class Node {

    };


};

string convert(string s) {
    string ans = "";
    for(int i = 0 ; i < s.size() ; i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            ans += s[i];
            continue;
        }
        if(s[i] == '\'') {
            ans += s[i];
            continue;
        }
        ans += (s[i] + 32);
    }
    return ans;
}

int main() {
    string s = "abcd35mnpo-qrsdOn't bnjK";
    //words = abcd mnop qrsdon't bnjk
    vector<string> ans;
    string temp = "";
    for(int i = 0 ; i < s.size() ; i++) {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '\'') {
            temp += s[i];
        }else {
            if(temp.size() > 0) ans.push_back(temp);
            temp = "";
        }
    }
    if(temp.size() > 0) {
        ans.push_back(temp);
    }

    // Tree *t; 

    for(int i = 0 ; i < ans.size() ; i++) {
        cout<<convert(ans[i])<<" ";
        // t->insert(ans[i]);
    }
}
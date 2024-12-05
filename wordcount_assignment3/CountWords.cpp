#include<bits/stdc++.h>
using namespace std;

#include"Tree.cpp"

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
    //words = abcd mnop qrsdon't bnjk
    vector<string> ans;
    string temp = "";
    char c;
    while(cin.get(c)) {
        if(c == '\n') {
            break;
        }
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '\'') {
            temp += c;
        }else {
            if(temp.size() > 0) ans.push_back(temp);
            temp = "";
        }
    }
    if(temp.size() > 0) {
        ans.push_back(temp);
    }

    WordTree *t = new WordTree();

    for(int i = 0 ; i < ans.size() ; i++) {
        string v = convert(ans[i]);
        t->add(v);
    }

    cout<<t<<"\n";

    cout<<t->numWords()<<"\n";
}
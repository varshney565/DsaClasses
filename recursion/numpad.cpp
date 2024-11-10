#include<iostream>
#include<vector>
#include<string>
using namespace std;

void solve(string &input,int index,string temp,vector<string> &numPad) {
    //Base Case
    if(index == input.size()) {
        cout<<temp<<"\n";
        return;
    }

    //do the things for the index.
    string x = numPad[input[index]-'0'];
    for(int i = 0 ; i < x.size() ; i++) {
        char t = x[i];
        temp.push_back(t);
        solve(input,index+1,temp,numPad);
        temp.pop_back();
    }
}

int main() {
    vector<string> numPad = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    string input = "23";
    solve(input,0,"",numPad);
}
#include<bits/stdc++.h>
using namespace std;

#include"Puzzle.h"


int main() {
    Puzzle p;
    cout<<"Enter the grid\n";
    cin>>p;

    cout<<"Initial Grid\n";
    cout<<p;
    bool res = p.solve();
    if(res) {
        cout<<"Final Grid\n";
        cout<<p;
    }else {
        cout<<"No solution exist !";
    }
}

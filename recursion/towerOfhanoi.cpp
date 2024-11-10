#include<iostream>
using namespace std;

int t_o_h_moves(int n,char start,char aux,char target) {
    //Base Case
    if(n == 0) {
        return 0;
    }

    int x = t_o_h_moves(n-1,start,target,aux);
    int y = t_o_h_moves(n-1,aux,start,target);
    return x+y+1;
}

int main() {
    cout<<t_o_h_moves(5,'S','A','T')<<"\n";
}
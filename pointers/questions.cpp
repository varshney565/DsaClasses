#include<bits/stdc++.h>
using namespace std;

int main() {
    // int a = 10;
    // int &ref = a;
    // int *p = &ref;
    // cout << *p << endl;



    // int arr[] = {1, 2, 3, 4};
    // int *p = arr;
    // *(p + 1) = 20;
    // cout << arr[1] << endl;


    // int a = 10, b = 20;
    // const int *p = &a;
    // p = &b;
    // cout << *p << endl;


    // int a = 10;
    // int *p = &a;
    // int **pp = &p;
    // cout << **pp << endl;


    // int *p = new int(25);
    // cout << *p << endl;
    // delete p;


    // int a = 10;
    // void *p = &a;
    // cout << *(int *)p << endl;

    // int *p;
    // p = 0;
    // cout<<*p<<"\n";


    // int *p = new int(10);
    // delete p;
    // cout << *p << endl;



    // char str[] = "Hello";
    // char *p = str;
    // cout << p << endl;
    // cout << *p << endl;
    // cout << *(p + 1) << endl;



    // int a = 10;
    // const int *p = &a;
    // a = 20;
    // cout << *p << endl;


    int a = 10, b = 20;
    int *p1 = &a, *p2 = &b;
    int *temp = p1;
    p1 = p2;
    p2 = temp;
    cout << *p1 << " " << *p2 << endl;



}
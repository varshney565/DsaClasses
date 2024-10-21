#include<bits/stdc++.h>
using namespace std;

class Person {
    public : 
    string name;
    int age;

    //Default Constructor
    Person() {

    }

    //Parameterzied Construtor
    Person(string name,int age) {
        this->name = name;
        this->age = age;
    }


    //Copy Constructor
    Person(const Person &p) {
        this->name = p.name;
        this->age = p.age;
    }

    //Copy Assignment Operator
    Person& operator=(const Person& p) {
        this->name = p.name;
        this->age = p.age;
        return *this;
    }

    void print() {
        cout<<this->name<<" : "<<this->age<<"\n";
    }
};


int main() {
    Person p1;
    Person p2("shivam",99);
    p1.print();
    p1 = p2;
    p1.print();
}
#pragma once
class Tree {
    public :
        virtual void add(const string& word) = 0;

        virtual int numWords() const = 0;
};
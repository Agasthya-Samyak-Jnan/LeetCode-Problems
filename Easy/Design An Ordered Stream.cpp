#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/design-an-ordered-stream/
// Difficulty : Easy

/* DESIGN PROBLEM - ORDERED STREAM */
class OrderedStream {
public:
    vector<string> MyStream;
    int ptr;
    int size;
    
    OrderedStream(int n) {
        MyStream.assign(n,"\0");
        ptr = 0;
        size = n;
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> output;
        MyStream[idKey-1] = value;
        while (ptr<size && MyStream[ptr] != "\0") {
           output.push_back(MyStream[ptr++]);
        }
        return output;
    }
};
